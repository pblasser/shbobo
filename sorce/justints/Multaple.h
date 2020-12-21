
#pragma once
#include "Prime.h"
#include "stdafx.h"

class Multaple {
private:
	Prime * valence;
	int occurance;
	Multaple * tail;
public:
	
	Multaple(Prime * v, Multaple * tel){
		valence = v;
		occurance = 1;
		tail = tel;
	}
	
	Prime * getValence() { return valence; }
	void increment() { occurance++; }
	
	int draw(CHDC chdc, int x, int y, int direction, HGRAXPEN tyo, int chink) {
		int i;
		int offset = direction * valence->getValue();
		for (i = 1; i <= occurance; i++) {
			int off = offset * i;
			//if (direction == -1) off += 2*offset;
			valence->draw(chdc, x+off, y+off, tyo, chink);
		}
		return valence->getValue() * occurance * direction;
	}
	
	Multaple * next() { return tail; }
	~Multaple(void){}
};
