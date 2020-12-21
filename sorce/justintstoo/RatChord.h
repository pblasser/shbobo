
struct RatChord {
 Numba*nume;
 Numba*deno;
 RatChord*next;
 RatChord*prev;
 float technicalValue;
 
 RatChord(Numba*n,Numba*d) :
  nume(n), deno(d), next(0), prev(0) {
  technicalValue=(float)(nume->value)/
  (float)(deno->value);
 }

 void insert(RatChord *insertion) {
  if (!prev) {
   prev = insertion;
   insertion->next=this;
   return;
  }
  if (insertion->technicalValue<=prev->technicalValue) 
   prev->insert(insertion);
  else {
   insertion->prev=prev;
   prev->next=insertion;  
   prev=insertion;
   insertion->next=this;
  }
 }
 
 void ouster(RatChord*oustron) {
  if (!next) {
   next=oustron;
   oustron->prev=this;
   return;
  }
  if (oustron->technicalValue>=next->technicalValue)
   next->ouster(oustron);
  else {
   oustron->next=next;
   next->prev=oustron;
   next=oustron;
   oustron->prev=this;
  }
 }
  void prf() { printf("%d %d\n",nume->value,deno->value);}
 void draw(SDL_Renderer*r,int x, int y){
  //SDL_SetRenderDrawColor(r,rand(),rand(),rand(),255);
  //nume->drawNume(r,x,y);
  nume->drawDominoX(r,x,y,-1);
  //SDL_SetRenderDrawColor(r,rand(),rand(),rand(),255);
  //deno->drawDeno(r,x,y);
  deno->drawDominoX(r,x,y,1);
  
 }  
};