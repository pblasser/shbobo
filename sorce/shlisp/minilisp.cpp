// This software is in the public domain.

#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef BILLGATES
#include <unistd.h>
#endif
#include "chub.h" 
#include "situations.h"

enum {
	TINT=0,
    TSYMBOL,
    TPRIMITIVE,
    TFUNCTION,
    TSPECIAL,
    TENV,
    
	TFISH,
	TSOUP,
	TTANK,
	TBOAT

};

// Subtypes for TSPECIAL
enum {
    TNIL = 1,
    TDOT,
    TCPAREN,
    TTRUE,
};

struct Obj;

// Typedef for the primitive function.
typedef struct Obj *Primitive(struct Obj *env, struct Obj *args);

// The object type
typedef struct Obj {
    // The first word of the object represents the type of the object. Any code that handles object
    // needs to check its type first, then access the following union members.
    int type;

    // Object values.
    union {
        // Int
        int value;
        // Cell
        struct {
            struct Obj *car;
            struct Obj *cdr;
            //for tank struct Obj *env;
        };
        // Symbol
        char name[1];
        // Primitive
        Primitive *fn;
        // Function or Macro
        struct {
            struct Obj *params;
            struct Obj *body;
            struct Obj *env;
        };
        // Subtype for special type
        int subtype;
        // Environment frame. This is a linked list of association lists
        // containing the mapping from symbols to their value.
        struct {
            struct Obj *vars;
            struct Obj *up;
        };
    };
} Obj;

// Constants
//static Obj *Nil;
#define Nil 0
static Obj *Dot;
static Obj *Cparen;
static Obj *True;

// The list containing all symbols. Such data structure is traditionally called the "obarray", but I
// avoid using it as a variable name as this is not an array but a list.
static Obj *Symbols;

static void error(const char *fmt, ...) ;//__attribute((noreturn));

//======================================================================
// Constructors
//======================================================================

static Obj *alloc(int type, size_t size) {
    // Add the size of the type tag.
    size += offsetof(Obj, value);

    // Allocate the object.
    Obj *obj = (Obj*)malloc(size);
    obj->type = type;
    return obj;
}

static Obj *make_int(int value) {
    Obj *r = alloc(TINT, sizeof(int));
    r->value = value;
    return r;
}

static Obj *make_symbol(const char *name) {
    Obj *sym = alloc(TSYMBOL, strlen(name) + 1);
    strcpy(sym->name, name);
    return sym;
}

static Obj *make_primitive(Primitive *fn) {
    Obj *r = alloc(TPRIMITIVE, sizeof(Primitive *));
    r->fn = fn;
    return r;
}

static Obj *make_function(Obj *params, Obj *body, Obj *env) {
    Obj *r = alloc(TFUNCTION, sizeof(Obj *) * 3);
    r->params = params;
    r->body = body;
    r->env = env;
    return r;
}

static Obj *make_special(int subtype) {
    Obj *r = (Obj*)malloc(sizeof(void *) * 2);
    r->type = TSPECIAL;
    r->subtype = subtype;
    return r;
}

struct Obj *make_env(Obj *vars, Obj *up) {
    Obj *r = alloc(TENV, sizeof(Obj *) * 2);
    r->vars = vars;
    r->up = up;
    return r;
}

static Obj *cons(int type, Obj *car, Obj *cdr) {
    Obj *cell = alloc(type, sizeof(Obj *) * 2);
    cell->car = car;
    cell->cdr = cdr;
    return cell;
}

static Obj *fish(Obj *car, Obj *cdr) {
    return cons(TFISH, car, cdr);
}
static Obj *soup(Obj *car, Obj *cdr) {
    return cons(TSOUP, car, cdr);
}
static Obj *tank(Obj *car, Obj *cdr) {
    return cons(TTANK, car, cdr);
}
static Obj *boat(Obj *car, Obj *cdr) {
    return cons(TBOAT, car, cdr);
}

// Returns ((x . y) . a)
static Obj *acons(Obj *x, Obj *y, Obj *a) {
    return tank(tank(x, y), a);
}
//parser
static Obj *read(void);

static void error(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    exit(1);
}

static int peek(void) {
    int c = getchar();
    ungetc(c, stdin);
    return c;
}

