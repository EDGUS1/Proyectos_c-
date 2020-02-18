#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

bool existe(int,int);
void gotoxy(int,int);
void generar();


vector<vector<int> > f;

int main(){;
	
	int k = 0;
	srand(time(NULL));
	while(k < 900){
		generar();
		k++;
	}
	getch();
	gotoxy(0,22);
	return 0;
}
void generar(){
	int x,y;
	vector<int> v;
	
	do{
		x = 1 + (rand() % 78);
		y = 1 + (rand() % 23);
	}while(existe(x,y));
	gotoxy(x,y);
	cout << "x";
	v.push_back(x);
	v.push_back(y);
	f.push_back(v);
}
bool existe(int x, int y){
	if(!f.empty()){
		
		for(int i = 0; i < f.size(); i++){
			if(x == f[i][0] && y == f[i][1]){
				return true;
			}
			if((x-1) == f[i][0] && y == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x-1) == f[j][0] && (y-1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if(x == f[k][0] && (y-1) == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			if(x == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y-1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if((x+1) == f[k][0] && y == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			
			if((x-1) == f[i][0] && y == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x-1) == f[j][0] && (y+1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if(x == f[k][0] && (y+1) == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			if(x == f[i][0] && (y+1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y+1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if((x+1) == f[k][0] && y == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			if((x-1) == f[i][0] && (y+1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y+1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if(x == f[k][0] && (y+2) == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			if((x+1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y+1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if((x+2) == f[k][0] && y == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			if((x-1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x-1) == f[j][0] && (y+1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if((x-2) == f[k][0] && y == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			if((x-1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y-1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if(x == f[k][0] && (y-2) == f[k][1]){
								return true;
							}
						}
					}
				}
			}
			if((x-1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y-1) == f[j][1]){
						for(int k = 0; k < f.size(); k++){
							if((x-1) == f[k][0] && (y+1) == f[k][1]){
								for(int l = 0; l < f.size(); l++){
									if((x+1) == f[k][0] && (y+1) == f[k][1]){
										return true;
									}
								}
							}
						}
					}
				}
			}
			if((x-1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y-1) == f[j][1]){
						return true;
					}
				}
			}
			if((x-1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x-1) == f[j][0] && (y+1) == f[j][1]){
						return true;
					}
				}
			}
			if((x-1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y+1) == f[j][1]){
						return true;
					}
				}
			}
			if((x+1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y+1) == f[j][1]){
						return true;
					}
				}
			}
			if((x+1) == f[i][0] && (y-1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x-1) == f[j][0] && (y+1) == f[j][1]){
						return true;
					}
				}
			}
			if((x-1) == f[i][0] && (y+1) == f[i][1]){
				for(int j = 0; j < f.size(); j++){
					if((x+1) == f[j][0] && (y+1) == f[j][1]){
						return true;
					}
				}
			}
			
		}
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

