

class Zelda : public Component {
public:
 Image i;
juce::Rectangle<int> frame;
 float reduction;
 ResizableBorderComponent rbc;
 Zelda() : Component(), rbc(this, nullptr) {
  setSize(100,100);
  rbc.setBorderThickness(BorderSize<int>(10));
  addAndMakeVisible(&rbc);
  setWantsKeyboardFocus(false);
 }
 ~Zelda() { }
 void paint(Graphics &g) {
  //g.setColour (Colours::yellow);
  //g.fillRoundedRectangle (1,1, getWidth()-1, getHeight()-1,5);
  framerei();
  juce::Rectangle<int> b= i.getBounds() * reduction;
  g.drawImageAt(i.rescaled(b.getWidth(),b.getHeight()),0,0);
  g.setColour (Colours::yellow);
  g.drawRect(frame);
 }
 void resized() {
  rbc.setBounds(0,0,getWidth(),getHeight());
 }
 void framerei() ;
 ComponentDragger myDragger;
 void mouseDown (const MouseEvent& e);
 void mouseUp(const MouseEvent& e);

 void mouseDrag (const MouseEvent& e) {
  myDragger.dragComponent (this, e, nullptr);
 }
};
