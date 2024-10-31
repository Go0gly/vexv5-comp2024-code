/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       googly                                                    */
/*    Created:      10/31/2024, 3:13:46 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include<iostream>

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

// controller
controller playerController = controller();

// left motors
motor frontLeftMotor = motor(PORT1);
motor leftMotor = motor(PORT2);
motor backLeftMotor = motor(PORT3);

// right motors
motor frontRightMotor = motor(PORT6);
motor rightMotor = motor(PORT7);
motor backRightMotor = motor(PORT8);

// left half of drivetrain
motor leftMotors[] = {frontLeftMotor, leftMotor, backLeftMotor};

// right half of drivetrain
motor rightMotors[] = {frontRightMotor, rightMotor, backRightMotor};

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    switch(playerController.Axis3.position())
    {
      case 1:
        for(motor i : leftMotors)
        {
          i.spin(forward);
        }
        break;
      case -1:
        for(motor i : leftMotors)
        {
          i.spin(reverse);
        }
        break;
      default:
        for(motor i : leftMotors)
        {
          i.stop();
        }
        break;
    }

    switch(playerController.Axis2.position())
    {
      case 1:
        for(motor i : rightMotors)
        {
          i.spin(forward);
        }
        break;
      case -1:
        for(motor i : rightMotors)
        {
          i.spin(reverse);
        }
        break;
      default:
        for(motor i : rightMotors)
        {
          i.stop();
        }
        break;
    }
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
