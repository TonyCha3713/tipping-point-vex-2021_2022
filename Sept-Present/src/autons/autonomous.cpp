#include "main.h"
void auton()
{
    bool holdValue = true;
    moveBase(900, 127);
    runbackLift(-127, holdValue);
    delay(300);
    runbackLift(127, holdValue);
    checkMoving(900);
    runbackLift(-127, holdValue);
    delay(500);
    moveBase(-480, 127);
    checkMoving(-480);
    delay(2000);
    runbackLift(127, holdValue);
    delay(1000);
    turnBase(-100, 127);
    delay(2000);
    moveBase(770, 127);
    checkMoving(770);
    runbackLift(-127, holdValue);
    delay(500);
    moveBase(-750, 127);
    /*runbackLift(-127, holdValue);
    delay(500);
    runbackLift(127, holdVa
    moveBase(1000, 127);
    runbackLift(-127, holdValue);
    delay(500);
    moveBase(-450, 127);
    runbackLift(127, holdValue);
    turnBase(-400, 100);*/
    //runbackLift(127, holdValue);
    //moveBase(-600, 127);
    //moveBase(-600, 127);
    /*
    //delay(1000);
    //turnBase(400,110);
    //setBool(false);
    runbackLift(127);
    delay(350);
    runbackLift(0);
    delay(1000);
    moveBase(-800, 127);
    delay(1500);
    runbackLift(-127);
    delay(2000);
    moveBase(800, 127);*/

}   