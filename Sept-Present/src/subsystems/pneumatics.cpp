#include "main.h"
void setBool(bool &input)
{
    bool value;
    value = (input) ? false : true;
    piston.set_value(value);
    piston2.set_value(value);
    input = !input;
}

