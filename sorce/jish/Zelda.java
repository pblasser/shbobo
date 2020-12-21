import java.awt.*;
import java.awt.geom.*;
import java.awt.image.*;
import java.awt.event.*;


public class Zelda extends Panel 
implements MouseMotionListener, MouseListener {
Point point;
boolean resizing;
Image im;
Rectangle frame;
float reduction;
	Zelda() {
  point = new Point();
	 setVisible(true);
  //setBackground(Color.GREEN);
  validate();
  addMouseListener(this);
	 addMouseMotionListener(this);
	}

	public void imago(Image i) {
		 im = i;
	}

	 public void paint(Graphics g) {
	

	// im.getScaledInstance(getWidth(),getHeight());
	framerei();
	 g.drawImage(im, 0, 0, (int)(reduction*(float)im.getWidth(null)),(int)(reduction*(float)im.getHeight(null)), null);
	 //super.paint(g);

    AffineTransform l = AffineTransform.
     getScaleInstance(reduction,reduction);
    Graphics2D g2d = (Graphics2D)g;
    g2d.setColor(Color.YELLOW);
    g2d.setStroke(new BasicStroke(1));
    g2d.draw(l.createTransformedShape(frame));

 }


public void framerei() {
 Julia j = Julia.getJulia(this);
 if (j==null) return;
 frame = new Rectangle(j.sp.getScrollPosition(),
  j.sp.getViewportSize());
 System.out.println(j.sp.getScrollPosition());
 System.out.println(j.sp.getVAdjustable().getValue());
 Rectangle max = j.gg.getBounds();
 float dx = (float)getWidth() / (float)(max.width);
 float dy = (float)getHeight() / (float)(max.height);
 reduction  = (dx>dy ? dy : dx);
 //j.sp.setScrollPosition(20,20);
}




public void mouseEntered(MouseEvent e) {}
public void mouseExited(MouseEvent e) {}
public void mouseReleased(MouseEvent e) {}
public void mouseClicked(MouseEvent e) {

  e.getX();
  e.getY();
}
 public void mousePressed(MouseEvent e) {
  point.x = e.getX();
  point.y = e.getY();
  resizing = getCursor().equals(Cursor.getDefaultCursor())? false:true;
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

  } //getParent().validate();
 } 
 public void mouseMoved(MouseEvent e) {
  Point cursorLocation = e.getPoint();
  int xPos = cursorLocation.x;
  int yPos = cursorLocation.y;
  if ((xPos>getWidth()-10)&&(yPos>getHeight()-10)) {
  	setCursor(Cursor.getPredefinedCursor(Cursor.SE_RESIZE_CURSOR));
  }else setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
 } 

}