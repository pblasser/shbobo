#pragma once
#include "stdafx.h"

#include "ging.h"
#include "grax.h"
#include "chub.h"
#include "SponGinger.h"

//QUADRANNULAR MINISTERIUM REGISNARUM
//QUADRANGULARIS OPERATOR DU ROY
class RoyalMinister {
private:
	int signales[4][2];
	//fore barres can modulate
	//fore barres in queen-way
	
	//fore barres can modulate
	//fore barres in king-way;
	
	//the computed offsetus
	
	
	int offsetus[4][4];
	int knume[4];
	int kdeno[4];
	int qwrth[4] ;
	
	SponGinger * sefton;
	Barre * bartholemew;
	HGRAXBRUSH NavyAccent;
	
	//int inhibit;
	RECT primus_rect[4];
	RECT  *nrectum,  *drectum;
	RECT rrrr_nk[4][4], rrrr_nq[4][4], rrrr_dk[4][4], rrrr_dq[4][4];
	int outset[4];
	unsigned char lastbuttes, buttes;
	Chinkwonkanater * cherokee;
	unsigned char gwonsz[4];
public:
	int inhibit;
	int queenals[4][4]; 
	int kingals[4][4];
	RoyalMinister(Chinkwonkanater * c, SponGinger * s, Barre * b) {
		sefton = s;
		bartholemew = b;
		cherokee = c;
		init();
		
	} 
	
	void init() {
		NavyAccent = GRAXBRUSHWAND(20,20,125);
		inhibit = 1;
		FORI {
			signales[i][0] = 0;
			signales[i][1] = 0;
			outset[i] = 0;
			FORJ {
				kingals[i][j] = queenals[i][j] = 0;
			}
			knume[i]=kdeno[i]=qwrth[i]=0;
		}
	}
	RoyalMinister(RoyalMinister*carbon,Chinkwonkanater * c, SponGinger * s, Barre * b) {
		sefton = s;
		bartholemew = b;
		cherokee = c;
		init();
		inhibit=carbon->inhibit;
		FORI FORJ {
			queenals[i][j] = carbon->queenals[i][j];
			kingals[i][j] = carbon->kingals[i][j];
		}
	}

	~RoyalMinister(){
		GRAXBRUSHNIL(NavyAccent);
	}// { DeleteObject(NavyAccent); }
	
