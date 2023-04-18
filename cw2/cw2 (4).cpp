#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct Kontakt{
	string imie;
	string nazwisko;
	string numer;
};
int main(){
int odp=0;
stringstream ss;
string pojemnik="";
int czy_znaleziono;
fstream plik;
Kontakt y;
string im,naz,nr,imz,nazz,nrz;
int odliczanie=0;

while(odp!=5){
	czy_znaleziono=0;
	im="";naz="";nr="";imz="",nazz="",nrz="";
	cout<<"1.Znajdz"<<endl<<"2.Dodaj"<<endl<<"3.Edytuj"<<endl<<"4.Usun"<<endl<<"5.Wyjdz"<<endl;
odliczanie=0;
	pojemnik="";
	y.imie="";
	y.nazwisko="";
	y.numer="";
	ss.str("");
	cin>>odp;
	switch(odp){
		case 1:
			plik.open("ksiazka.txt",ios::in);
			cout<<"podaj imie i nazwisko osoby ktorej szukasz"<<endl; cin>>im>>naz;
			czy_znaleziono=0;
			
		while((!plik.eof())&&(czy_znaleziono==0)){
			getline(plik,y.imie);
			getline(plik,y.nazwisko);
			getline(plik,y.numer);
			if(y.imie+y.nazwisko==im+naz){cout<<y.imie<<y.nazwisko<<y.numer<<endl; czy_znaleziono++;
			}
			}
			
			
			if(czy_znaleziono==0)cout<<"Nie ma takiego kontaktu na twojej liście"<<endl;
			plik.close();
			break;
		case 2:
			plik.open("ksiazka.txt",ios::out|ios::app);
			cout<<"Podaj kontakt do dodania im/naz/nr"<<endl;
			cin>>im>>naz>>nr;
			plik<<im<<endl<<naz<<endl<<nr<<endl;
			plik.close();
			break;
		case 3:
		plik.open("ksiazka.txt",ios::in);
			cout<<"Podaj kontakt do edycji im/naz/nr"<<endl;
			cin>>im>>naz>>nr;
			cout<<"Podaj kontakt po edycji im/naz/nr"<<endl;
			cin>>imz>>nazz>>nrz;
			while(!plik.eof()){
			getline(plik,y.imie);
			getline(plik,y.nazwisko);
			getline(plik,y.numer);
			
			if((im==y.imie)&&(naz==y.nazwisko)&&(nr==y.numer)){
			ss<<imz<<endl<<nazz<<endl<<nrz<<endl; odliczanie+=2;
		}
		else if((y.imie.empty())+(y.nazwisko.empty())+(y.numer.empty())==0) {ss<<y.imie<<endl<<y.nazwisko<<endl<<y.numer<<endl; odliczanie+=3;
		}
		}
		plik.close();
			plik.open("ksiazka.txt",ios::out);
			
			for(int i=0; i<odliczanie+1;i++){	ss>>pojemnik;
			plik<<pojemnik<<endl;
			}
			plik.close();
			
			break; 
		case 4:
			plik.open("ksiazka.txt",ios::in);
			ss.str("");
			cout<<"Podaj kontakt do usuniecia im/naz/nr"<<endl;
			cin>>im>>naz>>nr;
			while(!plik.eof()){
			getline(plik,y.imie);
			getline(plik,y.nazwisko);
			getline(plik,y.numer);
			
			if((im==y.imie)&&(naz==y.nazwisko)&&(nr==y.numer)){
		}
		else if((y.imie.empty())+(y.nazwisko.empty())+(y.numer.empty())==0) {ss<<endl<<y.imie<<endl<<y.nazwisko<<endl<<y.numer; odliczanie+=3;
		}
		}
		plik.close();
			plik.open("ksiazka.txt",ios::out);
			
			for(int i=0; i<odliczanie;i++){	ss>>pojemnik;
			plik<<pojemnik<<endl;
			}
			plik.close();
			break;
		case 5:return 0;
			
}}
	return 0;}

