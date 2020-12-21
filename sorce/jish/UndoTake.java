
import java.awt.*;
import javax.swing.undo.*;

public class UndoTake
 extends AbstractUndoableEdit {
 Stub who;
 Container where;
 int which;
 UndoTake(Stub w) {
 	super();
 	who = w;
 	doo();
 }
 private void doo() {
 	where = who.getParent();
 	System.out.println("par"+where.getLocation().x);
 	which = where.getComponentZOrder(who);
 	where.remove(which);
 }
 public void redo() {
 	super.redo();
 	doo();
 }
 public void undo() {
 	super.undo();
 	//if (!where) return;
 	where.add(who,which);
 }
}