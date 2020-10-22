#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
unsigned int microseconds;

FILE *LEDHandle = NULL;
char *LEDBrightness0 = "/sys/class/leds/beaglebone:green:usr0/brightness";
char *LEDBrightness1 = "/sys/class/leds/beaglebone:green:usr1/brightness";
char *LEDBrightness2 = "/sys/class/leds/beaglebone:green:usr2/brightness";
char *LEDBrightness3 = "/sys/class/leds/beaglebone:green:usr3/brightness";

void greater_t()
{
  if ((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL)
  {
    fwrite("1", sizeof(char), 1, LEDHandle);
    fclose(LEDHandle);
  }

}
void less_t()
{

  if ((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL)
  {
    fwrite("1", sizeof(char), 1, LEDHandle);
    fclose(LEDHandle);
  }
}
void equal_t()
{

  if ((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL)
  {
    fwrite("1", sizeof(char), 1, LEDHandle);
    fclose(LEDHandle);
  }
}
void off()
{

  if ((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL)
  {
    fwrite("0", sizeof(char), 1, LEDHandle);
    fclose(LEDHandle);
  }

  if ((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL)
  {
    fwrite("0", sizeof(char), 1, LEDHandle);
    fclose(LEDHandle);
  }


  if ((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL)
  {
    fwrite("0", sizeof(char), 1, LEDHandle);
    fclose(LEDHandle);
  }

  if ((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL)
  {
    fwrite("0", sizeof(char), 1, LEDHandle);
    fclose(LEDHandle);
  }
}

int main(int argc, char **argv)
{
  int Int0;
  int Int1;
  cout << "First int "; // Type a number and press enter
  cin >> Int0;             // Get user input from the keyboard
  cout << "Second int ";
  cin >> Int1;

  while (Int0 != 0 && Int1 != 0)
  {
    if (Int0 > Int1)
    {
      off();
      greater_t();
      
    }
    else if (Int0 < Int1)
    {
      off();
      less_t();

      
    }
    else if (Int0 == Int1)
    {
      off();
      equal_t();

    }else{
      cout << "check input ";
      break;
    }
  }
  return 0;
}
