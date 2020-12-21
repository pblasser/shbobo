

struct Chubagwonzer : public Chub, public Thread, public Component, public Timer  {
 struct Gwonzero : public Component {
  signed char vale;
  Gwonzero(): vale(0) {}
  void paint(Graphics &g) {
   g.setColour (Colours::green);
   int yc = getHeight()/2;
   int yh = vale * getHeight()/ 256;
   if (vale > 0)
    g.fillRect (0,yc-yh, getWidth(), yh);
   else
    g.fillRect (0,yc, getWidth(), -yh);
  }
  void setVale(signed char v) {
   vale = v; repaint();
  }
 };
 struct Gwonzedo : public Gwonzero {
  Gwonzedo() : Gwonzero() {}
  void paint(Graphics &g) {
   int yc = getHeight()/8;
   g.setColour (Colours::orange);
   for (int i =0; i<8; i++) {
    if (vale&(1<<i))
     g.fillRect (0,yc*i, getWidth(), yc);
   }
  }
 };
 Gwonzero* gwonzers[8];
 virtual void gwonzINIT(int id) {
  for (int i =0;i<4;i++) {
   gwonzers[i] = new Gwonzero();
   addAndMakeVisible(gwonzers[i]);
  }
  for (int i =4;i<8;i++) {
   if (id==0x7777)
    gwonzers[i] = new Gwonzedo();
   else
    gwonzers[i] = new Gwonzero();
    addAndMakeVisible(gwonzers[i]);
  }
 }
  
  
 Chubagwonzer(): Thread("GwonzerThread") {
  if (chubINIT()) {
   setSize(400,100);
   startThread();
   startTimer (20);
 }
 }
 
 ~Chubagwonzer(){
  for (int i =0;i<8;i++)
   delete(gwonzers[i]);
  //printf("stopt\n"); 
  stopThread(100);
  wait(100);
  chubCLOZ();
  //delete[8](gwonzers);
 }
 void run() {
  chubRUN(); 
  //printf("stoprunt\n");
 } 
 void resized() {
  for (int i = 0; i < 8; i++) 
    gwonzers[i]->setBounds(getWidth()*i/8,0,getWidth()/8,getHeight());
 }
 void timerCallback () {
  for (int i = 0; i < 8; i++) 
    gwonzers[i]->setVale(gwonz[i]);
 }
 bool chubShouldEnd(){return threadShouldExit();}
 void chubCALL() {}
 static void showGwonz() {
		Chubagwonzer  chb;
  DialogWindow::showModalDialog ("Spit Gwonz", &chb, nullptr, Colours::black, true, true, true);
	}
};
