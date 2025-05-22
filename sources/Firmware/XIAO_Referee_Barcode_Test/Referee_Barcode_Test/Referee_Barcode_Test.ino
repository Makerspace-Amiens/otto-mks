#include <Adafruit_NeoPixel.h>
#include <U8g2lib.h>

// ==== PINS ====
#define BUZZER_PIN   D0
#define NEOPIXEL_PIN D6
#define KEY_1        D9  // RESET
#define KEY_2        D8  // START/PAUSE
#define KEY_3        D7  // MENU
#define TOR_START    D3
#define TOR_END      D10

// ==== LED ====
#define NUMPIXELS    3
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// ==== OLED ====
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE);

// ==== ÉTATS ====
enum State {IDLE, WAIT_START, RUNNING, PAUSED, FINISHED};
State chronoState = IDLE;
const char* stateLabels[] = {"IDLE", "WAIT", "RUN", "PAUSE", "FINISH"};

// ==== TEMPS ====
unsigned long startTime = 0;
unsigned long pauseTime = 0;
unsigned long elapsedTime = 0;
unsigned long lastTime = 0;

// ==== TOR ====
bool torStartPrev = false;
bool torEndPrev = false;

// ==== MODES ====
enum Mode {MODE_COURSE, MODE_SUMO};
Mode currentMode = MODE_COURSE;

// ==== MENU ====
bool inMenu = true;
uint8_t menuIndex = 0;
const char* menuOptions[] = {"COURSE", "SUMO"};

// ==== SUMO ====
bool sumoRunning = false;
unsigned long sumoStart = 0;

// ==== UTILS ====
void setLED(uint32_t color) {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, color);
  }
  pixels.show();
}

void beep(unsigned int duration = 100) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(duration);
  digitalWrite(BUZZER_PIN, LOW);
}

bool isPressed(uint8_t pin) {
  return digitalRead(pin) == LOW;
}

void drawScreen(unsigned long t, const char* stateLabel, unsigned long lastT) {
  char timeStr[16];
  char lastTimeStr[16];
  float seconds = t / 1000.0;
  float lastSeconds = lastT / 1000.0;
  sprintf(timeStr, "%6.3f s", seconds);
  sprintf(lastTimeStr, "%6.3f s", lastSeconds);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso16_tr);
  u8g2.drawStr(0, 26, timeStr);
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(90, 6, stateLabel);
  u8g2.drawStr(90, 16, "Last:");
  u8g2.drawStr(90, 26, lastTimeStr);
  u8g2.sendBuffer();
}

void drawMenu(uint8_t selected) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  for (uint8_t i = 0; i < 2; i++) {
    if (i == selected) {
      u8g2.drawBox(0, 14 + i * 12, 128, 12);
      u8g2.setDrawColor(0);
      u8g2.drawStr(2, 23 + i * 12, menuOptions[i]);
      u8g2.setDrawColor(1);
    } else {
      u8g2.drawStr(2, 23 + i * 12, menuOptions[i]);
    }
  }
  u8g2.sendBuffer();
}

String getCode39Pattern(char c) {
  switch (c) {
    case '*': return "010010100";
    case '0': return "000110100";
    case '1': return "100100001";
    case '2': return "001100001";
    case '3': return "101100000";
    case '4': return "000110001";
    case '5': return "100110000";
    case '6': return "001110000";
    case '7': return "000100101";
    case '8': return "100100100";
    case '9': return "001100100";
    case '.': return "110000100";
    default: return "000000000";
  }
}

void drawCode39(unsigned long timeMs) {
  char floatBuffer[10];
  float seconds = timeMs / 1000.0;
  dtostrf(seconds, 4, 2, floatBuffer);

  String originData = "*" + String(floatBuffer) + "*";
  originData.toUpperCase();

  u8g2.setDrawColor(1);
  u8g2.drawBox(0, 0, 128, 32);
  u8g2.setDrawColor(0);

  uint16_t totalWidth = 0;
  for (uint8_t i = 0; i < originData.length(); i++) {
    String binCode = getCode39Pattern(originData.charAt(i));
    for (uint8_t j = 0; j < 9; j++) {
      totalWidth += (binCode.charAt(j) == '1') ? 2 : 1;
    }
    totalWidth += 1;
  }

  uint8_t x = (128 - totalWidth) / 2;

  for (uint8_t i = 0; i < originData.length(); i++) {
    String binCode = getCode39Pattern(originData.charAt(i));
    bool drawBar = true;
    for (uint8_t j = 0; j < 9; j++) {
      uint8_t barWidth = (binCode.charAt(j) == '1') ? 2 : 1;
      if (drawBar) {
        u8g2.drawBox(x, 0, barWidth, 28);
      }
      x += barWidth;
      drawBar = !drawBar;
    }
    x += 1;
  }

  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.setDrawColor(0);
  u8g2.drawStr(5, 31, floatBuffer);
  u8g2.sendBuffer();
}

