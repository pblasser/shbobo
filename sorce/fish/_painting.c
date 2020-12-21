//Image Garcon Imago



void Stub::paint(Graphics &g) {
 if (hasKeyboardFocus(false)) {
  g.setTiledImageFill(mastro->imago(),0,0,0.25f);
 }
}

void Bubble::paint(Graphics &g) {
 Stub::paint(g);
 if (hasKeyboardFocus(false) && (fudge==scoot))
  g.fillRect(getLocalBounds());//bsi.subtractedFrom(getLocalBounds()));
 if (scoot && !fudge)
  g.fillRect(0,0,bsi.getLeft(),getHeight());
 if (fudge && !scoot)
  g.fillRect(getWidth()-bsi.getRight(),0,bsi.getRight(),getHeight());
 //gl.repaint();
}

void Guts::paint(Graphics &g) {
 Bubble::paint(g);
 g.setFont(mastro->getSubFont());
 g.setColour(Colours::black);
 g.drawSingleLineText(getName(),gsi.getLeft(),getHeight()-mastro->getSubFont().getDescent());
}

void Recipe::paint(Graphics&g) {
 g.setColour(getPastry(false));
 g.fillRect(getLocalBounds());
 //JuliaChild * jc = findParentComponentOfClass<JuliaChild>();
 //if (jc==nullptr) return;
// jc->childBoundsChanged();
}

void Bloque::paint(Graphics&g) {
 AffineTransform l = AffineTransform()
  .scaled(-bsi.getLeft(),getHeight())
  .translated(bsi.getLeft(),0);
 AffineTransform r = AffineTransform()
  .scaled(bsi.getRight(),getHeight())
  .translated(getWidth()-bsi.getRight(),0);
 g.setColour(getPastry(type<2));
 Stub::paint(g);
 if (fudge==scoot)
  g.fillRect(bsi.subtractedFrom(getLocalBounds()));
 if (scoot)
  g.fillPath(fields[type], l);
 if (fudge)
  g.fillPath(fields[type], r);
 if(!scoot!=!fudge) {
  g.setColour(getPastry(type<2));
  g.fillRect(bsi.subtractedFrom(getLocalBounds()));
 }
 if (!scoot)
  g.fillPath(fields[type], l);
 if (!fudge)
  g.fillPath(fields[type], r);
 g.setColour(Colours::black.withAlpha(0.25f));
 g.strokePath(pathos[type], PathStrokeType(1), l);
 g.strokePath(pathos[type], PathStrokeType(1), r);
 g.setFont(mastro->getSubFont());
 g.setColour(Colours::black);
 g.drawSingleLineText(getName(),bsi.getLeft(),getHeight()-mastro->getSubFont().getDescent());
}

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
 void Bloque::pathify() {
 //pathos.addRoundedRectangle(0,0,20,20,10);
 //pathos[0].addCentredArc(0,0.5,1,0.5,0,M_PI, true);
 pathos[0].addArc(0,0,1,1,0,M_PI, true);
 //pathos[0].closeSubPath ();
 pathos[0].scaleToFit(0,0,1,1,false);
 fields[0] = Path(pathos[0]);
 fields[0].closeSubPath ();
 
 pathos[1].addArc(0,0,1,0.4,0,M_PI, true);
 pathos[1].lineTo(1,0.5);
 pathos[1].addArc(0,0.6,1,0.4,0,M_PI, false);
 //pathos[1].closeSubPath ();
 pathos[1].scaleToFit(0,0,1,1,false);
 fields[1] = Path(pathos[1]);
 fields[1].closeSubPath ();
 
 
 pathos[2].startNewSubPath(0,0);
 pathos[2].lineTo(1,0);
 pathos[2].lineTo(1,1);
 pathos[2].lineTo(0,1);
 fields[2] = Path(pathos[2]);
 fields[2].closeSubPath ();
 //pathos[2].closeSubPath ();
 
 
 pathos[3].startNewSubPath(0,0);
 pathos[3].lineTo(1,0.5);
 pathos[3].lineTo(0,1);
 fields[3] = Path(pathos[3]);
 fields[3].closeSubPath ();
 
 //pathos[3].closeSubPath ();
 
 shapes[0] = "()";
 shapes[1] = "{}";
 shapes[2] = "[]";
 shapes[3] = "<>";
}