// Skips the input until newline is found. Newline is one of \r, \r\n or \n.
static void skip_line(void) {
    for (;;) {
        int c = getchar();
       
        if (c == EOF || c == '\n')
            return;
        if (c == '\r') {
            if (peek() == '\n')
                getchar();
            return;
        }
    }
}

// Reads a list. Note that '(' has already been read.
static Obj *read_list(int type) {
    Obj *obj = read();
    if (obj==0) //return 0;
        error("Unclosed parenthesis");
    if (obj == Dot)
        error("Stray dot");
    if (obj == Cparen)
        return cons(type,0,0);
    Obj *head, *tail;
    head = tail = cons(type,obj,0);

    for (;;) {
        Obj *obj = read();
//        if (!obj)
			
 //           return 0;//error("Unclosed parenthesis");
        if (obj == Cparen)
            return head;
        if (obj == Dot) {
            tail->cdr = read();
            if (read() != Cparen)
                error("Closed parenthesis expected after dot");
            return head;
        }
        if (obj) tail->cdr = cons(type,obj,0);
        else tail->cdr = cons(type,0,0);
        tail = tail->cdr;
    }
}

// May create a new symbol. If there's a symbol with the same name, it will not create a new symbol
// but return the existing one.
static Obj *intern(const char *name) {
    for (Obj *p = Symbols; p; p = p->cdr)
        if (strcmp(name, p->car->name) == 0)
            return p->car;
    Obj *sym = make_symbol(name);
    Symbols = tank(sym, Symbols);
    return sym;
}

static int read_number(int val) {
    while (isdigit(peek()))
        val = val * 10 + (getchar() - '0');
    return val;
}

#define SYMBOL_MAX_LEN 200

static Obj *read_symbol(char c) {
    char buf[SYMBOL_MAX_LEN + 1];
    int len = 1;
    buf[0] = c;
    while (isalnum(peek()) || peek() == '-') {
        if (SYMBOL_MAX_LEN <= len)
            error("Symbol name too long");
        buf[len++] = getchar();
    }
    buf[len] = '\0';
    return intern(buf);
}

int looper = 1;
static Obj *read(void) {
    for (;;) {
        int c = getchar();
        //printf("char%c\n",c);
        if (c == ' ' || c == '\n' || c == '\r' || c == '\t')
            continue;
        if (c == EOF) {
           looper = 0;
            return 0;
		}
        if (c == ';') {
            skip_line();
            continue;
        }
        if (c == '(')
            return read_list(TFISH);
        if (c == '{')
            return read_list(TSOUP);
        if (c == '[')
            return read_list(TTANK);
        if (c == '<')
            return read_list(TBOAT);
        if (c == ')' || c == '}' || c == ']' || c == '>')
            return Cparen;
        if (c == '.')
            return Dot;
        if (isdigit(c))
            return make_int(read_number(c - '0'));
        if (c == '-')
            return make_int(-read_number(0));
        if (isalpha(c) || strchr("+=!@#$%^&*", c))
            return read_symbol(c);
        error("Don't know how to handle %c", c);
    }
}

static void print(Obj*env,Obj*obj);
static void gutsprinter(const char* s,const char*e,Obj*env,Obj *obj) {
	    printf(s);
        for (;;) {
			if (obj->car == 0) break;
            print(env,obj->car);
            if (obj->cdr == 0)
                break;
            if (obj->cdr->type < TFISH) {
                printf(" . ");
                print(env,obj->cdr);
                break;
            }
            printf(" ");
            obj = obj->cdr;
        }
        printf(e);
       }
	
static Obj *eval(Obj*env,Obj*obj);	
// Prints the given object.
//needs symbolprinter/byter
static void print(Obj * env, Obj *obj) {
	if (obj==0) {
		printf("<>");return;}
    switch (obj->type) {
    case TINT:
     insituate(obj->value);
        printf("%d", obj->value);
        return;
    case TFISH:
     insituate(0xFF);
     gutsprinter("(",")",env,obj);
     insituate(0);
     return;
    case TSOUP:
     situatier();
     gutsprinter("{","}",env,obj);
     situatend();
     insituate(0);
     return;
    case TTANK:
        gutsprinter("[","]",env,obj);
        return;
    case TBOAT:
		print(env, eval(env, obj));
        //gutsprinter("<",">",obj);
        return;
    case TSYMBOL:
     print(env, eval(env, obj));
        //printf("%s", obj->name);
        return;
    case TPRIMITIVE:
        printf("<primitive>");
        return;
    case TFUNCTION:
        printf("<function>");
        return;
    case TSPECIAL:
        if (obj == Nil)
            printf("()");
        else if (obj == True)
            printf("t");
        else
            error("Bug: print: Unknown subtype: %d", obj->subtype);
        return;
    default:
        error("Bug: print: Unknown tag type: %d", obj->type);
    }
}

