

String Guts::printe() {
 return gl.getText();
// f->writeText(gl.getText(),false,false, nullptr);
}

String Bubble::printe() {
 String tarno = gl.getText().trimCharactersAtEnd ("\n\r");
 if (!tarno.isEmpty())
  return ";"+tarno+"\n";
 // f->writeText(";" + tarno + "\n",false,false,nullptr);
 //else f->writeText("\n",false,false,nullptr);
 return "\n";
}

String Recipe::printe() {
 int childro = getNumChildComponents();
 String s;
 for (int i = 0; i < childro; i++) {
  if (i>0) s+=" ";
   
   //f->writeText(" ",false,false,nullptr);
  Component* c = getChildComponent (i);
  Stub * g = dynamic_cast<Stub*>(c);
  if (g!= nullptr) s += g->printe();
 }
 return s;
}

String Bloque::printe() {
 return shapes[type].substring(0,1)+
  Recipe::printe() +
 shapes[type].substring(1,2);
// s.append(shapes[type].substring(0,1),1)//,false,false,nullptr);
 
// s.append(shapes[type].substring(1,2),1)
 //f->writeText(shapes[type].substring(1,2),false,false,nullptr);
}

