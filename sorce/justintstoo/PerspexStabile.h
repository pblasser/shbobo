
//PerspexStabile is hollow-form,
//yet it has exponential surface area
//in the form of quadrangularis,
//a doubly linked list of queenal gradation
//and the quid, a rigid "numerist"
//interpretation of all possible numes
//and denos.
//the form for a ratio is RatChord.
struct PerspexStabile {
	RatChord * quadrangularis;
	RatChord ** quid;
	Numba gyou[256];
 Limba quonks[256];
 //RoyalMoutarde dinks[16];
	Prime * primes;
 int strittle;
	//HGRAXBRUSH MarylandAnnex[256];
	//HGRAXBRUSH CardinalAccent;
	//quadrangularis is the "lyst-pointer", 
	//as in the sense that it points to 1/1
	//then quid is s'posed to be a quad format
	//i.e. an array of an array
	//brings up an interesting question,
	//can anyone explain how to implement:
	//RatChord *** quidquid? i.e. tripple pointr



PerspexStabile(): strittle(16) {
		primes = gimmeTruth(URPRIMLIM, URPRIMLIM, 0);
		makeNumbarz();
  printf("numbarz\n");
  
  makeQuonkz();
printf("quonkz\n");
		quid =  new RatChord*[URPRIMLIM*URPRIMLIM];
		quadrangularis = new RatChord(&gyou[0],&gyou[0]);
		RatChord * oldPrincipal = quadrangularis;//[0][0];
		RatChord * oldUndertown = quadrangularis;//[0][0];
		for (int i = 0; i < 256; i++) {
			//creating both the quadrangularis organoform
			//as well as the quid array of array quad;
			//the dialect here is of Baron von Depressus.
			RatChord * principal_hvarmonik = 
    new RatChord(&gyou[i], &gyou[0]);
			quid[i*256] = principal_hvarmonik;
			oldPrincipal->ouster(principal_hvarmonik);
			oldPrincipal = principal_hvarmonik;
			oldUndertown = principal_hvarmonik;
			for (int j = 1; j<256; j++) {
				RatChord * underbourg_piez = 
     new RatChord(&gyou[i],&gyou[j]);
				oldUndertown->insert(underbourg_piez);
				oldUndertown = underbourg_piez;
				quid[i*256+j] = underbourg_piez;
			} 
		}
	}

 	void PerspexStabilee() {
  delete (primes);
  for (int i = 0; i < 256; i++) 
   for (int j = 0; j < 256; j++) 
    delete(quid[i*256+j]);
 }
 
 
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

	Multaple * computeMultnas(int v, Multaple * m, Prime * strng){
		int p = 1;
  if (!strng || v < 2) return m;
		if (strng) p = strng->value;
		Multaple * mm = m;
		if ((v % p) == 0) {
			if (m && (m->valence == strng)) {
				if(m->increment()) {
     printf("killdhjeree");
     delete(m);
     return 0;
    }
			} else mm = new Multaple(strng, m);
			return computeMultnas(v/p,mm,strng);
		} else return computeMultnas(v, m, strng->tail);
	}

 
 void makeQuonkz() {
  int placz = 0;
  int p = 1;
  while (placz<URPRIMLIM) {
   Multaple * m = computeMultnas(p,0,primes);
   if (m) {
    if (m->tail==0) delete(m);
   //swweerlord!@ else if (m->tail->tail==0) delete(m);
    else {
     printf("p%d,%d ",placz,p);
     m->prf();
     printf("\n");
     //quonks[placz]=new Limba();
     quonks[placz].value=p;
     quonks[placz++].multna=m;
    }
   }
   p = p+2;
   
  }
 }
 
	void makeNumbarz() { //call first!
		for (int i = 0; i < URPRIMLIM; i++) {
			gyou[i].value = (i<1?1:i);
   gyou[i].multna = computeMultnas(i,0,primes);
  }
 }
 
 void paint(SDL_Renderer*rn,int x,int y) {
  quonks[3].drawDominoX(rn,x,y);
 }
	void init(SDL_Renderer*rn) {
  for (int i = 0; i < URPRIMLIM; i++) 
   gyou[i].init(rn);
  for (int i = 0; i < URPRIMLIM; i++)
   quonks[i].init(rn);
  RoyalMoutarde::init(rn);
 }
 
		#define LIMRAP(x) (x%URPRIMLIM)
 Numba * getNumba(int i) {
		return &gyou[LIMRAP(i)];
	}

 RatChord * getQuadrangularis() {
		return quadrangularis;
	}

	RatChord * getQuid(int n, int d) {
		n = LIMRAP(n)*URPRIMLIM;//n %= URPRIMLIM;
		d = LIMRAP(d);// %= URPRIMLIM;
		//if (n < 1) n = 1;
		//if (d < 1) d = 1;
		return quid[n+d];
	}
 RatChord * kingalNume(RatChord*r,int n) {
  if (r==0) return 0;
  if (n==0) return 0;
  int curs = r->nume->value;
  int newt = curs+n;
  if (newt<0) newt=URPRIMLIM-((-newt)%URPRIMLIM);
  Numba * num = 0;
  while (curs!=newt) {
   Numba * numn = getNumba(curs);
   if (Multaple::compare(numn->multna, quonks[3].multna)) num=numn;
   curs+=(curs<newt?1:-1);
  } 
  if (num) return getQuid(num->value,r->deno->value);
  return 0;
 }
 RatChord * kingalDeno(RatChord*r,int n) {
  if (r==0) return 0;
  if (n==0) return 0;
  int curs = r->deno->value;
  int newt = curs+n;
  if (newt<0) newt=URPRIMLIM-((-newt)%URPRIMLIM);
  Numba * num = 0;
  while (curs!=newt) {
   Numba * numn = getNumba(curs);
   if (Multaple::compare(numn->multna, quonks[2].multna)) num=numn;
   curs+=(curs<newt?1:-1);
  } 
  if (num) return getQuid(r->nume->value,num->value);
  return 0;
 }
 RatChord * queenalis(RatChord*r,int n) {
  if (r==0) return 0;
  if (n==0) return 0;
  RatChord * curs=r;
  RatChord * begg=0;
  while (n!=0) {
   if (n>0) {
    if (curs->next==0) 
     return curs;
    n--;curs=curs->next;
   }
   else {
    if (curs->prev==0) 
     return curs;
    n++; curs=curs->prev;
   }
   
   if (Multaple::compare(curs->nume->multna, quonks[2].multna) && Multaple::compare(curs->deno->multna, quonks[2].multna)) begg=curs;
  } 
  if (begg) return begg;
  return 0;
 }
	
	Prime * getTruth() { return primes; }
};

