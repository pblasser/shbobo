

struct Grub : public Atom, public TooltipClient {
 String skull;
 String toolt;
 StringArray args;
 int basenum;
 int limitor;
 int iter;
 
 Grub(String sk, String ar, String tooltip,int num, int lim ) {
  skull = sk;
  toolt = tooltip;
  iter = 0;
  args.addTokens(ar, " ", "");
 // Logger::
  basenum = num;
  limitor = lim;
  //setName("Skul");
  setVisible(true);
  setSize(100,20);
  resetRibs();
  //setMouseClickGrabsKeyboardFocus(true);
  
 }
 void tutor();
 int ribs;
 void resetRibs() { ribs=0; }
 String getTooltip() { return toolt; }
 String getRib() { return args[ribs++]; }
 int getRibCount() const { return args.size(); }
 String getSkull() {
  iter = (iter+1)%limitor;
  if (iter==0) return skull;
  return skull +  String("abcdefgh")[iter];
 }
 
 int getGillCount() const {
  if (args.indexOf ("mul") >= 0)
   return args.indexOf ("mul");
  else if (args.indexOf ("liszt") >= 0)
   return args.indexOf ("liszt");
  return getRibCount();
 }
 
 
 
 Component * getFlesh() {
  Fish * holder = new Fish();
  holder->addAndMakeVisible(new Guts(getSkull()));
  for (int i = 0; i < getGillCount(); i++)
   holder->addAndMakeVisible(new Guts());
  return holder;
 }
 
 
 
 
 void paint(Graphics &g) {
  g.setColour (Colours::white);
  g.fillRoundedRectangle (1,1, getWidth()-1, getHeight()-1,5);
  g.setColour(Colours::black);
  if (limitor == 1)
   g.drawSingleLineText(skull,5,getHeight()/2);
  else
   g.drawSingleLineText(skull+" "+String(limitor),5,getHeight()/2);
  int wido = getWidth()-5;
  int hido = 5;
 }
 void mouseDrag(const MouseEvent &evnt) {
  Component::unfocusAllComponents 	( 		);
  DragAndDropContainer* dragC =
  DragAndDropContainer::findParentDragContainerFor(this);
  if (!dragC->isDragAndDropActive()) {
   dragC->startDragging(var("flesh") ,getFlesh(),Image::null, true );
   //dragC->startDragging(var("flesh") ,this,Image::null, true );
  }
 }
 
 
 
};

struct OrangeGrub : public Grub {
 Image mulbTILE;
 OrangeGrub(String sk, String ar, String tooltip, int num, int lim) :
  Grub(sk, ar, tooltip, num, lim) {
    Image r(Image::RGB, 2, 2, true);
    r.setPixelAt(1,1,Colour(250,225,200).withMultipliedSaturation(((float)(rand()%100))/100.0    ));
    r.setPixelAt(0,0,Colour(250,225,200).withMultipliedSaturation(((float)(rand()%100))/100.0    ));
    r.setPixelAt(0,1,Colour(250,200,150).withMultipliedSaturation(((float)(rand()%100))/100.0    ));
    r.setPixelAt(1,0,Colour(250,200,150).withMultipliedSaturation(((float)(rand()%100))/100.0    ));
    mulbTILE = r.rescaled(8,8,Graphics::lowResamplingQuality);

   
  }
 
 
 void paint(Graphics &g) {
  g.setTiledImageFill(mulbTILE,0,0,1);
  g.fillRoundedRectangle (1,1, getWidth()-1, getHeight()-1,5);
  g.setColour(Colours::black);
  if (limitor == 1)
   g.drawSingleLineText(skull,5,getHeight()/2);
  else
   g.drawSingleLineText(skull+" "+String(limitor),5,getHeight()/2);
  int wido = getWidth()-5;
  int hido = 5;
 }
 
 
 
};
