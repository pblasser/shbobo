import java.awt.*;
import java.awt.event.*;
import java.io.*;
import  javax.swing.*;
import java.awt.image.*;
import javax.swing.*;
import javax.swing.filechooser.*;
import java.io.File; 
import java.nio.file.*;   


public class Julia extends Frame 
implements LayoutManager, ActionListener, WindowListener {
  public ScrollPane sp;
  public Recipe gg;
  Zelda z;
  //ArrayList<Julia> windows;
  static int sz_julia;
  static Garcon gar;
 static {
  gar=new Garcon();
  sz_julia=0;
}
 Julia() {
  super("JISH");
  setFont(new Font("TimesRoman", Font.PLAIN, 20));
  setSize(400,400);
  z = new Zelda();
  z.setBounds(200,200,50,50);
  add(z);
  sp = new ScrollPane();
  add(sp);
  gg = new Recipe();
  sp.add(gg);
  gg.add(new Guts('c'));
  gg.validate();
  imago();
  menuu();
  setVisible(true);
  sz_julia++;
  addWindowListener(this);
 }


 public void neww() {
  new Julia();
 }
 public void zoomInn() {
  float snew = getFont().getSize()+1;
  if (snew<1) snew = 1;
  setFont(getFont().deriveFont(snew));
  System.out.println("zoijoijfdsa");
  validate();
 }
 public void zoomOut() {
  float snew = getFont().getSize()-1;
  if (snew<1) snew = 1;
  setFont(getFont().deriveFont(snew));
  validate();
 }
 public void serve(String flg) {
  gar.chub.jish(flg, gg.toString());

 }
 public void actionPerformed(ActionEvent e) {
  System.out.println(e.getActionCommand());
  if (e.getActionCommand()=="New") neww();
  if (e.getActionCommand()=="Open...") open();
  if (e.getActionCommand()=="Save...") save();
  if (e.getActionCommand()=="Zoom inn") zoomInn();
  if (e.getActionCommand()=="Zoom out") zoomOut();
  if (e.getActionCommand()=="Serve") serve("");
  if (e.getActionCommand()=="Change Cuisine") serve("-bshnbth.bin");
  if (e.getActionCommand()=="Gwonz") serve("-g");
 }

 public void menuu() {
  MenuBar m = new MenuBar();
  Menu mm = new Menu("File");
  MenuItem mn = new MenuItem("New", new MenuShortcut(KeyEvent.VK_N));
  mn.addActionListener(this);
  mm.add(mn);
  mn = new MenuItem("Open...", new MenuShortcut(KeyEvent.VK_O));
  mn.addActionListener(this);
  mm.add(mn);
  mn = new MenuItem("Save...", new MenuShortcut(KeyEvent.VK_S));
  mn.addActionListener(this);
  mm.add(mn);
  m.add(mm);

  mm = new Menu("Edit");
  m.add(mm);

  mm = new Menu("View");
  mn = new MenuItem("Zoom inn", new MenuShortcut(KeyEvent.VK_EQUALS));
  mn.addActionListener(this);
  mm.add(mn);
  mn = new MenuItem("Zoom out", new MenuShortcut(KeyEvent.VK_MINUS));
 mn.addActionListener(this);
  mm.add(mn);
  m.add(mm);


  mm = new Menu("Shbobo");
  mn = new MenuItem("Serve", new MenuShortcut(KeyEvent.VK_U));
  mn.addActionListener(this);
  mm.add(mn);
  mn = new MenuItem("Change Cuisine", new MenuShortcut(KeyEvent.VK_Y));
  mn.addActionListener(this);
  mm.add(mn);
    mn = new MenuItem("Gwonz", new MenuShortcut(KeyEvent.VK_T));
  mn.addActionListener(this);
  mm.add(mn);
  m.add(mm);





  setMenuBar(m);
 }

 public void imago() {
   BufferedImage i = new BufferedImage(gg.getWidth(),gg.getHeight(),
     BufferedImage.TYPE_INT_ARGB);
    Graphics ggg  = i.createGraphics();
    gg.paint(ggg);
    ggg.dispose();
    z.imago(i);
 }

 public void paint(Graphics g) {
  imago();
  super.paint(g);
 }
 static File fileplacer = null;
 static JFileChooser chooser = new JFileChooser();
 static {
  FileNameExtensionFilter filter = new FileNameExtensionFilter(
        "shlisp textes", "shlisp", "txt", "texte");
  chooser.setFileFilter(filter);
 }
public void open() {
  //JFileChooser chooser = new JFileChooser();
  chooser.setCurrentDirectory(fileplacer);
  chooser.setDialogTitle("peter's custom opener");
  int result = chooser.showOpenDialog(this);
  if (result == JFileChooser.APPROVE_OPTION) {
    fileplacer = chooser.getSelectedFile();
    try { 
    sp.remove(gg);
    gg = new Recipe();
    gg.parze(new PushbackReader(new FileReader(fileplacer)));
    sp.add(gg);
    gg.validate();
    } catch (Exception e) { e.printStackTrace(); }
  }
}

public void save() {
  //JFileChooser chooser = new JFileChooser();
  chooser.setCurrentDirectory(fileplacer);
  chooser.setDialogTitle("peter's custom saver");
  int result = chooser.showDialog(this, "save");
//  int result = chooser.showSaveDialog(this);

  if (result == JFileChooser.APPROVE_OPTION) {
    fileplacer = chooser.getSelectedFile();
    try { 
      FileWriter fw = new FileWriter(fileplacer);
      fw.write(gg.toString());
      fw.close();
    } catch (IOException e) { e.printStackTrace(); }
  }
}

  public void addLayoutComponent(String name, Component comp) {}
  public void removeLayoutComponent(Component comp) {}
  public Dimension minimumLayoutSize(Container p) { return getSize();}
  public Dimension preferredLayoutSize(Container p) { return getSize();}
 public void layoutContainer(Container p){ 
  Insets i = getInsets();
  sp.setBounds(i.left, i.top, getWidth()-i.left-i.right, getHeight()-i.top-i.bottom);
  //pane.setBounds(i.left, i.top, getWidth()-i.left-i.right, getHeight()-i.top-i.bottom);
 }

 public void windowActivated(WindowEvent e) {}
  public void windowClosing(WindowEvent e) {
   dispose(); sz_julia--; 
   if (sz_julia<1) System.exit(0);
  }
   public void windowClosed(WindowEvent e) {}
     public void windowDeactivated(WindowEvent e) {}
       public void windowDeiconified(WindowEvent e) {}
         public void windowIconified(WindowEvent e) {}
           public void windowOpened(WindowEvent e) {}


public static Julia getJulia(Container c){
  while (c instanceof Julia != true) {
    c = c.getParent();
    if (c == null) return null;
  } return (Julia)c;
 }
 public static void main (String[] args) {new Julia();}

}

