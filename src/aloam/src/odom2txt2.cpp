#include <iostream>
#include <string>
#include <fstream>
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

using namespace std;
string GT_file = "/home/zhw/txt/Ground_Truth.txt";
string LIEO_file = "/home/zhw/txt/Marked-LIEO(ours).txt";
string LIOSAM_file = "/home/zhw/txt/LIO-SAM.txt";
string ALOAM_file = "/home/zhw/txt/ALOAM.txt";
fstream gt_file, lieo_file, liosam_file, aloam_file;

void gt_handler(const nav_msgs::Odometry::ConstPtr& msgIn)
{
    nav_msgs::Odometry data = *msgIn;
    static int flag=1;
    static double stamp_init;
    if(flag==1){
        stamp_init = data.header.stamp.toSec();
        flag=0;
    }
    gt_file << fixed << data.header.stamp.toSec()-stamp_init   << " "   << data.pose.pose.position.x    << " " << data.pose.pose.position.y << " " 
            << data.pose.pose.position.z    << " "   << data.pose.pose.orientation.x << " " << data.pose.pose.orientation.y << " " 
            << data.pose.pose.orientation.z << " " << data.pose.pose.orientation.w   << std::endl;
}

void lieo_handler(const nav_msgs::Odometry::ConstPtr& msgIn)
{
    nav_msgs::Odometry data = *msgIn;
    static int flag=1;
    static double stamp_init;
    if(flag==1){
        stamp_init = data.header.stamp.toSec();
        flag=0;
    }
    lieo_file << fixed << data.header.stamp.toSec()-stamp_init   << " "   << data.pose.pose.position.x    << " " << data.pose.pose.position.y << " " 
              << data.pose.pose.position.z    << " "   << data.pose.pose.orientation.x << " " << data.pose.pose.orientation.y << " " 
              << data.pose.pose.orientation.z << " " << data.pose.pose.orientation.w   << std::endl;
}

void liosam_handler(const nav_msgs::Odometry::ConstPtr& msgIn)
{
    nav_msgs::Odometry data = *msgIn;
    static int flag=1;
    static double stamp_init;
    if(flag==1){
        stamp_init = data.header.stamp.toSec();
        flag=0;
    }
    liosam_file << fixed << data.header.stamp.toSec()-stamp_init   << " "   << data.pose.pose.position.x    << " " << data.pose.pose.position.y << " " 
                << data.pose.pose.position.z    << " "   << data.pose.pose.orientation.x << " " << data.pose.pose.orientation.y << " " 
                << data.pose.pose.orientation.z << " " << data.pose.pose.orientation.w   << std::endl;
}

void aloam_handler(const nav_msgs::Odometry::ConstPtr& msgIn)
{
    nav_msgs::Odometry data = *msgIn;
    static int flag=1;
    static double stamp_init;
    if(flag==1){
        stamp_init = data.header.stamp.toSec();
        flag=0;
    }
    aloam_file << fixed << data.header.stamp.toSec()-stamp_init   << " "   << data.pose.pose.position.x    << " " << data.pose.pose.position.y << " " 
            << data.pose.pose.position.z    << " "   << data.pose.pose.orientation.x << " " << data.pose.pose.orientation.y << " " 
            << data.pose.pose.orientation.z << " " << data.pose.pose.orientation.w   << std::endl;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "odom2txt2");
    ros::NodeHandle nh;

    gt_file.open(GT_file, ios::out);
    lieo_file.open(LIEO_file, ios::out);
    liosam_file.open(LIOSAM_file, ios::out);
    aloam_file.open(ALOAM_file, ios::out);

    // ros::TransportHints().tcpNoDelay()?????????????????????????????????
    ros::Subscriber sub_gt = nh.subscribe<nav_msgs::Odometry>("/gazebo_odom", 1000, &gt_handler, ros::TransportHints().tcpNoDelay());
    ros::Subscriber sub_lieo = nh.subscribe<nav_msgs::Odometry>("/fused_odom", 1000, &lieo_handler, ros::TransportHints().tcpNoDelay());
    ros::Subscriber sub_liosam = nh.subscribe<nav_msgs::Odometry>("/lio_sam/odom", 1000, &liosam_handler, ros::TransportHints().tcpNoDelay());
    ros::Subscriber sub_aloam = nh.subscribe<nav_msgs::Odometry>("/laser_odom", 1000, &aloam_handler, ros::TransportHints().tcpNoDelay());

    ROS_INFO("\033[1;32m----> odom2txt start.\033[0m");
    ros::spin();

    return 0;
}
