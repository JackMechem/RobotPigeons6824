// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>

#include <frc/drive/DifferentialDrive.h>

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include <frc/Spark.h>

#include <frc/VictorSP.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  int controllerUsbIndex = 0;

  frc::XboxController xbox{controllerUsbIndex};

  bool leftbump = false;
  bool rightbump = false;
  bool bA = false;
  bool bB = false;
  bool bX = false;
  bool bY = false;

  double left_x = 0.0;
  double left_y = 0.0;
  double right_x = 0.0;
  double right_y = 0.0;

  frc::Spark m_left{1};
  frc::Spark m_right{2};
  frc::DifferentialDrive m_drive{m_left, m_right};

};
