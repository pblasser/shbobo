#pragma once
#include "stdafx.h"
#include "ging.h"
#include "grax.h"
#include "chub.h"
#include "SponGinger.h"
#include "RoyalMinister.h"
//SSINUS FMOUTARDE 
//to bring upon a state of
//"BALCIUM", which is the calx
//of squish, funky dunks
//fancy art, from a dream,
//BALTIMORE MUSEUM OF ART
//exhibits BALCIUM,
//calcium bones
class RoyalFMoutarde
{
private:
	
	int barres[4], forebarres, oldForebarres, oldBarres[4];
	int gingszacc[4][2];
	int stereo_acc[2];
	int ginging[4];
	SponGinger * sefton;
	Barre * bartholemew;
	RoyalMinister * rolf;
	HGRAXBRUSH TaupeAccent;
	RECT  *nrectum,  *drectum;
	RECT rrrr_nk[4][4], rrrr_nq[4][4], rrrr_dk[4][4], rrrr_dq[4][4];
	RECT maskrect;
	//int bitshift;
	int outset[4];
	
public:
	int inhibit,bitshift;
	int numals[4][4];
	int denals[4][4];

	RoyalFMoutarde(SponGinger * s, Barre * b, RoyalMinister * r) {
		inhibit = 1;
		sefton = s;
		bartholemew = b;
		rolf = r;
		init();
	} 
	
	void init() {
		FORI {
			
			barres[i] = 0;
			forebarres = 0;
			FORJ {
				numals[i][j] = denals[i][j] = 0;
			}
		}
		TaupeAccent = GRAXBRUSHWAND(120,120,125);
		bitshift = 0;
		beging();
	}
	RoyalFMoutarde(RoyalFMoutarde*carbon,SponGinger * s, Barre * b, RoyalMinister * r) {
		sefton = s;
		bartholemew = b;
		rolf = r;
		init();
		inhibit = carbon->inhibit;
		bitshift = carbon->bitshift;
		FORI FORJ {
			numals[i][j] = carbon->numals[i][j];
			denals[i][j] = carbon->denals[i][j];
		}
	}
	~RoyalFMoutarde() { 
		GRAXBRUSHNIL(TaupeAccent);
	}//DeleteObject(TaupeAccent); }
	void text(FILE * file) {
		fprintf(file, "  inhibit %d\n", inhibit);
		FORI {
			fprintf(file, "  numals %d = ", i);
			FORJ fprintf(file, "%d ", numals[i][j]);
			fprintf(file, "\n  denals %d = ", i);
			FORJ fprintf(file, "%d ", denals[i][j]);
			fprintf(file, "\n");
		} fprintf(file, "  bitshift %d\n", bitshift);
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
			
			if (strncmp (token,"numals",5)==0) {
				token = strtok(NULL, " \n\r"); //nml#
				token = strtok(NULL, " \n\r"); //=
				FORJ {
					token = strtok(NULL, " \n\r"); 
					numals[i][j] = atoi(token);
				} token = strtok(NULL, " \n\r");
			} 
			if (strncmp (token,"denals",5)==0) {
				token = strtok(NULL, " \n\r"); //dnl#
				token = strtok(NULL, " \n\r"); //=
				FORJ {
					token = strtok(NULL, " \n\r"); 
					denals[i][j] = atoi(token);
				} token = strtok(NULL, " \n\r");
			}
		}
		//token = strtok(NULL, " \n\r"); if (token)
		if (strncmp (token,"bitsh",5)==0) {
			token = strtok(NULL, " \n\r");
			bitshift = atoi(token);
			token = strtok(NULL, " \n\r");
		} return token;
	}
	void draw(CHDC chdc, int xchub, int ychibble, int numbr) {
		//int xchubby = xchub>>1;
		//int ychub = numbr * ychibble;
		if (!inhibit) {
			nrectum = sefton->getNumeRect();
			drectum = sefton->getDenoRect();
			
			FORI {
				FORJ {
					maskrect.left = rrrr_nk[i][3-j].left = nrectum[i].left;
					maskrect.bottom = rrrr_nk[i][3-j].bottom = nrectum[i].bottom;
					maskrect.top = rrrr_nk[i][3-j].top = nrectum[i].bottom - ((4-j)*9);
					maskrect.right = rrrr_nk[i][3-j].right = nrectum[i].left + ((4-j)*9);
					maskrect.top += 9 - bitshift;
					maskrect.right -= 9 - bitshift;
					if (numals[i][3-j] > 0) 
						FILLRECT(chdc.hdc,bartholemew->getMarylandFlag((3-j+i)%4),rrrr_nk[i][3-j])
					FILLRECT(chdc.hdc,TaupeAccent,maskrect)
					
					maskrect.right = rrrr_nq[i][3-j].right = nrectum[i].right;
					maskrect.top = rrrr_nq[i][3-j].top = nrectum[i].top;
					maskrect.bottom = rrrr_nq[i][3-j].bottom = nrectum[i].top  + ((4-j)*9);
					maskrect.left = rrrr_nq[i][3-j].left = nrectum[i].right - ((4-j)*9);
					maskrect.bottom -= 9 - bitshift;
					maskrect.left += 9 - bitshift;
					if (numals[i][3-j] < 0) 
						FILLRECT(chdc.hdc,bartholemew->getMarylandFlag((3-j+i)%4),rrrr_nq[i][3-j])	
					FILLRECT(chdc.hdc,TaupeAccent,maskrect)
					
					maskrect.left = rrrr_dq[i][3-j].left = drectum[i].left;
					maskrect.bottom = rrrr_dq[i][3-j].bottom = drectum[i].bottom;
					maskrect.top = rrrr_dq[i][3-j].top = drectum[i].bottom - ((4-j)*9);
					maskrect.right = rrrr_dq[i][3-j].right = drectum[i].left + ((4-j)*9);
					maskrect.top += 9 - bitshift;
					maskrect.right -= 9 - bitshift;
					if (denals[i][3-j] > 0) 
						FILLRECT(chdc.hdc,bartholemew->getMarylandFlag((3-j+i)%4),rrrr_dq[i][3-j])	
						FILLRECT(chdc.hdc,TaupeAccent,maskrect)
					
					maskrect.right = rrrr_dk[i][3-j].right = drectum[i].right;
					maskrect.top = rrrr_dk[i][3-j].top = drectum[i].top;
					maskrect.bottom = rrrr_dk[i][3-j].bottom = drectum[i].top + ((4-j)*9);
					maskrect.left = rrrr_dk[i][3-j].left = drectum[i].right - ((4-j)*9);
					maskrect.bottom -= 9 - bitshift;
					maskrect.left += 9 - bitshift;
					if (denals[i][3-j] < 0) 
						FILLRECT(chdc.hdc,bartholemew->getMarylandFlag((3-j+i)%4),rrrr_dk[i][3-j])	
						FILLRECT(chdc.hdc,TaupeAccent,maskrect)
				}
			}
			
			
			
		}
	}
	void bbarr(signed char * b) {
		
		
		forebarres = 0;
		
		FORI {
			forebarres += b[i];
			barres[i] = b[i];
		}
		
		
		
		if (bartholemew->isQueenPresent()) sefton->queenSpon(barres);
		else if (bartholemew->isKingPresent()) sefton->kingSpon(barres);
	}
	
	void beging() { 
		oldForebarres = forebarres; 
		FORI oldBarres[i] = barres[i];
		
	}
		
	
	
