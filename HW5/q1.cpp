#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h> //for usleep
#include "GPIO.h"
using namespace exploringBB;

using namespace std;

#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

int readAnalog(int number)
{
    stringstream ss;
    ss << LDR_PATH << number << "_raw";
    fstream fs;
    fs.open(ss.str().c_str(), fstream::in);
    fs >> number;
    fs.close();
    return number;
}
int main(int argc, char *argv[])
{
    GPIO outGPIO(60), inGPIO(46);
    // set GPIO directions
    outGPIO.setDirection(OUTPUT);
    inGPIO.setDirection(INPUT);
    
    cout << "Starting the readLDR program" << endl;
    while (1)
    {
        int value = readAnalog(0);
        if (value >= 2048)
        {
            outGPIO.setValue(LOW);
        }
        else
        {
            outGPIO.setValue(HIGH);
        }
    }
    return 0;
}