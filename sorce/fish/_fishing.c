

void JuliaChild::chubberdubber() {
 File f;
 Chubbalyzer *c = new Chubbalyzer(f);
 r->chubber(c);
 c->runThread();
 delete(c);
}

void JuliaChild::gwonzer() {
// ChildProcess *cp = new ChildProcess();
// TextEditor *te = new TextEditor();
// te->setMultiLine(true,false);
// te->setColour(TextEditor::backgroundColourId, Colours::black);
// te->setColour(TextEditor::textColourId, Colours::grey);
// te->setReadOnly(true);
// DialogWindow::showDialog ("shlisp", te, nullptr, Colours::black, true, true, true);
//	cp->start("./shlisp -h");
// cp->waitForProcessToFinish(1000);
// te->moveCaretToEnd ();
// te->insertTextAtCaret(cp->readAllProcessOutput());
 
  Chubagwonzer::showGwonz();
}

void JuliaChild::uploadBinar() {
 FileChooser chooser ("Choose binary",File::nonexistent,"*.bin");
 if (!(chooser.browseForFileToOpen ())) return;
 File curBin = chooser.getResult ();
 if (!(curBin.existsAsFile ())) return;
 Chubbalyzer * c = new Chubbalyzer(curBin);
 r->chubber(c);
 //c->situatend();
 c->runThread();
 delete(c);
}

void JuliaChild::chubberdubbertab() {
 File f;
 Chubbalyzer *c = new Chubbalyzer(f);
 Recipe * rr = dynamic_cast<Recipe*>(Component::getCurrentlyFocusedComponent());
 if (!rr) return;
 rr->chubber(c);
// c->situatend();
 c->runThread();
 delete(c);
}

void Guts::chubber(Chubbalyzer * c) {
 //printf("gutschub\n");
 static String numstrin = String("-0123456789");
 String brakcandi = gl.getText().initialSectionContainingOnly(numstrin);
 if (!brakcandi.isEmpty()) {
  int spoon = brakcandi.getIntValue();
  if ((unsigned char)spoon == 0) {
   c->insituate(255);
   c->insituate(0);
  } else if ((unsigned char)spoon == 255) {
   c->insituate(255);
   c->insituate(242);
   c->insituate(0);
  } else c->insituate(spoon);
 }
 if (lookup()!=nullptr) {
  Atom * a = lookup();
  Grub * gg =dynamic_cast<Grub*>(a);
  if (gg) c->insituate(gg->basenum);
 }
}

void Recipe::mouseDoubleClick(const MouseEvent &evnt){
 chubber();
}
void Recipe::chubber(){
 File f;
 Chubbalyzer *c = new Chubbalyzer(f);
 chubber(c);
 c->runThread();
 delete(c);
}

void Recipe::chubber(Chubbalyzer * chb) {
 int childro = getNumChildComponents ();
 for (int i = 0; i < childro; i++) {
  Component* c = getChildComponent (i);
  Stub * g = static_cast<Stub*>(c);
  g->chubber(chb);
 }
}
void Fish::chubber(Chubbalyzer * chb) {
 chb->insituate(255);
 Recipe::chubber(chb);
 chb->insituate(0);
}
 
void Soup::chubber(Chubbalyzer * chb) {
 chb->situatier();
 Recipe::chubber(chb);
 chb->insituate(0);
}