// Ajout de la variable pour afficher le code-barres ou non
bool displayBarcode = false;

// ==== SETUP ====
void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(KEY_1, INPUT_PULLUP);
  pinMode(KEY_2, INPUT_PULLUP);
  pinMode(KEY_3, INPUT_PULLUP);
  pinMode(TOR_START, INPUT);
  pinMode(TOR_END, INPUT);
  pixels.begin();
  pixels.clear();
  pixels.show();
  u8g2.begin();
  u8g2.setDrawColor(1); // Fond noir, texte blanc au démarrage
  drawMenu(menuIndex);
  setLED(pixels.Color(80, 0, 80));
}

// ==== LOOP ====
void loop() {
  unsigned long now = millis();

  if (inMenu) {
    if (isPressed(KEY_3)) {
      menuIndex = (menuIndex + 1) % 2;
      drawMenu(menuIndex);
      delay(200);
    }
    if (isPressed(KEY_1)) {
      currentMode = (Mode)menuIndex;
      inMenu = false;
      chronoState = IDLE;
      elapsedTime = 0;
      lastTime = 0;
      sumoRunning = false;
      displayBarcode = false;
      u8g2.setDrawColor(1); // Fond noir, texte blanc
      drawScreen(0, stateLabels[chronoState], 0);
      setLED(currentMode == MODE_SUMO ? pixels.Color(255, 255, 0) : pixels.Color(80, 0, 80));
      delay(300);
    }
    return;
  }

  bool torStart = digitalRead(TOR_START);
  bool torEnd = digitalRead(TOR_END);
  bool frontStart = torStart && !torStartPrev;
  bool frontEnd = torEnd && !torEndPrev;

  if (currentMode == MODE_SUMO) {
    if (chronoState == IDLE && !sumoRunning) {
      sumoRunning = true;
      sumoStart = now;
      chronoState = RUNNING;
      setLED(pixels.Color(255, 255, 0));
      Serial.println("SUMO demarre");
    }
    if (sumoRunning && chronoState == RUNNING) {
      unsigned long remaining = 60000 - (now - sumoStart);
      if ((int32_t)remaining <= 0) {
        beep();
        setLED(pixels.Color(255, 0, 0));
        chronoState = FINISHED;
        sumoRunning = false;
        displayBarcode = true;
        drawCode39(60000);
      } else {
        drawScreen(remaining, "SUMO", 60000);
      }
    }
  } else {
    switch (chronoState) {
      case IDLE:
        if (isPressed(KEY_2)) {
          chronoState = WAIT_START;
          displayBarcode = false;
          u8g2.setDrawColor(1);
          drawScreen(0, stateLabels[chronoState], lastTime);
          setLED(pixels.Color(0, 0, 255));
          delay(300);
        }
        break;

      case WAIT_START:
        if (frontStart) {
          chronoState = RUNNING;
          startTime = now;
          elapsedTime = 0;
          beep();
          setLED(pixels.Color(0, 255, 0));
          Serial.println("Chrono lance !");
        }
        break;

      case RUNNING:
        if (isPressed(KEY_2)) {
          chronoState = PAUSED;
          pauseTime = now;
          setLED(pixels.Color(255, 165, 0));
          Serial.println("Pause !");
          delay(300);
        } else if (frontEnd) {
          chronoState = FINISHED;
          elapsedTime = now - startTime;
          lastTime = elapsedTime;
          beep();
          setLED(pixels.Color(255, 0, 0));
          Serial.println("Chrono arrete !");
          displayBarcode = true;
          drawCode39(elapsedTime);
        } else {
          elapsedTime = now - startTime;
        }
        break;

      case PAUSED:
        if (isPressed(KEY_2)) {
          chronoState = RUNNING;
          unsigned long pauseDuration = now - pauseTime;
          startTime += pauseDuration;
          setLED(pixels.Color(0, 255, 0));
          Serial.println("Reprise !");
          delay(300);
        }
        break;

      case FINISHED:
        if (isPressed(KEY_1)) {
          chronoState = IDLE;
          elapsedTime = 0;
          displayBarcode = false;
          u8g2.setDrawColor(1);
          drawScreen(0, stateLabels[chronoState], lastTime);
          setLED(pixels.Color(80, 0, 80));
          Serial.println("Reset !");
          delay(300);
        }
        break;
    }
  }

  if (isPressed(KEY_3) && chronoState == FINISHED) {
    displayBarcode = true;
    drawCode39(lastTime);
    delay(300);
  }

  if (!displayBarcode && (currentMode == MODE_COURSE) && (chronoState == RUNNING || chronoState == PAUSED)) {
    drawScreen(elapsedTime, stateLabels[chronoState], lastTime);
  }

  torStartPrev = torStart;
  torEndPrev = torEnd;
  delay(10);
}
