 //#pragma once

static signed char gwonzulate[8];
static unsigned char mastroBarcode =0;

class Chub {
protected:
 signed char gwonz[8];
public:
 
 bool chubINIT();
 void chubRUN();
 virtual void gwonzINIT(int id) {}
 virtual void chubCALL() {}
 virtual bool chubShouldEnd(){return false;}
 void chubSENDATE(unsigned char * rept);
 void chubSENDEND();
 void chubCLOZ();
};

