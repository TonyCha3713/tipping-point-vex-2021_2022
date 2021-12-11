#include "main.h"
void runLift(double error)
{
    lift.move(127);
    //if (lift.get_position() > 1400 || lift.get_position() < 0) runLift(0);
    //else
        lift.move(error/8);
}