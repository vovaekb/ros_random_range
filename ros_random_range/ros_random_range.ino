#define USE_USBCON

#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

ros::NodeHandle nh;

sensor_msgs::Range range_msg;
ros::Publisher pub("/range", &range_msg);

char frameid[] = "/range";

float getRange(){
  float range = 4 + static_cast<float>(rand()) / (static_cast<float> (RAND_MAX));
  return range;
}

void setup(){
  nh.initNode();
  nh.advertise(pub);
  
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id = frameid;
  range_msg.field_of_view = 0.1;
  range_msg.min_range = 0.0;
  range_msg.max_range = 6.5;
}

long range_time;

void loop(){
  if( millis() >= range_time ){
    range_msg.range = getRange();
    range_msg.header.stamp = nh.now();
    pub.publish(&range_msg);
    range_time = millis() + 50;
  }
  
  nh.spinOnce();
}
