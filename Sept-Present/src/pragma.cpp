#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor leftBase1(12, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBase2(16, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase1(20, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase2(15, pros::E_MOTOR_GEARSET_18, 1, pros::E_MOTOR_ENCODER_DEGREES);