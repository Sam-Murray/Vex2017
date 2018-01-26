/**
 * File for operator control code.
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of Purdue University ACM SIG BOTS nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 ********************************************************************************/

#include "main.h"


/**
 * Runs the user operator control code.
 *
 * This function will be started in its own task with the default priority and stack size whenever the robot is enabled via the Field Management System or the VEX Competition Switch in the operator control mode. If the robot is disabled or communications is lost, the operator control task will be stopped by the kernel. Re-enabling the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will run the operator control task. Be warned that this will also occur if the VEX Cortex is tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
 // {
 // 		delay(200);
 //     //!digitalRead(3)
 // 		if(connected)
 // 		{
 //       digitalWrite(9,true);
 // 			//motor1.setSpeed(50);
 //       delay(400);
 //       digitalWrite(9,false);
 // 			//motor1.setSpeed(50);
 //       delay(100);
 //       digitalWrite(9,true);
 //       delay(400);
 // 		}
 //
 //     //motor1.setSpeed(0);
 //     digitalWrite(9,false);

   // if(connected){
   //   digitalWrite(9,true);
   // }
   // else
   // {
   //   digitalWrite(9,false);
   // }
   //digitalWrite(9,false);
 #include "Robot.h"
# include "API.h"


void operatorControl()
{
  while (1){

      // if(left>50){
      //   motorSet(2, 127);
      //   motorSet(3, 127);
      // }else if(left< -50){
      //   motorSet(2, -127);
      //   motorSet(3, -127);
      // }else{
      //   motorSet(2, 0);
      //   motorSet(3, 0);
      // }
      // if(right>50){
      //   motorSet(1, 127);
      //   motorSet(4, 127);
      // }else if(right< -50){
      //   motorSet(1, -127);
      //   motorSet(4, -127);
      // }else{
      //   motorSet(1, 0);
      //   motorSet(4, 0);
      // }
      //I1

      DriveTrain drive1=DriveTrain(3,4,1);
      drive1.Update(joystickGetAnalog(1, 3), joystickGetAnalog(1, 2));


      // motorSet(2, left) ; // set left wheels in motion
      // motorSet(3, left);
      //
      //
      // motorSet(1, right); // set right wheels in motion
      // motorSet(4, right);


       int rightTriggerUpPressed = joystickGetDigital(1, 6, JOY_UP); // get state of right trigger top
       int leftTriggerDownPressed = joystickGetDigital(1, 6, JOY_DOWN); // get state of left trigger top

       if (rightTriggerUpPressed){

         motorSet(5, 50); // set arm system in upward motion
         motorSet(6, -50);

       }else if(leftTriggerDownPressed){

         motorSet(5, -50); // set arm system in downward motion
         motorSet(6, 50);

       }else{

         motorSet(5, 0); // stop moving
         motorSet(6,0);

       }
     }
}
