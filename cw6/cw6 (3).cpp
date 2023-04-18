#include<iostream>
#include<map>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	map<int,string> mojamapa;
	fstream plik;
	plik.open("imiona.txt",ios::in);
	int i=0;
	while(!plik.eof()){
		getline(plik,mojamapa[i]);
		i++;
	}
	vector<string> wynik;
	string pojemnik="";
	int count;
	for(i=0;i<mojamapa.size();i++){
		count=0;
		for(int j=0;j<mojamapa.size();j++){
			if(mojamapa[i]==mojamapa[j]) count++;
		}
		pojemnik=mojamapa[i]+' '+to_string(count)+' '+to_string(count)+'/'+to_string(mojamapa.size());
		if (find(wynik.begin(), wynik.end(), pojemnik) == wynik.end()) 	wynik.push_back(pojemnik);	
	}
	sort(wynik.begin(),wynik.end()); //dla alfabetycznego ułóżenia
	for(int i=0;i<wynik.size();i++){
	cout<<wynik[i]<<endl;
}
	plik.close();
	return 0;
}