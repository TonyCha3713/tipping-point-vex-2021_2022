#include "main.h"
void rightMain()
{
    pros::delay(50);
    bool clamp = false;
    moveStraightTimed(-95, -1050); 
    setBool(clamp); runLift(-100);
    moveStraightTimed(95, 700); delay(200);
    turnBase(400, -80); delay(1700);
    runLift(100); delay(1850);
    moveStraightTimed(75, 820);
    runLift(-80); delay(1350); runLift(0); 
    moveStraightTimed(-65, -1200); setBool(clamp); delay(200);
    moveStraightTimed(65, 390); delay(250);
    turnBase(-140, 55); delay(1400);
    moveStraightTimed(-50, -350); setBool(clamp); delay(100);
    moveStraightTimed(50, 300);
    runIntake(90);
    //moveStraightTimed(100, 1000);
    //moveBasePID(1000, 3000, 95);
}   