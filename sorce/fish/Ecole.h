

#include <map>

class Ecole : public Component, public DragAndDropContainer {
// std::map<String,Skul*> mymap;
// std::map<int,Skul*> urmap;
 
public:
 Ecole() :  Component() {
  setSize(100,400);
  Grub * saintePierre;
#define MEXPTOKE(a,b,c,d,e) \
saintePierre = new Grub(a,b,c,d,e); \
addAndMakeVisible(saintePierre);

#define JEXPTOKE(a,b,c,d,e) \
saintePierre = new OrangeGrub(a,b,c,d,e); \
addAndMakeVisible(saintePierre);
  
#include "juliaTokes.txt"
 }
 void childrenChanged () {
  int childro = getNumChildComponents ();
  int wido = 0;
  int hido = 0;
  for (int i = 0; i < childro; i++) {
   Component* c = getChildComponent (i);
   if (hido > getHeight() - 20) {
    wido += 100; hido = 0;
   } c->setTopLeftPosition(wido,hido);
   hido += c->getHeight();
  }
 }
 void resized () { childrenChanged (); }
};

Ecole * standardo;

class GoneFishing : public ResizableWindow {
public:
 GoneFishing() : ResizableWindow("Toolbar",false) {
  Component::addToDesktop (getDesktopWindowStyleFlags());
  setResizable(true, true);
  standardo = new Ecole();
  standardo->addMouseListener(this,0);
  setContentNonOwned(standardo,true);
  centreWithSize (100,400);
  setVisible (true);
  
 }
 int getDesktopWindowStyleFlags() const {
  return ComponentPeer::windowIsResizable;
 }
 
 //BorderSize<int> getContentComponentBorder () {
 // return BorderSize<int>(20,20,20,20); }
// BorderSize<int> getBorderThickness () {
//  return BorderSize<int>(20,20,20,20); }
};
