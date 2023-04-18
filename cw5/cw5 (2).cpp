#include<iostream>
#include<string>
using namespace std;

class dana{
	string wartosc;
	string sprawdz;
public:

	dana();
	dana(string wartoscpodana):wartosc(wartoscpodana){};
	dana(const dana &dx );
	void	wypisz(){cout<<wartosc<<endl;}
	void	wczytaj();
	void	virtual isvalid();
	string	getwartosc(){ return wartosc;}
	string  getsprawdz(){return sprawdz;} 
	void	setwartosc(string w){wartosc=w;}
};
dana::dana(){
	cout<<"Dane konstruktora: ";
	cin>>wartosc;}
dana::dana(const dana &dx ){
	wartosc=dx.wartosc;
	sprawdz=dx.sprawdz;
		}
void dana::wczytaj(){
	cout<<"Podaj dane do sprawdzenia: ";
	cin>>sprawdz;
	}
void dana::isvalid(){
	if(sprawdz==wartosc) cout<<"Zgodne"<<endl;
	else cout<<"Nie zgodne"<<endl;
}

class bok:public dana{
	public:
	
		bok(){
			while(stof(getwartosc())<0){
			cout<<"Blad danych dlugosc nie moze byc <0"<<endl;
			
			string x;
			cin>>x;
		setwartosc(x);
			}
	
		}
		void isvalid ()override{
			while(stof(getsprawdz())<0){
			cout<<"Blad danych dlugosc nie moze byc <0 "<<endl;
			wczytaj();}
			
			 if(getsprawdz()==getwartosc()) cout<<"Zgodne"<<endl;
			else cout<<"Nie zgodne"<<endl;
		}
};


class kat:public dana{
	public:
	
			kat(){
			while((stof(getwartosc())<0)||(stof(getwartosc())>360)){
			cout<<"Blad danych kat ma zawierac sie w zakrecie "<<endl;
			string x;
			cin>>x;
		setwartosc(x);
			}}
			
		void isvalid ()override{
		while((stof(getsprawdz())<0)||(stof(getsprawdz())>360)){
			cout<<"Blad danych kat ma zawierac sie w zakresie 0-360 "<<endl;
			wczytaj();}
			
			if(getsprawdz()==getwartosc()) cout<<"Zgodne"<<endl;
			
			else cout<<"Nie zgodne"<<endl;
			
			
		}
};

int main(){
	dana d;
	d.wczytaj();
	d.isvalid();
	bok b;
	b.wczytaj();
	b.isvalid();
	kat k;
	k.wczytaj();
	k.isvalid();
	return 0;
}