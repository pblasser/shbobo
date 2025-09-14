import java.awt.*;
import java.io.*;
import java.awt.event.*;

public class Chubber extends TextArea implements TextListener {
 Chubber() {
		super("",3,100,TextArea.SCROLLBARS_NONE);
		addTextListener(this);

	 setFont(new Font(Font.MONOSPACED, Font.PLAIN, 12));
	 setBackground(Color.BLACK);
	 setForeground(Color.GREEN);
	 setEditable(false);
	 enableInputMethods(true);
	 jish(" -h","");
}

 public void textValueChanged(TextEvent e) {
	   setCaretPosition(getText().length());
 }
 public void jish(String flg, String txt) {
  String cmd="shlisp";
  String oss = "_mac"+File.separator;
  try{
   System.out.println(System.getProperty("os.name"));
   if(System.getProperty("os.name").startsWith("Linux")) oss = "_lin"+File.separator;
   else if (System.getProperty("os.name").startsWith("Windows")) {
   oss ="_win"+File.separator; cmd=cmd+".exe";}
   cmd=new File(Julia.class.getProtectionDomain()
   .getCodeSource().getLocation().toURI()).getParent()+File.separator+oss+cmd+" "+flg;
   append(cmd+"\n");
   Process child = Runtime.getRuntime().exec(cmd);
   InputStream lsOut = child.getInputStream();
    InputStream lsErr = child.getErrorStream();
   OutputStream os = child.getOutputStream();
   OutputStreamWriter osw = new OutputStreamWriter(os);
   osw.write(txt,0,txt.length());
   osw.close();
   //osw.flush();

   InputStreamReader r = new InputStreamReader(lsOut);
   BufferedReader in = new BufferedReader(r);
   String line;
   while ((line=in.readLine())!=null) {
	   append(line+"\n");
	   setCaretPosition(getText().length());
   }
   lsOut.close();
   
   r = new InputStreamReader(lsErr);
   in = new BufferedReader(r);
   
   while ((line=in.readLine())!=null) {
	   append(line+"\n");
	   setCaretPosition(getText().length());
   }
   lsErr.close();
   
   
   
   
   
  } catch (Exception e) {}
 }

}
 
