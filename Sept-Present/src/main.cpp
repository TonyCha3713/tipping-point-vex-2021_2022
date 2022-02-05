#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {

	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	leftBase1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftBase2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftBase3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rightBase1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rightBase2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rightBase3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	rightMain();
}

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
void opcontrol() {
	leftBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	leftBase3.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase3.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	bool pistonValue = false;
	std::uint_least32_t now = millis();
	lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	while (true) {
		runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100/127);
		runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100/127);
		
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntake(100);
		else if (master.get_digital(E_CONTROLLER_DIGITAL_A))
			runIntake(-100);
		else runIntake(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			runLift(-100);
		else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
			runLift(100);
		else { runLift(0); lift.set_brake_mode(E_MOTOR_BRAKE_HOLD); }

		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2))
			setBool(pistonValue);

		Task::delay_until(&now, 10);
	}
}
