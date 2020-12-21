

void JuliaChild::getAllCommands (Array <CommandID>& commands) {
 const CommandID ids[] = {
  newPhile, openPhile, savePhile, saveAsPhile, printBouillabaisse,
  copyToClip, newFromClip,
  undoEdit, redoEdit, zoomIn, zoomOut, upLoad, upLoadMatrix, gwonzify
 };
 commands.addArray (ids, numElementsInArray (ids));
}
#define COMINF(a,b,c,d,e) \
 case a:\
 result.setInfo (b, b, c, 0);\
 result.addDefaultKeypress (d, ModifierKeys::commandModifier | e); \
 break;

void JuliaChild::getCommandInfo (CommandID commandID, ApplicationCommandInfo& result) {
 const String filesz ("File");
 const String edtit ("Edit");
 const String vieuw ("View");
 const String devicz ("Shnth");
 switch (commandID) {
  COMINF(newPhile, "New File", "File", 'n', 0);
  case newFromClip:
   result.setInfo ("New form clipboard", "New from clipboard", filesz, 0);
   result.addDefaultKeypress ('n', ModifierKeys::commandModifier | ModifierKeys::shiftModifier);
   break;
  case openPhile:
   result.setInfo ("Open File", "Open a file", filesz, 0);
   result.addDefaultKeypress ('o', ModifierKeys::commandModifier);
   break;
  case savePhile:
   result.setInfo ("Save File", "Save this file", filesz, 0);
   result.addDefaultKeypress ('s', ModifierKeys::commandModifier);
   break;
  case saveAsPhile:
   result.setInfo ("Save as File", "Saves as another file", filesz, 0);
   result.addDefaultKeypress ('s', ModifierKeys::commandModifier| ModifierKeys::shiftModifier);
   break;
  case printBouillabaisse:
   result.setInfo ("Print Bouillabaisse", "Print the current bouillabaisse to PNG format", filesz, 0);
   result.addDefaultKeypress ('p', ModifierKeys::commandModifier);
   break;
  case copyToClip:
   result.setInfo ("Copy to clipboard", "Copy to the system text clipboard", edtit, 0);
   result.addDefaultKeypress ('c', ModifierKeys::commandModifier | ModifierKeys::shiftModifier);
   break;
  case undoEdit:
   result.setInfo ("Undo", "Undo changes", edtit, 0);
   result.addDefaultKeypress ('z', ModifierKeys::commandModifier );
   break;
  case redoEdit:
   result.setInfo ("Redo", "Redo changes", edtit, 0);
   result.addDefaultKeypress ('z', ModifierKeys::commandModifier | ModifierKeys::shiftModifier);
   break;
  case zoomIn:
   result.setInfo ("Zoom in", "Zoom in", vieuw, 0);
   result.addDefaultKeypress ('=', ModifierKeys::commandModifier );
   break;
  case zoomOut:
   result.setInfo ("Zoom out", "Zoom out", vieuw, 0);
   result.addDefaultKeypress ('-', ModifierKeys::commandModifier );
   break;
  case upLoad:
   result.setInfo ("Serve all", "Send all bouillabaisse to the SHNTH", devicz, 0);
   result.addDefaultKeypress ('u', ModifierKeys::commandModifier);
   break;
  case upLoadMatrix:
   result.setInfo ("Change cuisine", "Upload a new DSP matrix to device", devicz, 0);
   result.addDefaultKeypress ('u', ModifierKeys::commandModifier | ModifierKeys::shiftModifier);
   break;
  case gwonzify:
   result.setInfo ("Gwonzer", "Look at data from device", devicz, 0);
   result.addDefaultKeypress ('g', ModifierKeys::commandModifier | ModifierKeys::shiftModifier);
   break;
 };
}


bool JuliaChild::perform (const juce::ApplicationCommandTarget::InvocationInfo& info){
 switch (info.commandID) {
  case openPhile: chooseFileToOpen();break;
  case savePhile: saveFileFromEditor();break;
  case saveAsPhile: chooseFileToSave();break;
   case printBouillabaisse: printoBouillo();break;
  case upLoad: chubberdubber(); break;
  case upLoadMatrix: uploadBinar(); break;
  case gwonzify: gwonzer(); break;
  case zoomIn: zoomInn(); break;
  case zoomOut: zoomOutt(); break;
  case newPhile: newFile (); break;
  case copyToClip: copyToClippo(); break;
  case newFromClip: newFromClippo(); break;
  case undoEdit: undoEdito(); break;
  case redoEdit: redoEdito(); break;
  default: return false;
 };
 return true;
}

void Stub::getAllCommands (Array <CommandID>& commands) {
 const CommandID ids[] = {
  cutEdit, copyEdit, copyToClip, pasteEdit, dupEdit
 };
 commands.addArray (ids, numElementsInArray (ids));
}

