#include<iostream>
#include<cmath>
const float M_PI=3.14159265358979323846;
using namespace std;
class Punkt{
	float x;
	float y;
	public:
	void opisz(float ax,float ay);
	float odleglosc(Punkt &p);
	friend class Circle;
	float getx(){return x;}
	float gety(){return y;}
	void setx(float a){x=a;}
	void sety(float a){y=a;}
	
	}; 
float Punkt::odleglosc(Punkt &p){ return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));}	
void Punkt::opisz(float ax,float ay) {
	cout<<"Podaj wspolrzedne punktu "<<endl;
	cout<<"x: ";cin>>ax;
	cout<<"y: ";	cin>>ay;
	x=ax; y=ay;}
	
class Circle{
	Punkt p;
	float r;
	public:

	Circle(float tab[2],float r){this->r=r;p.setx(tab[0]);p.sety(tab[1]);}
	Circle(float ax=0.0, float ay=0.0,float ar=0.0){r=ar;p.setx(ax);p.sety(ay);}
	
	void opisz();
	void wypisz();
	void pole(){cout<<"Pole:"<<M_PI*r*r<<endl;}
	
	string przeciec(Circle &b);
};
void Circle::opisz(){
	float ax=0.0;float ay=0.0;float ar=0.0;
	cout<<"Podaj wspolrzedne punktu "<<endl;
	cout<<"x: ";cin>>ax;
	cout<<"y: ";	cin>>ay;
	p.setx(ax); p.sety(ay);
	cout<<"Podaj promien"<<endl; cin>>ar;
r=ar;}

void Circle::wypisz(){ 
	cout<<"Punkt:"<<"("<<round(p.getx()*100)/100<<","<<round(p.gety()*100)/100<<")"<<" Promien: "<<r<<endl;}

string Circle::przeciec(Circle &b){
		string odp="";
		if ((p.odleglosc(b.p)==0)&&(r==b.r))odp= "Infinity"; 
		else if(p.odleglosc(b.p)==r+b.r) odp= "1";
		else if(p.odleglosc(b.p)==abs(r-b.r)) odp= "1";
		else if(p.odleglosc(b.p)>r+b.r) odp="0";
		else odp="2";
		return odp;
	}


int main(){
	Circle a(1,1,1);
	a.opisz();
	a.wypisz();
	Circle b(5,1,2);
	b.opisz();
	b.wypisz();
	a.pole();
	cout<<endl<<"Punktow wspolnych: "<<a.przeciec(b);
	return 0;
}