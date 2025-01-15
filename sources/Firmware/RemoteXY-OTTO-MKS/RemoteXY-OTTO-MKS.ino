#define REMOTEXY_MODE__ESP32CORE_BLE
#define REMOTEXY_BLUETOOTH_NAME "Otto-MKS-4"

#define ARDUINO_ARCH_ESP32

#include <BLEDevice.h>
#include <Otto.h>
#include <RemoteXY.h>

Otto Otto;

#define LeftLeg D7
#define LeftFoot D8
#define RightFoot D9
#define RightLeg D10

#define HeadPin D6

#define Buzzer  A0

#define SERVO_LIMIT_DEFAULT 200

int pos = 0;      // position in degrees
int interPos = 2; // interval en ms entre deux positions

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "OTTO-MKS-4"

// RemoteXY GUI configuration  
#pragma pack(push, 1)

uint8_t RemoteXY_CONF[] =   // 86 bytes
  { 255,6,0,0,0,79,0,19,0,0,0,79,84,84,79,45,77,75,83,45,
  52,0,31,1,200,84,1,1,5,0,5,117,20,60,60,37,1,26,31,4,
  39,3,109,11,160,36,26,1,60,48,30,30,4,176,31,240,159,143,160,0,
  1,42,17,30,30,4,134,31,240,159,149,186,0,1,24,48,30,30,4,30,
  31,240,159,142,137,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_01_x; // from -100 to 100
  int8_t joystick_01_y; // from -100 to 100
  int8_t Head; // from -100 to 100
  uint8_t Home; // =1 if button pressed, else =0
  uint8_t Dance; // =1 if button pressed, else =0
  uint8_t Party; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

Servo HeadServo;

void setup() 
{
  Serial.begin(9600);

  RemoteXY_Init ();

  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.home();
  Otto.sing(S_connection);
  Otto.enableServoLimit(180); //Limit the speed of the servomotor. 240 default

  HeadServo.attach(HeadPin);
  
}

void loop() 
{
  RemoteXY_Handler ();

  HeadServo.write(map(RemoteXY.Head, -100, 100, 0, 180));

  // La variable "action" sera utilisée pour déterminer quelle action est activée

  int8_t action = 0;

  // On commence par vérifier les mouvements horizontaux (droite/gauche), 
  // car ils ont la priorité, même si le joystick est aussi en haut ou en bas
  if (RemoteXY.joystick_01_x > 70) {
      action = 1;  // Droite
  } else if (RemoteXY.joystick_01_x < -70) {
      action = 2;  // Gauche
  } else if (RemoteXY.joystick_01_y > 70) {
      action = 3;  // Haut
  } else if (RemoteXY.joystick_01_y < -70) {
      action = 4;  // Bas
  } else if (RemoteXY.Dance){
      action = 6;
  } else if (RemoteXY.Party){
      action = 7;
  } else if (RemoteXY.Home){
      action = 8;
  } else {
    action = 0;
  }

  Serial.println(action);

  // Switch case basé sur la valeur de action
  switch (action) {
      case 0: 
          Otto.home();
          break;
      case 1:  // Droite
          Otto.turn(1,1000,1);
          break;
      case 2:  // Gauche
          Otto.turn(1,1000,-1);
          break;
      case 3:  // Haut
          Otto.walk(1,1000,1);
          break;
      case 4:  // Bas
          Otto.walk(1,1000,-1);
          break;
      case 5:  // Shoot
          //Otto.shakeLeg(1,500,RIGHT);
          //Otto.sing(S_happy_short);
          break;
      case 6:  // Dance
          Otto.swing(1, 1000, 30);
          Otto.home();
          break;
      case 7:  // Party
          Otto.playGesture(OttoVictory);
          Otto.home();
          break;
      case 8:  // Home
          if(Otto.getRestState()==true)
          {
            Otto.setRestState(false);
          }
          Otto.home();
          break;
      default:
          Otto.home();
          break;
    }

}