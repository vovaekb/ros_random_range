#include <ros.h>
#include "range_generator.h"

RangeGenerator::RangeGenerator(/* args */)
{
    frameid[] = "/range";
    pub = new ros::Publisher("/range", &range_msg);
}

void RangeGenerator::setup()
{
    nh.initNode();
    nh.advertise(pub);

    range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
    range_msg.header.frame_id = frameid;
    range_msg.field_of_view = 0.1;
    range_msg.min_range = 0.0;
    range_msg.max_range = 6.5;
}

RangeGenerator::~RangeGenerator()
{
}

float RangeGenerator::getRange()
{
    float range = 4 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX));
    return range;
}

void RangeGenerator::generate()
{
    if (millis() >= range_time)
    {
        range_msg.range = getRange();
        range_msg.header.stamp = nh.now();
        pub.publish(&range_msg);
        range_time = millis() + 50;
    }

    nh.spinOnce();
}