#include<iostream>
#include<math.h>
using namespace std;

class Wektor{
float x,y,wx,wy; // x,y punkt zaczepienia  wx,wy wspolrzedne wektora
public:
	Wektor();
	Wektor(float ax, float ay):wx(ax),wy(ay){}
	void  opisz(float ax,float ay);
	Wektor operator*(float i){
	return Wektor(i*wx,i*wy);}
	
	void wypisz(){cout<<"["<<wx<<","<<wy<<"]"<<endl;
	}
	
	float operator*(Wektor& W){
		return (wx*W.wx)+(wy*W.wy);
	}
	
	float operator~(){	
	return sqrt(wx*wx+wy*wy);	}
};
Wektor::Wektor(){
	cout<<"Podaj wektor"<<endl;
	cin>>wx;
	cin>>wy;
}

int main(){
	Wektor W0;
	Wektor W1(3,4);
	Wektor W2(2,5);
	W0.wypisz();
	W1.wypisz();
	W2.wypisz();
	cout<<"W1*5: ";
	(W1*5).wypisz();
	cout<<"W1*W2= "<<W1*W2<<endl;
	cout<<"Wartosci bezwgledne:"<<endl;
	cout<< ~W0<<endl;
	cout<< ~W1<<endl;
	cout<< ~W2<<endl;
	
	return 0;
}