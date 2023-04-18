#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
	fstream plik1,plik2;
	plik1.open("nazwiska.txt",ios::in);
	plik2.open("nazwiskad.txt",ios::out);
	stringstream ss;
	string wypisz;
	if (plik1.good()){
	while(!plik1.eof()){
	wypisz="";
	getline(plik1,wypisz);
	wypisz[0]=toupper(wypisz[0]);
	ss<<wypisz<<endl;

	
		
			
		}
		while(!ss.eof()){	
		ss>>wypisz;
		plik2<<wypisz<<endl;
	}
	
   
	 
	
	plik2.close();
	plik1.close();
	return 0;
}}