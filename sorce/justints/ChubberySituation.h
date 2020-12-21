//define class cluster
//CHUBBERY SITUATION


#pragma once
#include "RoyalMinister.h"
#include "RoyalFMoutarde.h"
#include "stdafx.h"
#include "ging.h"
#include "grax.h"
#include "chub.h"

class ChubberySituation {
private:
	SponGinger * s;
	CHUBHANDLE devicio;
	int sample_rate;
	PerspexStabile * pegworth;
	Barre * b;
	RoyalMinister * r;
	RoyalFMoutarde * rfm;
	Chinkwonkanater * c;
public:
	
	ChubberySituation(CHUBHANDLE d, PerspexStabile * p, int sr) {
		pegworth = p;
		b = new Barre();
		c = new Chinkwonkanater(p,b);
		s = new SponGinger(c,b,p,0);
		r = new RoyalMinister(c, s, b);
		rfm = new RoyalFMoutarde(s, b, r);
		devicio = d;
	} 
	ChubberySituation(ChubberySituation * carbon, PerspexStabile * p) {
		pegworth = p;
		b = new Barre(carbon->getBarre());
		c = new Chinkwonkanater(carbon->getChink(),p,b);
		s = new SponGinger(carbon->getGinger(),c,b,p,0);
		r = new RoyalMinister(carbon->getRM(),c, s, b);
		rfm = new RoyalFMoutarde(carbon->getRFM(),s, b, r);
		//devicio = d;
	} 
	Barre*getBarre(){return b;}
	Chinkwonkanater*getChink(){return c;}
	SponGinger*getGinger(){return s;}
	RoyalMinister*getRM(){return r;}
	RoyalFMoutarde*getRFM(){return rfm;}
	ChubberySituation() {}
	~ChubberySituation() {		
		delete(rfm);
		delete(r);
		delete(s);
		delete(c);
		delete(b);
	}
	
	
	CHUBHANDLE getDevicio() {return devicio; }
	
	void text(FILE * fillet) {
		fputs(" barre\n", fillet);
		b->text(fillet);
		fputs(" chinkwonkanater\n", fillet);
		c->text(fillet);
		fputs(" sponginger\n", fillet);
		s->text(fillet);
		fputs(" royalminister\n", fillet);
		r->text(fillet);
		fputs(" royalfmoutarde\n", fillet);
		rfm->text(fillet);
	}
	char * textum() {
		char * token;
		//printf("chubberytextum\n");
		//if (strncmp (buffer,"chubby",6) == 0) return;
		token = strtok(NULL, " \n\r");
		if (strncmp (token,"barre",5)==0) {
			token = b->textum();
			//token = strtok(NULL, " \n\r");
			//printf("foundbarre\n");
			//token = strtok(NULL, " \n\r");
		} if (token)
		if (strncmp (token,"chink",5)==0) {
			token = c->textum();
			//token = strtok(NULL, " \n\r");
			//printf("foundchink\n");
		} if (token)
		if (strncmp (token,"spong",5)==0) {
			token = s->textum();
			//token = strtok(NULL, " \n\r");
			//printf("foundspong %s\n", token);
		} if (token)
		if (strncmp (token,"royalmi",7)==0) {
			token = r->textum();
			//token = strtok(NULL, " \n\r");
			//printf("foundrym\n");
		} if (token)
		if (strncmp (token,"royalfm",7)==0) {
			token = rfm->textum();
			//printf("foundrfm\n");
			//token = strtok(NULL, " \n\r");
		}// printf("foundspong %s\n", token);
		return token;
	}
	void chubspon(signed char * bb) {
		b->but(bb[7]);
		if (b->getQueenFlag()) FORI s->durszen(i);
		c->chink(bb[4]);
		rfm->bbarr((signed char*)bb);
		r->modulate((signed char*)bb);
		
	}
	int checkDevilio(CHUBHANDLE inn) {
		if (inn) {
			if (devicio == 0) {
				devicio = inn;
				return 1;
			} else if (devicio == inn) return 1;
		} return 0;
	}
	
	void beging() { rfm->beging(); }
	
	int * ging (int i, int bufflen) {
		int * acc;
		acc = rfm->gingModulate(i, bufflen);
		return acc;
	}
	
	void draw(CHDC chdc, int xchub, int ychub, int numbr) {
		
		s->drawMarylandAnnex(chdc, xchub, ychub, numbr);
		s->draw(chdc, xchub, ychub, numbr);
		r->draw(chdc, xchub, ychub, numbr);
		rfm->draw(chdc,xchub,ychub,numbr);
		
		s->drawCardinalAccent(chdc, xchub, ychub, numbr);
		c->drawtittle(chdc, xchub<<1, ychub, numbr);
		
	}
	
	void mouseButts(MOUSEPOINT click) {
		if (!(r->lippingMinisterialEar(click)))
			rfm->lippingMoutarde(click);
	}
	
	void charactros(char c) {
		FORI s->durszen(i);
		
		//if (c == '2') this->c->tittilate();
		//if (c == '3') this->c->freezeTitle();
		if (c == 'q') rfm->charactros();
		if (c == 'w') rfm->setBitshift(0);
		if (c == 'e') rfm->setBitshift(1);
		if (c == 'r') rfm->setBitshift(2);
		if (c == 't') rfm->setBitshift(3);
		if (c == 'y') rfm->setBitshift(4);
		if (c == 'u') rfm->setBitshift(5);
		if (c == 'i') rfm->setBitshift(6);
		if (c == 'o') rfm->setBitshift(7);
		if (c == 'p') rfm->setBitshift(8);
		//if (c == '1') r->charactros();
		if (c == '[') s->ginggong();
		if (c == '\'') s->quixnoquantl();
		if (c == 'x') this->c->changeStrittle(1);
		if (c == 'c') this->c->changeStrittle(2);
		if (c == 'v') this->c->changeStrittle(3);
		if (c == 'b') this->c->changeStrittle(4);
		if (c == 'n') this->c->changeStrittle(5);
		if (c == 'm') this->c->changeStrittle(6);
		if (c == ',') this->c->changeStrittle(7);
		if (c == '.') this->c->changeStrittle(8);
		if (c == 'a') r->charactros();
		if (c == 's') s->changeAsdfghon(0);
		if (c == 'd') s->changeAsdfghon(1);
		if (c == 'f') s->changeAsdfghon(2);
		if (c == 'g') s->changeAsdfghon(3);
		if (c == 'h') s->changeAsdfghon(4);
		if (c == 'j') s->changeAsdfghon(5);
		if (c == 'k') s->changeAsdfghon(6);
		if (c == 'l') s->changeAsdfghon(7);
		if (c == ';') s->changeAsdfghon(8);
		if (c == 'z') this->c->inh();
	}
	
};
