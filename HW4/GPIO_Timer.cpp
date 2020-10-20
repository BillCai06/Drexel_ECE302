#include <iostream>
#include <unistd.h> //for usleep
#include "GPIO.h"
#include <sys/time.h>
#include <time.h>

using namespace exploringBB;
using namespace std;
struct timespec  stop, start;

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

            //call to setValue once
            while (state == 0)
            {

                if (inGPIO.getValue() == 1)
                {
                    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
                    state = 1;
                }
            }
        }
        else
        {

            while (state == 1)
            {

                if (inGPIO.getValue() == 1)
                {
                    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
                    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
                    cout << "Time pasted" << delta_us << endl;
                }
            }
        }
    }
    return 0;
}