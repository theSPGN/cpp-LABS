#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
const string cz_zn=",.?!-*~#$%^&()_<>/\[]{}:;\"";
//"-koniec-" nie jest liczone jako wiersz oraz jako znaki i slowa! , nalezy po wpisaniu wiersza umiescic w nowej lini napis: -koniec- 
// zakoncz to program i wypisze informacje ktore nas interesuja, przykladowy wiersz oraz zrodlo znajduje sie pod programem w komentarzu
// wiersz mozna skopiowac i wkleic w konsoli programu po uruchomieniu

int main(){
	string input="";
	string wyraz;
	int znaki=0,wiersze=0,slowa=0,spacje=0;
	while(input!="-koniec-"){
	stringstream ss;
	getline(cin,input);
	wiersze++;
	ss<<input;
	while(!ss.eof()){
	slowa++;
	ss>>wyraz;
	for(int i=0;i<sizeof(cz_zn);i++){
	if(count(wyraz.begin(),wyraz.end(),cz_zn[i])!=0) znaki+=count(wyraz.begin(),wyraz.end(),cz_zn[i]);	
	}

	
	spacje++;
}
		}

cout<<"Spacje:"<<spacje-wiersze<<endl;
cout<<"Wiersze:"<<wiersze-1<<endl;
cout<<"Slowa:"<<slowa-1<<endl;
cout<<"liczba znakow interpunkcyjnych:"<<znaki-2<<endl;

	return 0;
}
/* Wiersz autorstwa Ma�gorzaty Strza�kowskiej �r�d�o: https://polszczyzna.pl/lamance-jezykowe/
JAMNIK
W grz�skich trzcinach i szuwarach 
kroczy jamnik w szarawarach, 
szarpie k��cza oczeretu 
i przytracza do beretu, 
wa�kom p�ki skrzypu wr�cza, 
traszkom suchych trzcin nar�cza, 
a gdy zmierzcha� si� zaczyna 
z jaszczurkami sprzeczk� wszczyna, 
po czym znika w oczerecie 
w szarawarach i berecie.....
*/