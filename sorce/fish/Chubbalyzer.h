
struct Chubbalyzer : public Chub, public ThreadWithProgressWindow {
 unsigned char situation_txt[65536];
 unsigned short situation_place;
 unsigned short situations_vector[256];
 unsigned short situations_plz;
#if defined(BILLGATES) 
 unsigned char bytebuff[8];
#else 
 unsigned char bytebuff[8];
#endif
 int bytesz;
 int masterbytesz;
 double progressDeno;
 File binary;
 double progress;
#define IDEOSPAZ "\xe3\x80\x80"
 Chubbalyzer(File f) : 
  ThreadWithProgressWindow ("Uploader", true, true) {
   if (f.exists()) binary = f;
  resetSituations();
  chubINIT();
  progressDeno = 1.0;
 }
 ~Chubbalyzer() {

  chubSENDEND();
  printf("closing\n");
  chubCLOZ();
 }
 void resetSituations() {
  situation_place = 0;
  situations_plz = 0;
  bytesz = 0;
  masterbytesz = 0;
 }
 void insituate (unsigned char byte) {
  if (situations_plz > 255) return;
  situation_txt[situation_place++] = byte;
 }
 void situatier () {
  if (situations_plz > 255) return;
  if (situations_plz>0)
   situations_vector[situations_plz] = 
	  situation_place; //-1;no barcoding
  situations_plz++;
 }
 void situatend () {

 }
 void write_bytez (unsigned char byte) {
  masterbytesz++;
  setProgress ((double)masterbytesz/progressDeno);
  bytebuff[bytesz++] = byte;
  bytesz %= 8;
  if (bytesz == 0) {
   chubSENDATE(bytebuff);
  }
  printf("%d ",byte);
 }
	
 
 void binarify() {
  unsigned char c;
  FileInputStream * fis = binary.createInputStream();
  situsb();
  while (masterbytesz < 0x10000) {
   if (threadShouldExit()) {
    //chubSENDEND();
    return;
   }
   write_bytez(0);
  }
  fis->setPosition(0x20000);
  fis->read(&c,1);
  while (!fis->isExhausted()) {
   if (threadShouldExit()) {
    //chubSENDEND();
    return;
   }
   write_bytez(c);
   fis->read(&c,1);
   //c = fgetc (filefish);
  }
  chubSENDEND();
 }

 
 
#define packshort(vec) \
write_bytez((unsigned char)vec);\
write_bytez((unsigned char)(vec>>8));

 void situsb() {
  unsigned short i;
  for (int i = 0; i < 16; i++) insituate(0);
  situations_plz  = (situations_plz < 1 ? 1 : situations_plz );
  for (i = 0; i < situations_plz; i++) {
   if (i == 0) {
    write_bytez(mastroBarcode);
    write_bytez(situations_plz - 1);
   } else {
    situations_vector[i] += 
     ((situations_plz - 1) << 1) + 2;
    packshort(situations_vector[i])
   }  
  }
  for (i = 0; i < situation_place; i++) {
	  if (threadShouldExit()) {
		  //chubSENDEND();
		  return;
	  }
   if (masterbytesz >= 0x10000) return;
   write_bytez(situation_txt[i]);
  }
 }
 
 bool chubShouldEnd() { return threadShouldExit(); }


 void run () {
  if (binary.exists()) {
   progressDeno = 0x30000;
   situsb();
   binarify();
  } else {
   progressDeno = situation_place;
   situsb();
  }
 }
};
 
