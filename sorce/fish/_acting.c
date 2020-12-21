

void Stub::itemDropped (const SourceDetails &sd) {
 itemDragExit (sd);
 Component * paro = this->getParentComponent();
 if (!paro) return;
 Component * f = sd.sourceComponent.get();
 if  (f == this || f->isParentOf(this)) {
  //repaint();
  return;
 }
 mastro->beginNewTransaction();
 TakeAction*takey=nullptr;
 takey= new TakeAction(f);
 int xer = sd.localPosition.x;
 if (xer < getWidth()/3)  {
   ScootAction*scooty = new ScootAction(f,this);
   if (takey) mastro->perform(takey);
    mastro->perform(scooty);
  } else if (xer > getWidth()*2/3)  {
    FudgeAction*fudgey = new FudgeAction(f,this);
    if (takey) mastro->perform(takey);
    mastro->perform(fudgey);
  } else  {
    ScootAction*scooty = new ScootAction(f,this);
    if (takey) mastro->perform(takey);
    mastro->perform(scooty);
    mastro->perform(new TakeAction(this));
  }
 //repaint();
 }

void Recipe::itemDropped (const SourceDetails &sd) {
 itemDragExit (sd);
 Component * f = sd.sourceComponent.get();
 if  (f == this || f->isParentOf(this)) return;
 mastro->beginNewTransaction();
 TakeAction*takey=nullptr;
 takey= new TakeAction(f);
 if (takey) mastro->perform(takey);
 PutinAction*scooty = new PutinAction(f,this);
 mastro->perform(scooty);
}

void Bloque::itemDropped(const SourceDetails &sd) {
 Stub::itemDropped(sd);
}
void Stub::itemDragMove (const SourceDetails &sd) {
 grabKeyboardFocus();
 int xer = sd.localPosition.x;
 if (xer > getWidth()*2/3){
  scoot = false; fudge = true;
 } else if (xer < getWidth()/3)  {
  fudge=false; scoot=true;
 } else {
  fudge =scoot = false;
 } repaint();
}

void Stub::itemDragExit (const SourceDetails &sd) {
 fudge = scoot = true;
 repaint();
}

void GutsLabel::editorAboutToBeHidden(TextEditor * t) {
 setGoodSize();
 Component * paro = this->getParentComponent();
 if (!paro) return;
 paro->grabKeyboardFocus();
 if (lastext==getText()) return;
 mastro->beginNewTransaction();
 StringAction*stringy=new StringAction(paro,lastext,getText());
 mastro->perform(stringy);
 JuliaChild * jc = findParentComponentOfClass<JuliaChild>();
 if(jc)jc->notify ();
}
