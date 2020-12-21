

struct Recipe : Stub {
 Recipe();
 virtual bool visitInsert(Stub*s);
 //int getCumulopasty();
 virtual Recipe* cloner() {return nullptr; }//new Recipe(); }
 virtual Stub* clone() {
  Recipe * r = cloner();
  if (r==nullptr) return nullptr;
  int childro = getNumChildComponents ();
  for (int i = 0; i < childro; i++) {
   Stub* s = dynamic_cast<Stub*>(getChildComponent (i));
   r->addAndMakeVisible(s->clone());
  }
  childBoundsChanged(nullptr);
  return r;
 }
 Stub* reference() {
  Recipe * r = cloner();
  if (r==nullptr) return nullptr;
  int childro = getNumChildComponents ();
  if (childro>0) {
   Stub* s = dynamic_cast<Stub*>(getChildComponent (0));
   r->addAndMakeVisible(s->clone());
  }
  childBoundsChanged(nullptr);
  return r;
 }
 void dupEditoRef();
 void lookAndFeelChanged 	( 		) {
  int childro = getNumChildComponents ();
  if (childro<1) childBoundsChanged(0);
  repaint();
 }
 virtual void mouseDrag(const MouseEvent &evnt) {}
 virtual void itemDropped (const SourceDetails &sd) ;
 Recipe * parze(String&ss);
 String printe();
 
 virtual void chubber();
 virtual void chubber(Chubbalyzer*c);
 virtual void mouseDoubleClick(const MouseEvent &evnt);
 
 bool keyPressed (const KeyPress &key);

 //virtual ApplicationCommandTarget* getNextCommandTarget();
 
 void childBoundsChanged (Component* child);
 void childrenChanged ();
 bool isInterestedInDragSource (const SourceDetails &sd) {
  return true;
 }
 Colour getPastry(bool col) {
  uint8 hh = cumulopasty;
  uint8 green = (hh <= 128 ? hh : 256 - hh) + 126 + 1;
  if (col) return Colour::fromRGB((511-hh)>>1,green,(255+hh)>>1);
  else return Colour::fromRGB((511-hh)>>1,green,(255+hh)>>1).withMultipliedSaturation(0);
 }
 virtual void paint(Graphics&g);
};


struct Bloque : Recipe {
 enum tyub {
  _fish = 0,
  _soup = 1,
  _tank = 2,
  _boat = 3
 };
 Bloque() : Recipe() {
  mastro->registerAllCommandsForTarget(this);
  addKeyListener (mastro->getKeyMappings());
  childBoundsChanged(nullptr);
 }
 int type;
 static Path pathos[4];
 static Path fields[4];
 static String shapes[4];
 static void pathify();
 
 virtual void getAllCommands (Array <CommandID>& commands);
 virtual void getCommandInfo (CommandID commandID, ApplicationCommandInfo& result);
 virtual bool perform (const juce::ApplicationCommandTarget::InvocationInfo& info);
 
 virtual bool visitInsert(Stub*s);
 virtual void paint(Graphics&g);
 String printe();
 virtual void mouseDrag(const MouseEvent &evnt) {
  Stub::mouseDrag(evnt);
 }
 virtual void itemDropped (const SourceDetails &sd) ;
};

Path Bloque::pathos[4];
Path Bloque::fields[4];
String Bloque::shapes[4];

struct Fish : Bloque {
 Fish() : Bloque() { type=_fish; }
 Recipe * cloner() { return new Fish(); }
 virtual void chubber(Chubbalyzer*c);
};

struct Soup : Bloque {
 Soup() { type=_soup; }
 Recipe * cloner() { return new Soup(); }
 virtual void chubber(Chubbalyzer*c);
};

struct Tank : Bloque {
 Tank() { type=_tank; }
 Recipe * cloner() { return new Tank(); }
};

struct Boat : Bloque {
 Boat() { type=_boat; }
 Recipe * cloner() { return new Boat(); }
};




