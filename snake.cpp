#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void gotoxy(int, int);
bool gameOver(int, int);

class Serpiente{
	private:
		int x,y,cantidad;
	public:
		Serpiente(){
			srand(time(NULL));
			x = 20 + (rand() % 40);
			y = 5 +(rand() % 15);
			cantidad = 1;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		void setX(int x){
			this->x = x;
		}
		void setY(int y){
			this->y = y;
		}
		void incrementarLongtud(){
			cantidad++;
		}
		void movimiento(char a){
			gotoxy(x,y);
			if(a == 'x'){
				for(int i = 0; i < cantidad; i++){
					cout << "X";
				}
			}else if(a == 'y'){
				for(int i = 0; i < cantidad; i++){
					cout << "X\n";
				}
			}else{
				cout << "X";
			}
		}
		
};

int main(){
	char opc = 'X';
	Serpiente s;
	while(true){
		s.movimiento(opc);
		while(!kbhit()){//Se movera en la posicion elegida anteriormente
			if(opc == 'x'){
				s.setX(s.getX() - 1);
//				s.incrementarLongtud();
			}
			if(opc == 'Y') s.setY(s.getY() - 1);
			if(opc == 'y'){
				s.setY(s.getY() + 1);
//				s.incrementarLongtud();
			} 
			if(opc == 'X') s.setX(s.getX() + 1);
			Sleep(200);
			system("cls");
			
			if(gameOver(s.getX(),s.getY())){
				system("cls");
				cout << "GAME OVER";
				Sleep(100);
				exit(1);
			}
			
			s.movimiento(opc);
		}
		
		switch(getch()){ //Se elige la direccion del movimiento
			case 'a': 
				s.setX(s.getX() - 1); 
				opc = 'x';
				break;
			case 'w': 
				s.setY(s.getY() - 1);
				opc = 'Y';
				break;
			case 's': 
				s.setY(s.getY() + 1);
				opc = 'y';
				break;
			case 'd': 
				s.setX(s.getX() + 1);
				opc = 'X';
				break;
		}		
		Sleep(200);
		system("cls");
	}
	gotoxy(0,20);
	return 0;
}
bool gameOver(int x, int y){
	if(x == 79 || x == 0 || y == 0 || y == 24){
		return true;
	}
	return false;
}
void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
