

struct Atom : public Component {};

struct Recipe;
struct Grub;

struct Stub : public Atom,
public DragAndDropTarget,
public HouseCommands,
public ApplicationCommandTarget
{
 //String metatext;
 bool fudge, scoot;
 bool lefty;
 int cumulopasty;
 Stub() ;
 virtual Stub * clone() { return new Stub(); }
 virtual bool visitInsert(Stub * s);
 
 virtual void bounds_visit(int&curxo,int&curyo,int&wido,int&hido);
 virtual void pastry_visit(Recipe & r);
 virtual void gruber_visit(Grub&g);
 
 virtual ApplicationCommandTarget* getNextCommandTarget();
 virtual void getAllCommands (Array <CommandID>& commands);
 virtual void getCommandInfo (CommandID commandID, ApplicationCommandInfo& result);
 virtual bool perform (const juce::ApplicationCommandTarget::InvocationInfo& info);
 
 void cutEdito();
 void copyEdito();
 void copyToClippo();
 void pasteEdito();
 void dupEdito();
 
 
 
 bool shouldDrawDragImageWhenOver(){return true;}
 static Stub * parze(String&ss);
 virtual int getCumulopasty() { return cumulopasty;}
 virtual String printe() {  return String();}
 void paint(Graphics &g);
 virtual void chubber(Chubbalyzer * c) {}
 bool dragon;
 void focusGained(FocusChangeType cause);
 void focusLost(FocusChangeType cause);
 void mouseDown(const MouseEvent &event);
 void mouseUp(const MouseEvent &event) ;
 virtual void mouseDrag(const MouseEvent &evnt) ;
 virtual void mouseDoubleClick(const MouseEvent &evnt) {}
 bool isInterestedInDragSource(const SourceDetails &sd) {return true;}
 void itemDragEnter (const SourceDetails &sd) {grabKeyboardFocus();}
 void itemDragMove (const SourceDetails &sd);
 void itemDragExit (const SourceDetails &sd);
 void itemDropped (const SourceDetails &sd);
 virtual void processString(const String&s){}
 bool keyPressed (const KeyPress &key);
};



struct GutsLabel
: public Label
{
 
 
 GutsLabel(const String &texto) :
 Label("",texto)
 {
  setEditable(true);
  setBorderSize(gsi);
  setGoodSize();
  setWantsKeyboardFocus(false);
 }
 void setGoodSize() {
  setSize(getWido(),getHido());
 }
 int getWido() {		
  Font f = LookAndFeel::getDefaultLookAndFeel().getLabelFont (*this);
  String s = getText(true);
  if (s=="") s = String(" ");
  return f.getStringWidth(s)+getBorderSize().getLeft()+getBorderSize().getRight();
 }
 int getHido() {
  Font f = LookAndFeel::getDefaultLookAndFeel 	().getLabelFont (*this);
  return f.getHeight()+getBorderSize().getTop()+getBorderSize().getBottom();//+10;
 }
 void lookAndFeelChanged 	( 		) {
  setBorderSize(gsi);
  setGoodSize();
 }
 void textEditorTextChanged (TextEditor &) ;
 void setText(const String &newText) {
  Label::setText(newText,dontSendNotification);
  setGoodSize();
 }
 String lastext;
 void editorShown (TextEditor* editorComponent) {
  lastext = getText();
 }
 void editorAboutToBeHidden(TextEditor * t);
};



struct Bubble : public Stub {
 GutsLabel gl;
 Bubble() : gl("") {
  setWantsKeyboardFocus(true);
 }
 Bubble(const String& t) : Bubble() {
  gl.setName("b");
  addAndMakeVisible (&gl);
  processString(t);
  
 }

 virtual void bounds_visit(int&curxo,int&curyo,int&wido,int&hido);
 virtual void pastry_visit(Recipe & r);
 virtual void gruber_visit(Grub&g);
 
 virtual Stub * clone() {
  return new Bubble(gl.getText());
 }
 String printe();
 void paint(Graphics &g);
 void childBoundsChanged (Component* child);
 virtual void processString(const String&s){
  gl.setText(s);
  childBoundsChanged(0);
  
 }
 bool keyPressed (const KeyPress &key);
};



struct Guts : public Bubble {
 Guts(const String& t) : Bubble() {
  gl.setName("g");
  //gl.addMouseListener(this, true);
  addAndMakeVisible (&gl);
  processString(t);
 }
 Guts() : Bubble()  {
  gl.setName("g");
  //gl.addMouseListener(this, true);
  addAndMakeVisible (&gl);
  int spoon = rand() % 255 - 128;
  processString(String(spoon));
  
  
 }
 virtual Stub * clone() {
  return new Guts(gl.getText());
 }
 virtual void bounds_visit(int&curxo,int&curyo,int&wido,int&hido);
 virtual void pastry_visit(Recipe & r);
 virtual void gruber_visit(Grub&g);
 Atom * lookup();
 String printe();
 void paint(Graphics &g) ;
 void chubber(Chubbalyzer*c);
 void processString(const String&s);
 virtual void mouseDoubleClick(const MouseEvent &evnt);
};



