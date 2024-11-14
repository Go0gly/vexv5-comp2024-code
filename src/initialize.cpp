#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 */
void initialize()
{
    pros::lcd::initialize();
    pros::lcd::set_text(1, "Hello PROS User!");

    pros::delay(1500);
    pros::lcd::clear_line(1);
}