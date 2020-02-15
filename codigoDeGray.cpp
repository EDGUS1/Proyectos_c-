#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void bgray();
void gbina();

int main(){
	
	int opc;
	
	do{
		system("cls");
		cout<<"\t\tMENU"<<endl;
		cout<<"1. Convertir de binario a Gray"<<endl;
		cout<<"2. Convertir de Gray a binario"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case 1: bgray();break;
			case 2: gbina();break;
		}
	}while(opc != 0);
	
	return 0;
}
void bgray(){
	string a;
	int b[100],c=0,e;
	char d[2];
	
	system("cls");
	cout<<"Ingrese el numero binario: ";
	cin>>a;
	
	d[0] = a[0];
	e = atoi(d);
	b[0] = e;
	
	for(int i=0;i<(a.length()-1);i++){
		if((a[i]=='1' && a[i+1] == '1') || (a[i] == '0' && a[i+1] == '0')){
			b[i+1] = 0;
		}else{
			b[i+1] = 1;
		}
		c++;
	}
	
	cout<<"Codigo de gray: ";
	
	for(int i=0;i<=c;i++){
		cout<<b[i];
	}
	getch();
}

void gbina(){
	string a;
	int g[100],c=0,e;
	char d[2];
	
	system("cls");
	cout<<"Ingrese el numero en gray: ";
	cin>>a;
	
	d[0] = a[0];
	e = atoi(d);
	g[0] = e;
	
	for(int i=1;i<a.length();i++){
		if((a[i] == '1' && g[i-1] == 1) || (a[i] == '0' && g[i-1] == 0)){
			g[i] = 0;
		}else{
			g[i] = 1;
		}
		c++;
	}
	
	cout<<"Codigo en binario: ";
	
	for(int i=0;i<=c;i++){
		cout<<g[i];
	}
	getch();
}
