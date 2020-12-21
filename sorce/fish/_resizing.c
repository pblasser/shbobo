

void Recipe::childBoundsChanged (Component* child){
 int childro = getNumChildComponents ();
 int wido = bsi.getLeft();
 int hido = 0;
 int curxo = bsi.getLeft();
 int curyo = mastro->getHeight();
 for (int i = 0; i < childro; i++) {
  Stub* c = dynamic_cast<Stub*>(getChildComponent(i));
  if (c) c->bounds_visit(curxo,curyo,wido,hido);
  
 }
 setSize(wido+bsi.getRight(),hido+curyo+mastro->getSubFont().getHeight());
}

//void JuliaChild::reSnap() {
// notify();
//}

void JuliaChild::run () {
 while(!threadShouldExit()) {
  wait(-1);
  //r->childrenChanged();
  z.i = r->createComponentSnapshot (r->getLocalBounds(),
                                   false);
  z.repaint();
  //printf("hcha\n");
// cancelPendingUpdate ();
  
 }
 
}


void Stub::bounds_visit(int&curxo,int&curyo,int&wido,int&hido) {
 if (getHeight()>curyo) curyo=getHeight();
 setTopLeftPosition(curxo,hido);
 curxo+=getWidth();
 wido=((curxo>wido)?curxo:wido);
}

void Bubble::bounds_visit(int&curxo,int&curyo,int&wido,int&hido) {
 Stub::bounds_visit(curxo,curyo,wido,hido);
 hido+=curyo;
 curyo=0;
 curxo=bsi.getLeft();
}

void Guts::bounds_visit(int&curxo,int&curyo,int&wido,int&hido) {
 Stub::bounds_visit(curxo,curyo,wido,hido);
}

void Bubble::childBoundsChanged (Component* child) {
  int maxwido = gl.getWidth();
  setSize(maxwido, gl.getHeight()+mastro->getSubHeight());
  gl.setTopLeftPosition(0,0);

 }
