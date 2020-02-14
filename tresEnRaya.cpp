#include<iostream>
#include<windows.h> //gotoxy
#include<conio.h>//getch
#include<stdlib.h>
#include<time.h>

using namespace std;

void gotoxy(int,int);
void dibujarEquis(int);
void equis(int,int,int);
void dibujarCirculo(int);
void circulo(int,int,int,int,int,int);
void cuadro();
void cuadro2();
bool busq(int mat[][3],int);
bool ganador(int mat[][3]);

string jug1 = "jugador 1",  jug2 = "jugador 2";

int main(){
	int opc, a,b, cont = 0, mat[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	bool band = true;
	
	srand(time(NULL));
	a  = rand() % 10;

	cuadro();
	cuadro2();
	
	gotoxy(5,30);
	cout<<"JUEGO"<<endl;
	
	while(cont < 9){
		if(a%2==0){
			gotoxy(5,31);
			cout<<"Turno de "<<jug1<<endl;
			do{
				do{
					gotoxy(5,32);
					cout<<"            ";
					gotoxy(5,32);
					cout<<"opc: ";
					cin>>opc;
				}while(opc<1 || opc >9);
				band = busq(mat,opc);
			}while(band == true);
			dibujarEquis(opc);
			b = 1;
		}else{
			gotoxy(5,31);
			cout<<"Turno de "<<jug2<<endl;
			do{
				do{
					gotoxy(5,32);
					cout<<"            ";
					gotoxy(5,32);
					cout<<"opc: ";
					cin>>opc;
				}while(opc<1 || opc >9);
				band = busq(mat,opc);
			}while(band == true);
			dibujarCirculo(opc);
			b = 2;
		}
		
		switch(opc){
			case 1: mat[0][0] = b;break;
			case 2: mat[0][1] = b;break;
			case 3: mat[0][2] = b;break;
			case 4: mat[1][0] = b;break;
			case 5: mat[1][1] = b;break;
			case 6: mat[1][2] = b;break;
			case 7: mat[2][0] = b;break;
			case 8: mat[2][1] = b;break;
			case 9: mat[2][2] = b;break;
			default:break;
		}
		a++;
		cont++;
		gotoxy(5,32);
		cout<<"                ";
		if(ganador(mat) == 1){
			break;
		}
	}
	
	gotoxy(5,31);
	cout<<"                                          ";
	gotoxy(5,30);
	cout<<"                                          ";
		
	gotoxy(30,30);
	cout<<"Fin del juego"<<endl;
	gotoxy(5,40);

	getch();
	return 0;
}
void dibujarEquis(int opc){
	switch(opc){
		case 1: equis(12, 8, 4);break;
		case 2: equis(26, 22, 4);break;
		case 3: equis(40, 36, 4);break;
		case 4: equis(12, 8, 12);break;
		case 5: equis(26, 22, 12);break;
		case 6: equis(40, 36, 12);break;
		case 7: equis(12, 8, 20);break;
		case 8: equis(26, 22, 20);break;
		case 9: equis(40, 36, 20);break;
		default:break;
	}
}
void equis(int e, int c, int d){
	for(int i=0;i<5;i++){
		gotoxy(c,d);
		cout<<"x";
		gotoxy(e,d);
		cout<<"x";
		c++;d++;e--;
	}
}
void dibujarCirculo(int opc){
	switch(opc){
		case 1: circulo(8,12,4,8,5,9);break;
		case 2: circulo(22,26,4,8,5,23);break;
		case 3: circulo(36,40,4,8,5,37);break;
		case 4: circulo(8,12,12,16,13,9);break;
		case 5: circulo(22,26,12,16,13,23);break;
		case 6: circulo(36,40,12,16,13,37);break;
		case 7: circulo(8,12,20,24,21,9);break;
		case 8: circulo(22,26,20,24,21,23);break;
		case 9: circulo(36,40,20,24,21,37);break;
		default:break;
	}
}
void circulo(int a, int b, int c,int d,int x,int y){
	for(int i=0;i<3;i++){//vertical
		gotoxy(a,x);
		cout<<"o";
		gotoxy(b,x);
		cout<<"o";
		x++;
	}
	for(int i=0;i<3;i++){//horizontal
		gotoxy(y,c);
		cout<<"o";
		gotoxy(y,d);
		cout<<"o";
		y++;
	}
}
void cuadro(){
	int a=2,b=3;
	for(int i=0;i<22;i++){//horizontales
		gotoxy(b,2);
		cout<<"*";
		gotoxy(b,10);
		cout<<"*";
		gotoxy(b,18);
		cout<<"*";
		gotoxy(b,26);
		cout<<"*";
		b++;b++;
	}
	for(int i=0;i<24;i++){//verticales
		gotoxy(3,a);
		cout<<"*";
		gotoxy(17,a);
		cout<<"*";
		gotoxy(31,a);
		cout<<"*";
		gotoxy(45,a);
		cout<<"*";
		a++;
	}
}
void cuadro2(){
	int a=2,b=50;
	for(int i=0;i<13;i++){//horizontales
		gotoxy(b,2);
		cout<<"*";
		gotoxy(b,7);
		cout<<"*";
		gotoxy(b,12);
		cout<<"*";
		gotoxy(b,17);
		cout<<"*";
		b++;b++;
	}
	for(int i=0;i<15;i++){//verticales
		gotoxy(50,a);
		cout<<"*";
		gotoxy(58,a);
		cout<<"*";
		gotoxy(66,a);
		cout<<"*";
		gotoxy(74,a);
		cout<<"*";
		a++;
	}
	gotoxy(54,4);
	cout<<"1";
	gotoxy(62,4);
	cout<<"2";
	gotoxy(70,4);
	cout<<"3";
	gotoxy(54,9);
	cout<<"4";
	gotoxy(62,9);
	cout<<"5";
	gotoxy(70,9);
	cout<<"6";
	gotoxy(54,14);
	cout<<"7";
	gotoxy(62,14);
	cout<<"8";
	gotoxy(70,14);
	cout<<"9";
}
bool busq(int mat[][3],int opc){
	bool a = false;
	switch(opc){
		case 1: if(mat[0][0] == 1 || mat[0][0] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 2: if(mat[0][1] == 1 || mat[0][1] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 3: if(mat[0][2] == 1 || mat[0][2] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 4: if(mat[1][0] == 1 || mat[1][0] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 5: if(mat[1][1] == 1 || mat[1][1] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 6: if(mat[1][2] == 1 || mat[1][2] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 7: if(mat[2][0] == 1 || mat[2][0] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 8: if(mat[2][1] == 1 || mat[2][1] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		case 9: if(mat[2][2] == 1 || mat[2][2] == 2){
					a = true;
					gotoxy(5,33);
					cout<<"Opcion no permitida!!!";
					Sleep(700);
					gotoxy(5,33);
					cout<<"                           ";
				}
				break;
		default:break;
		}
	return a;
}
void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
bool ganador(int mat[][3]){
	bool a = false;
	if(mat[0][0] == 1 && mat[0][1] == 1 && mat[0][2] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[0][0] == 2 && mat[0][1] == 2 && mat[0][2] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	if(mat[1][0] == 1 && mat[1][1] == 1 && mat[1][2] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[1][0] == 2 && mat[1][1] == 2 && mat[1][2] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	if(mat[2][0] == 1 && mat[2][1] == 1 && mat[2][2] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[2][0] == 2 && mat[2][1] == 2 && mat[2][2] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	if(mat[0][0] == 1 && mat[1][0] == 1 && mat[2][0] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[0][0] == 2 && mat[1][0] == 2 && mat[2][0] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	if(mat[0][1] == 1 && mat[1][1] == 1 && mat[2][1] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[0][1] == 2 && mat[1][1] == 2 && mat[2][1] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	if(mat[0][2] == 1 && mat[1][2] == 1 && mat[2][2] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[0][2] == 2 && mat[1][2] == 2 && mat[2][2] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	if(mat[0][0] == 1 && mat[1][1] == 1 && mat[2][2] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[0][0] == 2 && mat[1][1] == 2 && mat[2][2] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	if(mat[0][2] == 1 && mat[1][1] == 1 && mat[2][0] == 1){
		gotoxy(29,32);
		cout<<"Gano "<<jug1<<endl;
		a = true;
	}
	if(mat[0][2] == 2 && mat[1][1] == 2 && mat[2][0] == 2){
		gotoxy(29,32);
		cout<<"Gano "<<jug2<<endl;
		a = true;
	}
	return a;
}
