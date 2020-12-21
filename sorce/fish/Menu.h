
struct JuliaMenu :
public MenuBarModel,
public ApplicationCommandTarget {
public:
 
 enum CommandIDs {
  newPhile = 0x2000,
  openPhile, savePhile, saveAsPhile, closeWindowe, printBouillabaisse,
  undoEdit, redoEdit,
  cutEdit, copyEdit, pasteEdit, deleteEdit,
  dupEdit, dupEditRef,
  upLoad, upLoadTab, upLoadMatrix
 };
 ApplicationCommandManager* commandManager;
 JuliaMenu() {
  //bwMode = tooltipMode = false;
  commandManager = new ApplicationCommandManager();
  commandManager->registerAllCommandsForTarget(this);
  setApplicationCommandManagerToWatch(commandManager);
 }
 ~JuliaMenu() { delete (commandManager); }
 StringArray getMenuBarNames() {
  const char* const names[] = { "File", //"Edit",
   "Edit", "Shbobo", nullptr };
  return StringArray (names);
 }
 PopupMenu getMenuForIndex (int menuIndex, const String&) {
  PopupMenu menu;
  if (menuIndex == 0) {
   menu.addCommandItem (commandManager, newPhile,String("New"));
   menu.addSeparator();
   menu.addCommandItem (commandManager,openPhile,String("Open..."));
   menu.addCommandItem (commandManager, savePhile,String("Save"));
   menu.addCommandItem (commandManager, saveAsPhile,String("Save as..."));
   menu.addSeparator();
   menu.addCommandItem (commandManager, printBouillabaisse,String("Export png..."));
   menu.addSeparator();
   menu.addCommandItem (commandManager, printBouillabaisse,String("Close Window"));
   
  } else if (menuIndex == 1) {
   menu.addCommandItem (commandManager, undoEdit, String("Undo"));
   menu.addCommandItem (commandManager, redoEdit, String("Redo"));
   menu.addSeparator();
   menu.addCommandItem (commandManager, cutEdit, String("Cut"));
   menu.addCommandItem (commandManager, copyEdit, String("Copy"));
   menu.addCommandItem (commandManager, pasteEdit, String("Paste"));
   menu.addCommandItem (commandManager, dupEdit, String("Duplicate"));
   menu.addCommandItem (commandManager, dupEditRef, String("Reference"));
   menu.addCommandItem (commandManager, deleteEdit, String("Delete"));
  } else if (menuIndex == 2) {
   menu.addCommandItem (commandManager, upLoadTab, String("Serve this"));
   menu.addCommandItem (commandManager, upLoad, String("Serve all"));
   menu.addCommandItem (commandManager, upLoadMatrix, String("Change cuisine"));
  }
  return menu;
 }
 void menuItemSelected (int menuItemID, int) {}
 void menuBarActivated 	( 	bool  	isActive	) {}
 ApplicationCommandTarget* getNextCommandTarget() {
  return findFirstTargetParentComponent();
 }
 bool perform (const InvocationInfo& info){return true;}
 void getAllCommands (Array <CommandID>& commands) {
  const CommandID ids[] = {
   newPhile,
   openPhile, savePhile, saveAsPhile, printBouillabaisse,
   undoEdit, redoEdit,
   cutEdit, copyEdit, pasteEdit, deleteEdit,
   dupEdit, dupEditRef, randupEdit,
   insertReturn, insertFish, insertGuts,
   bbaisseNew, bbaisseDup, bbaisseRandup, bbaisseRandupddd, bbaisseDel,
	  bbaisseBW,tooltipTog,brax,
   upLoad, upLoadTab, upLoadMatrix, gwonzer, barcoder
  };
  commands.addArray (ids, numElementsInArray (ids));
 }
 void getCommandInfo (CommandID commandID, ApplicationCommandInfo& result) {}
};