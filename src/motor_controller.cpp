#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Bool.h>
#include <wiringPi.h>


#define IN1 18
#define IN2 19
#define IN3 23
#define IN4 24

float distance = 1000.0;
float orientation_z = 0.0;

void distanceCallback(const sensor_msgs::Range::ConstPtr& msg) {
    distance = msg->range;
}

void imuCallback(const sensor_msgs::Imu::ConstPtr& msg) {
    orientation_z = msg->orientation.z;
}

void setupMotors() {
    wiringPiSetupGpio();
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "motor_controller");
    ros::NodeHandle nh;

    ros::Subscriber distance_sub = nh.subscribe("/distance", 10, distanceCallback);
    ros::Subscriber imu_sub = nh.subscribe("/imu", 10, imuCallback);

    setupMotors();

    ros::Rate loop_rate(10);

    while (ros::ok()) {
        if (distance < 0.3) {
            stopMotors();
        } else if (orientation_z > 0.2) {
            turnRight();
        } else if (orientation_z < -0.2) {
            turnLeft();
        } else {
            moveForward();
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
