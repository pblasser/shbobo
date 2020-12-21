#pragma once
#include "stdafx.h"
#include "PerspexStabile.h"
#include "Barre.h"
#include "Chinkwonkanater.h"
//SponGinger makes the oscillation-
//it has the oscillator code
//it also has the methods to 
//search through RatChords
//kingally, queenally, and
//utilizing the prime-checking
//abilities of the Chinkwonkantr
class SponGinger {
private:
	RatChord ** rats;
	Barre * bartholemew;
	Chinkwonkanater * cherokee;
	PerspexStabile * chube;
	//the queen has two helpers, minstrel and executioner
	//left handed movement takes the quadrangularis 
	//"chromatically" and I quote b/c it moves in
	//microtones down in pitch.  
	//right handed movement takes the quadrangularis up.
	int queen_acc_sinister, queen_acc_dexter;
	int nume_acc, deno_acc;
	int numeMustard[4];
	int denoMustard[4];
	//osc sect
	int osc[4];
	int hys[4];
	RatChord * dursz[4];//for queenal cruising on a persistant plane
	RatChord * origz[4];//for resetting osc on persistant plane too.
	
	int sample_rate;
	int wraparound;
	//HGRAXBRUSH MarylandAnnex[256];
	RECT nrectum[4], drectum[4];
	unsigned char gwonsz[4];
	//int bitshift;
	//HGRAXBRUSH CardinalAccent;
public:
	
	int gingzgongz,quiznoquantan,bitshift;

	SponGinger(Chinkwonkanater * c, Barre * b, PerspexStabile * p, int sr) {
		cherokee = c;
		chube = p;
		bartholemew = b;
		init();
	}
	SponGinger(SponGinger*carbon, Chinkwonkanater * c, Barre * b, PerspexStabile * p, int sr) {
		cherokee = c;
		chube = p;
		bartholemew = b;
		init();
		FORI rats[i] = carbon->getRat(i);
		gingzgongz = carbon->gingzgongz;
		quiznoquantan = carbon->quiznoquantan;
		bitshift = carbon->bitshift;
	}

	void init() {
		queen_acc_sinister=queen_acc_dexter=0;
		nume_acc=deno_acc=0;
		rats = new RatChord*[4];
		rats[0] = chube->getQuadrangularis();
		rats[1] = chube->getQuadrangularis()->getPrev();
		rats[2] = chube->getQuadrangularis()->getPrev()->getPrev();
		rats[3] = chube->getQuadrangularis()->getPrev()->getPrev()->getPrev();
		FORI osc[i] = 0;
		FORI hys[i] = 1;
		FORI dursz[i] = rats[i];
		FORI origz[i] = rats[i];
		gingzgongz = 0;
		quiznoquantan = 0;

		//sample_rate = sr;
		wraparound = 1;
		
		//for (int orange = 0; orange < 128; orange++) {
		//	int spranckle = rand()%8;
		//	MarylandAnnex[orange] = GRAXBRUSHWAND(spranckle+128+orange+(orange>>1),  spranckle+128+(orange>>1), spranckle+128);
		//}
		//for (int turq = 0; turq < 128; turq++) {
		//	int spranckle = rand()%8;
		//	MarylandAnnex[255-turq] = GRAXBRUSHWAND(spranckle+128, spranckle+128+(turq>>1), spranckle+128+turq+(turq>>1));
		//}
		//CardinalAccent = GRAXBRUSHWAND(170,20,22);
		//cardinal accent is a way bacon color,
		//must have odour of blood and communion wine
		//plus the natural carotinids of the bird species
		//Cardinalis Virginia
		changeAsdfghon(0);
	}
	
	~SponGinger() { 
		//for (int i = 0; i < 256; i++) 
		//	GRAXBRUSHNIL(MarylandAnnex[i]);
		//GRAXBRUSHNIL(CardinalAccent);
	}

