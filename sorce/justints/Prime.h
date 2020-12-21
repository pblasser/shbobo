#pragma once
#include "stdafx.h"
#include "ging.h"
#include "grax.h"
#include "chub.h"


class Prime {
protected:
	int value; 
	int weight;
	int scale;
	int coss[URPRIMLIM];
	int sinn[URPRIMLIM];
	Prime * tail;

	int chinkwonk;
public:
	Prime(int v, int w, Prime * tel){
		value = v;
		scale = URPRIMLIM/value;
		weight = w;
		tail = tel;
		if (!tel) chinkwonk = 1;
		else chinkwonk = tel->getValue();
		
		for (int i = 0; i < value; i++) {
			sinn[i] =  (double)value * (double)weight * sin( (((double)i) / (double)value) * 3.14159 * 2) / 3; 
			coss[i] =  (double)value * (double)weight * cos( (((double)i) / (double)value) * 3.14159 * 2) / 3; 
			sinn[i] =  (double)value * sin( (((double)i) / (double)value) * 3.14159 * 2) ; 
			coss[i] =  (double)value * cos( (((double)i) / (double)value) * 3.14159 * 2) ; 
		}
	}
	~Prime(){
	
	}
	
	int getValue() { return value; }
	
	int getWeight() { return weight; }
	
	void drawScaled(CHDC chdc, int x, int y, 
					HGRAXPEN tyo, int chink) {
		chink = 1;
		int off = 0;
		GRAXPENSET(chdc,tyo)
		GRAXPENMOV(chdc,x+sinn[0]*scale, y+coss[0]*scale)
		for (int i = 0; i < value; i++) {
			off += chink;
			off %= value;
			GRAXPENLIN(chdc,x+sinn[off]*scale,y+coss[off]*scale)
		} GRAXPENEND(chdc)
	}
	
	void draw(CHDC chdc, int x, int y, HGRAXPEN tyo, int chink) {
		int off = 0;
		GRAXPENSET(chdc,tyo)
		GRAXPENMOV(chdc,x+(sinn[off]), y+(coss[off]))
		for (int i = 0; i < value; i++) {
			off += chink;
			off %=  value;
			GRAXPENLIN(chdc, x+(sinn[off]), y+(coss[off]))
		} GRAXPENEND(chdc)
	}
	
	void drawHolographically(CHDC chdc, int x, 
							 int y, HGRAXPEN * tyo, int sz, int chink) {
		int off = 0;
		GRAXPENMOV(chdc,x+sinn[0], y+coss[0])
		for (int i = 0; i < value; i++) {
			off += chink;
			off %=  value;
			GRAXPENSET(chdc,(tyo[off%sz]))
			GRAXPENLIN(chdc,x+sinn[off],y+coss[off])
		}  GRAXPENEND(chdc)
	}
	
	
	
	Prime * next() { return tail; }
	
};


