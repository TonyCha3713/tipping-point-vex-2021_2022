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
    //std::cout << "left " << input << std::endl;
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
    //std::cout << "right " << input << std::endl;
}

void moveBase(double input, double speed)
{
    leftBase1.tare_position(); leftBase2.tare_position(); leftBase3.tare_position();
    rightBase1.tare_position(); rightBase2.tare_position(); rightBase3.tare_position();
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    leftBase3.move_relative(input, speed); 
    rightBase1.move_relative(input, speed); 
    rightBase2.move_relative(input, speed); 
    rightBase3.move_relative(input, speed); 
    /*bool run = true;
    while (run)
    {
        pros::delay(2);
        double avgPos = (leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position()
            + rightBase1.get_position() + rightBase2.get_position() + rightBase3.get_position()) / 6.0;
        run = (avgPos < abs(input));
    }
    //while (!((leftBase2.get_position() < abs(input) + 5) && (leftBase2.get_position() > abs(input) - 5))) 
      //  pros::delay(2);*/
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
    /*bool run = true;
    while(run)
    {

        pros::delay(2);
        double avgPos = (leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position()
            + rightBase1.get_position() + rightBase2.get_position() + rightBase3.get_position()) / 6.0;
        run = (avgPos < abs(input));
    }*/
}

void checkMoving(double input)
{
    std:: cout << "checkMoving " << input << std::endl;
    //input = abs(input);
    while (1) {
        double avgPos = (leftBase2.get_position() + rightBase2.get_position())/2.0;
        if (avgPos <= input + 5 && avgPos >= input - 5) break;
    }
}