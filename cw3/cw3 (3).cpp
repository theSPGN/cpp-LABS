#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

const int mnoznik=5;

int ile(){
	fstream plik;
	string y;
	int ile=0;
	plik.open("dane.txt",ios::in);
	while(!plik.eof()){
			getline(plik,y); ile++;
	}

	
	plik.close();
	return ile;
}

void wczytaj(int **macierz){
	fstream plik;
	string y;
	plik.open("dane.txt",ios::in);
	for(int i=0;i<ile();i++){
		macierz[i]=new int[ile()];
		for(int j=0;j<ile();j++){
			plik>>y;
		macierz[i][j]=stoi(y);
		}
	}
	
	plik.close();
}
void wypisz(int **macierz){
	for(int i=0;i<ile();i++){
		cout<<"|";
		for(int j=0;j<ile();j++){
		if(j!=(ile()-1))	cout.width(ile()+1);
		cout<<left;
		cout<<macierz[i][j];
			
		}
		cout<<"|";
	cout<<endl;
	}
}

void suma(int **macierz){
	int diagonalna=0;
	for(int i=0,j=0;i<ile();i++,j++){
			diagonalna+=macierz[i][j];
	}
	
	cout<<"Suma liczb na diagonalnej: "<<diagonalna<<endl;
}

void skalar(int **macierz,int xd=1){
	int macierzp[ile()][ile()];
	for(int i=0;i<ile();i++){
		for(int j=0;j<ile();j++){
			macierzp[i][j]=xd*macierz[i][j];
			
		}
	}	
for(int i=0;i<ile();i++){
		for(int j=0;j<ile();j++){
			macierz[i][j]=macierzp[i][j];
			
		}
	}	



}

void iloczyn(int **macierz){
	int s;
	int d=ile();
	int matrix[d][d];
	for(int i=0;i<d;i++){
		for(int j=0;j<d;j++){
		s=0;	
		for(int k=0;k<d;k++) s+=macierz[i][k]*macierz[k][j];
		
		matrix[i][j]=s;
				
	
		}
		
	}
	for(int i=0;i<ile();i++){
		for(int j=0;j<ile();j++){
			macierz[i][j]=matrix[i][j];
			
		}
	}	
	
}


int main(){
	
	int **Matrix=new int *[ile()];
	cout<<"Macierz:"<<endl;
	wczytaj(Matrix);
	wypisz(Matrix);
	cout<<endl;
	suma(Matrix);
	skalar(Matrix,mnoznik);
	cout<<endl<<"Macierz przemnozona przez 5: "<<endl;
	wypisz(Matrix);
	cout<<endl<<"Macierz przemnozona przez sama siebie:"<<endl;
	wczytaj(Matrix); // ponowne wczytanie ponieważ macież Matrix uległa zmianie w poleceniu skalar
	iloczyn(Matrix);
	wypisz(Matrix);
	
	delete Matrix [];
	return 0;
}