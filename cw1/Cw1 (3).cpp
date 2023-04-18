#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

const char zakres1[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char zakres2[]="0123456789";
const char zakres3[]="!@#$%^&*()";
const char zakres4[]={'a','e','i','o','u'};
const char zakres5[]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','u','v','w','x','y','z'};

int main(){
		srand(time(NULL));
	int dlugosc=0;int pointer=1;int pamiec=0;string haslo;int pamiec2=0;
	while(dlugosc<3){	
	cout<<"Podaj dlugosc hasla"<<endl; cin>>dlugosc;
}
cout<<"Twoje haslo to: ";
	for(int i=0;i<dlugosc;i++){
	
		if(i>=3){
		pointer=rand()%5+1;
		while(pointer==pamiec){
		pointer=rand()%5+1;}
		}
		if(i<3){
		pointer=rand()%3+1;
		while((pointer==pamiec)||(pointer==pamiec2)){//AD.1
		pointer=rand()%3+1;}
		}
		
		
		switch(pointer){ 
			case 1:haslo[i]=zakres1[rand()%(sizeof(zakres1))];
				break;
			case 2:haslo[i]=zakres2[rand()%(sizeof(zakres2))];
				break;
			case 3:haslo[i]=zakres3[rand()%(sizeof(zakres3))];
				break;
			case 4:haslo[i]=zakres4[rand()%(sizeof(zakres4))];
				break;
			case 5:haslo[i]=zakres5[rand()%(sizeof(zakres5))];
				break;
		}
	cout<<haslo[i];
	
		if(i>1)	pamiec=pointer;
		if (i==0)pamiec=pointer;  // AD.1
		if (i==1)pamiec2=pointer; // ZAPEWNIENIE SOBIE WARUNKU ŻE 3 PIERWSZE ZNAKI TO DUŻA LITERA LICZBA I ZNAK SPECJALNY W DOWOLNEJ KOLEJNOŚCI
	}
	
	return 0;
}
