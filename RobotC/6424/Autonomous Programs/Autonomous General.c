#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     infrared,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     weight,         sensorHiTechnicTouchMux)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  motorA,          motor_A,       tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          motor_B,       tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          motor_C,       tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor_L,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motor_R,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motor_lift,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motor_G,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    servo_IR,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo_claw,           tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    servo_ramp,           tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
// Code generated by the 'ROBOTC' configuration wizard.
#include "JoystickDriver.c"
#include "hitechnic-irseeker-v2.h"
#include "typedefs.h"
#include "global vars.h"
#include "enums.h"
#include "structs.h"
#include "low-level functions.h"
#include "high-level functions.h"
#include "subroutines.h"



void initializeRobot()
{
	// Place code here to init servos to starting positions.
	// Sensors are config'ed and setup by RobotC (need to stabalize).
	// Also add any settings that need to be set (other than global
	// variables), such as max PID speed, servo update rate, etc.

	Servo_Rotate(servo_IR, g_IRServoExtended);		// fold back up after start of tele-op
	Servo_Rotate(servo_claw, g_clawServoExtended);	// keep it straight out after tele-op

	Servo_SetSpeed(servo_IR, 0);	// maximum speed!
	Servo_SetSpeed(servo_claw, 0);	// maximum speed!


	Motor_SetMaxSpeed(g_FullMotorPower);

	Motor_ResetEncoder(motor_L);
	Motor_ResetEncoder(motor_R);
	Motor_ResetEncoder(motor_lift);

	nMotorEncoder[motor_lift] = 0;

	return;
}



task main()
{
	initializeRobot();

	// These will be used later and are declared here to save from having to
	// declare them every single loop.
	int powerL = 0;
	int powerR = 0;
	int powerLift = 0;

	waitForStart();

	Move_Forward(70, 100);
	Turn_Left(50, 100, 100);
	Move_Forward(100, 80);
	Turn_Right(130, 100, 100);
	Move_Forward(30, 100);

	while (true)
	{
		;
	}
}
