#include <iostream>
#include <unistd.h> //for usleep
#include "GPIO.h"
using namespace exploringBB;
using namespace std;
int main()
{
    GPIO outGPIO(60), inGPIO(46);
    // set GPIO directions
    outGPIO.setDirection(OUTPUT);
    inGPIO.setDirection(INPUT);
    int state = 0;
    while (1)
    {
        if (state == 0)
        {
            //button pullup stuck until press
            while (inGPIO.getValue() == 1)
                ;
            usleep(20000); //slowdown
            //stuck until release
            while (inGPIO.getValue() == 0)
                ;
            state = 1;
            //call to setValue once
            outGPIO.setValue(HIGH);
            usleep(500000);
            outGPIO.setValue(LOW);
            usleep(500000);
        }
        else
        {
            while (inGPIO.getValue() == 1)
                ;
            usleep(20000);
            while (inGPIO.getValue() == 0)
                ;
            outGPIO.setValue(HIGH);
            usleep(200000);
            outGPIO.setValue(LOW);
            usleep(200000);
            state = 0;
        }
    }
    return 0;
}