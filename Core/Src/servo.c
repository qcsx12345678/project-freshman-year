/*
 * servo.c
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */
#include "main.h"
#include "servo.h"
#include <string.h>

extern TIM_HandleTypeDef htim1;


#include "main.h"

extern TIM_HandleTypeDef htim1;

void Servo_SetAngle(Servo_ID servo, float angle)
{

    if (angle < 0.0f)   angle = 0.0f;
    if (angle > 180.0f) angle = 180.0f;

    uint16_t ccr_value = (uint16_t)(500.0f + (angle / 180.0f) * 2000.0f);

    uint32_t channel;
    switch (servo)
    {
        case LF: channel = TIM_CHANNEL_1; break;
        case RF: channel = TIM_CHANNEL_2; break;
        case LB: channel = TIM_CHANNEL_3; break;
        case RB: channel = TIM_CHANNEL_4; break;
        default: return; // 非法标签，直接返回
    }
    __HAL_TIM_SET_COMPARE(&htim1, channel, ccr_value);
}

void Servo_SetAll(float lf, float rf,
                  float lb, float rb)
{
    Servo_SetAngle(LF, lf);
    Servo_SetAngle(RF, rf);
    Servo_SetAngle(LB, lb);
    Servo_SetAngle(RB, rb);
}
void Servo_Init(void){
	Servo_SetAll(90,90,90,90);
}
