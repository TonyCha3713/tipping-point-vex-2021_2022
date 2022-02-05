#include "main.h"

void runLeftBase(double percVolt)
{
    leftBase1.move_voltage(percVolt * 12000/100);
    leftBase2.move_voltage(percVolt * 12000/100);
    leftBase3.move_voltage(percVolt * 12000/100);
}

void runRightBase(double percVolt)
{
    rightBase1.move_voltage(percVolt * 12000/100);
    rightBase2.move_voltage(percVolt * 12000/100);
    rightBase3.move_voltage(percVolt * 12000/100);
}

double getLeftBase()
{
    return (leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position()) / 3.0;
}

double getRightBase()
{
    return (rightBase1.get_position() + rightBase2.get_position() + rightBase3.get_position()) / 3.0;
}

void resetLeftBase()
{
    leftBase1.tare_position();
    leftBase2.tare_position();
    leftBase3.tare_position();
}

void resetRightBase()
{
    rightBase1.tare_position();
    rightBase2.tare_position();
    rightBase3.tare_position();
}

void moveBase(double input, double speed)
{
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    leftBase3.move_relative(input, speed); 
    rightBase1.move_relative(input, speed); 
    rightBase2.move_relative(input, speed); 
    rightBase3.move_relative(input, speed); 
}

void turnBase(double input, double speed)
{
    std::cout << "works" << std::endl;
    leftBase1.tare_position(); leftBase2.tare_position(); leftBase3.tare_position();
    rightBase1.tare_position(); rightBase2.tare_position(); rightBase3.tare_position();
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    leftBase3.move_relative(input, speed); 
    rightBase1.move_relative(-input, speed); 
    rightBase2.move_relative(-input, speed); 
    rightBase3.move_relative(-input, speed); 
}

void checkMoving(double input)
{
    leftBase1.tare_position(); leftBase2.tare_position(); leftBase3.tare_position();
    rightBase1.tare_position(); rightBase2.tare_position(); rightBase3.tare_position();
    //std:: cout << "checkMoving " << input << std::endl;
    while (1) {
        double avgPos = (leftBase2.get_position() + rightBase2.get_position())/2.0;
        if (avgPos <= input + 5 && avgPos >= input - 5) break;
    }
}

void moveStraight(double percVolt)
{
    leftBase1.move_voltage(percVolt * 12000/100);
    leftBase2.move_voltage(percVolt * 12000/100);
    leftBase3.move_voltage(percVolt * 12000/100);
    rightBase1.move_voltage(percVolt * 12000/100);
    rightBase2.move_voltage(percVolt * 12000/100);
    rightBase3.move_voltage(percVolt * 12000/100);
}

void moveStraightTimed(double percVolt, double input)
{
    moveStraight(percVolt);
    checkMoving(input);
    moveStraight(0);
}

void moveBasePID(double deltaTicks, double time, double maxOutput)
{
    double leftBaseTarget = getLeftBase() + deltaTicks;
    double rightBaseTarget = getRightBase() + deltaTicks;
    PID leftBase (0.35, 0.3, 0.5);
    PID rightBase (0.35, 0.3, 0.5);
    std::uint_least32_t now = millis();
    for (int i = 0; i < time; i++) {
        leftBase.setError(leftBaseTarget - getLeftBase());
        rightBase.setError(rightBaseTarget - getRightBase());
        
        runLeftBase(leftBase.runPID());
        runRightBase(rightBase.runPID());
        Task::delay_until(&now, 1);
    }
    runLeftBase(0);
    runRightBase(0);
}