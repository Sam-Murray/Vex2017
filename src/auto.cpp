/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */
#include "main.h"
#include "DriveTrain.h"
#include "Robot.h"
/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

void autonomous() {
  // int Cpin=8;
  // int DRpin=2;
  // int DLpin=3;
  // int LRpin=4;
  // int LLpin=5;
  // int SLpin=6;
  // int Ipin=7;
  // Robot robot= Robot(DRpin, DLpin,LRpin,LLpin,Cpin,Ipin,SLpin, 1);
  // int upTime=1500;
  // int downTime=1000;
  // int driveTime=2500;
  // int backtime=1000;
  // int t=0;
  // while(t<15000000){
  //
  //   if(t<upTime){
  //       robot.SpecialUpdate(0,0,1, 0, 1, 0, 0,0, 1, 0, 0);
  //   }else if(t<(upTime+driveTime)){
  //         robot.SpecialUpdate(127, 127,0,0, 0, 0, 0,0, 1, 0, 0);
  //   }else if(t<(upTime+driveTime+downTime)){
  //     robot.SpecialUpdate(0, 0,0,1, 0, 1, 0,0, 1, 0, 0);
  //   }else if(t<(upTime+driveTime+downTime+backtime)){
  //     robot.SpecialUpdate(-127, -127,0,0, 0, 0, 0, 0, 0, 0, 0);
  //   }else{
  //     robot.SpecialUpdate(0, 0,0,0, 0, 0, 0, 0, 0, 0, 0);
  //   }
  //   delay(1);
  //   t++;
  // }

}
  // upSecond(robot,upTime);
  // driveForward(robot,driveTime);
  // downSecond(robot,downTime);
