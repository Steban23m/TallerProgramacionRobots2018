#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include <stdio.h>
#include <sstream>

#include "geometry_msgs/Twist.h"			//for command velocity
#include "geometry_msgs/Vector3.h"			//for command velocity

#include "ardrone_autonomy/Navdata.h"

/**
* This tutorial demonstrates simple sending of messages over the ROS system.
*/

/*Mensajes*/
std_msgs::Empty emp_msg;
geometry_msgs::Twist vel_msg;			// variable in the command velocity class

// Variables for Publishing
ros::Publisher T_pub_empty;				//take off publisher
ros::Publisher L_pub_empty;				//landing publisher
ros::Publisher velocity_publisher;		// velocity publisher

ros::Subscriber pose_subscriber;		// ardrone navdata subsciber


/*Variables a utilizar*/

float lx, ly, lz, ax, ay, az,foc = 685, angx,angy,angz, est_x, est_y, est_z,K_est_x, K_est_y, K_est_z,test_x,test_y,test_z;
const double PI = 3.14159265359;
const double degree90 = 1.570796327;


ardrone_autonomy::Navdata drone_navdata;  	// Using this class variable for storing navdata

void move(float lx, float ly, float lz, float ax, float ay, float az ); // publishing command velocity
void hover(int timee);		// hovering
void takeoff(ros::Publisher takeoff_pub);
void land();
void moveDron(float lx, float ly, float lz, float ax, float ay, float az, ros::Rate loop_rate);
void rotateDron(float ax, float ay, float az, ros::Rate loop_rate);

void rotateDron360(bool clockwise, ros::Rate loop_rate);
void rotateDron180(bool clockwise, ros::Rate loop_rate);
void rotateDronAngle(bool clockwise, float angle, ros::Rate loop_rate);

void poseCallback(const ardrone_autonomy::Navdata::ConstPtr & pose_message);		// drone actual data

float convertirAngulos(float ang);
float distanciaEntreDosAngulos(float ang1, float ang2);

int main(int argc, char **argv){
  ros::init(argc, argv, "takeoff");


  ros::NodeHandle n;

  ros::Publisher takeoff_pub = n.advertise<std_msgs::Empty>("/ardrone/takeoff", 1);
  L_pub_empty = n.advertise<std_msgs::Empty>("/ardrone/land", 1); //initialize to send the land command /* Message queue length is just 1 */
  velocity_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 100); // initialize to send the Control Input

  ros::Rate loop_rate(10);

  // Subscribing the data
  pose_subscriber = n.subscribe("/ardrone/navdata", 200, poseCallback);	//initialize to receive processed sensor data


  int count = 0;


  while (ros::ok()) {

    ROS_INFO("Calling take off");
    ROS_INFO("Altitude %d (cm)", drone_navdata.altd);
    ros::Rate loop_rate(10);
    //Probar sleep
    loop_rate.sleep();

    /**Take Off **/
    ros::Time start = ros::Time::now();
    while(ros::Time::now() - start < ros::Duration(5.0)){
      double init_time=ros::Time::now().toSec();  // epoch time
      ROS_INFO("NavData Status %d", drone_navdata.state);
      //ROS_INFO("Time Loop");
      takeoff_pub.publish(emp_msg); /* launches the drone */
      ROS_INFO("Published");
      ros::spinOnce(); // feedback
      loop_rate.sleep();
      if(drone_navdata.state == 3){
        ROS_INFO("Ardrone Taking off");
        ROS_INFO("Altitude %d (cm)", drone_navdata.altd);
        break;
      }

    }

    //hover(2);
    moveDron(0,0,1,0,0,0,loop_rate);
    ROS_INFO("Altitude %d (cm)", drone_navdata.altd);

    moveDron(1,0,0,0,0,0,loop_rate);
    rotateDron180(false,loop_rate);
    moveDron(1,0,0,0,0,0,loop_rate);
    moveDron(1,0,0,0,0,0,loop_rate);
    rotateDron180(true,loop_rate);
    moveDron(1,0,0,0,0,0,loop_rate);
    rotateDronAngle(true,90,loop_rate);
    moveDron(1,0,0,0,0,0,loop_rate);
    rotateDron180(false,loop_rate);
    moveDron(2,0,0,0,0,0,loop_rate);
    rotateDron180(true,loop_rate);
    moveDron(1,0,0,0,0,0,loop_rate);
    rotateDronAngle(false,90,loop_rate);
    hover(2);
    moveDron(0,0,-1,0,0,0,loop_rate);
    ROS_INFO("Altitude %d (cm)", drone_navdata.altd);
    land();
    break;

  }



  return 0;
}


