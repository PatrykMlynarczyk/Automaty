#include <LPC21xx.H>
#include "led.h"

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

void LedOn(unsigned char ucLedIndeks){	
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	switch (ucLedIndeks){
	case 0:
		IO1SET = LED0_bm;
		break;
	case 1:
		IO1SET = LED1_bm;
		break;
	case 2:
		IO1SET = LED2_bm;
		break;
	case 3:
		IO1SET = LED3_bm;
		break;
}
}

enum Direction{
	Right, Left
};

 void LedStep(enum Direction direction){
		static unsigned int uiLedPoint = 1;
    if (direction == Left) {
       uiLedPoint = uiLedPoint - 1;
    } 
		else {
       uiLedPoint = uiLedPoint + 1;
    }
		LedOn(uiLedPoint%4);
}

void LedIint(){
	IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm; // Piny wyjsciowe ustawiamy na 1
}
void LedStepRight(){
			LedStep(Right);
}

void LedStepLeft(){
			LedStep(Left);
}