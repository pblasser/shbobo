
struct TakeAction :
public UndoableAction {
 Component* who;
 Component* where;
 int which;
 TakeAction(Component*w) {
  who = w;
 }
 bool perform() {
  where = who->getParentComponent();
  if (!where) return false;
  which = where->getIndexOfChildComponent(who);
  where->removeChildComponent(who);
  return true;
 }
 bool undo() {
  if (!where) return false;
  where->addAndMakeVisible(who,which);
  return true;
 }
};

struct PutinAction :
public UndoableAction {
 Component* who;
 Component* whom;
 PutinAction(Component*o,Component*m) :
 UndoableAction() {
  who=o;
  whom=m;
 }
 ~PutinAction() {}
 bool perform() {
  if (!whom) return false;
  whom->addAndMakeVisible(who);
  who->grabKeyboardFocus();
  return true;
 }
 bool undo() {
  if (!whom) return false;
  whom->removeChildComponent(who);
  return true;
 }
};

struct ScootAction :
public UndoableAction {
 Component* who;
 Component* whom;
 Component* where;
 ScootAction(Component*o,Component*m) :
 UndoableAction() {
  who=o;
  whom=m;
 }
 ~ScootAction() {}
 bool perform() {
  //printf("scooty\n");
  where = whom->getParentComponent();
  if (!where) return false;
  where->addAndMakeVisible(who);
  who->toBehind(whom);
  who->grabKeyboardFocus();
  return true;
 }
 bool undo() {
  if (!where) return false;
  where->removeChildComponent(who);
  return true;
 }
};

struct FudgeAction :
public UndoableAction {
 Component* who;
 Component* whom;
 Component* where;
 FudgeAction(Component*o,Component*m) :
 UndoableAction() {
  who=o;
  whom=m;
 }
 ~FudgeAction() {}
 bool perform() {
  where = whom->getParentComponent();
  if (!where) return false;
  int indo = where->getIndexOfChildComponent(whom);
  where->addAndMakeVisible(who,indo+1);
  who->grabKeyboardFocus();
  return true;
 }
 bool undo() {
  if (!where) return false;
  where->removeChildComponent(who);
  return true;
 }
};

struct StringAction :
public UndoableAction {
 Stub* who;
 String sew;
 String old;
 StringAction(Component*w, String ol, String  ne) :
 sew(ne), old(ol) {
  who = dynamic_cast<Stub*>(w);
 }
 bool perform() {
  
  if (!who) return false;
  //printf("whod\n");
  who->processString(sew);
  //printf("stringaction%s\n",old.toUTF8().getAddress());
  //printf("stringaction%s\n",sew.toUTF8().getAddress());
  return true;
 }
 bool undo() {
  if (!who) return false;
  //printf("whod\n");
  //printf("stringaction%s\n",old.toUTF8().getAddress());
  who->processString(old);
  return true;
 }
};