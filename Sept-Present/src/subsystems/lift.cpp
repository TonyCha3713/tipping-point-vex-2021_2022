#include "main.h"
void runLift(double input)
{
    lift.move_voltage(input * 12000/100);
}