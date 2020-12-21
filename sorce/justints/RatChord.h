#pragma once
#include "Numba.h"
#include "stdafx.h"


class RatChord {
private:
	Numba * nume;
	Numba * deno;
	int denoacc;
	int numeacc;
	int osc;
	int hysterion;
	RatChord * next;
	RatChord * prev;
	float technicalValue; // for nerds only
	Numba * gyou;
public:
	
	RatChord() { RatChord(1,1,0); }
	RatChord(int n, int d, Numba * g) {
		gyou = g;
		setNume(n); setDeno(d);
		numeacc = n<<8;
		denoacc = d<<8;
		osc = 0;
		hysterion = 1;
		prev = 0;
		next = 0;
		technicalValue = (float)(nume->getValue())/(float)(deno->getValue());
	}
	/*void addToNume(int amt) { 
	 numeacc += amt<<8; 
	 if (numeacc > 0) setNume(numeacc>>8);
	 }
	 void addToDeno(int amt) { 
	 denoacc += amt<<8; 
	 if (denoacc > 0) setDeno(denoacc>>8);
	 }*/
	void setNext(RatChord * setter) { next = setter; }
	void setOsc(int o) { osc = o; }
	RatChord * getNext() { if (next) next->setOsc(osc); return next;}
	void setPrev(RatChord * setter) { prev = setter; }
	RatChord * getPrev() { if (prev) prev->setOsc(osc); return prev; }
	void insert(RatChord * insertion) {
		if(insertion) {
			if (insertion->getTechnicalValue() <= technicalValue) {
				if (prev) {
					if (insertion->getTechnicalValue() <= prev->getTechnicalValue()) {
						prev->insert(insertion);
					} else {
						insertion->setPrev(prev);
						prev->setNext(insertion);
						prev = insertion;
						insertion->setNext(this);
					} 
				} else {
					prev = insertion;
					insertion->setNext(this);
				}
			}}
	}
	void ouster(RatChord * oustron) {
		if (oustron) {
			if (oustron->getTechnicalValue() >= technicalValue) {
				if (next) {
					if (oustron->getTechnicalValue() >= next->getTechnicalValue()) {
						next->ouster(oustron);
					} else {
						oustron->setNext(next);
						next->setPrev(oustron);
						next = oustron;
						oustron->setPrev(this);
					}
				} 
				else {
					next = oustron;
					oustron->setPrev(this);
				}
			}}
	}
	
	//the only floating values here
	//are used at static initiation-time
	//to create the quadrangularis/quidmachine
	float getTechnicalValue() {
		return technicalValue;
	}
	
	
	void setNume(int n) {
		nume = &gyou[n % URPRIMLIM];
	}
	int getNume() {
  		return nume->getValue();
	}
	Numba * getNumeP () { return nume; }
	Numba * getDenoP() { return deno; }
	void setDeno(int d) {
		deno = &gyou[d % URPRIMLIM];
	}
	int getDeno() {
		return deno->getValue();
	}
	void drawChube(CHDC chdc, int x, int y, int siz) {
		nume->drawNume(chdc, x, y);
		deno->drawDeno(chdc, x, y);
	}
	void drawRunix(CHDC chdc, int x, int y, int chink) {
		nume->drawNumeRunes(chdc,x,y,  chink);
		deno->drawDenoRunes(chdc,x,y,  chink);
	}
	
	
	~RatChord()
	{
	}
};

