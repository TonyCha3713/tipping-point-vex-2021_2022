#include "main.h"
void left()
{
    bool clamp = false;
    moveStraightTimed(-95, -1150);
    setBool(clamp); runLift(-100); delay(100);
    moveStraightTimed(95, 900);
    delay(1000);
    turnBase(140,70);
    delay(1700);
    setBool(clamp);
    moveStraightTimed(60, 375);
    delay(1000);
    turnBase(90, 80);
    delay(500); runLift(0);
    moveStraightTimed(-50, -500);
    setBool(clamp);
    delay(100);
    moveStraightTimed(30, 130); delay(50);
    runIntake(80);
    delay(1000);
    moveStraightTimed(40, 300); delay(50);
    moveStraightTimed(-60, -300);
    moveStraightTimed(50, 300);
}
