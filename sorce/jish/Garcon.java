import java.awt.*;
//import javax.swing.*;
import java.awt.image.*;
import java.awt.dnd.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
//import javax.swing.*;

import java.util.ArrayList;
import java.util.Iterator;


public class Garcon extends Frame 
 implements MouseMotionListener, MouseListener, 
 LayoutManager {
 	boolean resizing;
	Point point;
	public Chubber chub;
 ArrayList<Grub> ecole;
 GrubFactory gf;
	Container c;
 public static Grub evilGrub;
 static { evilGrub = new Grub("","","",0,0); }
	Garcon() {
	 super();
	 ecole = new ArrayList<Grub>();
	 chub =  new Chubber();
	 point = new Point();
	 setUndecorated(true);
	 setBounds(100,100,400,400);
	 setFocusableWindowState(true);
	 //setAlwaysOnTop(true);
	 //pane = new Ecole();
	 gf = new GrubFactory(); //Perspex Stabile
	 Iterator<Grub> foreach = gf.ecole.iterator();
  while (foreach.hasNext()) add(foreach.next());
  add(chub);
  setVisible(true);
  setLayout(this);
  chub.addMouseListener(this);
	 chub.addMouseMotionListener(this);
  validate();
	}
 public Grub lookup(String s) {
  Iterator<Grub> foreach = gf.ecole.iterator();
  while (foreach.hasNext()) {
   Grub g = foreach.next();
  // System.out.println(s+" "+g.skull);
   if (s.startsWith(g.skull)) return g;
  } 
  //System.out.println("evil");
  return evilGrub;
 }
public void mouseEntered(MouseEvent e) {}
public void mouseExited(MouseEvent e) {}
public void mouseReleased(MouseEvent e) {}
public void mouseClicked(MouseEvent e) {}
 public void mousePressed(MouseEvent e) {
  point.x = e.getX();
  point.y = e.getY();
  resizing = chub.getCursor().equals(Cursor.getDefaultCursor())? false:true;
 }
 public void mouseDragged(MouseEvent e) {
 	Point pt = e.getPoint();
  if(resizing){
   setSize(getWidth()+pt.x - point.x,getHeight()+pt.y-point.y);
   point.x = pt.x;point.y = pt.y;
  }
  else {
   Point p = getLocation();
   setLocation(p.x + e.getX() - point.x,
   p.y + e.getY() - point.y);
  }
 } 
 public void mouseMoved(MouseEvent e) {
  Point cursorLocation = e.getPoint();
  int xPos = cursorLocation.x;
  int yPos = cursorLocation.y;
  if ((xPos>getWidth()-10)&&(yPos>getHeight()-10)) chub.setCursor(Cursor.getPredefinedCursor(Cursor.SE_RESIZE_CURSOR));
  else chub.setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
 }



 public void addLayoutComponent(String name, Component comp) {}
	public void removeLayoutComponent(Component comp) {}
	public Dimension minimumLayoutSize(Container p) { return getSize();}
	public Dimension preferredLayoutSize(Container p) { return getSize();}
 public void layoutContainer(Container p){ 
  Insets i = getInsets();
  //System.out.println("insety");
  chub.setBounds(i.left, i.top, getWidth()-i.left-i.right, getHeight()-i.top-i.bottom);
  Iterator<Grub> foreach = gf.ecole.iterator();
  int wido = 5;
  int hido = 5;
  while (foreach.hasNext()) {
  	Grub g = foreach.next();
   if (wido > getWidth() - g.getWidth()) {
    hido += g.getHeight()+5; wido = 5;
   } g.setLocation(wido,hido);
   wido += g.getWidth()+5;
  }
}






 	//pane.setBounds(i.left, i.top, getWidth()-i.left-i.right, getHeight()-i.top-i.bottom);
 

}