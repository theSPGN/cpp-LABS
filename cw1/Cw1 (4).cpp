#include<iostream>
#include<string>
#include<fstream>
#include <algorithm>
using namespace std;
//lista słów pochodzi z : https://raw.githubusercontent.com/ehamiter/anagram/master/wordlist.txt
//slowo należy wpisac w języku angielskim
//nie każde jest umieszczone na liscie
int main(){
string wyraz;
cin>>wyraz;cout<<endl;
fstream plik;
string wyraz_z_pliku;
plik.open("anagram.txt",ios::in); // przykładem jest "sleep" lub "solve"

	while(plik.eof()!=true)
	{
		getline(plik,wyraz_z_pliku);
		string s=wyraz_z_pliku;
		sort(wyraz_z_pliku.begin(),wyraz_z_pliku.end());
		sort(wyraz.begin(),wyraz.end());
		
		
		
		if(wyraz_z_pliku==wyraz){
			cout<<s<<endl;
		}
	}
	
plik.close();
	return 0;
}