	void text(FILE * file) {
		 int nume, deno;
		FORI {
			nume = getRat(i)->getNumeP()->getValue();
			deno = getRat(i)->getDenoP()->getValue();
			fprintf(file, "  rat %d = %d / %d\n", i, nume, deno);
		} fprintf(file, "  bitshift %d\n", bitshift);
		fprintf(file, "  gingzgongz %d\n", gingzgongz);
		fprintf(file, "  quiznoquantan %d\n", quiznoquantan);
	}
	char * textum() {
		char * token;
		token = strtok(NULL, " \n\r"); if (token)
		FORI if (strncmp (token,"rat",3)==0) {
			int n,d;
			token = strtok(NULL, " \n\r"); //rat#
			token = strtok(NULL, " \n\r"); //=
			token = strtok(NULL, " \n\r"); //nume
			n = atoi(token);
			token = strtok(NULL, " \n\r"); ///
			token = strtok(NULL, " \n\r"); //deno
			d = atoi(token);
			rats[i] = chube->getQuid(n,d);
			token = strtok(NULL, " \n\r");
		} if (token)
		if (strncmp (token,"bitsh",5)==0) {
			token = strtok(NULL, " \n\r");
			bitshift = atoi(token);
			token = strtok(NULL, " \n\r");
		}	if (token)	
		if (strncmp (token,"gingz",5)==0) {
			token = strtok(NULL, " \n\r");
			gingzgongz = atoi(token);
			token = strtok(NULL, " \n\r");
		} if (token)
		if (strncmp (token,"quizno",6)==0) {
			token = strtok(NULL, " \n\r");
			quiznoquantan = atoi(token);
			token = strtok(NULL, " \n\r");
		} return token;
	}
	RatChord * getRat(int i) { return rats[i]; }
	void setRat(int i, RatChord * r) { rats[i] = r; }
	void gwonszulate(signed char * b) { FORI gwonsz[i] = b[i]; }
	void changeAsdfghon(int inn) { bitshift = inn; }
	
	void drawMarylandAnnex(CHDC chdc, int xchub, int ychibble, int numbr) {
		int xchubby = xchub>>1;
		int ychub = numbr * ychibble;
		int xxxchub = xchubby>>1;
		
		FORI {
			
			nrectum[i].left = xchubby+xchub*i;
			nrectum[i].right = xchubby+xchub*i + 81;
			nrectum[i].top = ychub - 81;
			nrectum[i].bottom = ychub;
			FILLRECT(chdc.hdc, chube->getMarylandAnnex(gwonsz[i]),nrectum[i])
			
			drectum[i].left = xchubby+xchub*i - 81;
			drectum[i].right = xchubby+xchub*i;
			drectum[i].top = ychub;
			drectum[i].bottom = ychub + 81;
			FILLRECT(chdc.hdc, chube->getMarylandAnnex(255-gwonsz[i]), drectum[i])
			
		}
	}
	
	void drawCardinalAccent(CHDC chdc, int xchub, int ychibble, int numbr) {
		int xchubby = xchub>>1;
		int ychub = numbr * ychibble;
		RECT kgous[2];
		RECT qnass[4];
		kgous[0].left = kgous[1].left = nrectum[0].left;
		kgous[0].top = nrectum[1].top;
		kgous[0].right = kgous[1].right = kgous[0].left+36;
		kgous[0].bottom = kgous[0].top+(bitshift<<1);
		kgous[1].bottom = kgous[0].top + 36;
		kgous[1].top = kgous[1].bottom -(bitshift<<1);
		
		qnass[2].right = qnass[3].right = nrectum[0].right;
		qnass[0].left = qnass[1].left = nrectum[0].right-36;
		qnass[3].top = qnass[0].top = nrectum[0].bottom - 36;
		qnass[2].bottom = qnass[1].bottom = nrectum[0].bottom;
		qnass[0].bottom = qnass[3].bottom = qnass[3].top +(bitshift<<1);
		qnass[2].top = qnass[1].top = qnass[1].bottom -(bitshift<<1);
		qnass[0].right = qnass[1].right =qnass[0].left+(bitshift<<1);
		qnass[2].left = qnass[3].left = qnass[3].right - (bitshift<<1);
		
		RECT tessile;
		RECT dentagon[6];
#define TESSELATE(in,out,xoff,yoff) \
out.left = in.left+xoff; \
out.right = in.right+xoff; \
out.bottom = in.bottom+yoff; \
out.top = in.top+yoff;
		
		FORI {
			TESSELATE(kgous[0],dentagon[0],xchub*i,0)
			FILLRECT(chdc.hdc, chube->getCardinalAccent(),dentagon[0])
			TESSELATE(kgous[1],dentagon[1],xchub*i,0)
			FILLRECT(chdc.hdc, chube->getCardinalAccent(),dentagon[1])
			TESSELATE(qnass[0],dentagon[2],xchub*i,0)
			FILLRECT(chdc.hdc, chube->getCardinalAccent(),dentagon[2])
			TESSELATE(qnass[1],dentagon[3],xchub*i,0)
			FILLRECT(chdc.hdc, chube->getCardinalAccent(),dentagon[3])
			TESSELATE(qnass[2],dentagon[4],xchub*i,0)
			FILLRECT(chdc.hdc, chube->getCardinalAccent(),dentagon[4])
			TESSELATE(qnass[3],dentagon[5],xchub*i,0)
			FILLRECT(chdc.hdc, chube->getCardinalAccent(),dentagon[5])
			for (int kui = 0; kui<6;kui++) {
				TESSELATE(dentagon[kui],tessile,(-81),(81))
				FILLRECT(chdc.hdc, chube->getCardinalAccent(),tessile)
			}	
		}
	}
	
	
	RECT * getNumeRect() { return nrectum; }
	RECT * getDenoRect() { return drectum; }
	
