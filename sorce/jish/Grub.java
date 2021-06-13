import java.awt.*;
import java.awt.image.*;
import java.awt.dnd.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
import javax.swing.undo.*;

public class Grub extends Container 
implements DragGestureListener,
DragSourceListener, LayoutManager { 
 DragGestureRecognizer dgr;
 DropTarget dt;
 String skull;
 String[] args;
 String toolt;
 public int code;
 static Container skullholder;
 static {
 	skullholder = new Container();
 	skullholder.setFont(new Font("TimesRoman", Font.PLAIN, 10));
 	skullholder.setVisible(true);
 }
 Grub(String s, String ar, String tt, int c, int n) {
 	skull = s;
  args = ar.split(" ");
  code = c;
   
	 dgr = DragSource.getDefaultDragSource()
	  .createDefaultDragGestureRecognizer(this,
	  DnDConstants.ACTION_MOVE, this);
	 setVisible(true);
	 setSize(new Dimension(50,20));
	 setLayout(this);//new FlowLayout());
  setVisible(true);
  setBackground(new Color(0,0,0,0));
 }	
 public void tutor(){}
 int ribs;
 void resetRibs() {ribs=0;}
 String getRib() { 
  if (ribs<args.length)  
   return args[ribs++];
  return "";
 }
 int getRibCount() { return args.length; }
 int getGillCount() { return getRibCount();}
 Stub getFlesh() { return new Guts(); }
 public void addNotify() {
	 super.addNotify();
	 //dt = new DropTarget(this, DnDConstants.ACTION_MOVE, this, true);
 }
 public void removeNotify() {
 	super.removeNotify();
 	//dt.removeDropTargetListener(this);
 }

 public void paint(Graphics g) {
	 g.setColor(Color.BLACK);
	 g.drawString(skull, 10,10);
 }

 //DragSourceListener
	public void dragDropEnd(DragSourceDropEvent dsde) {}
	public void dragEnter(DragSourceDragEvent dsde) {}
 public void dragExit(DragSourceEvent dse) {}
 public void dragOver(DragSourceDragEvent dsde) {}
 public void dropActionChanged(DragSourceDragEvent dsde) {}

 //DragGestureListener

	public void dragGestureRecognized(DragGestureEvent dge) {
		Bloque b = new Bloque(0);
		add(b);
    	b.add(new Guts(skull));
		for (int i=0;i<args.length;i++) {
          b.add(new Guts(""+i));
		}

    	
    	Stub.draggerman=b;
    	System.out.println("draggest");
		BufferedImage i = new BufferedImage(b.getWidth(),b.getHeight(),
		 BufferedImage.TYPE_INT_ARGB);
		Graphics g  = i.createGraphics();
		b.paint(g);
		g.dispose();
		DragSource ds = dge.getDragSource();
		ds.startDrag(dge,Cursor.getPredefinedCursor(Cursor.MOVE_CURSOR),
		 i, new Point(10,10), b, b); 
	}
 public boolean isOpaque() {return false;}

 //LayoutManager
	public void addLayoutComponent(String name, Component comp) {}
	public void removeLayoutComponent(Component comp) {}
	public Dimension minimumLayoutSize(Container p) { return getSize();}
	public Dimension preferredLayoutSize(Container p) { return getSize();}
 public void layoutContainer(Container p){ 
 	
 }
}
