#include "Robot.h"

Robot::Robot()
{
}
Robot::Robot(int DRpin,int DLpin,int LRpin,int LLpin,int LURpin,int LULpin,int Cpin,int Ipin,int SLpin,int speedC){
  driveT=DriveTrain(DRpin, DLpin,speedC);
  liftL=ActuatorArray(LLpin,LULpin);
  liftR=ActuatorArray(LRpin,LURpin);
  intake=Actuator(Ipin);
  claw=Claw(Cpin,50);
  secondaryLift=Actuator(SLpin);

}
void Robot::Update(int joystickSlot)
{

    driveT.Update(joystickGetAnalog(joystickSlot,L_MOVE),joystickGetAnalog(joystickSlot,R_MOVE));
    liftL.Update(joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,5,JOY_DOWN));
    liftR.Update(joystickGetDigital(joystickSlot,6,JOY_DOWN),joystickGetDigital(joystickSlot,6,JOY_UP));
    intake.Update(joystickGetDigital(joystickSlot,7,JOY_DOWN),joystickGetDigital(joystickSlot,7,JOY_UP));
    claw.Update(joystickGetDigital(joystickSlot,8,JOY_RIGHT));
    secondaryLift.Update(joystickGetDigital(joystickSlot,8,JOY_DOWN),joystickGetDigital(joystickSlot,8,JOY_UP));

}
void Robot::Update(int LMOVE,int RMOVE,bool liftUp,bool liftDown,bool intakeUp,bool intakeDown,bool clawToggle,bool secondUp,bool secondDown)
{

    driveT.Update(LMOVE,RMOVE);
    liftL.Update(liftUp,liftDown);
    liftR.Update(liftDown,liftUp);
    intake.Update(intakeDown,intakeUp);
    claw.Update(clawToggle);
    secondaryLift.Update(secondUp,secondDown);
}
void Robot::SpecialUpdate(int LMOVE,int RMOVE,bool liftUp,bool liftDown,bool intakeUp,bool intakeDown,bool clawSet,bool secondUp,bool secondDown)
{

    driveT.Update(LMOVE,RMOVE);
    liftL.Update(liftUp,liftDown);
    liftR.Update(liftDown,liftUp);
    intake.Update(intakeDown,intakeUp);
    claw.clawSet(clawSet);
    secondaryLift.Update(secondUp,secondDown);

}
