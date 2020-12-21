
#include <stdio.h>
#include <string.h>
//#include <ctype.h>
#include "Chub.h"
#include "_chubbing.c"

#include "../JuceLibraryCode/JuceHeader.h"


#include "Chubbalyzer.h"
#include "Chubagwonzer.h"

BorderSize<int> bsi;
BorderSize<int> gsi;

#include "Garcon.h"
Garcon * mastro;

#include "Atom.h"
#include "Recipe.h"
#include "Grub.h"
#include "Ecole.h"
GoneFishing * gf;

#include "Actions.h"
#include "Zelda.h"
#include "Julia.h"
//#include "Chain.h"
//ChainWin * cw;



#include "_constructing.c"
#include "_acting.c"
#include "_editing.c"
#include "_cursing.c"
#include "_mousing.c"
#include "_painting.c"
#include "_parzing.c"
#include "_printing.c"
#include "_resizing.c"
#include "_changing.c"
#include "_commanding.c"
//#include "_chubbing.c"
#include "_fishing.c"
#include "_filing.c"

class ShboboFish : public JUCEApplication {
public:
 
 ShboboFish(){}
 ~ShboboFish(){}
 void initialise (const String& commandLine) {
  //Julia::juliaz = Array <Julia* >();
  bsi = BorderSize<int>(0,8,0,8);
  gsi = BorderSize<int>(0,4,0,4);
  mastro = new Garcon();
  gf = new GoneFishing();
  //cw = new ChainWin();
  LookAndFeel::setDefaultLookAndFeel(mastro);
  Bloque::pathify();
  new Julia();
  new TooltipWindow();
//MenuBarModel::setMacMainMenu 	( mastro);
  //mastro->chooseFileToOpen();
 }
 void shutdown() {
  //jj = 0; //tt = 0;
 }
 const String getApplicationName() {
  return "Fish";
 }
 const String getApplicationVersion() {
  return ProjectInfo::versionString;
 }
 bool moreThanOneInstanceAllowed() {
  return false;
 }
    void anotherInstanceStarted (const String& commandLine) {
new Julia();
}
private:
};

START_JUCE_APPLICATION (ShboboFish)

