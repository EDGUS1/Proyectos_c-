#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std; 

void disparo(int, int, int&);
void gotoxy(int,int);
void marco();

class Objetivo{
	private:
		int posX, posY;
	public:
		Objetivo(){
		}
		int getX(){
			return posX;
		}
		void dibujarObjetivo(){
			srand(time(NULL));
			posX = 3 + (rand() % 70);
			posY = 2 + (rand() % 10);
			gotoxy(posX, posY);
			cout << char(157);
		}
};

class Nave{
	private:
		int x, y;
	public:
		Nave(){
			x = 37;
			y = 22;
		}
		void dibujar(){
			gotoxy(x,y);
			cout << char(94);
		}
		void setX(int x){
			(*this).x = x;
		}
		void setY(int y){
			this->y = y;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		void borrar(){
			gotoxy(x,y);
			cout << " ";
		}
};

int main(){
	
	Nave n;
	Objetivo o;
	char a;
	int x = 20, y = 20, cantidad = 0, contador = 30,cuenta = 0;
	
	marco();
	o.dibujarObjetivo();
	n.dibujar();
	gotoxy(75,1);
	cout << contador;
	
	while(contador > 0){
		
		if(kbhit()){
			switch(getch()){
			
				case 13: 
					disparo(n.getX(),n.getY() - 1,cuenta);
					if(o.getX() == n.getX()){
						cantidad++;
						o.dibujarObjetivo();
					}
					break;
				case 97: 
					n.borrar();
					n.setX(n.getX() - 1);
					break;
				case 100: 
					n.borrar();
					n.setX(n.getX() + 1); 
					break;
			}
			n.dibujar();
		}
		if(cuenta >= 20000){
			contador--;
			cuenta = 0;
			gotoxy(75,1);
			cout << "   ";
			gotoxy(75,1);
			cout << contador;
		}
		cuenta++;
	}
	system("cls");
	gotoxy(35,13);
	cout << "SCORE = " << cantidad*10;
	Sleep(3000);
	gotoxy(0,20);
	return 0;
}
void disparo(int x, int y, int &c){
	cout << "\a";
	for(int i = 0; i < 21; i++){
		gotoxy(x,y);
		cout << char(221);
		Sleep(18);
		gotoxy(x,y--);
		cout << " ";
		c += 500;
	}
}

void marco(){
	for(int i = 0; i < 79; i++){
		gotoxy(i, 0);
		cout << char(205);
		gotoxy(i, 23);
		cout << char(205);
	}
	for(int i = 0; i < 23; i++){
		gotoxy(0, i);
		cout << char(186);
		gotoxy(79, i);
		cout << char(186);
	}
	gotoxy(0,0);
	cout << char(201);
	gotoxy(0,23);
	cout << char(200);
	gotoxy(79,0);
	cout << char(187);
	gotoxy(79,23);
	cout << char(188);
}

void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
