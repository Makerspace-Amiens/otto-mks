#include <Arduino.h>
#include <U8g2lib.h>

// Déclaration de l'écran OLED 128x32 avec U8G2 en I2C
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE);

// Variables pour la lecture série
String inputString = "";
bool stringComplete = false;

// Fonction pour obtenir le motif binaire Code39 d'un caractère spécifique
String getCode39Pattern(char c) {
  switch (c) {
    case '*': return "010010100"; // Symbole de début/fin Code 39
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
    default: return "000000000"; // Caractère inconnu (erreur visuelle)
  }
}

// Fonction principale pour dessiner un Code39 sur l'écran OLED
void drawCode39(const char* data, uint8_t xOffset, uint8_t y, uint8_t pitch, uint8_t height) {
  String originData = "*" + String(data) + "*"; // Ajouter les symboles Start/Stop obligatoires
  originData.toUpperCase();

  // Effacer l'écran avec fond blanc
  u8g2.setDrawColor(1);
  u8g2.drawBox(0, 0, 128, 32);

  // Préparer le dessin des barres noires
  u8g2.setDrawColor(0);

  // Calculer la largeur totale du code-barres pour le centrer
  uint16_t totalWidth = 0;
  for (uint8_t i = 0; i < originData.length(); i++) {
    String binCode = getCode39Pattern(originData.charAt(i));
    for (uint8_t j = 0; j < 9; j++) {
      totalWidth += (binCode.charAt(j) == '1') ? pitch * 2 : pitch;
    }
    totalWidth += pitch; // Espace entre caractères
  }

  // Position X de départ centrée
  uint8_t x = (128 - totalWidth) / 2;

  // Dessiner chaque caractère
  for (uint8_t i = 0; i < originData.length(); i++) {
    String binCode = getCode39Pattern(originData.charAt(i));
    bool drawBar = true;
    for (uint8_t j = 0; j < 9; j++) {
      uint8_t barWidth = (binCode.charAt(j) == '1') ? pitch * 2 : pitch;
      if (drawBar) {
        u8g2.drawBox(x, y, barWidth, height);
      }
      x += barWidth;
      drawBar = !drawBar;
    }
    // Ajouter un espace après chaque caractère
    x += pitch;
  }
}

void setup() {
  Serial.begin(115200);
  u8g2.begin();

  // Écran d'attente au démarrage
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x13_te);
  u8g2.drawStr(0, 12, "Waiting for float...");
  u8g2.sendBuffer();

  inputString.reserve(100);
  Serial.println("[DEBUG] Setup complete. Send float like 6.25 followed by newline");
}

void loop() {
  // Lecture série caractère par caractère
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    Serial.print("[DEBUG] Received char: ");
    Serial.println(inChar);
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }

  if (stringComplete) {
    Serial.print("[DEBUG] Received string: ");
    Serial.println(inputString);

    // Validation et parsing du float reçu
    float value = inputString.toFloat();
    if (value == 0 && inputString != "0" && inputString != "0.0") {
      Serial.println("[ERROR] Invalid float input. Aborting.");
    } else {
      char floatBuffer[10];
      dtostrf(value, 4, 2, floatBuffer);
      Serial.print("[DEBUG] Parsed float: ");
      Serial.println(floatBuffer);

      // Effacer écran et redessiner
      u8g2.clearBuffer();
      u8g2.setFont(u8g2_font_5x7_tr);
      u8g2.setDrawColor(0);

      uint8_t startX = 0;
      drawCode39(floatBuffer, startX, 0, 1, 32); // Dessiner le code-barres en pleine hauteur

      u8g2.sendBuffer();
      Serial.println("[INFO] Full Code39 barcode drawn.");
    }

    inputString = "";
    stringComplete = false;
  }
}