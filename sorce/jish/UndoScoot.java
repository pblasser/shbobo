
import java.awt.*;
import javax.swing.undo.*;

public class UndoScoot
 extends AbstractUndoableEdit {
 Stub who;
 Stub whom;
 Container where;
 UndoScoot(Stub w, Stub m) {
 	super();
 	who = w;whom=m;
 	doo();
 }
 private void doo() {
 	where = whom.getParent();
 	int indo = where.getComponentZOrder(whom);
 	where.add(who,indo);
 	who.requestFocusInWindow();
 }
 public void redo() {
 	super.redo();
 	doo();
 }
 public void undo() {
 	super.undo();
 	//if (!where) return;
 	where.remove(who);
 }public boolean isSignificant(){return true;}
}