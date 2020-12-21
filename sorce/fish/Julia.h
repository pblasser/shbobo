





struct JuliaChild
#ifndef RIKER
: public Viewport, public DragAndDropContainer,
public ApplicationCommandTarget,
public HouseCommands,
public Thread
#endif
{public:
 File currentFile;
 File currentBinar;
 Recipe * r;
 Zelda z;

 JuliaChild() : Thread("painter") {
  r = new Recipe();
  addAndMakeVisible(&z);
  z.setBounds(260,180,120,160);
  setViewedComponent(r);
  startThread();
 }
 ~JuliaChild() { stopThread(100); }
 void run() ;
// void componentChildrenChanged();
 
 void childrenChanged();
 void visibleAreaChanged(const juce::Rectangle<int> &nva);
 
 ApplicationCommandTarget* getNextCommandTarget();
 void getAllCommands (Array <CommandID>& commands);
 void getCommandInfo (CommandID commandID, ApplicationCommandInfo& result);
 bool perform (const juce::ApplicationCommandTarget::InvocationInfo& info);
 
 void chubberdubber() ;
 void chubberdubbertab();
 void newFile();
 void newFromClippo();
 void copyToClippo();
 void zoomInn() {
  mastro->zoomInn();
  sendLookAndFeelChange();
  notify();
 }
 void zoomOutt() {
   mastro->zoomOutt();
  sendLookAndFeelChange();
  notify ();
 }
 void undoEdito() {mastro->undo();}
 void redoEdito() {mastro->redo();}

  void uploadBinar();
   void gwonzer();
  void closeWindow() {}
  void tooltipToggle() {}
  void barcodero() {}
 void openFileInEditor (File f);
  void chooseFileToOpen ();
 void saveFileFromEditor () ;
 void chooseFileToSave ();
 virtual void printoBouillo () ;


};



class Julia
#ifndef RIKER
 : public DocumentWindow
#endif
{
public:
static Array <Julia* > juliaz;
 JuliaChild jc;
 void closeButtonPressed();
 ~Julia();
 Julia();
 Julia( File  f);
};


Array <Julia* > Julia::juliaz;

Julia::~Julia() {
printf("decon\n");
}
void Julia::closeButtonPressed() {
  if (juliaz.size() == 1)
   JUCEApplication::quit();
  else{
   juliaz.remove( juliaz.indexOf(this));
   delete(this);
  }
 printf("wart\n");
 }
void JuliaChild::newFile() {
 new Julia();
}