void move(float lx, float ly, float lz, float ax, float ay, float az )
{

  //defining the linear velocity
  vel_msg.linear.x = lx;
  vel_msg.linear.y = ly;
  vel_msg.linear.z = lz;

  //defining the linear velocity
  vel_msg.angular.x = ax;
  vel_msg.angular.y = ay;
  vel_msg.angular.z = az;

  velocity_publisher.publish(vel_msg);

}


void hover(int timee){

  double t0 = ros::Time::now().toSec(); //ros has a 'Time' function in which the current time can be found by using 'now'.                                         							we need time in sec to compute hence 'tosec'
  double t1;
  ros::Rate loop_rate(200);
  do{

    t1 = ros::Time::now().toSec(); //ros has a 'Time' function in which the current time can be found by using 'now'.                                         							we need time in sec to compute hence 'tosec'

    vel_msg.linear.x = 0;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;

    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = 0;

    velocity_publisher.publish(vel_msg);

    ros::spinOnce(); //if this function is not mentioned the function will stay in the buffer and cannot be able to publish
    loop_rate.sleep();

  }while(t1 <= (t0+timee));

  //ros::spinOnce();
}

void land()
{
  ROS_INFO("Landing");
  ROS_INFO("Altitude %d (cm)", drone_navdata.altd);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    double init_time=ros::Time::now().toSec();
    double time;
    while (time < (init_time+5.0)) /* Send command for five seconds*/
    {
      L_pub_empty.publish(emp_msg); /* lands the drone */
      ros::spinOnce();
      loop_rate.sleep();
      time = ros::Time::now().toSec();
    }//time loop
    ROS_INFO("Ardrone landed");
    exit(0);
  }//ros::ok loop

}

void takeoff(ros::Publisher T_pub_empty)
{
  ROS_INFO("Calling take off");
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    double init_time=ros::Time::now().toSec();  // epoch time
    double time;
    while (time < (init_time+5.0)) /* Send command for five seconds*/
    {
      ROS_INFO("Time Loop");
      T_pub_empty.publish(emp_msg); /* launches the drone */
      ROS_INFO("Published");
      ros::spinOnce(); // feedback
      loop_rate.sleep();
      time = ros::Time::now().toSec();
    }//time loop
    ROS_INFO("ARdrone launched");
    exit(0);
  }//ros::ok loop
  hover(2);

}


void moveDron(float lx, float ly, float lz, float ax, float ay, float az, ros::Rate loop_rate){
  ros::Time start_move = ros::Time::now();
  int countdown =0;

  while(ros::Time::now() - start_move < ros::Duration(4.0))
  {
    //ROS_INFO("Move Dron %d", countdown);
    move(lx,ly,lz,ax,ay,az);
    ros::spinOnce();
    loop_rate.sleep();
    countdown++;
  }
  hover(1);

}

void rotateDron360(bool clockwise, ros::Rate loop_rate){

  float initialZrot =drone_navdata.rotZ;
  int direction;
  if (clockwise) {
    direction=-1;
  }
  else{
    direction=1;
  }

  //Avanzar 180 dos veces

  float finalZRotation = convertirAngulos(initialZrot + 180);


  ROS_INFO("Rotate Dron");
  ROS_INFO("Z rotation Initial : %f", initialZrot);
  ROS_INFO("Z rotation Destination : %f", finalZRotation);

  float prevZvalue = initialZrot;

  do
  {
    ROS_INFO("Z rotation : %f", drone_navdata.rotZ);
    move(0,0,0,0,0,direction*0.3);
    ros::spinOnce();
    loop_rate.sleep();

    float distanceFromAngle = distanciaEntreDosAngulos(finalZRotation,drone_navdata.rotZ);
    ROS_INFO("Distancia entre %f y %f   : %f", drone_navdata.rotZ, finalZRotation,distanceFromAngle);
    if(distanceFromAngle <= 1){
      ROS_INFO("Rotation 180 Accomplished : %f", drone_navdata.rotZ);
      //ROS_INFO("DIfference rotation : %f", degreeDiference);
      break;
    }

  }while(true);
hover(1);
  finalZRotation = initialZrot;
  do
  {
    ROS_INFO("Z rotation : %f", drone_navdata.rotZ);
    move(0,0,0,0,0,direction);
    ros::spinOnce();
    loop_rate.sleep();

    float distanceFromAngle = distanciaEntreDosAngulos(finalZRotation,drone_navdata.rotZ);
    ROS_INFO("Distancia entre %f y %f   : %f", drone_navdata.rotZ, finalZRotation,distanceFromAngle);
    if(distanceFromAngle <= 1){
      ROS_INFO("Rotation 180 Accomplished : %f", drone_navdata.rotZ);
      //ROS_INFO("DIfference rotation : %f", degreeDiference);
      break;
    }

  }while(true);
hover(1);
  ROS_INFO("Rotate 360 finished");
}

