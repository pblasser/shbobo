#pragma once
#include "RatChord.h"
//PerspexStabile is hollow-form,
//yet it has exponential surface area
//in the form of quadrangularis,
//a doubly linked list of queenal gradation
//and the quid, a rigid "numerist"
//interpretation of all possible numes
//and denos.
//the form for a ratio is RatChord.
class PerspexStabile {
private:
	
	RatChord * quadrangularis;
	RatChord ** quid;
	Numba gyou[256];
	Prime * truthfulprimestring;
	HGRAXBRUSH MarylandAnnex[256];
	HGRAXBRUSH CardinalAccent;
	//quadrangularis is the "lyst-pointer", 
	//as in the sense that it points to 1/1
	//then quid is s'posed to be a quad format
	//i.e. an array of an array
	//brings up an interesting question,
	//can anyone explain how to implement:
	//RatChord *** quidquid? i.e. tripple pointr
public:
	
	PerspexStabile(void) {
		truthfulprimestring = gimmeTruth(URPRIMLIM, URPRIMLIM, 0);
		makeNumbarz();
		
		quid =  new RatChord*[URPRIMLIM*URPRIMLIM];
		quadrangularis = new RatChord(1,1,gyou);
		RatChord * oldPrincipal = quadrangularis;//[0][0];
		RatChord * oldUndertown = quadrangularis;//[0][0];
		quid[0] = quid[1] = quadrangularis;
		for (int i = 1; i < 256; i++) {
			//creating both the quadrangularis organoform
			//as well as the quid array of array quad;
			//the dialect here is of Baron von Depressus.
			RatChord * principal_hvarmonik = new RatChord(i, 1,gyou);
			quid[i*256+1] = quid[i*256] = principal_hvarmonik;
			//quadrangularis[i][0] = quadrangularis[i][1] = principal_hvarmonik;
			oldPrincipal->ouster(principal_hvarmonik);
			oldPrincipal = principal_hvarmonik;
			oldUndertown = principal_hvarmonik;
			for (int j = 2; j<256; j++) {
				RatChord * underbourg_piez = new RatChord(i,j,gyou);
				oldUndertown->insert(underbourg_piez);
				oldUndertown = underbourg_piez;
				quid[i*256+j] = underbourg_piez;
			} 
		} init_annex();
	}

	void init_annex() {
		for (int orange = 0; orange < 128; orange++) {
			int spranckle = rand()%8;
			MarylandAnnex[orange] = GRAXBRUSHWAND(spranckle+128+orange+(orange>>1),  spranckle+128+(orange>>1), spranckle+128);
		}
		for (int turq = 0; turq < 128; turq++) {
			int spranckle = rand()%8;
			MarylandAnnex[255-turq] = GRAXBRUSHWAND(spranckle+128, spranckle+128+(turq>>1), spranckle+128+turq+(turq>>1));
		}
		CardinalAccent = GRAXBRUSHWAND(170,20,22);
	} 
	
	HGRAXBRUSH getMarylandAnnex(int i) {
		return MarylandAnnex[i];
	} HGRAXBRUSH getCardinalAccent() { return CardinalAccent; }


	
	static Prime * gimmeTruth(int range, int tst, Prime * hed) {
		Prime * pote = hed;
		int potest = 1;
		for (int i = 2; i < tst; i++) {
			if ((tst % i) == 0) potest = 0; 
		} 
		if (potest) {
			int w = 0;
			for (int j = 2; j < range; j++) 
				if ((j % tst) == 0) w++;
			pote = new Prime(tst, w, hed);
		}
		if (tst == 2) return pote;
		else return gimmeTruth(range, tst-1, pote);
	}
	
	Multaple * computeMultnas(unsigned char v, Multaple * m, Prime * strng){
		int p = 1;
		if (strng) p = strng->getValue();
		if (!strng || v == 1) return m;
		Multaple * mm = m;
		if ((v % p) == 0) {
			if (m && (m->getValence() == strng)) 
				m->increment();
			else mm = new Multaple(strng, m);
			return computeMultnas(v/p,mm,strng);
		} else return computeMultnas(v, m, strng->next());
	}
	
	void makeNumbarz() { //call first!
		gyou[0].setValue(1, 0);
		for (int i = 1; i < URPRIMLIM; i++) {
			gyou[i].setValue(i, computeMultnas(i,0,truthfulprimestring));
		}
	}
	Numba * getNumba(int i) {
		return &gyou[limrap(i)];
	}
	RatChord * getQuadrangularis() {
		return quadrangularis;
	}
	
	RatChord * getQuid(int n, int d) {
		n = limrap(n);//n %= URPRIMLIM;
		d = limrap(d);// %= URPRIMLIM;
		//if (n < 1) n = 1;
		//if (d < 1) d = 1;
		return quid[n*URPRIMLIM+d];
	}
	
	int limrap(int input) {
		input %= URPRIMLIM;
		if (input < 1) return 1;
		else return input;
	}
	
	Prime * getTruth() { return truthfulprimestring; }
	~PerspexStabile(void)
	{
		for (int i = 0; i < 256; i++) 
			GRAXBRUSHNIL(MarylandAnnex[i]);
		GRAXBRUSHNIL(CardinalAccent);
	}
};

