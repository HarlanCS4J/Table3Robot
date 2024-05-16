#include <PRIZM.h>  // Include all of the instructions for Tetrix stuff
PRIZM robot;
const int DRIVE_SPEED = 100;
const int TURN = 25;

void setup() {
  // put your setup code here, to run once:
  robot.PrizmBegin();  // Tells the robot to start up
  robot.setMotorInvert(1,1);   // (which motor, 1=yes/0=no)
}

void loop() {
  // put your main code here, to run repeatedly:
  while(robot.readSonicSensorCM(A3) > 25) {
    robot.setMotorPowers(DRIVE_SPEED,DRIVE_SPEED); //  (motor1, motor2) in percents
  }
  while(robot.readSonicSensorCM(A3) < 50 ) {
    robot.setMotorPowers(-TURN,TURN);
  }
  robot.setMotorPowers(0,0);  // STOP!!!
}
