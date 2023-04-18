#include<iostream>
#include<cmath>
using namespace std;


int main(){
	string odp="tak";
	string pomocnicza="";
	float a=0,b=0,c=0,delta=0,x1=0,x2=0;
	while(odp!="nie"){
		a=0;b=0;c=0;delta=0;x1=0;x2=0;
		cout<<"Podaj wsp a,b,c"<<endl;
		cin>>a>>b>>c;
		cout<<endl;
		delta=(b*b)-(4*a*c);
		
		if(delta==0){
		x1=(-b+sqrt(delta))/2*a;
		cout<<x1;
		}
		if (delta <0)cout<<"Brak"<<endl;
	else{
		x1=(-b+sqrt(delta))/2*a;
		cout<<x1<<endl;
		x2=(-b-sqrt(delta))/2*a;
		cout<<x2<<endl;
	}
	do{
	
	cout<<endl<<"czy powtorzyc?";
	cin>>odp;
	pomocnicza=odp;
	for(int i=0;i<sizeof(odp);i++){
		odp[i]=tolower(pomocnicza[i]);
	}
}while((odp!="nie")&&(odp!="tak"));

}
	return 0;}