#include <iostream>
#include <fstream> //archivos
#include <sstream> //stringstream
#include <windows.h> //Sleep
#include <conio.h> //getch
#include <time.h>
#include <stdlib.h>//atoi

using namespace std;

//funciones
void nuevaCuenta();
void eliminarCuenta();
void modificarCuenta();
void ingresarCuenta();
void mostrarCuentas();
void buscarCuenta();
string esEntero(int,int);
bool validarNumeroDeCuenta(string);
string generarNumeroDeCuenta();
void gotoxy(int,int);
void menuCuenta();

//Clases
class Persona{
	private:
		string nombre, apellido, dni,numeroDeCuenta;
		int edad,saldo,numeroDeTransacciones;
	public:
		Persona(){
			nombre = "Desconocido";
			apellido = "Desconocido";
			dni = "--------";
			edad = 0;
		}
		Persona(string n, string a, string d, int e, int s){
			nombre = n;
			apellido = a;
			dni = d;
			edad = e;
			numeroDeCuenta = generarNumeroDeCuenta();
			saldo = s;
			numeroDeTransacciones = 0;
		}
		void setNommbre(string n){
			nombre = n;
		}
		void setApellido(string a){
			apellido = a;
		}
		void setDni(string d){
			dni = d;
		}
		void setEdad(int e){
			edad = e;
		}
		string getNombre(){
			return nombre;
		}
		string getApellido(){
			return apellido;
		}
		string getDni(){
			return dni;
		}
		int getEdad(){
			return edad;
		}
		int getSaldo(){
			return saldo;
		}
		int getNumeroDeTransacciones(){
			return numeroDeTransacciones;
		}
		string getNumeroDeCuenta(){
			return numeroDeCuenta;
		}
		string to_String(){
			stringstream s;
			s << "Nombre:\t" << nombre << "\nApellido:\t" << apellido << "\nDNI:\t\t" << dni << "\nEdad:\t\t" << edad << "\nNumero de Cuenta: "<< numeroDeCuenta << endl;
			return s.str();
		}
};

//variables globales
ifstream leer;
ofstream escribir;

int main(){
	int opc;
	
	//MENU
	do{
		system("cls");
		cout << "\t\tMENU\n1. Aniadir cuenta\n2. Eliminar cuenta\n3. Modificar cuenta\n4. Ingresar a la cuenta (estado,traspaso,etc)\n5. Mostrar cuentas";
		cout << "\n6. Buscar Cuenta\n0. Salir\nOpcion: ";
		opc = atoi(esEntero(8,8).c_str());
		switch(opc){
			case 0: break;
			case 1: nuevaCuenta();break;
			case 2: eliminarCuenta();break;
			case 3: modificarCuenta();break;
			case 4: ingresarCuenta; break;
			case 5: mostrarCuentas(); break;
			case 6: buscarCuenta(); break;
			default: cout << "Opcion no valida\n"; Sleep(800);
		}
	}while(opc != 0);
	
	return 0;
}

