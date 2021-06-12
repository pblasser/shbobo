import java.awt.*;
import java.awt.image.*;
import java.awt.dnd.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
import javax.swing.undo.*;
import java.io.*;

public class Guts extends Bubble {	

 Guts(int c) { 
  super(true); 
  txt=""+(char)c;
  first=false;
 }	
 Guts() { 
  super(true); 
  txt="";
 }  
  public Stub clone()  {
       Guts clonedMyClass = new Guts();
       clonedMyClass.chng(txt);
       return clonedMyClass ;
}
  public void paint(Graphics g) {
  stubbornPaint(g);
  Font f = getFont();
  g.setFont(f);
  g.setColor(Color.black);
  g.drawString(txt,f.getSize()>>2,g.getFontMetrics().getAscent());
 drawSubtext(g,true);  
 }  

 public boolean breakers(int c) {
   if ((c==32)||(c==';')) return true;
   if ((c=='(')|| (c=='{')|| (c=='[')|| (c=='<'))
    return true;
   if ((c==')')||(c=='}')||(c==']')||(c=='>')) 
   	return true;
   return false;  
 }
 public void keyTyped(KeyEvent e) {
  char c = e.getKeyChar();
  if (breakers(c)) stubbornKey(e); 
  else super.keyTyped(e);
 }
 public void parze(PushbackReader pr) {
  if (!editing) return;
  int c=0;
  while (c>-1) {
   try{c=pr.read();}catch (Exception e) {return;}
   if (c==32) break;
   if (breakers(c)){
    try {pr.unread(c);}catch (Exception e) {return;}
    break;
   }
   txt +=  (char)c;
  } chng(txt);
 }
 public String toString() { return txt; }
  public void gruberVisit(Grub g) {
   stubbornGruber(g);
 }
 public void boundsVisit(Rectangle r) {
  //validate();
  stubbornVisit(r); 
 }
 public void chng(String t) {
  try {cumulopasty = Integer.parseInt(t);}
  catch (Exception nfe) {
    cumulopasty=0;
  }
  super.chng(t);
 }



}