static int list_length(Obj *list) {
    int len = 0;
    for (;;) {
        if (list == 0)
            return len;
        if (list->car == 0) return len;
        if (list->type < TFISH)
            error("length: cannot handle dotted list");
        list = list->cdr;
        len++;
    }
}

//======================================================================
// Evaluator
//======================================================================

static Obj *eval(Obj *env, Obj *obj);

static void add_variable(Obj *env, Obj *sym, Obj *val) {
    env->vars = acons(sym, val, env->vars);
}

// Returns a newly created environment frame.
static Obj *push_env(Obj *env, Obj *vars, Obj *values) {
    if (list_length(vars) != list_length(values))
        error("Cannot apply function: number of argument does not match");
    if (list_length(vars)==0) return env;
    Obj *map = 0;
    for (Obj *p = vars, *q = values; p != 0; p = p->cdr, q = q->cdr) {
        Obj *sym = p->car;
        Obj *val = q->car;
        map = acons(sym, val, map);
    }
    return make_env(map, env);
}

// Evaluates the list elements from head and returns the last return value.
static Obj *progn(Obj *env, Obj *list) {
    Obj *r = 0;
    for (Obj *lp = list; lp; lp = lp->cdr)
        r = eval(env, lp->car);
    return r;
}

// Evaluates all the list elements and returns their return values as a new list.
static Obj *eval_list(Obj *env, Obj *list) {
    Obj *head = 0;
    Obj *tail = 0;
    for (Obj *lp = list; lp; lp = lp->cdr) {
        Obj *tmp = eval(env, lp->car);
        if (head == 0) {
            head = tail = cons(list->type,tmp, 0);
        } else {
            tail->cdr = cons(list->type,tmp, 0);
            tail = tail->cdr;
        }
    }
    if (head == 0)
        return 0;
    return head;
}

static bool is_list(Obj *obj) {
  return obj == 0 || obj->type >= TFISH;
}

// Apply fn with args.
static Obj *apply(Obj *env, Obj *fn, Obj *args) {
	//if (args==0) return 0;
    if (!is_list(args))
        error("argument must be a list");
    if (fn->type == TPRIMITIVE)
    //printf("inside apply\n");
        return fn->fn(env, args);
    if (fn->type == TFUNCTION) {
        Obj *body = fn->body;
        Obj *params = fn->params;
        Obj *eargs = eval_list(env, args);
        Obj *newenv = push_env(fn->env, params, eargs);
        
        return progn(newenv, body);
    }
    error("not supported");
}

// Searches for a variable by symbol. Returns null if not found.
static Obj *find(Obj *env, Obj *sym) {
    for (Obj *p = env; p; p = p->up) {
        for (Obj *cell = p->vars; cell != Nil; cell = cell->cdr) {
            Obj *bind = cell->car;
            if (sym == bind->car)
                return bind;
        }
    }
    return 0;
}

static Obj *eval(Obj *env, Obj *obj) {
	if (obj==0) return 0;
    switch (obj->type) {
    case TINT:
    case TPRIMITIVE:
    case TFUNCTION:
    case TSPECIAL:
    case TTANK:
    case TFISH:
    case TSOUP:
        // Self-evaluating objects
        return obj;
    case TSYMBOL: {
        // Variable
        Obj *bind = find(env, obj);
        if (!bind)
            error("Undefined symbol: %s", obj->name);
        return bind->cdr;
    }
    case TBOAT: {        
		Obj *fn = eval(env, obj->car);
		if (fn==0) return 0;
        Obj *args = obj->cdr;
        if (fn->type != TPRIMITIVE && fn->type != TFUNCTION)
            error("The head of a list must be a function");
            //printf(" to aply\n");
        return apply(env, fn, args);
    }
    default:
        error("Bug: eval: Unknown tag type: %d", obj->type);
    }
}


