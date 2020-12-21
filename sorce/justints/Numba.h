#pragma once
#include "Multaple.h"
#include "stdafx.h"

class Numba {
private:
	int value;
	HGRAXBRUSH mong, twong; 
	HGRAXPEN dong, shong;
	Multaple * multna;
public:
	Numba() {
		unsigned char r[2] = {rand(),rand()};
		unsigned char g[2] = {rand(),rand()};
		unsigned char b[2] = {rand(),rand()};
		mong = GRAXBRUSHWAND(r[0],g[0],b[0]);
		twong = GRAXBRUSHWAND(r[1],g[1],b[1]);
		dong = GRAXPENWAND(r[0],g[0],b[0],1);
		shong = GRAXPENWAND(r[1],g[1],b[1],1);
	}
	~Numba(void){
		GRAXBRUSHNIL(mong);
		GRAXBRUSHNIL(twong);
		GRAXPENNIL(dong);
		GRAXPENNIL(shong);
	}
	HGRAXPEN getDongShard() { return dong; }
	HGRAXPEN getShongShrd() { return shong; }
	void setValue(int v, Multaple * m) {
		value = v;
		multna = m;
	}
	int getValue() { return value; }
	
	void drawNume(CHDC chdc, int x, int y) {
		RECT rrr = {x-value,y-value,x,y};
		FILLRECT(chdc.hdc,mong,rrr)
	}
	void drawNumeRunes(CHDC chdc, int x, int y, int chink) {
		Multaple * m = multna;
		int acc = 0 ;
		while (m) {
			acc += m->draw(chdc,x+acc,y+acc, -1, shong, chink);
			m = m->next();
		}
	}
	void drawDeno(CHDC chdc, int x, int y) {
		RECT rrr = {x,y,x+value,y+value};
		FILLRECT(chdc.hdc,twong,rrr)
	}
	void drawDenoRunes(CHDC chdc, int x, int y, int chink) {
		Multaple * m = multna;
		int acc = 0;
		while (m) {
			acc += m->draw(chdc,x+acc,y+acc, 1, dong, chink);
			m = m->next();
		}
	}
	Prime * getPrimeHed() {
		if (multna) return multna->getValence();
		else return 0;
	}
	
	
};

