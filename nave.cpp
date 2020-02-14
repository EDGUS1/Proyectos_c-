#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std; 

void disparo(int, int);
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
			cout << "C";
		}
};

class Nave{
	private:
		int x, y;
	public:
		Nave(){
			x = 37;
			y = 23;
		}
		void dibujar(){
			gotoxy(x,y);
			cout << "O";
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
	int x = 20, y = 20, cantidad = 0;
	
	marco();
	o.dibujarObjetivo();
	
	while(true){
		
		n.dibujar();
		
		switch(getch()){
			
			case 13: 
				disparo(n.getX(),n.getY() - 1);
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
	}
	gotoxy(0,20);
	return 0;
}
void disparo(int x, int y){
	cout << "\a";
	for(int i = 0; i < 21; i++){
		gotoxy(x,y);
		cout << ".";
		Sleep(18);
		gotoxy(x,y--);
		cout << " ";
	}
}

void marco(){
	for(int i = 0; i < 79; i++){
		gotoxy(i, 0);
		cout << "#";
		gotoxy(i, 24);
		cout << "#";
	}
	for(int i = 0; i < 24; i++){
		gotoxy(0, i);
		cout << "#";
		gotoxy(79, i);
		cout << "#";
	}
}

void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
