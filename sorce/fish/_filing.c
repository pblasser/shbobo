

void JuliaChild::newFromClippo() {
 Julia * j = new Julia();
 String s =SystemClipboard::getTextFromClipboard();
 j->jc.r->parze(s);
}


void JuliaChild::copyToClippo() {
 SystemClipboard::copyTextToClipboard 	(r->printe());
}


void JuliaChild::saveFileFromEditor () {
  if (currentFile == File::nonexistent) {
   chooseFileToSave () ;
   return;
  }
  if (currentFile.existsAsFile ())
   currentFile.deleteFile ();
  currentFile.create ();
  FileOutputStream * fos = currentFile.createOutputStream();
 // printtar(fos);
 fos->writeText(r->printe(),false,false,nullptr);
 
  fos->flush();
  delete(fos);
 }


//FILE    setAsCurrentWorkingDirectory
// setAsCurrentWorkingDirectory()
//statix

void JuliaChild::chooseFileToSave () {
  FileChooser chooser ("Choose file to save",currentFile,"*.txt");
  if (chooser.browseForFileToSave (true)) {
   currentFile = chooser.getResult ();
   saveFileFromEditor ();
  }
 }
void JuliaChild::openFileInEditor (File f) {
 if (!f.existsAsFile()) return;
 currentFile = f;
 String ss = currentFile.loadFileAsString();
 
 r = new Recipe();
 r->parze(ss);
 setViewedComponent(NULL,false);
 setViewedComponent(r,false);
 notify();
}

void JuliaChild::chooseFileToOpen () {
 FileChooser chooser ("OPEN",currentFile.getParentDirectory(),"*.txt");
 if (chooser.browseForFileToOpen ()) {
  openFileInEditor(chooser.getResult());
 }
}

void JuliaChild::printoBouillo () {
 File phile = currentFile.withFileExtension("png");
 FileChooser chooser ("Choose image to save",phile,"*.png");
 if (chooser.browseForFileToSave (true)) {
  File imageFile = chooser.getResult ();
  if (imageFile.existsAsFile ())
   imageFile.deleteFile ();
  imageFile.create ();
  PNGImageFormat * pingu = new PNGImageFormat();
  Image imago;
  imago = r->createComponentSnapshot (r->getLocalBounds());
  FileOutputStream* fos = imageFile.createOutputStream ();
  pingu->writeImageToStream (imago,*fos);
  fos->flush();
  delete (fos);
  delete (pingu);
 }
};



void Grub::tutor() {
 File f = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile);
 //printf("fullfile %s\n", f.getFullPathName().toRawUTF8());
 f = f.getParentDirectory().getParentDirectory();
 //printf("parentparent %s\n", f.getFullPathName().toRawUTF8());
 f = f.getChildFile("tutor");
 //printf("tutor %s\n", f.getFullPathName().toRawUTF8());
 if (!f.exists()) return;
 f = f.getChildFile(skull + ".txt");
 //printf("skull %s\n", f.getFullPathName().toRawUTF8());
// Logger::outputDebugString (f.getFullPathName ());
 if (f.existsAsFile()) new Julia(f);
}
