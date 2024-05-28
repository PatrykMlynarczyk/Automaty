#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
// gitteste
void delay(int iMs){
		int iDelayLoop=1;
		for(iDelayLoop=1; iDelayLoop<2400*iMs; iDelayLoop++){}
	}
	
enum ButtonState buttonstate;
	

enum LedState{STEP_LEFT, STAY, STEP_RIGHT};
enum LedState eLedState = STAY;

int iPressCounter = 1;

		enum ButtonState buttonstate;

		int main(){

			
		LedIint();
		KeyboardInit();
		LedStepRight();
		while(1) // EDYCJA
		{
			buttonstate = eKeyboardRead();
			switch(eLedState){

			case STAY:
				if(buttonstate == BUTTON_0){
					eLedState = STEP_LEFT;
				}
				else if (buttonstate == BUTTON_2) {
					eLedState = STEP_RIGHT;
				}
				else {
					eLedState = STAY;
				}
				break;
				
			case STEP_RIGHT:
				if(buttonstate == BUTTON_1){
					eLedState = STAY;
				}
					else{
						LedStepRight();
						break;
				}
				
				case STEP_LEFT:
				if(buttonstate == BUTTON_1){
					eLedState = STAY;
				}
					else{
						LedStepLeft();
						break;
				}
				
				default:
					break;
				}
		delay(100);
}
}