#define primmertypes(subn,tipe) \
 static Obj *prim_##subn(Obj *env, Obj *list) { \
    if (list_length(list) != 2) \
        error("Malformed #subn"); \
    Obj *cell = eval_list(env, list); \
    cell->cdr = cell->cdr->car; \
    cell->type = tipe; \
    return cell; \
}
primmertypes(fish, TFISH)
primmertypes(soup, TSOUP)
primmertypes(tank, TTANK)
primmertypes(boat, TBOAT)

static Obj *prim_car(Obj *env, Obj *list) {
    Obj *args = eval_list(env, list);
    if (args->car->type < TFISH || args->cdr )
        error("Malformed car");
    return args->car->car;
}

static Obj *prim_cdr(Obj *env, Obj *list) {
    Obj *args = eval_list(env, list);
    if (args->car->type < TFISH || args->cdr)
        error("Malformed cdr");
    return args->car->cdr;
}


static Obj *prim_fun(Obj *env, Obj *list) {
    if (list->type != TBOAT || !is_list(list->car) || list->cdr->type < TFISH)
        error("Malformed lambda");
    for (Obj *p = list->car; p; p = p->cdr) {
		if (p->car == 0) break;
        if (p->car->type != TSYMBOL)
            error("Parameter must be a symbol");
        if (!is_list(p->cdr))
            error("Parameter list is not a flat list");
    }
    Obj *car = list->car;
    Obj *cdr = list->cdr;
    return make_function(car, cdr, env);
}

static Obj *prim_def(Obj *env, Obj *list) {
    if (list_length(list) != 2 || list->car->type != TSYMBOL)
        error("Malformed setq");
    Obj *sym = list->car;
    Obj *value = eval(env, list->cdr->car);
    add_variable(env, sym, value);
    return 0;//value;
}

static Obj *prim_setq(Obj *env, Obj *list) {
    if (list_length(list) != 2 || list->car->type != TSYMBOL)
        error("Malformed setq");
    Obj *bind = find(env, list->car);
    if (!bind)
        error("Unbound variable %s", list->car->name);
    Obj *value = eval(env, list->cdr->car);
    bind->cdr = value;
    return value;
}

static Obj *prim_add(Obj *env, Obj *list) {
    int sum = 0;
    for (Obj *args = eval_list(env, list); args; args = args->cdr) {
        if (args->car->type != TINT)
            error("+ takes only numbers");
        sum += args->car->value;
    }
    return make_int(sum);
}

static Obj *prim_mul(Obj *env, Obj *list) {
    int sum = 1;
    for (Obj *args = eval_list(env, list); args; args = args->cdr) {
        if (args->car->type != TINT)
            error("* takes only numbers");
        sum *= args->car->value;
    }
    return make_int(sum);
}


static Obj *prim_rand(Obj *env, Obj *list) {
    int sum = rand();
    for (Obj *args = eval_list(env, list); args; args = args->cdr) {
        if (args->car->type != TINT)
            error("* takes only numbers");
        sum %= args->car->value;
    }
    return make_int(sum);
}



static Obj *prim_print(Obj *env, Obj *list) {
    print(env, eval(env, list->car));    
    return 0;
}

// (if expr expr expr ...)
static Obj *prim_if(Obj *env, Obj *list) {
    if (list_length(list) < 2)
        error("Malformed if");
    Obj *cond = eval(env, list->car);
    if (cond) {
        Obj *then = list->cdr->car;
        return eval(env, then);
    }
    Obj *els = list->cdr->cdr;
    return els == 0 ? 0 : progn(env, els);
}

// (= <integer> <integer>)
static Obj *prim_num_eq(Obj *env, Obj *list) {
    if (list_length(list) != 2)
        error("Malformed =");
    Obj *values = eval_list(env, list);
    Obj *x = values->car;
    Obj *y = values->cdr->car;
    if (x->type != TINT || y->type != TINT)
        error("= only takes numbers");
    return x->value == y->value ? True : 0;
}

// (exit)

static Obj *prim_exit(Obj *env, Obj *list) {
    looper = 0;//exit(0);
    return 0;
}

static void add_primitive(Obj *env, const char *name, Primitive *fn) {
    Obj *sym = intern(name);
    Obj *prim = make_primitive(fn);
    add_variable(env, sym, prim);
}

static void define_constants(Obj *env) {
    Obj *sym = intern("t");
    add_variable(env, sym, True);
}

