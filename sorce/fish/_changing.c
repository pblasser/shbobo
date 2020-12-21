
void GutsLabel::textEditorTextChanged (TextEditor &) {
 setGoodSize();

}


void JuliaChild::childrenChanged() {
 notify ();
}

void JuliaChild::visibleAreaChanged(const juce::Rectangle<int> &nva) {
  z.repaint();
}

 void Zelda::framerei() {
  JuliaChild * jc = findParentComponentOfClass<JuliaChild>();
  if (jc==nullptr) return;
  Point<int> pos = jc->getViewPosition();
  juce::Rectangle<int> are = jc->getViewArea();
  juce::Rectangle<int> max = jc->getViewedComponent()->getBounds();
  float x = (float)getWidth() / (float)(max.getWidth());
  float y = (float)getHeight()/ (float)(max.getHeight());
  reduction = (x>y ? y : x);
  frame = are*reduction;//)+(pos*reduction*0.5));
 }

Atom * Guts::lookup() {
 //return mastro->urmap[gl.getText()];
 auto search = mastro->urmap.find(gl.getText());
 if(search != mastro->urmap.end()) {
  return search->second;
 }
 return nullptr;
}


void Recipe::childrenChanged () {
 cumulopasty = 0;
 int childro = getNumChildComponents ();
 Grub * gg =0;
 if (childro>0) {
  Guts * g = dynamic_cast<Guts*>(getChildComponent(0));
  if (g) gg =dynamic_cast<Grub*>(g->lookup());
 }
 if (gg) {
  cumulopasty = gg->basenum;
  gg->resetRibs();
 }
 for (int i = 1; i < childro; i++) {
  Stub* s = dynamic_cast<Stub*>(getChildComponent (i));
  if (s) {
   if (gg) s->gruber_visit(*gg);
   else s->setName("");
   s->pastry_visit(*this);
  }
 }
 childBoundsChanged(nullptr);
 repaint();
 JuliaChild * jc = findParentComponentOfClass<JuliaChild>();
 if(jc)jc->notify();
}

void Stub::gruber_visit(Grub&g) {
 setName(g.getRib());
}
void Bubble::gruber_visit(Grub&g) {}
void Guts::gruber_visit(Grub&g) {
 Stub::gruber_visit(g);
}
void Stub::pastry_visit(Recipe&r) {
 r.cumulopasty+=cumulopasty;
}
void Bubble::pastry_visit(Recipe&r) {}
void Guts::pastry_visit(Recipe&r) {
 r.cumulopasty+=cumulopasty;
}


 void Guts::processString (const String&s) {
  String ss = s.retainCharacters("*/+-%^&|!@#0123456789abcdefghijklmnopqrstuvwxyz");
  static String numstrin = String("-0123456789");
  String brakcandi = ss.initialSectionContainingOnly(numstrin);
  if (!brakcandi.isEmpty()) {
   cumulopasty = brakcandi.getIntValue();
   ss = brakcandi;
  }
  if (ss.isEmpty())
   gl.setText("0");
  else gl.setText(ss);
  if (getParentComponent()) getParentComponent()->childrenChanged();
  //childBoundsChanged(0);
 }


