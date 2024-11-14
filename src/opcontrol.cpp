#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
    // The controller object for operator control
    pros::Controller masterController(pros::E_CONTROLLER_MASTER);

    pros::Motor frontRightMotor(1); // Front right drivetrain motor
    pros::Motor rightMotor(2);      // Middle right drivetrain motor
    pros::Motor backRightMotor(3);  // Back right drivetrain motor

    pros::Motor frontLeftMotor(4); // Front left drivetrain motor
    pros::Motor leftMotor(5);      // Middle left drivetrain motor
    pros::Motor backLeftMotor(6);  // Back left drivetrain motor

    while (true)
    {
        // Move left portion of the drivetrain based on the left joystick
        frontRightMotor.move(masterController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
        rightMotor.move(masterController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
        backRightMotor.move(masterController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));

        // Move right portion of the drivetrain based on the left joystick
        frontLeftMotor.move(masterController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
        leftMotor.move(masterController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
        backLeftMotor.move(masterController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));

        pros::delay(20); // Run for 20 ms then update
    }
}