	void moutardateNume(int i, int val) {
		numeMustard[i] += val;
	}
	void moutardateDeno(int i, int val) {
		denoMustard[i] += val;
	}
	//MUSTARD IS FM, it is done by 
	//SPECIAL FMOUTARDE MINISTER,
	//THROUGHT THE MUSTARD INTERFACE
	//NEXT THERE ARE TWO STRANDS TO
	//ACCOMODATE THE SPECIAL TITTLE
	//MODE THAT ACXTUALLY REWRITES
	//THE PERSPEX STABILE.
	//QUEENAL STILL TRAVERSES,
	//BUT KINGAL MAKES PERMANENT
	//CHANGES TO THE VALUES
	//OF RATCHORDS>
	void oscirate(int i, RatChord *r) {
		osc[i] *= r->getDeno();
		osc[i] /= rats[i]->getDeno();
		rats[i] = r;
	}
	
	void oscirate(int i, int n, int d) {
		osc[i] *= d;
		osc[i] /= rats[i]->getDeno();
		if (cherokee->specialTittle()) {
			rats[i]->setNume(n);
			rats[i]->setDeno(d);
		} else oscirate(i, chube->getQuid(n,d));
		
	}
	
	//heralding queen, the durszen function
	void durszen(int i) { dursz[i] = rats[i]; }
	
	int kingalNume(int i, int nin) {
		int n = nin >> bitshift;
		if (n == 0) return 0;if (n == -1) return 0;
		int curs = rats[i]->getNume();
		int dean = rats[i]->getDeno();
		int newt = curs + n;
		if (wraparound) {
			if (newt <= 0) 
				newt = 1-newt;//+= URPRIMLIM - 1;
			newt = (newt) % URPRIMLIM;
		} else if (newt >= URPRIMLIM)  return 1;
		else if (newt <= 0) return 1;
		Numba * newdist;
		if (newt > curs) for (;newt>curs;newt--) {
			newdist = chube->getNumba(newt); 
			if (cherokee->checkk(newdist)) {
				oscirate(i, newdist->getValue(), dean);
				return 1;
			}
		} 
		if (newt < curs) for (;newt<curs;newt++) {
			newdist = chube->getNumba(newt); 
			if (cherokee->checkk(newdist)) {
				oscirate(i, newdist->getValue(), dean);
				return 1;
			}
		} 
		return 0;
	}
	
	int kingalDeno(int i, int did) {
		int d = did >> bitshift;
		if (d == 0) return 0; if (d==-1 ) return 0;
		int curs = rats[i]->getDeno();
		int dean = rats[i]->getNume();
		int newt = curs + d;
		if (wraparound) {
			if (newt <= 0) 
				newt = 0-newt;//+= URPRIMLIM - 1;
			newt = (newt) % URPRIMLIM;
		} else if (newt >= URPRIMLIM)  return 1;
		else if (newt <= 0) return 1;
		Numba * newdist;
		if (newt > curs) for (;newt>curs;newt--) {
			newdist = chube->getNumba(newt); 
			if (cherokee->checkk(newdist)) {
				oscirate(i, dean, newdist->getValue());
				return 1;
			}
		} 
		if (newt < curs) for (;newt<curs;newt++) {
			newdist = chube->getNumba(newt); 
			if (cherokee->checkk(newdist)) {
				oscirate(i, dean, newdist->getValue());
				return 1;
			}
		} 
		return 0;
	}
	
	
	int queenalis (int i, int qiq) {
		int q = qiq >> bitshift;
		if (q==0 ) return 0;
		if (q==-1 ) return 0;
		RatChord * curs = dursz[i];
		RatChord * begg = curs;
		if (curs) {
			
			if (q > 0) for (;q>0;q--) if (curs->getNext()) {
				curs = curs->getNext();
				if (cherokee->checkk(curs)) dursz[i] = curs;
			}
			if (q < 0) for (;q<-1;q++) if (curs->getPrev()) {
				curs = curs->getPrev();
				if (cherokee->checkk(curs)) dursz[i] = curs;
			}
			if (dursz[i] != begg) {
				oscirate(i, dursz[i]);
				return 1;
			} else {
				dursz[i] = curs;
				return 1;
			}
		}return 1;
	}
	
	
	
