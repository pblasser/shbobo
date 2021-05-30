
import java.awt.*;
import javax.swing.undo.*;

public class UndoPutin
 extends AbstractUndoableEdit {
 Stub who;
 Stub whom;
 UndoPutin(Stub w, Stub m) {
 	super();
 	who = w;whom=m;
 	doo();
 }
 private void doo() {
 	whom.add(who);
 	who.requestFocusInWindow();
 }
 public void redo() {
 	super.redo();
 	doo();
 }
 public void undo() {
 	super.undo();
 	//if (!where) return;
 	whom.remove(who);
 }public boolean isSignificant(){return true;}
}