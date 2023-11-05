#ifndef RANGE_GENERATOR_H
#define RANGE_GENERATOR_H

#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

class RangeGenerator
{
private:
    ros::NodeHandle nh;

    sensor_msgs::Range range_msg;
    ros::Publisher pub;

    char frameid[];

public:
    RangeGenerator(/* args */);
    ~RangeGenerator();

    void setup();

    float getRange();

    void generate();
};
