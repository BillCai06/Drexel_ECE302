#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>

#include "GPIO.h"

using namespace std;
unsigned int microseconds;

FILE *LEDHandle = NULL;
char *LEDBrightness0 = "/sys/class/leds/beaglebone:green:usr0/brightness";
char *LEDBrightness1 = "/sys/class/leds/beaglebone:green:usr1/brightness";
char *LEDBrightness2 = "/sys/class/leds/beaglebone:green:usr2/brightness";
char *LEDBrightness3 = "/sys/class/leds/beaglebone:green:usr3/brightness";
char *LEDS[7] = {LEDBrightness0, LEDBrightness1, LEDBrightness2, LEDBrightness3, LEDBrightness2, LEDBrightness1, LEDBrightness0};

using namespace exploringBB;
using namespace std;
int main()
{
    GPIO inGPIO(46);
    inGPIO.setDirection(INPUT);

    while (1)
    {
        for (int i = 0; i < 6;)
        {

            if (inGPIO.getValue() == 1)
            {
                while (inGPIO.getValue() == 1)
                    ;

                if ((LEDHandle = fopen(LEDS[i], "r+")) != NULL)
                {
                    fwrite("1", sizeof(char), 1, LEDHandle);
                    fclose(LEDHandle);
                }
                if ((LEDHandle = fopen(LEDS[i - 1], "r+")) != NULL)
                {
                    fwrite("0", sizeof(char), 1, LEDHandle);
                    fclose(LEDHandle);
                }
                if (i == 6)
                {

                    if ((LEDHandle = fopen(LEDS[0], "r+")) != NULL)
                    {
                        fwrite("0", sizeof(char), 1, LEDHandle);
                        fclose(LEDHandle);
                    }
                }
                i++;
            }
        }
    }
    return 0;
}