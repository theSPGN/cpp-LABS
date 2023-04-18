#include<iostream>
#include<iomanip>
using namespace std;

void wypisz(int m, int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<setw(5)<<i*j;
		}
		cout<<endl;
	}
	
}

int main(){
	int m=0,n=0;
	cout<<"Podaj liczbe kolumn"<<endl;
	cin>>m;
	cout<<"Podaj liczbe wierszy"<<endl;
	cin>>n;	
	wypisz(m,n);
	return 0;
}