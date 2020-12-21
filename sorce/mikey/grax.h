
#define GL_GLEXT_PROTOTYPES
#define GLSL_BERNIE(src) "#version 150 core\n" #src
#define GLSL(src) GLSL_BERNIE(src)

#define GRAXDENO 4.0
const GLchar* chubeVert = GLSL(
 in vec3 position;
 out float zdepth;
 uniform vec3 chworl; // cos, sin, zoom
 uniform vec2 chtran; //xy transposition
 uniform vec2 chrosi;
 uniform vec2 chroco;
 uniform vec3 chbigg; //xyz bigness
 uniform vec3 chcolo; //rgb color
 uniform vec4 chtown; //rgb towne
 vec3 posi;
 void main() {
  posi = position*chbigg;///chworl.z;
  gl_Position.y = posi.y * chroco.x - posi.z * chrosi.x;
  gl_Position.z = posi.y * chrosi.x + posi.z * chroco.x;
  gl_Position.x = posi.x * chroco.y + gl_Position.z * chrosi.y;
  gl_Position.z = gl_Position.z * chroco.y - posi.x * chrosi.y;
  posi.xy = gl_Position.xy + chtran;
  gl_Position.x = posi.x * chworl.x - posi.y * chworl.y;
  gl_Position.y = posi.y * chworl.x + posi.x * chworl.y;
  gl_Position/=GRAXDENO;
  zdepth = gl_Position.z;
  gl_Position /= chworl.z;
  gl_Position.w = 1;
 });
 
const GLchar* chubeFrag = GLSL(
 in float zdepth;
 uniform vec3 chcolo; //rgb color
 uniform vec4 chtown; //rgb towne
 out vec4 outColor;
 void main() {
  vec3 town = vec3(chtown) * chtown.w;
  float fog; 
  fog = clamp(zdepth*0.01/chtown.w+1, 0.0, 1); 
  outColor = vec4(mix(chcolo,town,fog),1.0);
 });
const GLchar* towneVert = GLSL(
 in vec2 position;
 uniform vec3 toworl;// cos, sin, zoom
 uniform vec2 totran; //xy transposition
 uniform vec2 tobigg; //xyz bigness
 uniform vec4 tocolo; //rgb color
 vec2 posi;
 void main() {
  posi = position.xy*tobigg+totran;
  gl_Position.x = posi.x * toworl.x - posi.y * toworl.y;
  gl_Position.y = posi.y * toworl.x + posi.x * toworl.y;
  gl_Position /= GRAXDENO;
  //gl_Position.z = -9;
  gl_Position.w = toworl.z; 
  gl_Position/=gl_Position.w ;
  gl_Position.w =1;
  gl_Position.z = 0;
 });
const GLchar* towneFrag = GLSL(
 uniform vec4 tocolo;
 out vec4 outColor;
 void main() {
  outColor = tocolo*tocolo.a;
 });