void rotateDron180(bool clockwise, ros::Rate loop_rate){

  float initialZrot =drone_navdata.rotZ;
  int direction;
  if (clockwise) {
    direction=-1;
  }
  else{
    direction=1;
  }
  //Avanzar 180 dos veces

  float finalZRotation = convertirAngulos(initialZrot + 180*direction);
  ROS_INFO("Rotate Dron");
  ROS_INFO("Z rotation Initial : %f", initialZrot);
  ROS_INFO("Z rotation Destination : %f", finalZRotation);
  float prevZvalue = initialZrot;

  do{
    ROS_INFO("Z rotation : %f", drone_navdata.rotZ);
    move(0,0,0,0,0,direction*0.5);
    ros::spinOnce();
    loop_rate.sleep();
    float distanceFromAngle = distanciaEntreDosAngulos(finalZRotation,drone_navdata.rotZ);
    ROS_INFO("Distancia entre %f y %f   : %f", drone_navdata.rotZ, finalZRotation,distanceFromAngle);
    if(distanceFromAngle <= 1){
      ROS_INFO("Rotation 180 Accomplished : %f", drone_navdata.rotZ);
      //ROS_INFO("DIfference rotation : %f", degreeDiference);
      break;
    }
  }while(true);
  hover(1);

}

void rotateDronAngle(bool clockwise, float angle, ros::Rate loop_rate){

  float initialZrot = drone_navdata.rotZ;
  int direction;
  if (clockwise) {
    direction=-1;
  }
  else{
    direction=1;
  }
  //Avanzar 180 dos veces

  float finalZRotation = convertirAngulos(initialZrot + angle*direction);
  ROS_INFO("Rotate Dron");

  ROS_INFO("Z rotation Initial : %f", initialZrot);
  ROS_INFO("Z rotation Destination : %f", finalZRotation);
  float currentAngle = initialZrot;
  float speed=0.1;
  float angular_speed = speed*2*PI/360;
  float currentAngleRadians = initialZrot*2*PI/360;
  float relative_angleradians = finalZRotation*2*PI/360;

  //ROS_INFO("Distancia entre angulos: %f", distanciaEntreDosAngulosRadianes(currentAngle,relative_angle));

  double t0 = ros::Time::now().toSec();
  double t1;



    do{
      ROS_INFO("Z rotation : %f", drone_navdata.rotZ);
      move(0,0,0,0,0,direction*speed);
      ros::spinOnce();
      loop_rate.sleep();
      //move(0,0,0,0,0,0);
      //ros::spinOnce();
      //loop_rate.sleep();
      float distanceFromAngle = distanciaEntreDosAngulos(finalZRotation,drone_navdata.rotZ);
      ROS_INFO("Distancia entre %f y %f   : %f", drone_navdata.rotZ, finalZRotation,distanceFromAngle);
      if(distanceFromAngle <= 3){
        ROS_INFO("Rotation %f Accomplished : %f",convertirAngulos(angle), drone_navdata.rotZ);
        //ROS_INFO("DIfference rotation : %f", degreeDiference);
        break;
      }
    }while(true);





  hover(1);

}


