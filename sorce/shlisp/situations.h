
unsigned char mastroBarcode = 0;
unsigned char situation_txt[65536];
unsigned short situation_place = 0;
unsigned short situations_vector[256];
//unsigned short situations_length; // of now
//unsigned char situations_amt = 0;
unsigned char situations_plz = 0;
#if defined(BILLGATES) 
unsigned char bytebuff[8];
#else 
unsigned char bytebuff[8];
#endif
int bytesz = 0;
int masterbytesz = 0;

void write_bytez(unsigned char byte);
void situsb();

void insituate (unsigned char byte) {
//	printf("insituate%d\n",byte);
 situation_txt[situation_place++] = byte;
}

void situatier () {
 if (situations_plz>0)
  situations_vector[situations_plz] = 
	 situation_place;// - 1; getting rid of intro barcode
 situations_plz++;
}

void situatend () {
 //situations_plz++;
}

void write_bytez (unsigned char byte) {
 masterbytesz++;
 bytebuff[bytesz++] = byte;
 bytesz %= 8;
 if (bytesz == 0) {
  chubSEND(bytebuff,8);
 }
 printf("%d ",byte);
}

#define packshort(vec) \
write_bytez((unsigned char)vec);\
write_bytez((unsigned char)(vec>>8));

void situsb() {
 
 unsigned short i;
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
 for (i = 0; i < situation_place; i++) 
  write_bytez(situation_txt[i]);
}

 
