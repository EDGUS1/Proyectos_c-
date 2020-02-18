#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int a,int b);
void dibujarPlataforma(int, int);
void borrar(int,int);
bool gameOver();
void bricks();
void eliminarBrick();
void pelota(int, int);
void borrarPelota(int, int);

int main(){
	int x = 35,y = 22,pelotaX = 0, pelotaY = 7;
	bool bX = false, bY = false;
	bricks();
	do{
		dibujarPlataforma(x,y);
		
		pelota(pelotaX, pelotaY);
		Sleep(80);
		borrarPelota(pelotaX, pelotaY);
		if(bX == false){
			pelotaX++;
		}else{
			pelotaX--;
		}
		if(bY == false){
			pelotaY++;
		}else{
			pelotaY--;
		}
		if(pelotaX == 0) bX = false;
		
		if(pelotaX == 79) bX = true;
		
		if(pelotaY == 6) bY = false;
		
		if(pelotaY == 21) bY = true;
				
		if(kbhit()){
			switch(getch()){
				case 'a': 
					if(x > 3) {
						borrar(x--,y);
					}
					break;
				case 'd': 
					if(x < 76){
						borrar(x++,y);
					}
					break;
			}
		}
	
	}while(!gameOver());
	return 0;
}

void dibujarPlataforma(int a, int b){
	gotoxy(a,b);
	cout<<"x";
	gotoxy(a-1,b);
	cout<<"x";
	gotoxy(a-2,b);
	cout<<"x";
	gotoxy(a+1,b);
	cout<<"x";
	gotoxy(a+2,b);
	cout<<"x";
	gotoxy(a-3,b);
	cout<<"x";
	gotoxy(a+3,b);
	cout<<"x";
}

void borrar(int a,int b){
	gotoxy(a,b);
	cout<<" ";
	gotoxy(a-1,b);
	cout<<" ";
	gotoxy(a-2,b);
	cout<<" ";
	gotoxy(a+1,b);
	cout<<" ";
	gotoxy(a+2,b);
	cout<<" ";
	gotoxy(a-3,b);
	cout<<" ";
	gotoxy(a+3,b);
	cout<<" ";
}

bool gameOver(){
	return false;
}

void bricks(){
	for(int i = 0; i < 560; i++){
		cout << "X";
	}
}

void eliminarBrick(){
	
}

void borrarPelota(int a, int b){
	gotoxy(a,b);
	cout << " ";
}
void pelota(int x, int y){
	gotoxy(x, y);
	cout << "O";
}
void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}

