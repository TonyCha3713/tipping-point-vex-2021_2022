#include "main.h"

void runLeftBase(double input)
{
    if (input < 0)
    {
        input = -input * input / 130;
        //if (input < -127) input = -127;
    }
    else
    {
        input = input * input / 130;
        //if (input > 127) input = 127;
    }
    leftBase1.move(input);
    leftBase2.move(input);
    leftBase3.move(input);
    std::cout << "left " << input << std::endl;
}

void runRightBase(double input)
{
    if (input < 0)
    {
        input = -input * input / 130;
        //if (input < -127) input = -127;
    }
    else
    {
        input = input * input / 130;
        //if (input > 127) input = 127;
    }
    rightBase1.move(input);
    rightBase2.move(input);
    rightBase3.move(input);
    std::cout << "right " << input << std::endl;
}

void moveBase(double input, double speed)
{
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    leftBase3.move_relative(input, speed); 
    rightBase1.move_relative(input, speed); 
    rightBase2.move_relative(input, speed); 
    rightBase3.move_relative(input, speed); 
     while (!((leftBase2.get_position() < input + 5) && (leftBase2.get_position() > input - 5))) 
        pros::delay(2);
}