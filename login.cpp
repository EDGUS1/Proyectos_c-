#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){
	char a;
	string s = "PROCESANDO...";
	vector<char> v;
	vector<char> contra;
	
	contra.push_back('1');
	contra.push_back('2');
	contra.push_back('3');
	contra.push_back('4');
	
	cout << "PASSWORD: ";
	//LEYENDO CONTRASEÑA
	a = getch();
	
	while(a != 13){
		v.push_back(a);
		cout << "*";
		a = getch();
	}
	
	system("cls");
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < s.length(); j++){
			cout << s[j];
			Sleep(100);
		}
		system("cls");
	}
	
	if(contra == v){
		cout << "BIENVENIDO";
	}else{
		cout << "CONTRASENYA INCORRECTA";
	}
	getch();
	return 0;
}
