
struct Mikosphere {
 struct Point {
  float x,y,z;
  Point(float xx,float yy, float zz) {
   x=xx;y=yy;z=zz;
  }
  Point(const Point& a){
   x = a.x; y = a.y; z = a.z;
   float length = sqrt(x*x+y*y+z*z);
   x/=length;y/=length;z/=length;
  }
  Point() {}
  Point(const Point& a, const Point& b) {
   x = (a.x + b.x) / 2.0;
   y = (a.y + b.y) / 2.0;
   z = (a.z + b.z) / 2.0;
   float length = sqrt(x*x+y*y+z*z);
   x/=length;y/=length;z/=length;
  }
  void print(std::vector<float> & f) { 
   f.push_back(x);
   f.push_back(y);
   f.push_back(z);
  }
 };
 std::vector<Point> pts;
 struct Triangle {
  Point v1,v2,v3;
  Triangle (std::vector<Point>& pts,int x,int y, int z){
   v1=pts[x];v2=pts[y];v3=pts[z];
  }
  Triangle (const Point&x,const Point&y,const Point&z) {
   v1=x;v2=y;v3=z;
  }
  void print(std::vector<float>& f) { 
   v1.print(f);
   v2.print(f);
   v3.print(f); 
  }
  bool hyper() {
   if ((v1.z < 0) || (v2.z < 0) || (v3.z < 0))
    return false;
   return true;
  }
 };
 std::vector<Triangle> trs;
 std::vector<Triangle> trz;
 std::vector<float> finalis;
 
 
 const GLchar* mikeyVert = GLSL(
  in vec3 position;
 uniform vec2 mitran;
 uniform float micolo;
 //uniform float miroto;
 uniform float miworl; // zoom of world
 uniform float mibigg; //xyz bigness
 uniform vec4 mitown; //rgb towne
 out vec3 colorius;
 out float zdepth;
 vec3 posi;
 int poop;
 void main() {
  colorius = vec3(0);
  poop = int(mod(gl_VertexID,3));
  colorius[poop] = 1.0;
  gl_Position = vec4(position*mibigg+vec3(mitran,0),1);
  gl_Position /= GRAXDENO;
  zdepth = -gl_Position.z;
  gl_Position /= -miworl; 
  gl_Position.w = 1;
 }
);

const GLchar* mikeyFrag = GLSL(
 uniform float micolo;
 uniform vec4 mitown; //rgb towne
 out vec4 outColor;
 in vec3 colorius;
 in float zdepth;
 void main() {
  float mikeglow = max(max(colorius.r, colorius.b), colorius.g);
  mikeglow *=  3;
  mikeglow -= 1;
  mikeglow /= 2;
  mikeglow = clamp(mikeglow*0.1+micolo,0,1);
  
  vec3 town = vec3(mitown) * mitown.w;
  float fog; 
  fog = clamp(zdepth*0.02/mitown.w+1, 0.0, 1); 
  outColor = vec4(mix(vec3(mikeglow),town,fog),1.0);
  

 });  
  
 GLuint mivbo, mivao;
 GLuint misha;
 GLint mitran, miworl, mibigg, mitown, micolo;
 GLuint mivaosha[2];
 Mikosphere() {
  float t = (1.0 + sqrt(5.0)) / 2.0;
  pts.push_back(Point(-1,  t,  0));
  pts.push_back(Point( 1,  t,  0));
  pts.push_back(Point(-1, -t,  0));
  pts.push_back(Point( 1, -t,  0));
  pts.push_back(Point( 0, -1,  t));
  pts.push_back(Point( 0,  1,  t));
  pts.push_back(Point( 0, -1, -t));
  pts.push_back(Point( 0,  1, -t));
  pts.push_back(Point( t,  0, -1));
  pts.push_back(Point( t,  0,  1));
  pts.push_back(Point(-t,  0, -1));
  pts.push_back(Point(-t,  0,  1));
  trs.push_back(Triangle(pts,0, 11, 5));
  trs.push_back(Triangle(pts,0, 5, 1));
  trs.push_back(Triangle(pts,0, 1, 7));
  trs.push_back(Triangle(pts,0, 7, 10));
  trs.push_back(Triangle(pts,0, 10, 11));

  // 5 adjacent faces 
  trs.push_back(Triangle(pts,1, 5, 9));
  trs.push_back(Triangle(pts,5, 11, 4));
  trs.push_back(Triangle(pts,11, 10, 2));
  trs.push_back(Triangle(pts,10, 7, 6));
  trs.push_back(Triangle(pts,7, 1, 8));

  // 5 faces around point 3
  trs.push_back(Triangle(pts,3, 9, 4));
  trs.push_back(Triangle(pts,3, 4, 2));
  trs.push_back(Triangle(pts,3, 2, 6));
  trs.push_back(Triangle(pts,3, 6, 8));
  trs.push_back(Triangle(pts,3, 8, 9));

  // 5 adjacent faces 
  trs.push_back(Triangle(pts,4, 9, 5));
  trs.push_back(Triangle(pts,2, 4, 11));
  trs.push_back(Triangle(pts,6, 2, 10));
  trs.push_back(Triangle(pts,8, 6, 7));
  trs.push_back(Triangle(pts,9, 8, 1)); 
  for (std::vector<Triangle>::iterator it = trs.begin() ; it != trs.end(); ++it) {
   Point a = Point(it->v1, it->v2);
   Point b = Point(it->v2, it->v3);
   Point c = Point(it->v3, it->v1);
   Triangle t = Triangle(it->v1, a, c);
   if (t.hyper()) trz.push_back(t);
   Triangle u = Triangle(it->v2, b, a);
   if (u.hyper()) trz.push_back(u);
   Triangle v = Triangle(it->v3, c, b);
   if (v.hyper()) trz.push_back(v);
   Triangle w = Triangle(a, b, c);
   if (w.hyper()) trz.push_back(w);
  } 
  for (std::vector<Triangle>::iterator it = trz.begin() ; it != trz.end(); ++it) 
   it->print(finalis);
  shinit(finalis.size()*sizeof(GLfloat), &finalis[0], mivaosha, 3, mikeyVert, mikeyFrag);
  mivao = mivaosha[0];
  misha = mivaosha[1]; 
  mitran =  glGetUniformLocation(mivaosha[1], "mitran");
  micolo =  glGetUniformLocation(mivaosha[1], "micolo");
  miworl =  glGetUniformLocation(mivaosha[1], "miworl");
  mibigg =  glGetUniformLocation(mivaosha[1], "mibigg");
  mitown = glGetUniformLocation(mivaosha[1], "mitown");
 }
 void draw() {
  glBindVertexArray(mivaosha[0]);
  glUseProgram(mivaosha[1]);
  glUniform2f(mitran, 0,0);
  glUniform1f(micolo, 0);
  glUniform1f(miworl, 8);
  glUniform1f(mibigg, 10);
  glUniform4f(mitown, 0.2,0.1,0.1,1.0);
  glDrawArrays(GL_TRIANGLES,0,finalis.size()/3);   
           GLuint error = glGetError();
 if( error != GL_NO_ERROR ) printf( "durk!%d\n", error);
 }
 void bronk() {
  glDrawArrays(GL_TRIANGLES,0,finalis.size()/3);   
 }
};