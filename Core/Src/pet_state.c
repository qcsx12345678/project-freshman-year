/*
 * pet_state.c
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */

#include "main.h"
#include "menu.h"
#include "tim.h"
#include "oled_app.h"
#include "pet_state.h"
#include "key.h"
#include "movement.h"
#include <stdio.h>


//我在本模块和主循环里面各写了一百万种方式确保非待机模式下不会改变心情和体力，可能有点石山

PetState_t mood ={.last_tick=0,.number=100,.dirty=1};
PetState_t energy ={.last_tick=0,.number=100,.dirty=1};
#define CHANGE_INTERVAL 10000

void State_Change(PetState_t *type,int delta){
     int newnumber=type->number+delta;
     if (newnumber>100)newnumber=100;
     if(newnumber<0)newnumber=0;
     if(newnumber!=type->number){
    	 type->number=newnumber;
    	 type->dirty=1;
     }
     state = (mood.number == 0)?1:0;
     if(mood.number!=0)state = (energy.number == 0)?2:0;
}


void Mood_Update(void){
	uint32_t now = HAL_GetTick();
	if(standby){
		if(now-mood.last_tick>=CHANGE_INTERVAL){
			mood.last_tick = now;
			State_Change(&mood,-10);
		}
	}
	else{
		mood.last_tick = now;//不是待机状态就不扣心情，只是更新一下时间
	}
}

void Energy_Update(void){
	uint32_t now = HAL_GetTick();
	if(standby){
		if(now-energy.last_tick>=CHANGE_INTERVAL){
			energy.last_tick = now;
			State_Change(&energy,10);
		}
	}
	else{
		energy.last_tick = now;//不是待机状态就不加体力，只是更新一下时间
	}
}
void State_Refresh(void){
	if(mood.dirty+energy.dirty!=0){
		mood.dirty=0;
		energy.dirty=0;
		OLED_NewFrame();
        switch(state){
        case 0:
		OLED_DrawImage(0,0,&EXP_Standby, OLED_COLOR_NORMAL);
		break;
        case 1:
		OLED_DrawImage(0,0,&EXP_Sad, OLED_COLOR_NORMAL);
		break;
        case 2:
        OLED_DrawImage(0,0,&EXP_Tired, OLED_COLOR_NORMAL);
        break;
	}
		OLED_ShowState();
		OLED_ShowFrame();
}
}

void State_Standby(void){
	while(Key_Scan()==0){
			 HAL_Delay(200);
			  standby=1;
			  Mood_Update();
			  Energy_Update();
			  State_Refresh();

		  }
		  standby=0;
}

int IsActionAllowed(int Action_id){
	  if (state == 0) return 1;
	  else if (state == 1){
		  if(Action_id == 1 || (Action_id >= 5 && Action_id <= 7))return 1;
		  else return 0;
	  }
      else return 0;
}



void RunActionSequence(void)
{
    for (int i = 0; i < 4; ++i) {
        int actionId = sequence[i];
        if (!IsActionAllowed(actionId))
            break;

        Action(actionId);
    }
}

void PetState_Task(void){
	if(movement>0 && IsActionAllowed(movement)){
		Action(movement);
	}
	else{
		RunActionSequence();
	}
	 Mood_Update();
	 Energy_Update();
}
