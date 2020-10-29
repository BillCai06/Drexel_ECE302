#include <iostream>
#include <unistd.h> //for usleep
#include "GPIO.h"
using namespace exploringBB;
using namespace std;
int main()
{
    GPIO outGPIO(60), inGPIO0(46), inGPIO1(26);
    // set GPIO directions
    outGPIO.setDirection(OUTPUT);
    inGPIO0.setDirection(INPUT);
    inGPIO1.setDirection(INPUT);
    int state = 0;
    int password[3] = {1, 0, 1};
    int check[3];

    while (1)
    {
        for (int i = 0; i < 3;)
        {
            if (inGPIO1.getValue() == 1)
            {
                while (inGPIO1.getValue() == 1)
                    ;
                check[i] = 1;
                i++;
            }
            else if (inGPIO10.getValue() == 1)
            {
                while (inGPIO0.getValue() == 1)
                    ;
                check[i] = 0;
                i++;
            }
        }
        if (check == password)
        {
            outGPIO.setValue(HIGH);
        }
    }
    return 0;
}