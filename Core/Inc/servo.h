/*
 * servo.h
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_


typedef enum
{
    LF = 1,   // 左前
    RF = 2,   // 右前
    LB = 3,   // 左后
    RB = 4    // 右后
} Servo_ID;



void Servo_SetAngle(Servo_ID servo, float angle);
void Servo_SetAll(float lf, float rf,
                  float lb, float rb);
void Servo_Init(void);

#endif /* INC_SERVO_H_ */
