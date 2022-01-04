#include "main.h"
void runLift(double error)
{
    lift.move(error);
    //if (lift.get_position() > 1400 || lift.get_position() < 0) runLift(0);
    //else
      //  lift.move(error/8);
}

void runbackLift(double input, bool &ok)
{
    backLift.move(input);
    ok = !ok;
    //if (backLift.get_position() > 220 || backLift.get_position() < -700) runbackLift(0);
}