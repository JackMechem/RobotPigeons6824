// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  
  leftbump = xbox.GetBumper(frc::GenericHID::kLeftHand);
  rightbump = xbox.GetBumper(frc::GenericHID::kRightHand);

  bA = xbox.GetAButton();
  bB = xbox.GetBButton();
  bX = xbox.GetXButton();
  bY = xbox.GetYButton();

  left_x = xbox.GetX(frc::GenericHID::kLeftHand);
  left_y = xbox.GetY(frc::GenericHID::kLeftHand);


  right_x = xbox.GetX(frc::GenericHID::kRightHand);
  right_y = xbox.GetY(frc::GenericHID::kRightHand);
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {

  frc::SmartDashboard::PutBoolean("LB : ", leftbump);
  frc::SmartDashboard::PutBoolean("RB : ", rightbump);
  frc::SmartDashboard::PutBoolean("bA : ", bA);
  frc::SmartDashboard::PutBoolean("bB : ", bB);
  frc::SmartDashboard::PutBoolean("bX : ", bX);
  frc::SmartDashboard::PutBoolean("bY : ", bY);

  frc::SmartDashboard::PutNumber("left x : ", left_x);
  frc::SmartDashboard::PutNumber("left y : ", left_y);
  frc::SmartDashboard::PutNumber("right x : ", right_x);
  frc::SmartDashboard::PutNumber("right y : ", right_y);

}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
