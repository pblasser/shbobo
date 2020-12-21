#pragma once
#include "Barre.h"

class Chinkwonkanater
{
private:
	int radiochinkwonk;
	PerspexStabile * pegworth;
	//Prime * qlimm;
	Prime * klimm;
	HGRAXPEN dingdong;
	//int klimito, qlimito;
	
	//int strittle;
	int tittle;
	int freeze_tittle;
	//int inhibit;
	Barre * bartholemew;
	HGRAXPEN holograph[URPRIMLIM*2];
	HGRAXPEN maryflag[4];
public:
	int stritton,strittle,inhibit;
	Prime * qlimm;
	//ZEROASTRAL CHINKWONKANATER
	Chinkwonkanater(PerspexStabile * p, Barre * b) {
		pegworth = p;
		bartholemew = b;
		init();
	} 

	Chinkwonkanater(Chinkwonkanater * carbon, PerspexStabile * p, Barre * b) {
		pegworth = p;
		bartholemew = b;
		init();
		inhibit = carbon->inhibit;
		stritton=carbon->stritton;
		strittle=carbon->strittle;
		qlimm=carbon->qlimm;
	}

	void init() {
		klimm = pegworth->getTruth();
		qlimm = pegworth->getTruth();
		dingdong = GRAXPENWAND(0,0,0,1);
		//chink(0);
		stritton = 0;
		radiochinkwonk = 0;
		//asdfghon = 0;
		strittle = 128;
		inhibit = 0;
		tittle = 0;
		freeze_tittle = 0;
		for (int h = 0; h < URPRIMLIM; h++) {
			holograph[h*2] = pegworth->getNumba(h)->getDongShard();
			holograph[(h*2)+1] = pegworth->getNumba(h)->getShongShrd();
			
		}
		int quasz = rand() % 20;
		maryflag[0] = GRAXPENWAND(245,quasz,0,1);
		maryflag[1] = GRAXPENWAND(245,245-quasz,245,1);
		maryflag[2] = GRAXPENWAND(245,255,quasz,1);
		maryflag[3] = GRAXPENWAND(quasz,quasz,0,1);
		changeStrittle(0);
	}
	
	~Chinkwonkanater() { 
		GRAXPENNIL(dingdong);
		FORI GRAXPENNIL(maryflag[i]);
	}
	
	
	
	int getOfficio() {return radiochinkwonk+128;}
	
	Prime * getPrimeLimit() {
		int limit_acc = 0;
		Prime * limm;
		limm = pegworth->getTruth();
		limit_acc += limm->getWeight();
		while (limit_acc < ((radiochinkwonk<<2) + URPRIMLIM)) {
			limit_acc += limm->getWeight();
			if (limm->next()) limm = limm->next();
		} return limm;
	}
	
	int specialTittle() { return tittle; }
	void tittilate() { tittle = !tittle; }
	void freezeTitle() { freeze_tittle = !freeze_tittle; }
	void chink (signed char b) {
		radiochinkwonk = b;
		if (tittle) {
			if (!freeze_tittle) 
				klimm = getPrimeLimit();
		} if (!inhibit) qlimm = getPrimeLimit();
	}
	
	int getStrittle() {
#define STRITTONTING (stritton == 8 ? 0 : radiochinkwonk>>stritton)
#define STRITTLECOMPLEX ((STRITTONTING) + strittle)
		if (STRITTLECOMPLEX < 0) {
			strittle -= STRITTLECOMPLEX;
		}
		return STRITTLECOMPLEX;
	}
	void changeStrittle(int inn) {
		if (inn > stritton) strittle = getStrittle();// % URPRIMLIM;
		stritton = inn;
	}
	
	void inh() { inhibit = !inhibit; }
	
	int checkk(Numba * n) {
		//if (inhibit) return 1;
		if (n==0) return 1;
		if (n->getPrimeHed()) {
			if (tittle) 
				return (n->getPrimeHed()->getValue() <= klimm->getValue());
			else 
				return (n->getPrimeHed()->getValue() <= qlimm->getValue());
		} else return 1;
	}
	
	int checkk (RatChord * r) {
		Numba * n;
		Numba * d;
		int acc = 1;
		n = r->getNumeP();
		d = r->getDenoP();
		if (n->getPrimeHed())
			acc = (n->getPrimeHed()->getValue() <= qlimm->getValue());
		if (d->getPrimeHed())
			acc &=  (d->getPrimeHed()->getValue() <= qlimm->getValue());
		return acc;
	}
	
	void drawtittle(CHDC chdc, int x, int y, int n) {
		//getPrimeLimit();
		//if (!inhibit)
		if (tittle) {
			klimm->drawHolographically(chdc, x-klimm->getValue(),  
									   y*n-klimm->getValue(), holograph, URPRIMLIM*2, getOfficio());
			qlimm->drawHolographically(chdc, x-qlimm->getValue(),  
									   y*n-qlimm->getValue(), maryflag, 4, getOfficio());
			
		} else if (qlimm) 
			qlimm->draw(chdc, x, 
						y*n, dingdong, getOfficio());
	}
	
	
	 void text(FILE * file) {
		fprintf(file, "  inhibit %d\n", inhibit); 
		fprintf(file, "  primelm %d\n", qlimm->getValue());
		fprintf(file, "  stritton %d\n", stritton);
		fprintf(file, "  strittle %d\n", strittle);
	} 
	Prime * getPrimeLimit(int p) {
		Prime * limm;
		limm = pegworth->getTruth();
		while (p > limm->getValue()) {
			if (limm->next()) limm = limm->next();
			else break;
		} return limm;
	}
	char * textum() {
		char * token;
		token = strtok(NULL, " \n\r");
		if (token)
		if (strncmp (token,"inhib",5)==0) {
			token = strtok(NULL, " \n\r");
			inhibit = atoi(token);
			token = strtok(NULL, " \n\r");
		} if (token)
		if (strncmp (token,"prime",5)==0) {
			token = strtok(NULL, " \n\r");
			qlimm = getPrimeLimit(atoi(token));
			token = strtok(NULL, " \n\r");
		} if (token)
		
		if (strncmp (token,"stritton",8)==0) {
			token = strtok(NULL, " \n\r");
			stritton = atoi(token);
			token = strtok(NULL, " \n\r");
		}
		if (token)
		if (strncmp (token,"strittle",8)==0) {
			token = strtok(NULL, " \n\r");
			strittle = atoi(token);
			token = strtok(NULL, " \n\r");
		}  return token;
	}
	
};

