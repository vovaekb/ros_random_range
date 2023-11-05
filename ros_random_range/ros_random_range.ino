#define USE_USBCON

/*
Example: https://github.com/nohorbee/arduino-class-library-helloworld/blob/master/LED13/LED13.cpp

*/

#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
#include "range_generator.h"

RangeGenerator range;

void setup()
{
    range.setup();
}

void loop()
{
    range.generate();
}
