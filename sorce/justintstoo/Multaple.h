

struct Multaple {
 Prime * valence;
 int occurance;
 Multaple * tail;
 int powerful;
 
 Multaple(Prime *v, Multaple *tel) : 
  valence(v), tail(tel), 
  occurance(1) {
   powerful=valence->value;
  }
 ~Multaple(){}// if (tail) delete(tail);}
 int increment() { 
  occurance++; 
  powerful*=valence->value;
  return 0;
  if (powerful>URPRIMLIM) return 1;
  return 0;
 }
 
 void prf() {
  printf("%d^^%d ",valence->value, occurance);
  if (tail) tail->prf();
 }  
 static int compare(Multaple*king,Multaple*quonk) {
  if (king==0) return 1;
  if (king->valence->value==2) return 1;
  if (quonk==0) return 0;
  if (king->valence->value>quonk->valence->value) 
   return 0;
  if (king->valence->value<quonk->valence->value)
   return compare(king,quonk->tail);
  if (king->valence->value==quonk->valence->value)
   return 1; 
  //if (king->occurance>quonk->occurance) return 0;
  return compare(king->tail,quonk->tail);
 }
 
 int drawHead(SDL_Renderer*r,int x, int y, int d){
  for (int i =0;i<occurance;i++)
   valence->headVisit(r,x,y+d*i*2, d);
  return valence->getValue()+occurance*2;
 }
};