static void define_grub(Obj * env, const char*s,int v, int ningle) {
 char toke[100];
 for (int i=0; i<ningle; i++){
  strcpy(toke,s);
  char c = 'a'+i;
  strncat(toke,&c,(i>0?1:0));
  //printf("%s\n",toke);
  add_variable(env,intern(toke),make_int(v+i));\
 }
}

 #define MEXPTOKE(s,f,ff,v,ningle) \
  define_grub(env,s,v,ningle);   
 #define JEXPTOKE(s,f,ff,v,ningle) \
  MEXPTOKE(s,f,ff,v,ningle)


 
static void define_primitives(Obj *env) {
	srand(time(0));
	#include "tokes.c"
    add_primitive(env, "fish", prim_fish);
    add_primitive(env, "soup", prim_soup);
    add_primitive(env, "tank", prim_tank);
    add_primitive(env, "boat", prim_boat);
    add_primitive(env, "car", prim_car);
    add_primitive(env, "cdr", prim_cdr);
    add_primitive(env, "+", prim_add);
    add_primitive(env, "*", prim_mul);
    add_primitive(env, "rand", prim_rand);
    add_primitive(env, "def", prim_def);
    add_primitive(env, "fun", prim_fun);
    add_primitive(env, "?", prim_if);
    add_primitive(env, "=", prim_num_eq);
    add_primitive(env, "print", prim_print);
    add_primitive(env, "exit", prim_exit);
}


void printar() {
#undef MEXPTOKE
#define MEXPTOKE(s,f,t,v,ningle) \
printf("%2x: %s %s: %s; %d pieces\n", v, s, f,t,ningle);
#undef JEXPTOKE
#define JEXPTOKE(s,f,ff,v,ningle) MEXPTOKE(s,f,ff,v,ningle)

  #include "tokes.c"
}
int simian;
void printarsimp() {
 simian = 8810202;
#undef MEXPTOKE
#define MEXPTOKE(s,f,t,v,ningle) \
if (simian!=v) \
 printf("%2x: %s %s: %s; %d pieces\n", v, s, f,t,ningle); //simian = v;
#undef JEXPTOKE
#define JEXPTOKE(s,f,ff,v,ningle) MEXPTOKE(s,f,ff,v,ningle)

  #include "tokes.c"
  
}



void pooler(Obj*env) {
      for (;looper;) {    
   Obj *expr = read();
   if (!expr) continue;
   if (expr == Cparen)
    error("Stray close parenthesis");
   if (expr == Dot)
    error("Stray dot");
   print(env,eval(env, expr));
   printf("\n");
   
  //situsb();
  }  
}


int main(int argc, char * argv[]) {
 Dot = make_special(TDOT);
 Cparen = make_special(TCPAREN);
 True = make_special(TTRUE);
 Symbols = 0;
 Obj *env = make_env(0, 0);
 define_constants(env);
 define_primitives(env);
 char * inputfile=0;
 chubOPEN();
 int offset=1;
 if ((argc > offset) && (argv[1][0] == '-')) {
	 if (argv[1][1] == 'h') {

		 printarsimp();return 0;}
    if (argv[1][1] == 'g') {
         chubRUN();return 0;}
	 if (argv[1][1] == 'z') {
		 printar();return 0;}
	 if (argv[1][1] == 'b') {
		 inputfile = strdup(argv[1]+2);
         offset=2;
     }
 } 
 //printf("here\n");
 if (argc > offset) {
  char * texte = strdup(argv[offset]);
  printf("opening %s\n",texte);
  freopen(texte,"r",stdin);
 }
 pooler(env); 
 situsb();
  
 if (inputfile) {
  FILE * filefish;
  filefish = fopen(inputfile,"rb");
  if (filefish) {
   while (masterbytesz < 0x10000)
    write_bytez(0);
   int c;
   if (0 == fseek (filefish , 0x20000 , SEEK_SET)) {
    c = fgetc (filefish);
    while (c != EOF) {  
     //if (masterbytesz < 195600)
     write_bytez((unsigned char)c);
     c = fgetc (filefish); 
    } 
   }
  //fclose(filefish);
  }
 }  
 int j;
 for (j = 0; j < 16; j++)
 write_bytez(0);
 chubSENDEND();//bytebuff,1);
 printf("\n");
}
