/*
 * menu.c
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */


#include "menu.h"
#include "key.h"
#include "oled_app.h"
#include "main.h"

extern int movement;
extern int sequence[4];

int menu2;

int Menu1(void){
	int flag=1,last_flag=0,key;
	OLED_NewFrame();
	OLED_PrintString(12, 0, "动作", &font12x12, OLED_COLOR_NORMAL);
	OLED_PrintString(12, 12, "预设序列", &font12x12, OLED_COLOR_NORMAL);
	OLED_ShowFrame();


	while(1){
		key=Key_Scan();
		switch(key){
		case 1:
			flag++;
			if(flag==3)flag=1;
			break;
		case 2:
			OLED_NewFrame();
			return flag;
		}
		if(flag==last_flag)continue;   // 标记没变就不刷屏
		last_flag=flag;
		switch(flag){
		case 1:
			OLED_PrintString(0, 0, "*", &font12x12, OLED_COLOR_NORMAL);
			OLED_PrintString(0, 12, " ", &font12x12, OLED_COLOR_NORMAL);
			OLED_ShowFrame();
			break;
		case 2:
			OLED_PrintString(0, 0, " ", &font12x12, OLED_COLOR_NORMAL);
		    OLED_PrintString(0, 12, "*", &font12x12, OLED_COLOR_NORMAL);
		    OLED_ShowFrame();
		    break;
		}
	}
}

int Menu2_Movement(){
	int flag=1,key,last_flag=0;
	OLED_NewFrame();
	OLED_PrintString(12, 0, "打招呼", &font12x12, OLED_COLOR_NORMAL);
	OLED_PrintString(12, 12, "前进", &font12x12, OLED_COLOR_NORMAL);
	OLED_PrintString(12, 24, "左转", &font12x12, OLED_COLOR_NORMAL);
	OLED_PrintString(12, 36, "右转", &font12x12, OLED_COLOR_NORMAL);
	OLED_PrintString(12, 48, "坐下", &font12x12, OLED_COLOR_NORMAL);
	OLED_PrintString(60, 0, "趴下", &font12x12, OLED_COLOR_NORMAL);
	OLED_PrintString(60,12, "伸懒腰", &font12x12, OLED_COLOR_NORMAL);
	OLED_ShowFrame();
	while(1){
		key=Key_Scan();
	if(key==1){
		flag++;
		if(flag==8)flag=1;
	}
	if(key==2)return flag;
	if(key==3){
		OLED_NewFrame();
		return 8;
	}
	if(flag==last_flag)continue;   // 标记没变就不刷屏
	last_flag=flag;

	switch(flag){
			case 1:
				OLED_PrintString(0, 0, "*", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 24, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 36, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 48, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 0 , " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48,12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_ShowFrame();
				break;
			case 2:
				OLED_PrintString(0, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 12, "*", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 24, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 36, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 48, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_ShowFrame();
			    break;
			case 3:
				OLED_PrintString(0, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 24, "*", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 36, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 48, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_ShowFrame();
				break;
			case 4:
				OLED_PrintString(0, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 24, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 36, "*", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 48, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_ShowFrame();
				break;
			case 5:
				OLED_PrintString(0, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 24, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 36, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 48, "*", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_ShowFrame();
			    break;
			case 6:
				OLED_PrintString(0, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 24, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 36, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 48, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 0, "*", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_ShowFrame();
				break;
			case 7:
				OLED_PrintString(0, 0, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 12, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 24, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 36, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(0, 48, " ", &font12x12, OLED_COLOR_NORMAL);
				OLED_PrintString(48, 0, " ", &font12x12, OLED_COLOR_NORMAL);
			    OLED_PrintString(48, 12, "*", &font12x12, OLED_COLOR_NORMAL);
			    OLED_ShowFrame();
				break;
     }
  }
}

void Menu2_Preset(){
	int cnt=0;
	while(cnt<4){
		sequence[cnt]=Menu2_Movement();
		if(sequence[cnt]==8){
			sequence[cnt]=0;
			break;
		}
		cnt++;
	}
}

void Menu_Task(){
	while(movement+sequence[3]==0){
		menu2=Menu1();
		if(menu2==1)movement=Menu2_Movement();
		if(menu2==2)Menu2_Preset();

	}
}
