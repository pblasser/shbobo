#pragma once
#include "AbstractChubEngine.h"
#include "ging.h"
#include "grax.h"
#include "chub.h"
#include "MultiplexPotentiator.h"
#include "PerspexStabile.h"
//MISTER P, the POTENTIATOR
//sits at the top of the "original 
//application deliverable code".
//He interacts much with the library
//he inherits the AbstractChubEngine
//which is a callback class for
//ging grax and chub.

class LaceyBanks :  public AbstractChubEngine {
private:
	int amt;
	int sr;
	int sterge[2];
	int oneatatime;
	int offset_chub, offset_ging;
	HGRAXBRUSH MF[4];
	MultiplexPotentiator ** multis;
	PerspexStabile *peggy;
public:
	
	LaceyBanks(){
		peggy = new PerspexStabile();
		//offset = 0;
		oneatatime = 0;
		offset_chub=0; offset_ging=0;
		multis = new MultiplexPotentiator*[10];
		MF[0] = GRAXBRUSHWAND(200,0,0);
		MF[1] = GRAXBRUSHWAND(200, 200, 200);
		MF[2] = GRAXBRUSHWAND(200, 200, 0);
		MF[3] = GRAXBRUSHWAND(10, 10, 10);
		for (int i = 0; i < 10; i++) 
			multis[i] = new MultiplexPotentiator(peggy);
		sterge[0] = 1;
		sterge[1] = 1;
		//amt = 1;
		//harold = MAKECERCLE(64);
	}
	~LaceyBanks() {
		FORI GRAXBRUSHNIL(MF[i]);
	}

	void textorium_trigger(char * outus) { 
		multis[sterge[0]]->textorium_trigger(outus);
	}
	void textorium_script(char * innus) {
		multis[sterge[0]]->textorium_script(innus);
	}
	void dupe_multiplex() {
		int toWhere = (sterge[0] + 1) % 10;
		MultiplexPotentiator *oldus;
		oldus = multis[toWhere];
		multis[toWhere] = new MultiplexPotentiator(multis[sterge[0]],peggy);
		delete(oldus);
		
	}
	void dupe_chubbery() {
		multis[sterge[0]]->chubdupe();
		if (sterge[0] != sterge[1]) multis[sterge[1]]->chubdupe();
	}
	void chubness(CHUBHANDLE h, CHUBREPORT r) {
		
		multis[sterge[0]]->chubness(h,r);
		if (sterge[0] != sterge[1]) multis[sterge[1]]->chubness(h,r);
	}
	

	void chubching(CHUBHANDLE * h, int a) {
	}
	
	void beging() {
		multis[sterge[0]]->beging();
		multis[sterge[1]]->beging();
	}

	
	int * gingness(int ii, int bufflen) {
		offset_ging++; offset_ging%=2;
		return multis[sterge[offset_ging]]->gingness(ii,bufflen);
	}
	
	void graxness(CHDC chdc) {
		offset_chub++;
		offset_chub %= 2;
		multis[sterge[offset_chub]]->graxness(chdc);
		
	}
	
	void mouseButt(MOUSEPOINT m) {
		multis[sterge[0]]->mouseButt(m);	
		if (sterge[0]!=sterge[1])multis[sterge[1]]->mouseButt(m);
	}
	void push(int i) {
		sterge[1] = sterge[0];
		sterge[0] = i;
	}
	void charactros(unsigned char cc) {
		
		if ((cc-48)<10) 
			if (cc>=48) push(cc-48);
		 multis[sterge[0]]->charactros(cc);
		 if (sterge[0]!=sterge[1])multis[sterge[1]]->charactros(cc);
	}
		
};


