
import java.awt.*;
import javax.swing.undo.*;

public class UndoFudge
 extends AbstractUndoableEdit {
 Stub who;
 Stub whom;
 Container where;
 UndoFudge(Stub w, Stub m) {
 	super();
 	who = w;whom=m;
 	doo();
 }
 private void doo() {
 	where = whom.getParent();
 	int indo = where.getComponentZOrder(whom);
 	where.add(who,indo+1);
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
 }
}