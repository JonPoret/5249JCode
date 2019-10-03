/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\shsstudent                                       */
/*    Created:      Thu Oct 03 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// define your global instances of motors and other devices here
vex::motor RightMotor(PORT1);
vex::motor LeftMotor(PORT2);
vex::controller Controller;

int main() {
    Controller.Axis3.changed([] {
     if (Controller.Axis3.position() > 10)
      {
        RightMotor.spin(vex::directionType::fwd, Controller.Axis3.position(), vex::velocityUnits::pct);
        LeftMotor.spin(vex::directionType::fwd, Controller.Axis3.position(), vex::velocityUnits::pct);
      }
      else if (Controller.Axis3.position() < -10)
      {
        RightMotor.spin(vex::directionType::rev, Controller.Axis3.position(), vex::velocityUnits::pct);
        LeftMotor.spin(vex::directionType::rev, Controller.Axis3.position(), vex::velocityUnits::pct);
      }
  });
    
}
