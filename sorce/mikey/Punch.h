
struct Punch : Circo {
 Punch() {
  rad = 20;//siz = 10; 
 }
 void rendrar(Mikey& m) {  
  float sino, cosi, x, y;
  sino = sinf(PI+PI*m.rota/180.0f);
  cosi = cosf(PI+PI*m.rota/180.0f);
  glUniform1f(m.mm->micolo, 0.8);
  glUniform1f(m.mm->mibigg, rad );
  x = xloke-m.xloke;
  y = yloke-m.yloke;
  glUniform2f(m.mm->mitran, cosi*x-sino*y,cosi*y+sino*x);
  m.mm->bronk();
 } 
 void sounder(Mikey& m) {}
 void collide(Mikey& m) {}
};

struct Track : Circo {
 Punch left, rite;
 float dl,dr,ll, lr;
 float rol, ror, col,sil,cor,sir;
 void sounder(Mikey& m) {}
 void rendrar(Mikey& m) {
  left.rendrar(m);rite.rendrar(m);
 } 
 void collide(Mikey& m) {
  
  rad = m.siz + left.rad+ left.rad;
  
  xloke = m.xloke;
  yloke = m.yloke;
 //one way punch uses fmax
 //bring about the other toon hand?
//bring it back?
 // dl =  fmax(m.gwonz[1] -ll,0);
 // dr =  fmax(m.gwonz[2] -lr,0);

  dl =  (m.gwonz[1] -ll);
  dr =  (m.gwonz[2] -lr);

  ll = m.gwonz[1]; lr = m.gwonz[2];
  rol = m.gwonz[1]+m.rota;
  ror = m.gwonz[2]-m.rota;
  col = cos(PI-PI*(rol)/180.0f);
  sil = sin(PI-PI*(rol)/180.0f);
  cor = cos(PI*(ror)/180.0f);
  sir = sin(PI*(ror)/180.0f);
  float newrad = rad-rite.rad;
  left.xloke = m.xloke+ (float)newrad * col;
  left.yloke = m.yloke+(float)newrad* sil;
  rite.xloke = m.xloke+(float)newrad* cor;
  rite.yloke = m.yloke+(float)newrad* sir;
 }
};
