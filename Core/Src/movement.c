/*
 * movement.c
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */
#include <stdint.h>
#include "servo.h"
#include "pet_state.h"
#include "main.h"
#include "movement.h"
#include "oled_app.h"
// 记录四个舵机当前角度（顺序：lf, rf, lb, rb）
static uint8_t cur_angle[4] = {90, 90, 90, 90};   // 上电默认90
volatile int moving=0;

static void Pose(uint8_t lf, uint8_t rf, uint8_t lb, uint8_t rb, uint32_t delay_ms)
{
    Servo_SetAll(lf, rf, lb, rb);
    cur_angle[0] = lf;
    cur_angle[1] = rf;
    cur_angle[2] = lb;
    cur_angle[3] = rb;
    HAL_Delay(delay_ms);
}


#define SMOOTH_STEPS    30    // 每个动作分成30份
#define SMOOTH_STEP_MS  5     // 每份延迟5ms

static void Pose_Smooth(uint8_t lf, uint8_t rf, uint8_t lb, uint8_t rb)
{
    uint8_t start[4];
    start[0] = cur_angle[0];
    start[1] = cur_angle[1];
    start[2] = cur_angle[2];
    start[3] = cur_angle[3];

    uint8_t target[4] = {lf, rf, lb, rb};

    for (uint16_t s = 1; s <= SMOOTH_STEPS; s++)
    {
        uint8_t a = start[0] + ((int32_t)(target[0] - start[0]) * s) / SMOOTH_STEPS;
        uint8_t b = start[1] + ((int32_t)(target[1] - start[1]) * s) / SMOOTH_STEPS;
        uint8_t c = start[2] + ((int32_t)(target[2] - start[2]) * s) / SMOOTH_STEPS;
        uint8_t d = start[3] + ((int32_t)(target[3] - start[3]) * s) / SMOOTH_STEPS;

        Pose(a, b, c, d, SMOOTH_STEP_MS);
    }

    // 为保证最终真的能到位再来一下
    Pose(lf, rf, lb, rb, 0);

}

void Movement_Move_Forward(void){
	moving=1;
	for(int i=0;i<5;i++){
	    Pose_Smooth(90,130,50,90);
		Pose_Smooth(130,130,50,50);
		Pose_Smooth(130,90,90,50);
		Pose_Smooth(90,90,90,90);
		Pose_Smooth(50,90,90,130);
		Pose_Smooth(50,50,130,130);
		Pose_Smooth(90,50,130,90);
		Pose_Smooth(90,90,90,90);
	}
	moving=0;
}

void Movement_Turn_Left(void){
	moving=1;
	for(int i=0;i<10;i++){
	moving=1;
	Pose_Smooth(130,90,90,130);
	Pose_Smooth(130,50,130,50);
	Pose_Smooth(90,50,50,90);
	Pose_Smooth(90,90,90,90);
	}
	moving=0;
}

void Movement_Turn_Right(void){
	moving=1;
	for(int i=0;i<10;i++){
	Pose_Smooth(90,50,50,90);
	Pose_Smooth(130,50,130,50);
	Pose_Smooth(130,90,90,130);
	Pose_Smooth(90,90,90,90);
	}
	moving=0;
}

void Movement_Hello(void){
	moving=1;
	Pose_Smooth(90,130,90,90);
	HAL_Delay(200);
	Pose_Smooth(90,90,90,90);
	HAL_Delay(200);
	Pose_Smooth(90,130,90,90);
	HAL_Delay(200);
	Pose_Smooth(90,90,90,90);
	moving=0;
}

void Movement_Sit_Down(void){
	moving=1;
	Pose_Smooth(90,90,30,150);
	HAL_Delay(1000);
	Pose_Smooth(90,90,90,90);
	moving=0;
}

void Movement_Lie_Down(void){
	moving=1;
	Pose_Smooth(30,150,150,30);
	HAL_Delay(1000);
	Pose_Smooth(90,90,90,90);
	moving=0;
}

void Movement_Stretch(void){
	moving=1;
	Pose_Smooth(0,180,90,90);
	HAL_Delay(1000);
	Pose_Smooth(90,90,90,90);
	moving=0;
}


void Action(int Movement_id){
	OLED_NewFrame();
	switch(Movement_id){
	case 1:
			OLED_DrawImage(0,0,&EXP_Hello, OLED_COLOR_NORMAL);
			OLED_ShowFrame();
			Movement_Hello();
		    State_Change(&mood,20);
		    State_Change(&energy,-10);
			break;
	case 2:
	    	OLED_DrawImage(0,0,&EXP_Move_Forward, OLED_COLOR_NORMAL);
		    OLED_ShowFrame();
		    Movement_Move_Forward();
		    State_Change(&mood,20);
		    State_Change(&energy,-10);
		    break;
	case 3:
			OLED_DrawImage(0,0,&EXP_Turn_Left, OLED_COLOR_NORMAL);
			OLED_ShowFrame();
			Movement_Turn_Left();
		    State_Change(&mood,20);
		    State_Change(&energy,-10);
			break;

	case 4:
			OLED_DrawImage(0,0,&EXP_Turn_Right, OLED_COLOR_NORMAL);
			OLED_ShowFrame();
			Movement_Turn_Right();
		    State_Change(&mood,20);
		    State_Change(&energy,-10);
			break;

	case 5:
			OLED_DrawImage(0,0,&EXP_Sit_Down, OLED_COLOR_NORMAL);
			OLED_ShowFrame();
			Movement_Sit_Down();
		    State_Change(&mood,20);
		    State_Change(&energy,-10);
			break;
	case 6:
			OLED_DrawImage(0,0,&EXP_Lie_Down, OLED_COLOR_NORMAL);
			OLED_ShowFrame();
			Movement_Lie_Down();
		    State_Change(&mood,20);
		    State_Change(&energy,-10);
			break;
	case 7:
			OLED_DrawImage(0,0,&EXP_Stretch, OLED_COLOR_NORMAL);
			OLED_ShowFrame();
			Movement_Stretch();
		    State_Change(&mood,20);
		    State_Change(&energy,-10);
			break;
	default:
		break;
	}
}
