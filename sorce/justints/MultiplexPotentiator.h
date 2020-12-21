#pragma once
#include "AbstractChubEngine.h"
#include "ging.h"
#include "grax.h"
#include "chub.h"
#include "ChubberySituation.h"
#include "PerspexStabile.h"
//MISTER P, the POTENTIATOR
//sits at the top of the "original 
//application deliverable code".
//He interacts much with the library
//he inherits the AbstractChubEngine
//which is a callback class for
//ging grax and chub.
class MultiplexPotentiator {//:  public AbstractChubEngine {
private:
	int amt;
	int sr;
	int sterge[2];
	int oneatatime;
	int offset;
	
	ChubberySituation ** chubbies;
	PerspexStabile *peggy;
	HGRAXBRUSH MF[4];
	//char * buffer;
public:
	
	void init(){
		MF[0] = GRAXBRUSHWAND(200,0,0);
		MF[1] = GRAXBRUSHWAND(200, 200, 200);
		MF[2] = GRAXBRUSHWAND(200, 200, 0);
		MF[3] = GRAXBRUSHWAND(10, 10, 10);
		chubbies = new ChubberySituation*[16];
		FORI FORJ chubbies[i+(4*j)] = 0;
	}
	MultiplexPotentiator(PerspexStabile *p) {
		peggy = p;
		offset = 0;
		oneatatime = 0;
		init();
		chubbies[0] = new ChubberySituation(0,peggy,44);
		amt = 1;
		//harold = MAKECERCLE(64);
	}
	MultiplexPotentiator(MultiplexPotentiator * carbon, PerspexStabile *p) {
		peggy = p;
		offset = 0;
		oneatatime = 0;
		init();
		amt = carbon->chubamt();
		FORI FORJ if ((i+(j*4))<amt) chubbies[i+(j*4)] = carbon->chubdupe(i+(j*4));
	}
	~MultiplexPotentiator() {
		FORI FORJ chubdel();
		FORI GRAXBRUSHNIL(MF[i]);
		
	}

	void textorium_trigger(char * outus) { 
		FILE * filefish;
		filefish = fopen(outus,"w");
		if (filefish) {
			for (int i = 0; i < amt; i++) 
				if (chubbies[i]) {
					fprintf(filefish,"chubby %d\n",i);	
					chubbies[i]->text(filefish);
				}
			//fputs("donk\n",filefish);
			fclose(filefish);
		}
		printf("%s \n",outus); 
	}
	void textorium_script(char * innus) {
		FILE * filefish;
		filefish = fopen(innus,"r");
		if (filefish) {
  			long lSize;
  			char * buffer;
  			size_t result;
			fseek (filefish , 0 , SEEK_END);
			lSize = ftell (filefish);
			rewind (filefish);
  			buffer = (char*) malloc (sizeof(char)*lSize);
  			if (buffer) {
				
				result = fread (buffer,1,lSize,filefish);
  				char * pch;
 				//printf ("Splitting string into tokens:\n");
  				pch = strtok (buffer," \n\r");
				FORI FORJ chubdel(); //16 deletes
				FORI FORJ {
					if (pch) 	
					if (strncmp (pch,"chubby",6) == 0) {
						//printf("foundchubby\n");
						int chubby_plaz;
						pch = strtok(NULL," \n\r");
						chubby_plaz = chubadd();
						pch = chubbies[chubby_plaz]->textum();
					} 	
				}
				free (buffer);
			} fclose(filefish);
		}
	}
		
	
	void chubness(CHUBHANDLE h, CHUBREPORT r) {
		if (h) if (r.length > 5)
			if (oneatatime) {
				if (chubbies[offset])
					//if (chubbies[offset]->checkDevilio(h)) 
						chubbies[offset]->chubspon((signed char*)r.report);
			} else for (int i = 0; i < amt; i++) {
				if (chubbies[i])
					//if (chubbies[i]->checkDevilio(h)) 
						chubbies[i]->chubspon((signed char*)r.report);
			}
	}
	
	void chubadd(CHUBHANDLE h) {
		
		if(++amt <16) {
			chubbies[amt-1] = new ChubberySituation(h,peggy,44);
		} else amt = 15;
		if (amt) offset %= amt;
	}