	void queenSpon(int * barres) {
		if (barres[0] > 4) queen_acc_sinister += barres[0];
		if (barres[1] > 4) queen_acc_sinister -= barres[1];
		if (barres[2] > 4) queen_acc_dexter += barres[2];
		if (barres[3] > 4) queen_acc_dexter -= barres[3];
		if (queenalis(bartholemew->getFocius1(),queen_acc_sinister>>6))
			queen_acc_sinister = 0;
		if (queenalis(bartholemew->getFocius2(),queen_acc_dexter>>6))
			queen_acc_dexter = 0;
	} 
	
	void kingSpon(int * barres) {
		if (barres[0] > 4) nume_acc += barres[0];
		if (barres[1] > 4) nume_acc -= barres[1];
		if (barres[2] > 4) deno_acc += barres[2];
		if (barres[3] > 4) deno_acc -= barres[3];
		if (kingalNume(bartholemew->getFocius1(), nume_acc>>6))
			nume_acc = 0;
		if (kingalDeno(bartholemew->getFocius1(), deno_acc>>6))
			deno_acc = 0;
	}
	
	RatChord ** getRats() { return rats; }
	
	
	void draw(CHDC chdc, int xchub, int ychub, int numbr) {
		
		int focix = bartholemew->getFocius1();
		int fociy = bartholemew->getFocius2();
		for (int i = 0; i < 4; i++) {
			rats[i]->drawChube(chdc, xchub*i+(xchub>>1), ychub*numbr, 1);
			if (bartholemew->isQueenPresent()) {
				bartholemew->drawKing(chdc, xchub*focix+(xchub>>1), ychub*numbr);
				bartholemew->drawQueen(chdc, xchub*fociy+(xchub>>1), ychub*numbr);
			} else if (bartholemew->isKingPresent()) 
				bartholemew->drawKing(chdc, xchub*focix+(xchub>>1), ychub*numbr);
		}
		for (int i = 0; i < 4; i++) {
			rats[i]->drawRunix(chdc, xchub*i+(xchub>>1), ychub*numbr, cherokee->getOfficio());
		}
	}
	
	void rando() {
		FORI {
			int d = rand()%URPRIMLIM;
			int n = rand()%URPRIMLIM;
			if (cherokee->checkk(chube->getNumba(d)))
				rats[i]->setDeno(d);
			if (cherokee->checkk(chube->getNumba(n)))
				rats[i]->setNume(n);
		}
	}
	void ginggong() { gingzgongz = !gingzgongz; }
	void quixnoquantl() { quiznoquantan = !quiznoquantan; }
	
	int ging (int i) {
		int height = (denoMustard[i] + rats[i]->getDeno())<<10;
		if (height < (1<<10)) height = (1<<10);
		int height_chub = height << 1;
		int spoddy = (numeMustard[i] + rats[i]->getNume())*
			(cherokee->getStrittle());
		if (spoddy < 1) spoddy = 1;
		if (hys[i] == 1) osc[i] += spoddy;
		else osc[i] -= spoddy;
		int differosc = osc[i] - height;
		int pluserosc = -(osc[i] + height);
		if (quiznoquantan) {
			hys[i] =1;
			if (differosc >= 0) {
				osc[i] = (differosc % height_chub) - height;
			} 
		} else {
			if (differosc >= 0) {
				if (1&(differosc/height_chub)) {
					hys[i] =1;
					osc[i] = (differosc % height_chub) - height;
				} else {
					hys[i]  = -1;
					osc[i] = height - (differosc % height_chub);
				}
			}
			if (pluserosc >= 0) {
				if (1&(pluserosc/height_chub)) {
					hys[i] = -1;
					osc[i] = height - (differosc % height_chub);
				} else {
					hys[i]  = 1;
					osc[i] = (pluserosc % height_chub) - height;
				}
			}
		}
		numeMustard[i] = 0;
		denoMustard[i] = 0;
		if (gingzgongz) return osc[i]/rats[i]->getDeno();
		else return hys[i]<<10;
	} 
};

