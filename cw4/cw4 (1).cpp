#include<iostream>
#include<cmath>

using namespace std;
const float M_PI= 3.14;
class Punkt{
	float x;
	float y;
public:
	void opisz();
	void wypisz();
	void odleglosc(Punkt &p);
	void przesun();
	void alfa();
};
void Punkt::opisz(){
	float ax; float ay;
	cout<<"Podaj wspolrzedne punktu "<<endl;
	cout<<"x: ";cin>>ax;
	cout<<"y: ";	cin>>ay;
	x=ax; y=ay;
}

void Punkt::wypisz(){ 
cout<<"Punkt:"<<"("<<round(x*100)/100<<","<<round(y*100)/100<<")"<<endl;}

void Punkt::odleglosc(Punkt &p){
	 cout<<"odleglosc: "<<sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y))<<endl;
}

void Punkt::przesun(){
	float ax; float ay;
	cout<<"Podaj wektor przesuniecia"<<endl;
	cin>>ax; cin>>ay;
	y+=ay; x+=ax;
}
void Punkt::alfa(){
	float kat;
	cout<<"Podaj kat przesuniecia wzgledem poczatku ukladu wspolrzednych"<<endl;
	cin>>kat;
	float a=x,b=y;
		y=sin(kat*M_PI/180.0)*sqrt(a*a+b*b);
		x=cos(kat*M_PI/180.0)*sqrt(a*a+b*b);
		} 
int main(){
	Punkt A,B;
	A.opisz(); 
	A.wypisz();
	
	B.opisz(); 
	B.wypisz();
	
	A.odleglosc(B);
	A.przesun();
	A.wypisz();
	B.alfa();
	B.wypisz();
	return 0;
}