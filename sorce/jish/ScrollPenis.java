import java.awt.*;
 

public class ScrollPenis extends ScrollPane {
 ScrollPenis() {
 	super();
 }
 public void validate() {
  Point p = getScrollPosition();
  super.validate();
  setScrollPosition(p);
 }


 public void doLayout() {
  Point p = getScrollPosition();
  super.doLayout();
  setScrollPosition(p);
 }
}