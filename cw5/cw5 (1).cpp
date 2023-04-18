#include<iostream>
using namespace std;
class Plaska{
	float dlugosc;
	float szerokosc;
	float r;
	float wysokosc;
	public:
		Plaska(){dlugosc=0;szerokosc=0;}
		Plaska(float ax, float ay):dlugosc(ax),szerokosc(ay){}
		Plaska(float ax):r(ax){}
		Plaska(float ax, float ay,float ah):dlugosc(ax),szerokosc(ay),wysokosc(ah){}
	

		void opisz(float ax, float ay);
		void opisz(float ax){r=ax;}
		void opisz(float ax, float ay,float ah);
		float getd(){return dlugosc;}
		float gets(){return szerokosc;}
		float getr(){return r;}
		string virtual nazwa(){return "figura";}
	
	float virtual pole(){ return 0;}
	float virtual obwod(){ return 0;}
	void virtual info();

};
	void Plaska::opisz(float ax, float ay){
	
		dlugosc=ax; szerokosc=ay;
		}
	void Plaska::opisz(float ax, float ay,float ah){
		dlugosc=ax; szerokosc=ay; wysokosc=ah;}
	void Plaska::info(){
		cout<<endl;
		cout<<"Nazwa obiektu: "<< nazwa()<<endl;
		cout<<"Pole powierzchni: "<< pole()<<endl;
		cout<<"Obwod/obrys: "<< obwod()<<endl;
	}	



class Prostokat :public Plaska{
	public:
		Prostokat();
		Prostokat(float x, float y){opisz(x,y);}
		
		string nazwa(){return "prostokat";}	
		
	float pole() override;
	float obwod()override;
};
	float Prostokat::pole() {
		float a=getd();
		float b=gets();
		return a*b;
	}
	float Prostokat::obwod(){
		float a=getd();
		float b=gets();
		
		return 2*a+2*b;
	}

Prostokat::Prostokat(){
	cout<<"Podaj dlugosc i szerokosc prostokata"<<endl;
	float x,y;
	cin>>x;
	cin>>y;
opisz(x,y);
	
}
class Kwadrat :public Plaska{
	public:
		Kwadrat();
		Kwadrat(float x){opisz(x);
		}
		string nazwa(){
			return "kwadrat";
		}
	float pole() override{
	
		return getr()*getr();
	}
	float obwod()override{

		return 4*getr();
		}
};
Kwadrat::Kwadrat(){
	cout<<"Podaj bok kwadratu"<<endl;
	float x;
	cin>>x;
opisz(x);
}

class Przestrzenna:public Plaska{
	float grubosc;
	
	public:
		Przestrzenna(Prostokat &F){opisz(F.getd(),F.gets()); cout<<"Podaj grubosc"<<endl;cin>>grubosc;   
		};
		Przestrzenna(Kwadrat &F){opisz(F.getr()); cin>>grubosc;
		}
		
		Przestrzenna(Prostokat &F, float y){opisz(F.getd(),F.gets()); grubosc=y;  
		}
		Przestrzenna(Kwadrat &F,float y){opisz(F.getr());grubosc=y;
		}
	string nazwa(){return "prostopadloscian";}
	float pole() override;
	float obwod()override;
	float objetosc();
	void  info();
};
float Przestrzenna::pole(){
		float a=getd();
		float b=gets();
		float polee=a*b*2+a*grubosc*2+b*grubosc*2;
		if(a==b){
		if(getd()!=0)polee=getd()*getd()*2+getd()*grubosc*4;
		else polee=getr()*getr()*2+getr()*grubosc*4;
		}
		return polee;
	}
float Przestrzenna::objetosc(){
		float a=getd();
		float b=gets();
		float obj=a*b*grubosc;
		if(obj==0) obj=getr()*getr()*grubosc;
		return obj;
	}
void  Przestrzenna::info(){
	cout<<endl;
	cout<<"Nazwa obiektu: "<< nazwa()<<endl;
	cout<<"Pole powierzchni: "<< pole()<<endl;
	cout<<"Obwod/obrys: "<< obwod()<<endl;
	cout<<"Objetosc: "<< objetosc()<<endl;
	}	
float Przestrzenna::obwod(){
		float a=getd();
		float b=gets();
		float obwodd=4*a+4*b+4*grubosc;
		if(a==b){
		if((getd()!=0)&&(gets()!=0))	obwodd=4*a+4*b+4*grubosc;
		else	obwodd=4*getr()+4*getr()+4*grubosc;
		}
		return obwodd;
		
	}




int main(){
	cout<<"Obiekty:"<<endl;
//	Plaska P1(5,5); 
//	P1.info(); FUNKCJE W KLASIE PLASKA DOMYSLNIE WYPISUJA 0
//	Prostokat P2(3,5);
//	P2.info();
	Prostokat P3;
	P3.info();
//	Kwadrat K1(2);
//	K1.info();
	Kwadrat K2;
	K2.info();
	Przestrzenna A0(P3);
	A0.info();
	Przestrzenna A1(P3,5);
	A1.info();
	Przestrzenna A2(K2,5);
	A2.info();
	return 0;
}