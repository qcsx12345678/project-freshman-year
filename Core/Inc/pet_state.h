/*
 * pet_state.h
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */

#ifndef INC_PET_STATE_H_
#define INC_PET_STATE_H_
typedef struct{
	uint32_t last_tick;
	int number;
	uint8_t dirty;
}PetState_t;
extern PetState_t mood;
extern PetState_t energy;
void State_Standby();
void State_Change(PetState_t *type,int delta);
void PetState_Task();
#endif /* INC_PET_STATE_H_ */
