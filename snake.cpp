#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

void gotoxy(int, int);
bool gameOver(int, int);
void marco();

class Fruta{
	private:
		int x, y;
	public:
		bool existe(vector<int> v){
			if ((v[0] == this->x) && (v[1] == this->y)){
				return true;
			}
			return false;
		}
		void generar(){
			srand(time(NULL));
			x = 5 + (rand() % 70);
			y = 3 + (rand() % 20);
			gotoxy(x,y);
			cout << char(155);
		}
};

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
		int getScore(){
			return cantidad * 10;
		}
};

int main(){
	
	char opc = 'X';
	vector < vector<int> > f;
	Serpiente s;
	Fruta fruta;
	
	fruta.generar();
	marco();
	
	while(true){
		
		while(!kbhit()){//Se movera en la posicion elegida anteriormente
		
			vector <int> v;
			v.push_back(s.getX());
			v.push_back(s.getY());
			f.push_back(v);
			
			for(int i = 0; i < f.size(); i++){
				gotoxy(f[i][0], f[i][1]);
				cout << char(219);
			}
			if(opc == 'x') s.setX(s.getX() - 1);
			if(opc == 'Y') s.setY(s.getY() - 1);
			if(opc == 'y') s.setY(s.getY() + 1);
			if(opc == 'X') s.setX(s.getX() + 1);
			
			Sleep(40);
			
			if(gameOver(s.getX(),s.getY())){
				system("cls");
				gotoxy(36,12);
				cout << "GAME OVER";
				gotoxy(35,13);
				cout << "SCORE = " << s.getScore();
				gotoxy(0,20);
				Sleep(100);
				exit(1);
			}
			
			if(!fruta.existe(v)){
				gotoxy(f[0][0], f[0][1]);
				cout << " ";
				f.erase(f.begin());
			}else{
				s.incrementarLongtud();
				fruta.generar();
			}

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
		Sleep(30);
	}
	
	gotoxy(0,20);
	return 0;
}

bool gameOver(int x, int y){
	if(x == 79 || x == 0 || y == 0 || y == 23){
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
