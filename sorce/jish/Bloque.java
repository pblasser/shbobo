import java.io.*;
import java.awt.geom.*;
import java.awt.*;
import javax.swing.undo.*;
import java.awt.dnd.*;

public class Bloque extends Recipe { 
 public int type;
 static GeneralPath gp[];
 static char[] openers = {'(','{','[','<'};
 static char[] closers = {')','}',']','>'};
 static {
 	gp = new GeneralPath[4];
 	for (int i=0;i<4;i++) 
 		gp[i]=new GeneralPath();
 	gp[0].moveTo(0,0);
 	gp[0].curveTo(1.2,0,1.2,1,0,1);
 	//gp[0].quadTo(1,0.5,0,1);
 	
 	gp[1].moveTo(0,0);
 	gp[1].curveTo(1.2,0,1.2,0.4,0,0.4);
 	//gp[1].quadTo(1,0.2,0,0.4);
 	gp[1].lineTo(1,0.5);
 	gp[1].lineTo(0,0.6);
  gp[1].curveTo(1.2,0.6,1.2,1,0,1);
 	
 	//gp[1].quadTo(1,0.8,0,1);
  
  gp[2].moveTo(0,0);
 	gp[2].lineTo(1,0);
  gp[2].lineTo(1,1);
  gp[2].lineTo(0,1);

  gp[3].moveTo(0,0);
 	gp[3].lineTo(1,0.5);
  gp[3].lineTo(0,1);
 }
 Bloque(int t) {
	 super();
	 type = t%4;
	 repaint();
	}
public Stub clone() {
  Bloque clonedMyClass = new Bloque(type);
  for (int i =0; i<getComponentCount(); i++) {
    Stub s = ((Stub)getComponent(i));
    clonedMyClass.add(s.clone());
  }
  return clonedMyClass ;
 }
 public void visitInsert(Stub s) {
 	if (getComponentCount()<1) 
 		um.addEdit(new UndoPutin(s,this));
  else um.addEdit(new UndoFudge(s,this));
 }

    public void drop(DropTargetDropEvent dtde) {
     stubbornDrop(dtde);
  }
 public void stubbornTake() {
  um.addEdit(new UndoTake(this));
 }

  public String toString() {
   return openers[type]+super.toString()+closers[type];
  }
  public void paint(Graphics g) {
  	//stubbornPaint(g);
  	int siz = getFont().getSize();
	  AffineTransform l = AffineTransform.
	   getTranslateInstance(siz,0);
	  l.scale(-siz,getHeight()-1);
	  AffineTransform r = AffineTransform.
	   getTranslateInstance(getWidth()-siz,0);
	  r.scale(siz-1,getHeight()-1);

	  Graphics2D g2d = (Graphics2D)g;
	  g2d.setColor(getPastry(type<2));
	  stubbornPaint(g);
 	 
	  //g2d.setColor(Color.YELLOW);//getPastry(true));
	  Rectangle rrr = new Rectangle(getSize());
	  rrr.grow(-siz,0);
	  if (fudge==scoot) 
	  	g2d.fill(rrr);
	  if (scoot) 
	  	g2d.fill(l.createTransformedShape(gp[type]));
   if (fudge)  
    g2d.fill(r.createTransformedShape(gp[type]));
   if(!scoot!=!fudge) {
    g2d.setColor(getPastry(type<2));
    g2d.fill(rrr);
   }
   if (!scoot)
    g2d.fill(l.createTransformedShape(gp[type]));
 if (!fudge)
  g2d.fill(r.createTransformedShape(gp[type]));

	 g2d.setStroke(new BasicStroke(1));
	 g2d.setColor(Color.BLACK);
   g2d.draw(l.createTransformedShape(gp[type]));
   g2d.draw(r.createTransformedShape(gp[type]));
 drawSubtext(g,false);
   paintComponents(g);
 }



 public void layoutContainer(Container p){ 
 	int siz = getFont().getSize();
  stubbornLayout(new Rectangle(siz,siz+(siz>>1),siz,0));
 }

}
