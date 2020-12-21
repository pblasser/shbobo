import java.awt.*;
//import javax.swing.*;
import java.awt.image.*;
import java.awt.dnd.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
import javax.swing.*;

public class Ecole extends Container implements LayoutManager {


	TextArea t;

 Button[] bb;
	Ecole() {
	 //super();
	 t =  new TextArea("",3,100,TextArea.SCROLLBARS_NONE);
	 	 t.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 12));
	 t.setBackground(Color.BLACK);
	 t.setForeground(Color.GREEN);
	 t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.insert("dfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\ndfllkjlkj\n",0);
	t.setVisible(true);

	 setVisible(true);
  setLayout(this);
  bb = new Button[10];
  for (int i =0; i<10; i++) {
  	var b = new Button("fg"+i);
  	bb[i] = b;
  	//b.setVisible(true);
  	add(b);
  	b.setBounds(i*100, 10, 20, 20);
  	b.setVisible(true);
  }
  //add(t);
  setBackground(Color.BLACK);
  validate();
	}

public void mousies(Garcon g) {
	  	t.addMouseListener(g);
	 t.addMouseMotionListener(g);
}


 public void addLayoutComponent(String name, Component comp) {}
	public void removeLayoutComponent(Component comp) {}
	public Dimension minimumLayoutSize(Container p) { return getSize();}
	public Dimension preferredLayoutSize(Container p) { return getSize();}

 public void layoutContainer(Container p){ 
 	t.setLocation(0,0);
 	t.setSize(getSize());
  
 }


}