void CheckStatus( GLuint obj )
{
 
    GLint status = GL_FALSE, len = 10;
    if( glIsShader(obj) )   glGetShaderiv( obj, GL_COMPILE_STATUS, &status );
    if( glIsProgram(obj) )  glGetProgramiv( obj, GL_LINK_STATUS, &status );
    if( status == GL_TRUE ) return;
    if( glIsShader(obj) )   glGetShaderiv( obj, GL_INFO_LOG_LENGTH, &len );
    if( glIsProgram(obj) )  glGetProgramiv( obj, GL_INFO_LOG_LENGTH, &len );
    std::vector< char > log( len, 'X' );
    if( glIsShader(obj) )   glGetShaderInfoLog( obj, len, NULL, &log[0] );
    if( glIsProgram(obj) )  glGetProgramInfoLog( obj, len, NULL, &log[0] );    
}
void shinit(GLsizeiptr szVert, GLfloat* ptVert, GLuint* vaosha, GLint stride, const GLchar* vert, const GLchar* frag) {
 printf("GL %s %s %s\n", 
  (char *)glGetString(GL_VENDOR), 
  (char *)glGetString(GL_RENDERER), 
  (char *)glGetString(GL_VERSION));
	glGenVertexArrays(1, &vaosha[0]);
 glBindVertexArray(vaosha[0]);
 GLuint vbo;
 glGenBuffers(1, &vbo);
 glBindBuffer(GL_ARRAY_BUFFER, vbo);
 glBufferData(GL_ARRAY_BUFFER, szVert, ptVert, GL_STATIC_DRAW);
 GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
 glShaderSource(vertexShader, 1, &vert, NULL);
 glCompileShader(vertexShader);
 CheckStatus( vertexShader );
 GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
 glShaderSource(fragmentShader, 1, &frag, NULL);
 glCompileShader(fragmentShader);
 CheckStatus( fragmentShader );
 vaosha[1] = glCreateProgram();
 glAttachShader(vaosha[1], vertexShader);
 glAttachShader(vaosha[1], fragmentShader);
 glBindFragDataLocation(vaosha[1], 0, "outColor");
 glLinkProgram(vaosha[1]);
 CheckStatus( vaosha[1] );
 glUseProgram(vaosha[1]);
 glEnable(GL_CULL_FACE);
 //glFrontFace(GL_CW);
 GLint posAttrib = glGetAttribLocation(vaosha[1], "position");
 glEnableVertexAttribArray(posAttrib);
 glVertexAttribPointer(posAttrib, stride, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), 0);
}



GLint chtran, chcolo, chbigg, chworl, chrosi, chroco, chtown;
GLint toworl, totran, tobigg, tocolo;
GLuint chvaosha[2];
GLuint tovaosha[2];

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 60;
SDL_Window *screen;
void grax() {
 SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
 screen = SDL_CreateWindow("Mikey Walker",SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
 SDL_GLContext glcontext = SDL_GL_CreateContext(screen);
 glEnable(GL_DEPTH_TEST);
 //glDepthFunc(GL_LESS);
 GLfloat flatlan[] = {
  -0.5, +0.5, -0.5, -0.5,
  +0.5, +0.5, +0.5, -0.5, 
 };
 //for (int i = 0; i < sizeof(flatlan)/sizeof(flatlan); i++) 
	//flatlan[i] = -flatlan[i];
 shinit(sizeof(flatlan), flatlan, tovaosha, 2, towneVert, towneFrag);
	totran =  glGetUniformLocation(tovaosha[1], "totran");
 tobigg =  glGetUniformLocation(tovaosha[1], "tobigg");
 toworl =  glGetUniformLocation(tovaosha[1], "toworl");
 tocolo =  glGetUniformLocation(tovaosha[1], "tocolo");
 GLfloat triadem[] = {
  -0.5, +0.5, 0,
		-0.5, -0.5, 0, -0.5, -0.5, +1, +0.5, -0.5, 0,
		+0.5, -0.5, +1, +0.5, +0.5, +1, -0.5, -0.5, +1,
		-0.5, +0.5, +1, -0.5, +0.5, 0, +0.5, +0.5, +1,
		+0.5, +0.5, 0, +0.5, -0.5, 0}; 
	for (int i = 0; i < sizeof(triadem)/sizeof(GLfloat); i++) 
	 triadem[i] = -triadem[i];
	shinit(sizeof(triadem), triadem, chvaosha, 3, chubeVert, chubeFrag);
	chtran =  glGetUniformLocation(chvaosha[1], "chtran");
 chbigg =  glGetUniformLocation(chvaosha[1], "chbigg");
 chworl =  glGetUniformLocation(chvaosha[1], "chworl");
 chcolo =  glGetUniformLocation(chvaosha[1], "chcolo");
 chroco =  glGetUniformLocation(chvaosha[1], "chroco");
 chrosi =  glGetUniformLocation(chvaosha[1], "chrosi");
 chtown =  glGetUniformLocation(chvaosha[1], "chtown"); 
}
