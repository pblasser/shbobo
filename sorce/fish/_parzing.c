
//#include <string>         // std::string

Stub * Stub::parze(String & ss) {
 if (ss.isEmpty()) return nullptr;
 ss = ss.trimCharactersAtStart(" \t");
  
 static String brakstrin = String("\n\r");
 static String numstrin = String("*/+-%^&|!@#0123456789abcdefghijklmnopqrstuvwxyz");
 String brakcandi = ss.initialSectionContainingOnly(brakstrin);

 if (!brakcandi.isEmpty()) {
  ss = ss.substring(brakcandi.length());
  return new Bubble("");
 }
 if (ss.startsWith(";")) {
  int toWhere = ss.indexOfAnyOf("\n\r");
  String poop = ss.substring(1,toWhere);
  ss = ss.substring(toWhere+1);
  ss = ss.trimCharactersAtStart("\n\r");
  return new Bubble(poop);
 }
 String numcandi = ss.initialSectionContainingOnly(numstrin);
 if (!numcandi.isEmpty()) {
  ss = ss.substring(numcandi.length());
  return new Guts(numcandi);
 }
  Recipe * r;
 if (ss.startsWith("[")) {
  ss = ss.substring(1);
  r = new Tank(); r->parze(ss);
  return r;
 }
 if (ss.startsWith("<")) {
  ss = ss.substring(1);
  r = new Boat(); r->parze(ss);
  return r;
 }
 if (ss.startsWith("(")) {
  ss = ss.substring(1);
  r = new Fish(); r->parze(ss);
  return r;
 }
 if (ss.startsWith("{")) {
  ss = ss.substring(1);
  r = new Soup(); r->parze(ss);
  return r;
 }
  
 return nullptr;
 //return parze(ss);
}

Recipe * Recipe::parze(String & ss) {
 if (ss.isEmpty()) return this;
 ss = ss.trimCharactersAtStart(" \t");
 static String sterminal = String(")}]>");
 //Logger::outputDebugString (ss);
 String brakcandi = ss.initialSectionContainingOnly(sterminal);
 if (!brakcandi.isEmpty()) {
  //Logger::outputDebugString (ss);
  ss = ss.substring(1);
  return this;
 }
 Stub*s = Stub::parze(ss);
 if (s) addAndMakeVisible(s);
 return parze(ss);
}
