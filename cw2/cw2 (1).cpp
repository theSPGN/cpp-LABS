#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
using namespace std;
//Dane z pliku zapisane w sposób:
//1 2 3
//2 2 1
//3 2 1
//1 5 6
//itd.

// wynik dodany do pliku:
//Brak_rozwiazan_dla_ukladu_nr_1
//Brak_rozwiazan_dla_ukladu_nr_2
//Brak_rozwiazan_dla_ukladu_nr_3
//Rozwiazanie_dla_ukladu_nr_4:-2_oraz_-3
int main(){
	fstream plik,plik2;
	plik.open("dane.txt",ios::in|ios::out|ios::app);
	plik2.open("Odpowiedzi_do_1_zadania.txt",ios::out);
	string a,b,c;
	stringstream ss;
	int ile=0;
	float delta,x1,x2;
		while(!plik.eof()){
		plik>>a;
		plik>>b;
		plik>>c;
	
		delta=stoi(b)*stoi(b) - 4*stoi(a)*stoi(c);
		cout<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0"<<endl<<"delta:"<<delta<<endl;
		if (delta<0){
		
		cout<<"Brak rozwiazan ukladu"<<endl<<endl;	
		ss<<"Brak_rozwiazan_dla_ukladu_nr_"<<(ile+1)<<endl;
		}
		if (delta ==0){
			x1= -stoi(b)/(2*stoi(a));
			cout<<"Rozwiazanie:"<<x1<<endl;	
			ss<<"Rozwiazanie_dla_ukladu_nr_"<<(ile+1)<<": "<<x1<<endl;	
		}
		if(delta>0){
			x1= (-stoi(b)+delta)/(2*stoi(a));
			x2= (-stoi(b)-delta)/(2*stoi(a));
		cout<<"1 rozwiazanie:"<<x1<<endl;
		cout<<"2 rozwiazanie:"<<x2<<endl<<endl;
	ss<<"Rozwiazanie_dla_ukladu_nr_"<<(ile+1)<<":"<<x1<<"_oraz_"<<x2<<endl;
	}
ile++;
	}
string wypisz;
for(int i=0;i<ile;i++){

ss>>wypisz;
plik2<<wypisz;
plik2<<endl;
}
	plik.close();
	plik2.close();
	return 0;
}