
void Stub::focusGained(FocusChangeType cause){
 
 repaint();
}

void Stub::focusLost(FocusChangeType cause) {
 repaint();
}

bool Stub::visitInsert(Stub * s) {
 mastro->beginNewTransaction();
 mastro->perform(new FudgeAction(s,this));
 return true;
}

bool Recipe::visitInsert(Stub * s) {
 mastro->beginNewTransaction();
 mastro->perform(new PutinAction(s,this));
 return true;
}

bool Bloque::visitInsert(Stub*s) {
 if (getNumChildComponents()<1) {
  return Recipe::visitInsert(s);
 } return Stub::visitInsert(s);
}

bool Stub::keyPressed (const KeyPress &key) {
 //if (!hasKeyboardFocus(false)) return true;
 //JuliaChild * jc = findParentComponentOfClass<JuliaChild>();
 //if (!jc) return true;

 
 juce_wchar c = key.getTextCharacter();
 if (c == '(')
  return visitInsert(new Fish());
 if (c == '{')
  return visitInsert(new Soup());
 if (c == '<')
  return visitInsert(new Boat());
 if (c == '[')
  return visitInsert(new Tank());
 if (key.getKeyCode() == KeyPress::spaceKey)
  return visitInsert(new Guts());
 if (key.getKeyCode() == KeyPress::returnKey)
  return visitInsert(new Bubble(""));

 
 Recipe * pc =  dynamic_cast<Recipe*>(getParentComponent());
 if (!pc) return true;
 int i = pc->getIndexOfChildComponent(this);
 Component * fc;
 
 if (key.getKeyCode() == KeyPress::rightKey) {
  if (i+1>=pc->getNumChildComponents()) {
   fc=pc;
   static_cast<Stub*>(fc)->lefty = true;
  }
  else {
   fc=pc->getChildComponent(i+1);
   static_cast<Stub*>(fc)->lefty = false;
  }
  fc->grabKeyboardFocus();
  return true;
 }
 if (key.getKeyCode() == KeyPress::leftKey) {
  if (i<1) {
   fc=pc;
   static_cast<Stub*>(fc)->lefty = false;
  }
  else {
   fc=pc->getChildComponent(i-1);
   static_cast<Stub*>(fc)->lefty = true;
  }
  fc->grabKeyboardFocus();
  return true;
 }

 if ((key.getKeyCode() == KeyPress::deleteKey)|| 
 (key.getKeyCode() == KeyPress::backspaceKey)) {
  if (pc->getNumChildComponents()<=1) fc = pc;
  else if (i<1) fc = pc->getChildComponent(1);
  else fc = pc->getChildComponent(i-1);
  mastro->beginNewTransaction();
  mastro->perform(new TakeAction(this));
  fc->grabKeyboardFocus();
  return true;
 }
 return false;
}

bool Bubble::keyPressed (const KeyPress &key) {
  juce_wchar c = key.getTextCharacter();
 if (isalnum(c)) {
  gl.showEditor();
  TextEditor * t = gl.getCurrentTextEditor();
  if (t==nullptr) return true;
  t->setText(String::charToString(c));
  return true;
 }
 return Stub::keyPressed(key);
}

bool Recipe::keyPressed (const KeyPress &key) {
 if ((key.getKeyCode() == KeyPress::rightKey) &&!lefty)
  if (getNumChildComponents()>0) {
   getChildComponent(0)->grabKeyboardFocus();
   return true;
  }
 if ((key.getKeyCode() == KeyPress::leftKey) &&lefty)
  if (getNumChildComponents()>0){
   getChildComponent(getNumChildComponents()-1)->grabKeyboardFocus();
   return true;
  }
  juce_wchar c = key.getTextCharacter();
  if (isalnum(c)) {
   Guts * g = new Guts(String::charToString(c));
   mastro->beginNewTransaction();
   mastro->perform(new PutinAction(g,this));
   g->gl.showEditor();
   TextEditor * t = g->gl.getCurrentTextEditor();
   if (t==nullptr) return true;
   t->setCaretPosition(1);
   return true;
  }
 return Stub::keyPressed(key);
}
