

Stub * selected;

void Stub::cutEdito() {
 selected = this;
 mastro->beginNewTransaction();
 mastro->perform(new TakeAction(this));
}
void Stub::copyEdito(){
 selected = this;
}
void Stub::copyToClippo(){
 SystemClipboard::copyTextToClipboard(printe());
}
void Stub::pasteEdito(){
 if (selected==nullptr) return;
 Stub * s = selected->clone();
 if (s) visitInsert(s);
 //mastro->beginNewTransaction();
 //mastro->perform(new FudgeAction(selected->clone(), this));
}

void Stub::dupEdito(){
 Stub * s = clone();
 if (s) visitInsert(s);
 //mastro->beginNewTransaction();
 //mastro->perform(new FudgeAction(clone(), this));

}
void Recipe::dupEditoRef(){
 Stub * s = reference();
 if (s) visitInsert(s);
 //mastro->beginNewTransaction();
 //mastro->perform(new FudgeAction(reference(), this));
}