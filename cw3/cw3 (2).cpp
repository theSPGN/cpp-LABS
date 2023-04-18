#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

const int mnoznik=5;


void wczytaj(int macierz[][3]){
	fstream plik;
	string y;
	plik.open("dane.txt",ios::in);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			plik>>y;
			macierz[i][j]=stoi(y);
		}
	}
	
	plik.close();
}
void wypisz(int macierz[][3]){
	for(int i=0;i<3;i++){
		cout<<"|";
		for(int j=0;j<3;j++){
		if(j!=2)	cout.width(4);
			cout<<left;
			cout<<macierz[i][j];
			
		}
		cout<<"|"<<endl;
	}
}
void suma(int macierz[][3],int rozmiar=3){
	int diagonalna=0;
	for(int i=0,j=0;i<rozmiar;i++,j++){
			diagonalna+=macierz[i][j];
	}
	
	cout<<"Suma liczb na diagonalnej: "<<diagonalna<<endl;
}
void skalar(int macierz[][3],int ile=1){
	int macierzp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			macierzp[i][j]=ile*macierz[i][j];
			
		}
	}	
	wypisz(macierzp);
}
void iloczyn(int macierz[][3]){
	int s;
	int matrix[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		s=0;	
		for(int k=0;k<3;k++) s+=macierz[i][k]*macierz[k][j];
		
		matrix[i][j]=s;
				
	
		}
		
	}
	
	wypisz(matrix);
}


int main(){
	int Matrix[3][3];
	wczytaj(Matrix);
	wypisz(Matrix);
	suma(Matrix);
	skalar(Matrix,mnoznik);
	cout<<endl;
	iloczyn(Matrix);
	
	return 0;
}