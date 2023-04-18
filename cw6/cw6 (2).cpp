#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class List{
	public:
		string value;
		List(string x):value(x){}
		void show(){ cout<<value<<endl;}
	
		};
		
bool porownaj(const List &a ,const List &b) {
		return a.value<b.value;
}

int main(){
	vector <List> thing;
	fstream plik;
	plik.open("dane.txt",ios::in);
	string line;
	while(!plik.eof()){
		getline(plik,line);
		thing.push_back(line);
	}
for(int i=0;i<thing.size();i++){
	thing[i].show();
	}
	
sort(thing.begin(), thing.end(),porownaj);//https://www.geeksforgeeks.org/sort-c-stl/  
//										druga mozliwosc zamiast porownaj	[](const List &l, const List &r) -> bool { return l.value < r.value; }
cout<<endl;
for(int i=0;i<thing.size();i++){
	thing[i].show();
	}
string pojemnik=thing[1].value;
string duzy=thing[1].value;
for(int i=0;i<thing.size();i++){

if(thing[i].value.length()<pojemnik.length()) pojemnik=thing[i].value;
if(thing[i].value.length()>duzy.length()) duzy=thing[i].value;
}
cout<<endl<<pojemnik;
cout<<endl<<duzy;
	plik.close();
	return 0;
}