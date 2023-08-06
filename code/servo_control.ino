/*servo motor driver board control
   Home Page
*/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servo_control = Adafruit_PWMServoDriver();

#define SERVO_MIN_PULSE_WIDTH 150  // Minimum pulse width for the servo (in microseconds)
#define SERVO_MAX_PULSE_WIDTH 600  // Maximum pulse width for the servo (in microseconds)
#define SERVO_MIN_ANGLE 0          // Minimum angle for the servo
#define SERVO_MAX_ANGLE 180

#define leg_max 0
#define leg_min 180
#define leg_flat 90
void setup() {
  Serial.begin(9600);
  servo_control.begin();
  servo_control.setPWMFreq(60);
}

void loop() {

  startup();

  get_down();

 yawn();


  while (1) {
  }
}

void setServoAngle(uint8_t channel, int angle) {
  int pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  servo_control.setPWM(channel, 0, pulse_width);
}


void leg_control(int servo1, int servo2, int servo3, int servo4) {
  setServoAngle(0, servo1);
  setServoAngle(1, 180 - servo2);
  setServoAngle(2, 180 - servo3);
  setServoAngle(3, servo4);
  Serial.println("Command Given");
}

void thigh_control(int servo1, int servo2, int servo3, int servo4) {
  setServoAngle(12, servo1);        // 0 Out
  setServoAngle(13, 180 - servo2);  // 180 out
  setServoAngle(14, 180 - servo3);  // 180 out
  setServoAngle(15, servo4);        // 0 out
  Serial.println("Thigh Command Given");
}

void get_down() {
  for (int i = 140; i > 70; i--) {
    leg_control(i, i, i, i);
    delay(20);
  }
}

void startup() {
  leg_control(0, 0, 0, 0);
  delay(500);
  leg_control(180, 180, 180, 180);
  delay(500);
  thigh_control(0, 0, 0, 0);
  delay(500);
  thigh_control(0, 0, 70, 70);
  delay(500);
  leg_control(180, 120, 120, 120);
  delay(500);
  leg_control(70, 140, 140, 140);
  delay(500);
  leg_control(10, 140, 120, 140);
  delay(100);
  leg_control(70, 140, 120, 140);
  delay(100);
  leg_control(10, 140, 120, 140);
  delay(100);
  leg_control(140, 140, 140, 140);
  delay(500);
  leg_control(140, 70, 140, 120);
  delay(100);
  leg_control(140, 00, 140, 120);
  delay(100);
  leg_control(140, 70, 140, 120);
  delay(100);
  leg_control(140, 0, 140, 120);
  delay(100);
  leg_control(140, 140, 140, 140);
  delay(100);
  thigh_control(0, 0, 0, 0);
  delay(100);
}
void yawn()
{ for (int i = 40; i < 170; i++ ){
    leg_control(i, i, 170, 170);
    delay(50);
  }}
/*
setServoAngle(12, 40) ;
setServoAngle(13, 180 - 40) ;
setServoAngle(14, 180-40) ;
setServoAngle(15, 40) ; */
