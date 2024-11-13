#include "vex.h"
#include "../src/robot_config.cpp"
#include <iostream>

using namespace vex;

void pre_auton(void)
{

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void)
{
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void usercontrol(void)
{
  // User control code here, inside the loop
  while (1)
  {
    switch (playerController.Axis3.position())
    {
    case 1:
      for (motor i : leftMotors)
      {
        i.spin(forward);
      }
      break;
    case -1:
      for (motor i : leftMotors)
      {
        i.spin(reverse);
      }
      break;
    default:
      for (motor i : leftMotors)
      {
        i.stop();
      }
      break;
    }

    switch (playerController.Axis2.position())
    {
    case 1:
      for (motor i : rightMotors)
      {
        i.spin(forward);
      }
      break;
    case -1:
      for (motor i : rightMotors)
      {
        i.spin(reverse);
      }
      break;
    default:
      for (motor i : rightMotors)
      {
        i.stop();
      }
      break;
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
