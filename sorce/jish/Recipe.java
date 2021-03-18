import java.awt.*;
import java.awt.image.*;
import java.awt.dnd.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
import javax.swing.undo.*;
import java.io.*;
import java.util.*;

public class Recipe extends Stub implements LayoutManager,ContainerListener { 
 static {
 	KeyboardFocusManager kfm = KeyboardFocusManager.getCurrentKeyboardFocusManager();
  Set forwardKeys = kfm.getDefaultFocusTraversalKeys(
    KeyboardFocusManager.FORWARD_TRAVERSAL_KEYS);
  Set newForwardKeys = new HashSet(forwardKeys);
  newForwardKeys.add(AWTKeyStroke.getAWTKeyStroke(KeyEvent.VK_RIGHT, 0));
  kfm.setDefaultFocusTraversalKeys(KeyboardFocusManager.FORWARD_TRAVERSAL_KEYS,
    newForwardKeys);
  Set backers = new HashSet<AWTKeyStroke>(); 
  backers.add(AWTKeyStroke.getAWTKeyStroke(KeyEvent.VK_LEFT, 0));
  kfm.setDefaultFocusTraversalKeys(KeyboardFocusManager.BACKWARD_TRAVERSAL_KEYS,
    backers);
 }
 Recipe() {
	 super();
	 setLayout(this);
	 addContainerListener(this);
	}

 public void parze(PushbackReader pr) {
 	int c = 0;
 	while (c>-1) {
 		try {c=pr.read();}catch (Exception e) {}
 		if ((c==')')||(c=='}')||(c==']')||(c=='>')) 
   	return;
   if (c==32) continue;
 	 Stub s = parze(c);
   if (s!=null) {
   	s.parze(pr);
   	add(s);
   }
  } 
 }
 public void stubbornTake() {
  //um.addEdit(new UndoTake(this));
 }
 public String toString() {
 	String s = "";
  for (int i =0; i<getComponentCount(); i++) {
  	if(i>0) s+=" ";
  	s+=getComponent(i).toString();
  } return s;
 }

 public void visitInsert(Stub s) {
   um.addEdit(new UndoPutin(s,this));
  }
 public void visitAlnum(char c) {
 	visitInsert(new Guts(c));
 }
 public int mask(int i) { return i & 0xFF; }
 public Color getPastry(boolean col) {
  int hh = mask (cumulopasty);
  int green = ((hh <= 127 ? hh : 255 - hh) + 126 + 1);
  if (col) return new Color(mask((511-hh)>>1),mask(green),mask((255+hh)>>1));
  else return new Color((511-hh)>>1,(511-hh)>>1,(511-hh)>>1);//.withMultipliedSaturation(0);
  }

 public void paint(Graphics g) {
	 Rectangle r = new Rectangle(getSize());
	 Graphics2D g2D = (Graphics2D) g;
   g2D.setColor(getPastry(true));
   //g2D.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC,0.25f));
   g2D.fill(r);
	
	 paintComponents(g);
 }

 
 public void componentAdded(ContainerEvent e){

e.getChild().validate();
validate();
 }

 public void componentRemoved(ContainerEvent e) {
 	   validate();
//validate to remove dragdrop frame to frame
 }

  	public void addLayoutComponent(String name, Component comp) {}
	public void removeLayoutComponent(Component comp) {}
	public Dimension minimumLayoutSize(Container p) { return getSize();}
	public Dimension preferredLayoutSize(Container p) { return getSize();}
	public void stubbornLayout(Rectangle r) {
  int siz = getFont().getSize();
  cumulopasty=0;
  for (int i =0; i<getComponentCount(); i++) {
  	((Stub)getComponent(i)).boundsVisit(r);
  	((Stub)getComponent(i)).visitPastry(this);
  }
  setSize(r.width+siz,r.height+r.y+(siz>>2));

	}
 public void layoutContainer(Container p){ 
 	int siz = getFont().getSize();
  stubbornLayout(new Rectangle(siz,siz+(siz>>1),siz,0));
 }




}