void Stub::getCommandInfo (CommandID commandID, ApplicationCommandInfo& result) {
 const String edtit ("Edit");
 switch (commandID) {
  case cutEdit:
   result.setInfo ("Cut", "Cut any selected seafood", edtit, 0);
   result.addDefaultKeypress ('x', ModifierKeys::commandModifier );
   break;
  case copyEdit:
   result.setInfo ("Copy", "Copy any selected seafood", edtit, 0);
   result.addDefaultKeypress ('c', ModifierKeys::commandModifier );
   break;
  case copyToClip:
   result.setInfo ("Copy to clipboard", "Copy to the system text clipboard", edtit, 0);
   result.addDefaultKeypress ('c', ModifierKeys::commandModifier | ModifierKeys::shiftModifier);
   break;
  case pasteEdit:
   result.setInfo ("Paste", "Paste after the last selected seafood", edtit, 0);
   result.addDefaultKeypress ('v', ModifierKeys::commandModifier );
   break;
  case dupEdit:
   result.setInfo ("Duplicate", "Duplicate any selected seafood", edtit, 0);
   result.addDefaultKeypress ('d', ModifierKeys::commandModifier );
   break;
 };
}

bool Stub::perform (const juce::ApplicationCommandTarget::InvocationInfo& info){
 switch (info.commandID) {
  case cutEdit: cutEdito(); break;
  case copyEdit: copyEdito(); break;
   case copyToClip: copyToClippo(); break;
  case pasteEdit: pasteEdito(); break;
  case dupEdit: dupEdito(); break;
  default: return false;
 };
 return true;
}

void Bloque::getAllCommands (Array <CommandID>& commands) {
 const CommandID ids[] = {
  dupEditRef, upLoadTab
 };
 commands.addArray (ids, numElementsInArray (ids));
 Stub::getAllCommands(commands);
}

void Bloque::getCommandInfo (CommandID commandID, ApplicationCommandInfo& result) {
 const String edtit ("Edit");
 const String devicz ("Shnth");
 switch (commandID) {
  case dupEditRef:
   result.setInfo ("Reference", "Duplicate any poisson as a reference", edtit, 0);
   result.addDefaultKeypress ('f', ModifierKeys::commandModifier );
   break;
  case upLoadTab:
   result.setInfo ("Serve selected", "Send all bouillabaisse to the SHNTH", devicz, 0);
   result.addDefaultKeypress ('t', ModifierKeys::commandModifier);
   break;
 }; Stub::getCommandInfo(commandID, result);
}

bool Bloque::perform (const juce::ApplicationCommandTarget::InvocationInfo& info){
 switch (info.commandID) {
  case upLoadTab: chubber(); break;
  case dupEditRef: dupEditoRef(); break;
  default: return Stub::perform(info);
 };
 return true;
}


StringArray Garcon::getMenuBarNames() {
 const char* const names[] = {
  "File", "Edit", "View", "Shbobo", nullptr };
 return StringArray (names);
}

PopupMenu Garcon::getMenuForIndex (int menuIndex, const String&) {
 PopupMenu menu;
 if (menuIndex == 0) {
  menu.addCommandItem (mastro, newPhile,String("New"));
  menu.addCommandItem(mastro,newFromClip,String("New from clipboard"));
  menu.addSeparator();
  menu.addCommandItem (mastro,openPhile,String("Open..."));
  menu.addCommandItem (mastro, savePhile,String("Save"));
  menu.addCommandItem (mastro, saveAsPhile,String("Save as..."));
  menu.addSeparator();
  menu.addCommandItem (mastro, printBouillabaisse,String("Export png..."));
 } else if (menuIndex == 1) {
  menu.addCommandItem (mastro, undoEdit, String("Undo"));
  menu.addCommandItem (mastro, redoEdit, String("Redo"));
  menu.addSeparator();
  menu.addCommandItem (mastro, cutEdit, String("Cut"));
  menu.addCommandItem (mastro, copyEdit, String("Copy"));
  menu.addCommandItem (mastro, copyToClip, String("Copy to clipboard"));
  menu.addCommandItem (mastro, pasteEdit, String("Paste"));
  menu.addCommandItem (mastro, dupEdit, String("Duplicate"));
  menu.addCommandItem (mastro, dupEditRef, String("Reference"));
 } else if (menuIndex == 2) {
  menu.addCommandItem (mastro, zoomIn, String("Zoom in"));
  menu.addCommandItem (mastro, zoomOut, String("Zoom out"));
 } else if (menuIndex == 3) {
 menu.addCommandItem (mastro, upLoadTab, String("Serve selected"));
 menu.addCommandItem (mastro, upLoad, String("Serve all"));
 menu.addCommandItem (mastro, upLoadMatrix, String("Change cuisine"));
 menu.addCommandItem (mastro, gwonzify, String("Gwonzer"));
}return menu;
}

ApplicationCommandTarget* Stub::getNextCommandTarget() {
 return findFirstTargetParentComponent();
}

ApplicationCommandTarget* JuliaChild::getNextCommandTarget() {
 return findFirstTargetParentComponent();
}
