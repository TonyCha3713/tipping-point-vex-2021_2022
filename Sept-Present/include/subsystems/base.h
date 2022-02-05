#ifndef BASE_H
#define BASE_H
void runLeftBase(double input);
void runRightBase(double input);
double getLeftBase();
double getRightBase();
void resetLeftBase();
void resetRightBase();
void moveBase(double input, double speed);
void turnBase(double input, double speed);
void checkMoving(double input);
void moveStraight(double input);
void moveStraightTimed(double percVolt, double input);
void moveBasePID(double deltaTicks, double time, double maxOutput);
#endif