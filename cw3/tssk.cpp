#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int sprawdzile(){
	fstream plik;
	string y;
	int ile=0;
	plik.open("liczby.txt",ios::in);
	while(!plik.eof()){	
		ile++;
		plik>>y;
	}
	plik.close();
	return ile;
	
	
}
void wczytaj(float tablica[]){
fstream plik; 
plik.open("liczby.txt",ios::in);
for(int i=0;i<sprawdzile();i++){
	plik>>tablica[i];
}

plik.close();
}

void pisz(float (w)(float[]),float x[]){
    cout<<w(x)<<endl;
}
float suma(float tablica[]){
    float odp=0.0;
    for(int i=0;i<sprawdzile();i++){
        odp+=tablica[i];
    }
    return odp;
}
float aryt(float tablica[]){
    return suma(tablica)*1.0/sprawdzile()*1.0;

}
float geom(float tablica[]){
float odp=1.0;
for(int i=0;i<sprawdzile();i++) odp*=tablica[i];
return sqrt(odp);
}

int main(){

    float *tab=new float[sprawdzile()];
    wczytaj(tab);

pisz(suma,tab);
pisz(aryt,tab);
pisz(geom,tab); 


delete[] tab;
return 0;
}