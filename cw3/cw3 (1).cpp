#include<iostream>
#include<cmath>
using namespace std;

float pierwiastek(int x){
	return sqrt(x*1.0);
}

float pierwiastek(int x,int y){
	return pow(x*1.0,(1/(y*1.0)));
}



int main(){
	for (int i=1;i<=8;i++){
		cout<<"Pierwiastki dla "<<i<<" drugiego stopnia: "<<pierwiastek(i)<<" oraz trzeciego: "<<pierwiastek(i,3)<<endl<<endl;
		
	}
	
	return 0;
}