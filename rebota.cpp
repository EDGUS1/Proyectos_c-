#include<iostream>
#include<windows.h>

using namespace std;

void gotoxy(int a,int b);

int main(){
	//(79,24) -> tamaño maximo
	int x = 0, y = 0;
	bool bandX = false, bandY = false;
	
	while(true){
		
		gotoxy(x,y);
		
		cout << "O";
		
		if(bandX == false)
			x++;
		else
			x--;
		
		if(bandY == false)
			y++;
		else
			y--;
		
		if(x == 0) bandX = false;
		
		if(x == 79) bandX = true;
		
		if(y == 0) bandY = false;
		
		if(y == 24) bandY = true;
		
		Sleep(50);
//		system("cls");
	}
	
	return 0;
}
void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