#define STEREOGING(barfsplat,out,gingling) \
if (barfsplat>=0)out[0]+=barfsplat*gingling; \
else if (barfsplat<0)out[1]+=barfsplat*gingling;
	
#define TRINGING(ting) \
	((ting > 3 ? ting-3 : 0) + (ting < -3 ? ting + 3: 0))
	
#define GINGFADEFORE (((forebarres - oldForebarres)*ii/bufflen)+oldForebarres)
#define GINGFADEBARR (((barres[i] - oldBarres[i]) *ii/bufflen)+oldBarres[i])
	
	int * gingModulate(int ii, int bufflen) {
		stereo_acc[0] = stereo_acc[1] = 0;
		FORI { 
			ginging[i] = sefton->ging(i); 
			gingszacc[i][0]= gingszacc[i][1]=0;
			STEREOGING(GINGFADEBARR,gingszacc[i],ginging[i])
		} if (!inhibit) {
			FORI {
				
				FORJ {
					if (numals[i][3-j]> 0)
						sefton->moutardateNume(i,(gingszacc[(3-j+i)%4][0])>>(10+bitshift));
					else if (numals[i][3-j]< 0)
						sefton->moutardateNume(i,(gingszacc[(3-j+i)%4][1])>>(10+bitshift));
					if (denals[i][3-j]>0)
						sefton->moutardateDeno(i,(gingszacc[(3-j+i)%4][0])>>(10+bitshift));
					else if (denals[i][3-j]<0)
						sefton->moutardateDeno(i,(gingszacc[(3-j+i)%4][1])>>(10+bitshift));
				}
			}
		}
		if (bartholemew->isQueenPresent()) {
			STEREOGING(TRINGING(GINGFADEFORE),stereo_acc,ginging[bartholemew->getFocius1()])
			STEREOGING(TRINGING(GINGFADEFORE),stereo_acc,ginging[bartholemew->getFocius2()])	
		} else if (bartholemew->isKingPresent()) {
			STEREOGING(TRINGING(GINGFADEFORE),stereo_acc,ginging[bartholemew->getFocius1()])
		} else {
			FORI {
				STEREOGING(TRINGING(GINGFADEBARR),stereo_acc,ginging[i])
			}
		} return stereo_acc;
	}
	
	void charactros() { inhibit = !inhibit; }
	void setBitshift(int inn) {bitshift = inn;}
	int lippingMoutarde(MOUSEPOINT click) {
		if (!inhibit) {
			FORI {
				FORJ {
					if (POINTSINRECTALIS(click,rrrr_nk,i,j))
						RMLIPPER(1,numals[i][j]);
					if (POINTSINRECTALIS(click,rrrr_nq,i,j))
						RMLIPPER(-1,numals[i][j])
						if (POINTSINRECTALIS(click,rrrr_dk,i,j))
							RMLIPPER(-1,denals[i][j])
							if (POINTSINRECTALIS(click,rrrr_dq,i,j))
								RMLIPPER(1,denals[i][j])
								}
			}
		} return 0;
	}
};