void nuevaCuenta(){
	
	string nombre, apellido, dni;
	int edad;
	escribir.open("Registro.txt",ios::app | ios::out);
	
	if(escribir.fail()){
		cout << "Error al abrir el archivo";
		exit(1);
	}
	
	fflush(stdin);
	system("cls");
	cout << "\tNUEVO REGISTRO\n";
	cout << "Nombre:   "; getline(cin, nombre);
	cout << "Apellido: "; getline(cin, apellido);
	cout << "DNI:      "; dni = esEntero(10,3); 
	cout << "Edad:     "; edad = atoi(esEntero(10,4).c_str()); 
	
	Persona p(nombre,apellido,dni,edad,0);
	
	escribir << p.getNombre() <<"\t "<< p.getApellido() <<"\t "<< p.getDni() <<"\t "<< p.getEdad() << "\t " << p.getNumeroDeCuenta() << endl; 
	escribir.close();
	
	cout << "Registrado....\nPresione una tecla para volver al menu anterior....";
	getch();
}
void mostrarCuentas(){
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta;
	leer.open("Registro.txt", ios::in);
	if(leer.fail()){
		cout << "Error ";
		exit(1);
	}
	system("cls");
	cout << "-----------------------------------------\n";
	cout << "\tMOSTRANDO DATOS:\n";
	cout << "-----------------------------------------\n\n";
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		cout << "-------------------------------------------\n";
		cout << "Nombre:  	 	" << auxNombre << endl;
		cout << "Apellido: 		" << auxApellido << endl;
		cout << "DNI:      		" << auxDni << endl;
		cout << "Edad:    	 	" << auxEdad << endl;
		cout << "Numero de Cuenta: 	" << auxNumeroDeCuenta << endl;
		cout << "-------------------------------------------\n\n";
		leer >> auxNombre;
	}
	leer.close();
	cout << "\nPresione una tecla para volver al menu anterior....";
	getch();
}
void eliminarCuenta(){
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, var;
	ofstream nuevo;
	leer.open("Registro.txt", ios::in);
	nuevo.open("RegistroAuxiliar.txt", ios::out | ios::app);
	if(leer.fail()){
		cout << "Error ";
		exit(1);
	}
	if(nuevo.fail()){
		cout << "Error ";
		exit(1);
	}
	system("cls");
	cout << "\nIngrese el Numero de Cuenta o DNI para buscar: ";
	var = esEntero(47,1);
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		if(var == auxDni || var == auxNumeroDeCuenta){
			cout << "-----------------------------------------\n";
			cout << "\tEL REGISTRO SE HA ELIMINADO\n";
			cout << "-----------------------------------------\n";
			cout << "Nombre			:" << auxNombre << endl;
			cout << "Apellido		:" << auxApellido << endl;
			cout << "DNI	   		:" << auxDni << endl;
			cout << "Edad 			:" << auxEdad << endl;
			cout << "Numero de Cuenta	:" << auxNumeroDeCuenta << endl;
			cout << "-----------------------------------------\n\n";
		}else{
			nuevo << auxNombre << "\t " << auxApellido << "\t " << auxDni << "\t " << auxEdad << "\t " << auxNumeroDeCuenta << endl;
		}
		leer >> auxNombre;
	}
	leer.close();
	nuevo.close();
	remove("Registro.txt");
	rename("RegistroAuxiliar.txt","Registro.txt");
	
	cout << "\nPresione una tecla para volver al menu anterior....";
	getch();
}
void modificarCuenta(){
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, var, nuevoNombre, nuevoApellido, nuevoDni;
	int nuevaEdad;
	ofstream nuevo;
	leer.open("Registro.txt", ios::in);
	nuevo.open("RegistroAuxiliar.txt", ios::out | ios::app);
	if(leer.fail()){
		cout << "Error ";
		exit(1);
	}
	if(nuevo.fail()){
		cout << "Error ";
		exit(1);
	}
	system("cls");
	cout << "\nIngrese el Numero de Cuenta o DNI para buscar: ";
	var = esEntero(47,1);
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		if(var == auxDni || var == auxNumeroDeCuenta){
			fflush(stdin);
			cout << "-----------------------------------------\n";
			cout << "\tNUEVOS DATOS:\n";
			cout << "-----------------------------------------\n";
			cout << "Nombre:   "; getline(cin, nuevoNombre);
			cout << "Apellido: "; getline(cin, nuevoApellido);
			cout << "DNI:      "; nuevoDni = esEntero(10,7); 
			cout << "Edad:     "; nuevaEdad = atoi(esEntero(10,8).c_str()); 
			cout << "-----------------------------------------\n\n";
			
			cout << "-----------------------------------------\n";
			cout << "\tEL REGISTRO SE HA MODIFICADO\n";
			cout << "-----------------------------------------\n";
			cout << "Nombre			:" << nuevoNombre << endl;
			cout << "Apellido		:" << nuevoApellido << endl;
			cout << "DNI	   		:" << nuevoDni << endl;
			cout << "Edad 			:" << nuevaEdad << endl;
			cout << "Numero de Cuenta	:" << auxNumeroDeCuenta << endl;
			cout << "-----------------------------------------\n\n";
			
			nuevo << nuevoNombre << "\t " << nuevoApellido << "\t " << nuevoDni << "\t " << nuevaEdad << "\t " << auxNumeroDeCuenta << endl;
		}else{
			nuevo << auxNombre << "\t " << auxApellido << "\t " << auxDni << "\t " << auxEdad << "\t " << auxNumeroDeCuenta << endl;
		}
		leer >> auxNombre;
	}
	leer.close();
	nuevo.close();
	remove("Registro.txt");
	rename("RegistroAuxiliar.txt","Registro.txt");
	
	cout << "\nPresione una tecla para volver al menu anterior....";
	getch();
}
void ingresarCuenta(){
	
}
void buscarCuenta(){
	string auxNombre, auxApellido, auxDni, auxEdad, var,auxNumeroDeCuenta;
	leer.open("Registro.txt", ios::in);
	if(leer.fail()){
		cout << "Error ";
		exit(1);
	}
	system("cls");
	cout << "\nIngrese el Numero de Cuenta o DNI para buscar: ";
	var = esEntero(47,1);
	
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		if(var == auxDni || var == auxNumeroDeCuenta){
			cout << "-----------------------------------------\n";
			cout << "Nombre			:" << auxNombre << endl;
			cout << "Apellido		:" << auxApellido << endl;
			cout << "DNI	   		:" << auxDni << endl;
			cout << "Edad 			:" << auxEdad << endl;
			cout << "Numero de Cuenta	:" << auxNumeroDeCuenta << endl;
			cout << "-----------------------------------------\n\n";
		}
		leer >> auxNombre;
	}
	leer.close();
	cout << "\nPresione una tecla para volver al menu anterior....";
	getch();
}
string esEntero(int x, int y){

	bool band;
	string n;
	do{
		band = true;
		cin >> n;
		for(int i = 0; i < n.length(); i++){
			switch(n[i]){
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':break;
				default: band = false; 
			}
		}
		if(band == false){
			cout << "Ingrese un numero!!!";
			Sleep(250);
			gotoxy(x,y);
			cout << "                    \n";
			cout << "                    ";
			gotoxy(x,y);
		}
	}while(band == false);
	return n;
}
bool validarNumeroDeCuenta(string x){
	string aux;
	int contador = 0;
	leer.open("Registro.txt", ios::in);
	if(leer.fail()){
		cout << "error";
		exit(1);
	}
	leer >> aux; 
	while(!leer.eof()){
		contador = 0;
		for(int i = 0; i < 9; i++){
			if(aux[i] == x[i]){
				contador++;
			}
		}
		if(contador == 9){
			leer.close();
			return true;
		}
		leer>>aux;
	}
	leer.close();
	return false;
}
string generarNumeroDeCuenta(){
	string v;
	int x,c = 0;
	srand(time(NULL));
	do{
		c = 0;
		v = "";
		while(c < 9){
			x = rand() % 10;
			switch(x){
				case 0: v += '0';break;
				case 1: v += '1';break;
				case 2: v += '2';break;
				case 3: v += '3';break;
				case 4: v += '4';break;
				case 5: v += '5';break; 
				case 6: v += '6';break;
				case 7: v += '7';break; 
				case 8: v += '8';break; 
				case 9: v += '9';break; 
			}
		c++;
		}	
	}while(validarNumeroDeCuenta(v));
	return v;
}
void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
void menuCuenta(){
	system("cls");
	cout << "";
}


