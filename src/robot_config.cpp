#include "vex.h"
using namespace vex;

competition Competition;

// defining constants
controller playerController = controller(); // controller

// left motors
motor frontLeftMotor = motor(PORT1);
motor leftMotor = motor(PORT2);
motor backLeftMotor = motor(PORT3);

// right motors
motor frontRightMotor = motor(PORT6);
motor rightMotor = motor(PORT7);
motor backRightMotor = motor(PORT8);

motor leftMotors[] = {frontLeftMotor, leftMotor, backLeftMotor}; // left half of drivetrain

motor rightMotors[] = {frontRightMotor, rightMotor, backRightMotor}; // right half of drivetrain