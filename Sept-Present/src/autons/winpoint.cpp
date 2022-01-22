#include "main.h"
void winpoint()
{
    bool holdValue = true;
    bool clamp = false;
    runbackLift(-127, holdValue);
    delay(2500);
    runLift(110);
    delay(1000);
    runLift(0);
    runLeftBase(80);
    delay(1800);
    runLeftBase(0);
    moveBase(300, 100);
    checkMoving(300);
    turnBase(-280, 100);
    delay(1000);
    moveBase(-2150, 127);
    checkMoving(-2120);
    setBool(clamp);
    runLift(110);
    delay(1500);
    moveBase(400, 127);
}
