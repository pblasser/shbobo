
 void Zelda::mouseDown (const MouseEvent& e) {
  
  myDragger.startDraggingComponent (this, e);
 }

 void Zelda::mouseUp (const MouseEvent& e) {
  if (e.mouseWasClicked()) {
   JuliaChild * jc = findParentComponentOfClass<JuliaChild>();
   jc->setViewPosition(
     (e.getPosition()-frame.withZeroOrigin().getCentre())/reduction);
}
 }


void Stub::mouseDown	( 	const MouseEvent &  	event	) {
 lefty=false;
 //grabKeyboardFocus();
}


void Stub::mouseDrag(const MouseEvent &evnt) {
 Component::unfocusAllComponents 	( 		);
 dragon = true;
 DragAndDropContainer* dragC =
 DragAndDropContainer::findParentDragContainerFor(this);
 if (!dragC->isDragAndDropActive()) {
  fudge=scoot=true;
  dragC->startDragging(var("flesh") ,this, Image::null, true );
 }
}



 void Stub::mouseUp	( 	const MouseEvent &  	event	) {
 grabKeyboardFocus();
 repaint();
}


 void Guts::mouseDoubleClick(const MouseEvent &evnt) {
  Grub * gg =dynamic_cast<Grub*>(lookup());
  if (gg==0) return;
  gg->tutor();
}