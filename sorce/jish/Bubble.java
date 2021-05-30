import java.awt.*;
import java.awt.image.*;
import java.awt.dnd.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
import javax.swing.undo.*;
import java.io.*;

public class Bubble extends Stub 
implements TextListener, ComponentListener, LayoutManager {	
 boolean editing, first;
 String txt,lastext;
 Bubble() { 
  this(false);
 }
 Bubble(boolean v) {
  super();
  txt="";
  lastext="";
  chng("");//tries to find a julia!!! null
  requestFocusInWindow();
  editing = v;
  setLayout(this);
 }
 public boolean breakers(int c) {
  if ((c=='\n') || (c=='\r')) return true;
  return false;
 }
 public void parze(PushbackReader pr) {
  if (!editing) return;
  int c=0;
  while (c>-1) {
   try{c=pr.read();}catch (Exception e) {}
   if (breakers(c)) break;
   txt += (char)c;
  } chng(txt);
 }

 public String toString() {
  if (!txt.isEmpty()) return ";"+txt+"\n";
  return "\n";
 }
 public void chng(String t) {
  if (first) lastext  = txt;
  first = false;
  editing = true;
  txt = t;
  doLayout(); 
 }

 public void stubbornKey(KeyEvent e) {
  super.keyTyped(e);
 }
 public void keyTyped(KeyEvent e) {
  if (!editing) {
    super.keyTyped(e); 
   editing = true;
   return;
  }
  char c = e.getKeyChar();
  // System.out.println((int)e.getKeyChar());
  if ((c=='\n') || (c=='\r')) {
    um.addEdit(new UndoString(this,txt,lastext));
    editing = false;
    return;
  }
  if (c>=32) chng((first?""+c:txt+c));
  //if (c==5) chng((first?""+c:txt+"€"));
  if (c==8) {
   if (txt.length()<=0) 
    um.addEdit(new UndoTake(this));
   else
    chng(txt.substring(0,txt.length()-1));
  }
   
  if (e.getKeyCode()==KeyEvent.VK_ESCAPE) {
    chng(lastext); editing = false;
  }
  //if c==esc no edit, editing = false;
 }
 public void stubbornPaint(Graphics g) {
  super.stubbornPaint(g);
  int siz = getFont().getSize();
  Graphics2D g2d = (Graphics2D)g;
  if (isFocusOwner() && (fudge==scoot))
    g2d.fill(new Rectangle(getSize()));
  if (scoot && !fudge)
    g2d.fill(new Rectangle(0,0,siz,getHeight()));
  if (fudge && !scoot)
    g2d.fill(new Rectangle(getWidth()-siz,0,siz,getHeight()));
 }
 public void paint(Graphics g) {
  
  stubbornPaint(g);
  Font f = getFont();
  
  //g.setFont(fi);
  g.setFont(f.deriveFont(Font.ITALIC));
  g.setColor(Color.black);
  g.drawString(txt,(f.getSize())>>2,g.getFontMetrics().getAscent());  
  //drawSubtext(g);  
 }	

 public void visitAlnum(char c) {
 }
 public void textValueChanged(TextEvent e) {
  requestFocusInWindow();
 }
 public void stubbornVisit(Rectangle r) {

  super.boundsVisit(r);
 }
 
 public void gruberVisit(Grub g) {}
 
 public void boundsVisit(Rectangle r) {
  //validate();
  stubbornVisit(r);
  r.height += r.y;
  r.y=0;
  r.x = getFont().getSize();
 }

    public void addLayoutComponent(String name, Component comp) {}
  public void removeLayoutComponent(Component comp) {}
  public Dimension minimumLayoutSize(Container p) { return getSize();}
  public Dimension preferredLayoutSize(Container p) { return getSize();}
  public void layoutContainer(Container p){ 
      Font f = getFont();
  if (f==null) return;
  FontMetrics fm = getFontMetrics(f);
  int i = f.getSize();
  int wido = fm.stringWidth(txt)+(i>>1);
  int hido = fm.getHeight()+(i>>1);
  setSize(wido,hido);

 }
}