	void text(FILE * file) {
		fprintf(file, "  inhibit %d\n", inhibit);
		FORI {
			fprintf(file, "  kingals %d = ", i);
			FORJ fprintf(file, "%d ", kingals[i][j]);
			fprintf(file, "\n  queenals %d = ", i);
			FORJ fprintf(file, "%d ", queenals[i][j]);
			fprintf(file, "\n");
		}
	}
	char * textum() {
		char * token;
		token = strtok(NULL, " \n\r"); if (token)
		if (strncmp (token,"inhib",5)==0) {
			token = strtok(NULL, " \n\r");
			inhibit = atoi(token);
			token = strtok(NULL, " \n\r");
		} if (token)
		FORI {
			//token = strtok(NULL, " \n\r");
			if (strncmp (token,"kingals",5)==0) {
				token = strtok(NULL, " \n\r"); //kng#
				token = strtok(NULL, " \n\r"); //=
				FORJ {
					token = strtok(NULL, " \n\r"); 
					kingals[i][j] = atoi(token);
				} token = strtok(NULL, " \n\r");
			} 
			if (strncmp (token,"queenals",5)==0) {
				token = strtok(NULL, " \n\r"); //qn#
				token = strtok(NULL, " \n\r"); //=
				FORJ {
					token = strtok(NULL, " \n\r"); 
					queenals[i][j] = atoi(token);
				} token = strtok(NULL, " \n\r");
			}
		} return token;
	}
	void charactros() { inhibit = !inhibit; }
	void modulate(signed char * b) {
		FORI gwonsz[i] = b[i];
		sefton->gwonszulate(b);
		if (!inhibit) {
			FORI {
				signales[i][0] = (int)b[i] - signales[i][1];
				signales[i][1] = (int)b[i];
			} FORI {
				FORJ {
					if (kingals[i][3-j] > 0) 
						knume[i] += signales[(3-j+i)%4][0]; 
					else if (kingals[i][3-j] < 0)
						kdeno[i] += signales[(3-j+i)%4][0]; 
					qwrth[i] += signales[(3-j+i)%4][0] * queenals[i][3-j];
					//qwrth[j] *= 16;
				}
				
			}
			for (int i = 0; i < 4; i++) {
				if (sefton->kingalNume(i, (knume[i])>>0)) {
					knume[i] = 0;
					sefton->durszen(i);
				}
				
				if (sefton->kingalDeno(i, (kdeno[i])>>0)) {
					kdeno[i] = 0;
					sefton->durszen(i);
				}
				
				
				sefton->queenalis(i, qwrth[i]);
				qwrth[i] = 0;
				
			}
		}
	}
	void draw(CHDC chdc, int xchub, int ychibble, int numbr) {
		
		if (!inhibit) {	
			nrectum = sefton->getNumeRect();
			drectum = sefton->getDenoRect();
			FORI {
				FORJ {
					rrrr_nk[i][3-j].left = nrectum[i].left + (j*4);
					rrrr_nk[i][3-j].top = nrectum[i].top;
					rrrr_nk[i][3-j].right = nrectum[i].left + 36 - (j*4);
					rrrr_nk[i][3-j].bottom = nrectum[i].top+36;
					//FillRect(hdc, &rrrr_nk[i], NavyAccent);
					if (kingals[i][3-j] > 0) 
						FILLRECT(chdc.hdc, bartholemew->getMarylandFlag((3-j+i)%4) , rrrr_nk[i][3-j] )		
					else FILLRECT(chdc.hdc,NavyAccent,rrrr_nk[i][3-j])
					
					rrrr_nq[i][3-j].right = nrectum[i].right - (j*4);
					rrrr_nq[i][3-j].bottom = nrectum[i].bottom - (j*4);
					rrrr_nq[i][3-j].left = nrectum[i].right - 36 + (j*4);
					rrrr_nq[i][3-j].top = nrectum[i].bottom - 36 + (j*4);
					if (queenals[i][3-j] > 0) 
						FILLRECT(chdc.hdc, bartholemew->getMarylandFlag((3-j+i)%4),rrrr_nq[i][3-j])				
					else FILLRECT(chdc.hdc, NavyAccent,rrrr_nq[i][3-j])					
					rrrr_dk[i][3-j].left = drectum[i].left + (j*4);
					rrrr_dk[i][3-j].top = drectum[i].top;
					rrrr_dk[i][3-j].right = drectum[i].left + 36 - (j*4);
					rrrr_dk[i][3-j].bottom = drectum[i].top+36;
					if (kingals[i][3-j] < 0) 
						FILLRECT(chdc.hdc, bartholemew->getMarylandFlag((3-j+i)%4), rrrr_dk[i][3-j])				
					else FILLRECT(chdc.hdc, NavyAccent, rrrr_dk[i][3-j])
					
					rrrr_dq[i][3-j].right = drectum[i].right - (j*4);
					rrrr_dq[i][3-j].bottom = drectum[i].bottom - (j*4);
					rrrr_dq[i][3-j].left = drectum[i].right - 36 + (j*4);
					rrrr_dq[i][3-j].top = drectum[i].bottom - 36 + (j*4);
					if (queenals[i][3-j] < 0) 
						FILLRECT(chdc.hdc, bartholemew->getMarylandFlag((3-j+i)%4), rrrr_dq[i][3-j])			
					else FILLRECT(chdc.hdc, NavyAccent, rrrr_dq[i][3-j])
				}
			}	
		}
	}
	int lippingMinisterialEar(MOUSEPOINT click) {
		if (!inhibit) {
			FORI {
				FORJ {
					if (POINTSINRECTALIS(click,rrrr_nk,i,j))
						RMLIPPER(1,kingals[i][j]);
					if (POINTSINRECTALIS(click,rrrr_nq,i,j))
						RMLIPPER(1,queenals[i][j])
						if (POINTSINRECTALIS(click,rrrr_dk,i,j))
							RMLIPPER(-1,kingals[i][j])
							if (POINTSINRECTALIS(click,rrrr_dq,i,j))
								RMLIPPER(-1,queenals[i][j])
								}
			}
		} return 0;
	}
	
};