	int chubadd() {
		
		if(++amt <16) {
			chubbies[amt-1] = new ChubberySituation(NULL, peggy, 44);
			if (amt) offset %= amt;
			return amt-1;
		} else amt = 15; return amt-1;
	}
	void chubdel() {
		if (--amt<0) 
			amt = 0;
		else {
			if (chubbies[offset])
				delete(chubbies[offset]);
			for (int dell=offset;dell<amt;dell++) 
				chubbies[dell]=chubbies[dell+1];
			chubbies[amt] = 0;
		}
		if (amt) offset %= amt;
	}
	int chubamt() {return amt;}

	ChubberySituation * chubdupe(int in) {
		if (chubbies[in])
			return new ChubberySituation(chubbies[in], peggy);
		else return 0;
	}
	void chubdupe() {
		if(amt>0)
			if (amt++ < 16) {
				int toWhere= (offset)%amt;
				int ins;
				ChubberySituation * oldus = chubbies[toWhere];
				if (chubbies[offset])
					chubbies[toWhere] = chubdupe(offset);
				for (ins = amt-1; ins>toWhere; ins--)
					chubbies[ins] = chubbies[ins-1];
				if (oldus) chubbies[ins] = oldus;
				//offset = toWhere;
		} else amt = 16;
		
	}

	void chubching(CHUBHANDLE * h, int a) {
		//delete your oldz first
		
		for (int hads = 0; hads < amt; hads++) {
			int yourdead = 1;
			if (chubbies[hads]) {
				for (int newz = 0; newz < a; newz++) {
					if (chubbies[hads]->checkDevilio(h[newz]))
						yourdead = 0;
				} 
				if (yourdead) {
					delete(chubbies[hads]);
					chubbies[hads] = 0;
				}
			}
		}
		
		for (int newz = 0; newz < a; newz++) {
			int lurkerdood = 1;
			for (int hads=0; hads<amt; hads++) {
				if (chubbies[hads])
					if (chubbies[hads]->checkDevilio(h[newz]))
						lurkerdood = 0;
			} if (lurkerdood) chubadd(h[newz]);
		}
		
		if (amt) offset %= amt;
	}
	
	void beging() {
		for (int i = 0; i < amt; i++) 
				if (chubbies[i]) 
					chubbies[i]->beging();
	}

	
	int * gingness(int ii, int bufflen) {
		int * acc;
		sterge[0] = sterge[1] = 0;
		if (oneatatime) {
			if (chubbies[offset]) {
				acc = chubbies[offset]->ging(ii,bufflen);
				sterge[0] += acc[0];
				sterge[1] += acc[1];
			}
		}
		else for (int i = 0; i < amt; i++) {
			if (chubbies[i]) {
				acc = chubbies[i]->ging(ii,bufflen);
				sterge[0] += acc[0];
				sterge[1] += acc[1];
			}
		} return sterge;
	}
	
	void graxness(CHDC chdc) {
		//GRAXSPRITER(chdc,harold,10,10)
		RECT rsz[4];
		int cxchub = chdc.cx>>2;
		FORI {
			rsz[i].left = i*cxchub;
			rsz[i].top = 0;
			rsz[i].right  = (i+1)*cxchub;
			rsz[i].bottom =  chdc.cy; 
			FILLRECT(chdc.hdc,MF[i],rsz[i])
		} 
		int yskittle = chdc.cy/(1+amt);
		if (oneatatime) {
			RECT parmbnus;
			parmbnus.left = 0;
			parmbnus.right = chdc.cx;
			parmbnus.top = 0;
			parmbnus.bottom = amt*yskittle;
			FILLRECT(chdc.hdc,MF[3],parmbnus)
		} for (int i = 0; i < amt; i++) 
			if (chubbies[(amt+offset-i-1)%amt])
				chubbies[(amt+offset-i-1)%amt]->draw(chdc, chdc.cx>>2, yskittle, i+1);
		
	}
	
	void mouseButt(MOUSEPOINT m) {
		
		for (int i = 0; i < amt; i++) 
		chubbies[i]->mouseButts(m)	;	
	}
	void charactros(unsigned char cc) {
		if (cc == '\r') chubadd(0);
		if (cc == ' ') {
			offset++;
			if (amt) offset %= amt;
		}
		if (cc == '/') oneatatime = !oneatatime;
		//	ChubChingLoop();
		if (cc == LIZARDBACK ) chubdel();
		if (oneatatime) 
			chubbies[offset]->charactros(cc);
		else for (int i = 0; i < amt; i++) 
			if (chubbies[i])
			chubbies[i]->charactros(cc);
	}
		
};


