#pragma once
#include "stdafx.h"
#include "ging.h"
#include "grax.h"
#include "chub.h"

class Barre {
private:
	int buttes, lastbuttes;
	int focii[2];
	int king;
	int queenflag;
	int lastqueen;
	HGRAXBRUSH MarylandFlag[4];
public:
	
	Barre() {
		focii[0] = 0;
		focii[1] = 0;
		queenflag = 0;
		MarylandFlag[0] = GRAXBRUSHWAND(245,0,0);
		MarylandFlag[1] = GRAXBRUSHWAND(245,245,245);
		MarylandFlag[2] = GRAXBRUSHWAND(245,255,0);
		MarylandFlag[3] = GRAXBRUSHWAND(0,0,0);
	}
	Barre(Barre * carbon) {
		focii[0] = carbon->getFocius1() + 1;
		focii[1] = carbon->getFocius2() + 1;
		queenflag = 0;
		MarylandFlag[0] = GRAXBRUSHWAND(245,0,0);
		MarylandFlag[1] = GRAXBRUSHWAND(245,245,245);
		MarylandFlag[2] = GRAXBRUSHWAND(245,255,0);
		MarylandFlag[3] = GRAXBRUSHWAND(0,0,0);
	}
	~Barre() {
		FORI GRAXBRUSHNIL(MarylandFlag[i]);
	}
	int isKingPresent() { return (focii[0] != 0); }
	int isQueenPresent() { return (focii[0] != 0) & (focii[1] != 0); }
	int getFocius1() { return focii[0]-1; }
	int getFocius2() { return focii[1]-1; }
	int xxor(int i) {
		return (!((lastbuttes>>(i<<1))&1)) & 
		((buttes>>(i<<1))&1);
	}
	
	HGRAXBRUSH getMarylandFlag(int i) {
		return MarylandFlag[i];
	}
	void text(FILE * file) {
		if (isKingPresent()) fprintf(file, "  kingal %d\n", getFocius1());
		else if (isQueenPresent()) fprintf(file, "  queenal %d %d\n", getFocius1(), getFocius2());
		else fprintf(file, "  atrest\n");
	}
	char * textum() {
		char * token;
		token = strtok(NULL, " \n\r");
		if (token) {
		if (strncmp (token,"atrest",5)==0) {}//return;
		else if (strncmp (token,"kingal",5)==0) {
			token = strtok(NULL, " \n\r");
			focii[0] = 1 + atoi(token);
			focii[1] = 0;
		} else if (strncmp (token,"queenal",5)==0) {
			token = strtok(NULL, " \n\r");
			focii[0] = 1 + atoi(token);
			token = strtok(NULL, " \n\r");
			focii[1] = 1 + atoi(token);
		} else return token; }
		token = strtok(NULL, " \n\r");
		return token;
	}
	
	void but (unsigned char b) {
		lastbuttes = buttes;
		
		buttes = b;
		lastqueen = isQueenPresent();
		int switcheroon;
		for (int i = 0; i < 4; i++) {
			if (xxor(i)) {
				if (focii[0] == i+1) {
					focii[0] = focii[1];
					focii[1] = 0;
				} 
				else if (focii[1] == i+1) {focii[1] = 0;}
				else { focii[1] = focii[0]; focii[0] = i+1;};
				if (isQueenPresent() & (focii[0] > focii[1])) {
					switcheroon = focii[1];
					focii[1] = focii[0];
					focii[0] = switcheroon;
				}
			}
		} if (isQueenPresent()>lastqueen) queenflag = 1;
	}
	int getQueenFlag() {int tyo = queenflag; queenflag=0; return tyo; }
	
	void drawQueen(CHDC chdc, int x, int y) {
		RECT rrr;
		for (int i = 9; i > 0; i--) {
			rrr.left = x - i; 
			rrr.top = y - i;
			rrr.right = x + i;
			rrr.bottom = y + i;
			FILLRECT(chdc.hdc,MarylandFlag[i%4],rrr);
		}
	}
	
	void drawKing(CHDC chdc, int x, int y) {
		RECT rrr;
		for (int i = 10; i > 0; i--) {
			rrr.left = x - i; 
			rrr.top = y - i;
			rrr.right = x + i;
			rrr.bottom = y + i;
			FILLRECT(chdc.hdc,MarylandFlag[i%4],rrr);
			i--;
		}
	}
	
	
};

