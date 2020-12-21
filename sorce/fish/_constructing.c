
Garcon::Garcon() : sizico(4) {
 f = Font(16);
 sf = Font(8);
 currentBinar = File::nonexistent;
 currentFile = File::nonexistent;
 
 setApplicationCommandManagerToWatch(this);
 //addListener(this);
 Grub * saintePierre;
#define MEXPTOKE(a,b,c,d,e) \
for (int i = 0; i<e; i++) { \
saintePierre = new Grub(a,b,c,d+i,e); \
String sad = String(a); \
if (i>0)  \
sad = sad + String("abcdefgh")[i]; \
urmap[sad] = (Atom*) saintePierre; \
}
#define JEXPTOKE(a,b,c,d,e) \
for (int i = 0; i<e; i++) { \
saintePierre = new OrangeGrub(a,b,c,d+i,e); \
String sad = String(a); \
if (i>0)  \
sad = sad + String("abcdefgh")[i]; \
urmap[sad] = (Atom*) saintePierre; \
}
#include "juliaTokes.txt"
 saintePierre = new Grub("doubleclick","","",0,0);
 urmap[String("doubleclick")]=(Atom*)saintePierre;
 setDefaultLookAndFeel(this);
 zoomOutt();
}

Stub::Stub() : lefty(false), fudge(true), scoot(true), cumulopasty(0) {
 setWantsKeyboardFocus(true);
 mastro->registerAllCommandsForTarget(this);
 //setMouseClickGrabsKeyboardFocus(false);
  addKeyListener (mastro->getKeyMappings());
}

Recipe::Recipe()  {
 setWantsKeyboardFocus(true);

 childBoundsChanged(nullptr);
}

Julia::Julia() :  DocumentWindow ("Fish",
                                  Colours::lightgrey, DocumentWindow::allButtons,
                                  true) {
 juliaz.add(this);
 setResizable(true, true);
 mastro->registerAllCommandsForTarget(&jc);
 addKeyListener(mastro->getKeyMappings());
 setMenuBar(mastro);
 //m.setApplicationCommandManagerToWatch 	(mastro);
 setContentOwned(&jc,true);
 centreWithSize (400,400);
 setVisible (true);
 setFocusContainer 	( 	true	);
}

Julia::Julia(File f) :
 DocumentWindow ("Fish", Colours::lightgrey,
  DocumentWindow::allButtons, true) {
 juliaz.add(this);
 setResizable(true, true);
 mastro->registerAllCommandsForTarget(&jc);
 addKeyListener(mastro->getKeyMappings());
 setMenuBar(mastro);
 //m.setApplicationCommandManagerToWatch 	(mastro);
 setContentOwned(&jc,true);
 centreWithSize (400,400);
 setVisible (true);
 setFocusContainer 	( 	true	);
  printf("juliaconstruct\n");
  jc.openFileInEditor(f);
}