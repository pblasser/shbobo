 //#pragma once

//static signed char gwonzulate[8];
//static unsigned char mastroBarcode =0;


struct Chub {
 bool endor;
 signed char gwonz[8];
 bool chubINIT();
 void chubRUN();
 virtual void gwonzINIT(int id) {}
 virtual void chubCALL() {}
 virtual bool chubShouldEnd(){return endor;}
 void chubSENDATE(unsigned char * rept);
 void chubSENDEND();
 void chubCLOZ();
};

