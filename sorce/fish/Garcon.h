
#include <map>


struct HouseCommands {
 enum CommandIDs {
  newPhile = 0x2000,newFromClip,
  openPhile, savePhile, saveAsPhile, printBouillabaisse,
  undoEdit, redoEdit,
  copyToClip,
  cutEdit, copyEdit, pasteEdit,
  dupEdit, dupEditRef,
  zoomIn, zoomOut,
  upLoad, upLoadTab, upLoadMatrix, gwonzify
 };
 
};


struct Atom;

class Garcon :
public UndoManager,
public ApplicationCommandManager,
public MenuBarModel,
public HouseCommands,
public LookAndFeel_V2
{
public:
 //Menu m;
 Font f;
 Font sf;
 File currentFile;
 File currentBinar;
 std::map<String,Atom*> urmap; 
 Atom * selected;
 Garcon();
 
 Font getLabelFont 	(Label & l) {
  if (l.getName()=="b") return f.italicised();//f.setItalic(true);
  return f;
 }
 const Font& getSubFont() {
  return sf;
 }
 int sizico;
 void zoomInn() {
  sizico++;
  f.setHeight(sizico*4);
  sf.setHeight(sizico*2);
  bsi = BorderSize<int>(0,sizico*2,0,sizico*2);
  gsi = BorderSize<int>(0,sizico,0,sizico);
 }
 void zoomOutt() {
  sizico = (sizico > 1 ? sizico-1 : 1);
  f.setHeight(sizico*4);
  sf.setHeight(sizico*2);
  bsi = BorderSize<int>(0,sizico*2,0,sizico*2);
  gsi = BorderSize<int>(0,sizico,0,sizico);
 }
 int getSubHeight() { return sf.getHeight(); }
 int getHeight() {
  return f.getHeight() +sf.getHeight();
 }
 
 Image mulbTILE;
 
 const Image& imago() {
  Image r(Image::RGB, 2, 2, true);
  int n = rand()%256;
  r.setPixelAt(1,1,Colour(n,n,0));//.withAlpha((float)0.25));
  n = rand()%256;
  r.setPixelAt(0,0,Colour(n,n,0));//.withAlpha((float)0.25));
  n = rand()%256;
  r.setPixelAt(0,1,Colour(n,n,0));//.withAlpha((float)0.25));
  n = rand()%256;
  r.setPixelAt(1,0,Colour(n,n,0));//.withAlpha((float)0.25));
  mulbTILE = r.rescaled(rand()%16+1,rand()%16+1,Graphics::lowResamplingQuality);
  return mulbTILE;
 }
 StringArray getMenuBarNames();
 PopupMenu getMenuForIndex (int menuIndex, const String&);
 void menuItemSelected(int menuItemID, int) {}
 void menuBarActivated(bool isActive) {}


 
   
 
};
