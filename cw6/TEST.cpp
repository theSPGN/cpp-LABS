#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class rownanie{
	public:
	 int x;
	 int y;
	 float value;
	 rownanie(int tab[]){ 
	 x=tab[0];
	 y=tab[1];
	}
	void wartosc(){
		
	if(!(y==0)||(x==0)) {
		value= sqrt(1.0/x) + y*y;
		cout<<x<<","<<y<<" = "<<value<<endl;
	}	
	else cout<<x<<","<<y<<" ~blad y lub x zostalo zdefiniowane jako zero "<<endl;
	}
	void wartosc(int z){
	if(!(y==0)||(x==0)) {
		value= sqrt(1.0/x) + y*y;
		cout<<x<<","<<y<<","<<z<<" = "<<z*value<<endl;
	}	
	else cout<<x<<","<<y<<","<<z<<" ~blad y lub x zostalo zdefiniowane jako zero "<<endl;	
	}
};
int main(){
	vector <rownanie> Rownanie;
	fstream plik,plik2;
	plik.open("liczby.txt",ios::in);
	string z;
	string q;
	while(!plik.eof()){
		plik>>z;
		plik>>q;
	int tablica[2];
	tablica[0]=stoi(z);
	tablica[1]=stoi(q);
	Rownanie.push_back(tablica);
	
	}
	cout<<"X=sqrt(1/x)+y^2 & X*Z :\n"<<endl;
	for (int j=0;j<Rownanie.size();j++){
		Rownanie[j].wartosc();
		Rownanie[j].wartosc(2);
	}
	plik2.open("wynik.txt",ios::out);
	for (int j=0;j<Rownanie.size();j++){
	plik2<<Rownanie[j].value<<endl;	
	}
	
	plik.close();
	plik2.close();
	return 0;
}