void rotateDron(float ax, float ay, float az, ros::Rate loop_rate){
  ros::Time start_move = ros::Time::now();
  int countdown =0;
  float initialZrot =drone_navdata.rotZ;

  float finalZRotation;

  if(initialZrot + 90 > 180){
    finalZRotation = initialZrot + 90 -360;
  }
  else{
    finalZRotation = initialZrot + 90;
  }
  /*  if(initialZrot < 0){
  initialZrot = initialZrot + 360;
}*/



ROS_INFO("Rotate Dron");
ROS_INFO("Z rotation Initial : %f", initialZrot);
ROS_INFO("Z rotation Destination : %f", finalZRotation);

float prevZvalue = initialZrot;

while(true)
{
  ROS_INFO("Z rotation : %f", drone_navdata.rotZ);
  move(0,0,0,ax,ay,az);
  ros::spinOnce();
  loop_rate.sleep();
  countdown++;


  float distanceFromAngle = distanciaEntreDosAngulos(finalZRotation,drone_navdata.rotZ);
  ROS_INFO("Distancia entre %f y %f   : %f", drone_navdata.rotZ, finalZRotation,distanceFromAngle);
  if(distanceFromAngle <= 2){
    ROS_INFO("Rotation Accomplished : %f", drone_navdata.rotZ);
    ROS_INFO("Rotated  90  : %f", drone_navdata.rotZ);
    float degreeDiference = distanceFromAngle;


    ROS_INFO("DIfference rotation : %f", degreeDiference);
    /*      do{
    ROS_INFO("Adjusting Rotation : %f", drone_navdata.rotZ);
    ROS_INFO("Desired value : %f", initialZrot+90);
    move(0,0,0,ax,ay,-0.1);
    ros::spinOnce();
    loop_rate.sleep();

  }while (equality(initialZrot+90,drone_navdata.rotZ,0.5));
  */
  ROS_INFO("Rotated 90  : %f", drone_navdata.rotZ);
  ros::spinOnce();
  loop_rate.sleep();
  break;
}
}

}

void poseCallback(const ardrone_autonomy::Navdata::ConstPtr & pose_message )
{
  //  ROS_INFO("POS CallBack");
  drone_navdata.vx	= 	pose_message->vx;
  drone_navdata.vy 	= 	pose_message->vy;
  drone_navdata.vz 	= 	pose_message->vz;
  drone_navdata.ax	= 	pose_message->ax;
  drone_navdata.ay 	= 	pose_message->ay;
  drone_navdata.az 	= 	pose_message->az;
  drone_navdata.rotX	= 	pose_message->rotX;
  drone_navdata.rotY	= 	pose_message->rotY;
  drone_navdata.rotZ	= 	pose_message->rotZ;
  drone_navdata.magX	= 	pose_message->magX;
  drone_navdata.magY	= 	pose_message->magY;
  drone_navdata.magZ	= 	pose_message->magZ;
  drone_navdata.altd 	= 	pose_message->altd;
  drone_navdata.tm	= 	pose_message->tm;
  drone_navdata.header	= 	pose_message->header;
  drone_navdata.state	= 	pose_message->state;

  drone_navdata.batteryPercent= pose_message->batteryPercent;
}


/*Circuito*/
/*
moveDron(1,0,0,0,0,0,loop_rate);
//  moveDron(1,0,0,0,0,0,loop_rate);
//  moveDron(1,0,0,0,0,0,loop_rate);
//moveDron(1,0,0,0,0,0,loop_rate);
moveDron(0,0,0,0,0,0.5,loop_rate);
moveDron(0,1,0,0,0,0,loop_rate);
//moveDron(0,0,1,0,0,0,loop_rate);
//moveDron(0,0,1,0,0,0,loop_rate);
//moveDron(0,0,1,0,0,0,loop_rate);
moveDron(0,0,0,0,0,0.5,loop_rate);
moveDron(-1,0,0,0,0,0,loop_rate);
moveDron(0,0,0,0,0,0.5,loop_rate);
moveDron(1,0,0,0,0,0,loop_rate);
moveDron(0,0,0,0,0,0.5,loop_rate);
//moveDron(0,1,0,0,0,0,loop_rate);
//moveDron(0,1,0,0,0,0,loop_rate);
//moveDron(0,1,0,0,0,0,loop_rate);
moveDron(0,-1,0,0,0,0,loop_rate);

*/

float distanciaEntreDosAngulos(float ang1, float ang2){
  float r;
  r =fmod(abs(ang2 - ang1),360);       // This is either the distance or 360 - distance

  if(r>180){
    return 360 -r;
  }

  else{
    return r;
  }

}

float convertirAngulos(float ang){
  float r;

  r = fmod(ang,360);

  if (r > 180)
  {
    r-= 360;
  }
  return r;

}
