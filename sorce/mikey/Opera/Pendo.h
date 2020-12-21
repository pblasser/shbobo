
class Pendold : public Opero {
 float tx[4]; //th th' ti ti'
	float dx[4];
 Opero *sp,*spp,*q;
 public:
 static const char className[];
 Pendold(lua_State *L) : Opero() {
	 dx[0] = dx[1] = 0;
	 tx[0] = tx[1] = 20;
	 tx[2] = tx[3] = 20;
	 
  inn = lunar_getopero(L,1);
  sp = lunar_getopero(L,2);
	 spp = lunar_getopero(L,3);
  q = lunar_getopero(L,4,0.1);
  mul = lunar_getopero(L,5,1.0);
  addd = lunar_getopero(L,6);
 }
 float calx(float sr) {  
  float f = 2.0*sin(PI * sp->sounder() / (float)sr);
  f = (f<=0.0 ? -f : f);
	 float couple = 0.04;
  dx[0] = tx[1]; //lp in is bp
  dx[1] = inn->sounder() - tx[0] - tx[0]*couple*tx[2];
  dx[1] -= tx[1] * q->sounder();
  
  tx[0] += dx[0] * f;
  tx[1] += dx[1] * f; //bp is hp * f
  tx[0] = fmin(fmax(tx[0],-128.0),128.0);
  tx[1] = fmin(fmax(tx[1],-128.0),128.0);
	 
	 f = 2.0*sin(PI * spp->sounder() / (float)sr);
	 f = (f<=0.0 ? -f : f);
	 dx[2] = tx[3]; //lp in is bp
	 dx[3] = inn->sounder() - tx[2] - tx[2]*couple*tx[0];
	 dx[3] -= tx[3] * q->sounder();
	 
	 tx[2] += dx[2] * f;
	 tx[3] += dx[3] * f; //bp is hp * f
	 tx[2] = fmin(fmax(tx[2],-128.0),128.0);
	 tx[3] = fmin(fmax(tx[3],-128.0),128.0);
	 
  return tx[0] * mul->sounder() +addd->sounder();
 }
};


class Pendo : public Opero {
	float tx[4]; //th th' ti ti'
	float dx[4];
	float m1, m2; //point masses at the ends of the arms
	float g;      //gravity constant
	float l1, l2; //arm lengths
	Opero *sp,*spp,*q;
public:
	float inline frand() { 
		return (float)(rand()%1111) / (float)(1111); }
	//returns from 0 to 1
	float inline frand(float Max) { 
		return frand() * Max; 
	}
	//returns from 0 to Max
	float inline frand(float Min, float Max) { 
		return (frand() * (Max - Min)) + Min; 
	} //returns from Min to Max
	static const char className[];
	Pendo(lua_State *L) : Opero() {
		m1=frand(1,3);
		m2=frand(0.5,2);
		l1=frand(0.8,4);
		l2=5-l1;
		g=10; 
		dx[0] = dx[2] = 0;
		tx[0] = tx[2] = 0;
		tx[1] = tx[3] = 0;
		
		inn = lunar_getopero(L,1);
		sp = lunar_getopero(L,2);
		spp = lunar_getopero(L,3);
		q = lunar_getopero(L,4,0.2);
		mul = lunar_getopero(L,5,1.0);
		addd = lunar_getopero(L,6);
		//printf("done init pendo\n");
	}
	float calx(float sr) {  
	//COUPLED PENDULUM
		float f = 2.0*sin(PI * sp->sounder() / (float)sr);
		f = (f<=0.0 ? -f : f);
		float couple = 0.01;//10.4;
		dx[0] = tx[1]; //lp in is bp
		dx[1] = inn->sounder() - tx[0] - couple*fmax(tx[0]-tx[2],0);
		dx[1] = inn->sounder() - tx[0] - couple*pow(tx[0]-tx[2],1);
		dx[1] -= tx[1] * q->sounder();
		
		tx[0] += dx[0] * f;
		tx[1] += dx[1] * f; //bp is hp * f
		tx[0] = fmin(fmax(tx[0],-128.0),128.0);
		tx[1] = fmin(fmax(tx[1],-128.0),128.0);
		
		f = 2.0*sin(PI * spp->sounder() / (float)sr);
		f = (f<=0.0 ? -f : f);
		dx[2] = tx[3]; //lp in is bp
		dx[3] = inn->sounder() - tx[2] - couple*fmax(0,tx[2]-tx[0]);
		dx[3] = inn->sounder() - tx[2] - couple*pow(tx[2]-tx[0],1);
		dx[3] -= tx[3] * q->sounder();
		
		tx[2] += dx[2] * f;
		tx[3] += dx[3] * f; //bp is hp * f
		tx[2] = fmin(fmax(tx[2],-128.0),128.0);
		tx[3] = fmin(fmax(tx[3],-128.0),128.0);
		
		return tx[0] * mul->sounder() +addd->sounder();
	}
	float calxo(float sr) {  
	//DOUBLE PENDULUM
		float f = 2.0*sin(PI * sp->sounder() / (float)sr);
		f = (f<=0.0 ? -f : f);
		float couple = 0.04;
		//evaluate the state functions
		
		dx[0] = tx[1];
		//dx[1] = 
		dx[1] =  -g*(2*m1 + m2)*sin(tx[0]) -
		m2*g*sin(tx[0]-2*tx[2]) -
		2*sin(tx[0] - tx[2])*m2*(tx[3]*tx[3] * l2 +
							   tx[1]*tx[1]*l1 * cos(tx[0] - tx[2]));
		dx[1] = dx[1]/(l1*(2*m1 + m2 -m2*cos(2*tx[0]-2*tx[2])));
		dx[1] = dx[1]-0.08*tx[1]/(abs(tx[1])+0.01); //friction, should probably be elaborated on
		dx[1] -= inn->sounder();
		dx[2] = tx[3];
		
		dx[3] = 2*sin(tx[0] - tx[2])*(tx[1]*tx[1]*l1*(m1 + m2) +
									g*(m1 + m2)*cos(tx[0]) +
									tx[3]*tx[3]*l2*m2*cos(tx[0] - tx[2]));
		dx[3] = dx[3]/(l2*(2*m1 + m2 -m2*cos(2*tx[0]-2*tx[2])));
		dx[3] = dx[3]-0.1*tx[3]/(abs(tx[3])+0.01); //friction
		
		//euler step
		tx[0] += f*dx[0];
		tx[1] += f*dx[1];
		tx[2] += f*dx[2];
		tx[3] += f*dx[3];
		
		return tx[0] * mul->sounder() +addd->sounder();
	}
	float calxoo(float sr) {  
	//DUFFING OSCILLATOR
		float f = 2.0*sin(PI * sp->sounder() / (float)sr);
		f = (f<=0.0 ? -f : f);
		//evaluate the state functions
		dx[0] = tx[1]; //lp in is bp
		float tri = (tx[0] * tx[0] * tx[0]);
		dx[1] = inn->sounder();// - tx[0];
		dx[1] -= tx[0]*sin(tx[0]*100);
		//dx[1] -= 0.1*tri;//0.005*(tri-tx[0]);
		dx[1] -= tx[1] * q->sounder();
		
		tx[0] += dx[0] * f;
		tx[1] += dx[1] * f; //bp is hp * f
		//tx[0] = fmin(fmax(tx[0],-128.0),128.0);
		//tx[1] = fmin(fmax(tx[1],-128.0),128.0);
		
		return tx[0] * mul->sounder() +addd->sounder();
	}
};
const char Pendo::className[] = "Pendo";



