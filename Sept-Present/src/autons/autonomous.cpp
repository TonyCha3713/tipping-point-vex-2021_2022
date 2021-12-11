#include "main.h"
void auton()
{
    moveBase(1000,127);
    setBool(true);
    moveBase(-600, 127);
    turnBase(400,127);
    setBool(false);

}   