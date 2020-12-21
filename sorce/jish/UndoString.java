
import java.awt.*;
import javax.swing.undo.*;

public class UndoString
 extends AbstractUndoableEdit {
 Stub who;
 String sew, old;
 UndoString(Stub w, String s, String o) {
 	super();
 	who = w;
 	sew = s;
 	old = o;
 	doo();
 }
 private void doo() {
 	who.chng(sew);
 }
 public void redo() {
 	super.redo();
 	doo();
 }
 public void undo() {
 	super.undo();
 	who.chng(old);
 }
}