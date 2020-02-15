#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	
	int opc;
	
	do{
		cout<<"\tMENU"<<endl;
		cout<<"1. AZUL"<<endl;
		cout<<"2. VERDE"<<endl;
		cout<<"3. AGUAAMARINA"<<endl;
		cout<<"4. ROJO"<<endl;
		cout<<"5. PURPURA"<<endl;
		cout<<"6. BLANCO"<<endl;
		cout<<"7. GRIS"<<endl;
		cout<<"8. AZUL CLARO"<<endl;
		cout<<"9. VERDE CLARO"<<endl;
		cout<<"10. AGUAMARINA CLARO"<<endl;
		cout<<"11. ROJO CLARO"<<endl;
		cout<<"12. PURPURA CLARO"<<endl;
		cout<<"13. AMARILLO CLARO"<<endl;
		cout<<"14. BLANCO BRILLANTE"<<endl;
		cout<<endl<<"OPCION: ";
		cin>>opc;
		switch(opc){
			case 1: system("color f1");break; 
			case 2: system("color f2");break;
			case 3: system("color f3");break;
			case 4: system("color f4");break;
			case 5: system("color f5");break;
			case 6: system("color f6");break;
			case 7: system("color f7");break;
			case 8: system("color f8");break;
			case 9: system("color f9");;break;
			case 10: system("color fa");;break;
			case 11: system("color fb");break;
			case 12: system("color fc");break;
			case 13: system("color fd");break;
			case 14: system("color fe");break;
			default: system("color 0f");
		}
		system("cls");
	}while(opc != 0);
	return 0;
}

