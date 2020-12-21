

struct Barre {
 Gambit g[4];
 Barre() {
  FORI g[i].others=g;
 }
 void resized(int x, int y) {
  FORI g[i].resized(x,(i*(y>>2))+(y>>3));
 }
 void random() {
  //for (int i = 0; i < 32; i++)
  // g[i].random();
 }
 void ging(int * a, int ind, int len) {
  FORI g[i].ging(a, ind, len);
 }


 bool collide(signed char * gwonz) {
  //bool truth = 
  g[0].collide(gwonz[2]) ;
  g[1].collide(gwonz[0]);
  g[2].collide(gwonz[1]) ;
  g[3].collide(gwonz[3]); 
  return true;
  //return g[0].collide(gwonz[2]) && g[1].collide(gwonz[0]) &&
  // g[2].collide(gwonz[1]) && g[3].collide(gwonz[3]);
 }
 bool collide() {
  return g[0].collide() && g[1].collide() && 
   g[2].collide() && g[3].collide();
 }
 
 void prepaint(SDL_Renderer * rn) {
  FORI g[i].prepaint(rn);
 }
 void paint(SDL_Renderer * rn) {
  FORI g[i].paint(rn);
 }
};