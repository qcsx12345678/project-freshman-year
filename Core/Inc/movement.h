/*
 * movement.h
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */

#ifndef INC_MOVEMENT_H_
#define INC_MOVEMENT_H_

void Movement_Move_Forward(void);
void Movement_Turn_Left(void);
void Movement_Turn_Right(void);
void Movement_Hello(void);
void Movement_Sit_Down(void);
void Movement_Lie_Down(void);
void Movement_Stretch(void);
void Action(int Movement_id);
extern volatile int moving;

#endif /* INC_MOVEMENT_H_ */
