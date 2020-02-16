#include <iostream>
#include <fstream> //archivos
#include <sstream> //stringstream
#include <windows.h> //Sleep
#include <conio.h> //getch
#include <time.h>
#include <string.h>
#include <stdlib.h>//atoi

using namespace std;

//funciones
void nuevaCuenta();
void eliminarCuenta();
void modificarCuenta();
void mostrarCuentas();
void buscarCuenta();
string esEntero(int,int);
bool validarNumeroDeCuenta(string);
string generarNumeroDeCuenta();
void gotoxy(int,int);
void menuCuenta();
void estadoCuenta();
void transaccion();
void retiro();
void ingresoDinero();

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
			case 4: menuCuenta(); break;
			case 5: mostrarCuentas(); break;
			case 6: buscarCuenta(); break;
			default: cout << "Opcion no valida\n"; Sleep(800);
		}
	}while(opc != 0);
	
	return 0;
}

void nuevaCuenta(){

	string nombre, apellido, dni;
	int edad, monto;
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
	cout << "Monto:	   "; monto = atoi(esEntero(10,4).c_str()); 
	
	Persona p(nombre,apellido,dni,edad,monto);
	
	escribir << p.getNombre() <<" "<< p.getApellido() <<" "<< p.getDni() <<" "<< p.getEdad() << " ";
	escribir << p.getNumeroDeCuenta() << " " << p.getSaldo() << " " << p.getNumeroDeTransacciones() << endl; 
	escribir.close();
	
	cout << "Registrado....\nPresione una tecla para volver al menu anterior....";
	getch();
}
void mostrarCuentas(){
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, auxMonto, auxT;
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
		leer >> auxMonto;
		leer >> auxT;
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
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, var, auxMonto, auxT;

	leer.open("Registro.txt", ios::in);
	escribir.open("RegistroAuxiliar.txt", ios::out | ios::app);
	if(leer.fail()){
		cout << "Error ";
		exit(1);
	}
	if(escribir.fail()){
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
		leer >> auxMonto;
		leer >> auxT;
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
			escribir << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta << " ";
			escribir << auxMonto << " " << auxT <<endl;
		}
		leer >> auxNombre;
	}
	leer.close();
	escribir.close();
	remove("Registro.txt");
	rename("RegistroAuxiliar.txt","Registro.txt");
	
	cout << "\nPresione una tecla para volver al menu anterior....";
	getch();
}
void modificarCuenta(){
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, var, nuevoNombre, nuevoApellido, nuevoDni, auxMonto, auxT;
	int nuevaEdad;

	leer.open("Registro.txt", ios::in);
	escribir.open("RegistroAuxiliar.txt", ios::out | ios::app);
	if(leer.fail()){
		cout << "Error ";
		exit(1);
	}
	if(escribir.fail()){
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
		leer >> auxMonto;
		leer >> auxT;
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
			
			escribir << nuevoNombre << " " << nuevoApellido << " " << nuevoDni << " " << nuevaEdad << " " << auxNumeroDeCuenta;
			escribir << " " << auxMonto << " "<< auxT << endl;
		}else{
			escribir << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta;
			escribir << " " << auxMonto << " "<< auxT << endl;
		}
		leer >> auxNombre;
	}
	leer.close();
	escribir.close();
	remove("Registro.txt");
	rename("RegistroAuxiliar.txt","Registro.txt");
	
	cout << "\nPresione una tecla para volver al menu anterior....";
	getch();
}
void buscarCuenta(){
	string auxNombre, auxApellido, auxDni, auxEdad, var, auxNumeroDeCuenta, auxMonto, auxT;
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
		leer >> auxMonto;
		leer >> auxT;
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
	int opc;
	do{
		system("cls");
		cout << "1. Estado de la cuenta\n2. Realizar transaccion\n3. Retirar dinero\n4. Ingresar dinero\n0. Salir\nOpcion: ";
		opc = atoi(esEntero(8,4).c_str());
		switch(opc){
			case 0: break;
			case 1: estadoCuenta();break;
			case 2: transaccion();break;
			case 3: retiro();break;
			case 4: ingresoDinero();break;
			default: cout << "Opcion no encontrada"; Sleep(800);
		}
	}while(opc != 0);
	
}
void estadoCuenta(){
	
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, auxMonto, auxT, var;
	system("cls");
	
	leer.open("Registro.txt", ios::in);
	if(leer.fail()){
		cout<<"Error";
		exit(1);
	}
	cout << "Ingrese el Numero de Cuenta: ";
	var = esEntero(29,0);
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		leer >> auxMonto;
		leer >> auxT;
		if(var == auxNumeroDeCuenta){
			cout << "\n-----------------------------------------\n";
			cout << "Nombre:			" << auxNombre;
			cout << "\nNumero de cuenta:	" << auxNumeroDeCuenta;
			cout << "\nMonto disponible: 	" << auxMonto;
			cout << "\nN. Transacciones: 	" << auxT;
			cout << "\n-----------------------------------------\n";
		}
		leer >> auxNombre;
	}
	leer.close();
	cout << "Presione una tecla para volver...";
	getch();
}
void transaccion(){
	string auxNombre,aN1,aN2,auxApellido,aA1,aA2, auxDni,aD1,aD2, auxEdad,aE1,aE2, auxNumeroDeCuenta,aNC1,aNC2, auxMonto, auxT, var,var2;
	int m, aM1,aM2,aT1,aT2;
	ifstream leer2;
	ofstream escribir2;
	
	system("cls");
	
	leer.open("Registro.txt", ios::in);
	escribir.open("var.txt", ios::app | ios::out);
	escribir2.open("var2.txt", ios::app | ios::out);
	
	if(leer.fail()){
		cout<<"Error 1";
		exit(1);
	}
	if(escribir.fail()){
		cout<<"Error 2";
		exit(1);
	}
	if(escribir2.fail()){
		cout<<"Error 3";
		exit(1);
	}
	cout << "Ingrese el Numero de Cuenta: ";
	var = esEntero(29,0);
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		leer >> auxMonto;
		leer >> auxT;
		if(var == auxNumeroDeCuenta){
			aN1 = auxNombre.c_str();
			aA1 = auxApellido.c_str();
			aD1 = auxDni.c_str();
			aE1 = auxEdad.c_str();
			aNC1 = auxNumeroDeCuenta.c_str();
			aM1 = atoi(auxMonto.c_str());
			aT1 = atoi(auxT.c_str());
			cout << "Ingrese la cuenta de destino: ";
			var2 = esEntero(29,0);
		}else{
			escribir << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta;
			escribir << " " << auxMonto << " "<< auxT << endl;
		}
		leer >> auxNombre;
	}
	escribir.close();
	leer.close();
	leer2.open("var.txt", ios::in);
	if(leer2.fail()){
		cout<<"Error";
		exit(1);
	}
	fflush(stdin);
	leer2 >> auxNombre;
	while(!leer2.eof()){
		leer2 >> auxApellido;
		leer2 >> auxDni;
		leer2 >> auxEdad;
		leer2 >> auxNumeroDeCuenta;
		leer2 >> auxMonto;
		leer2 >> auxT;
		if(var2 == auxNumeroDeCuenta){
			aN2 = auxNombre.c_str();
			aA2 = auxApellido.c_str();
			aD2 = auxDni.c_str();
			aE2 = auxEdad.c_str();
			aNC2 = auxNumeroDeCuenta.c_str();
			aM2 = atoi(auxMonto.c_str());
			aT2 = atoi(auxT.c_str());
			cout << "Ingrese el monto a traspasar: ";
			fflush(stdin);
			do{
				gotoxy(30,2);
				cout << "              ";
				gotoxy(30,2);
				m = atoi(esEntero(30,2).c_str());
			}while(m > aM1);
			aT1++;
			aM1 -= m;
			aM2 += m; 
		}else{
			escribir2 << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta;
			escribir2 << " " << auxMonto << " "<< auxT << endl;
		}
		leer2 >> auxNombre;
	}
	
	escribir2 << aN1 << " " << aA1 << " " << aD1 << " " << aE1 << " " << aNC1 << " " << aM1 << " "<< aT1 << endl;
	escribir2 << aN2 << " " << aA2 << " " << aD2 << " " << aE2 << " " << aNC2 << " " << aM2 << " "<< aT2 << endl;
	
	leer2.close();
	escribir2.close();
	
	remove("Registro.txt");
	remove("var.txt");
	rename("var2.txt","Registro.txt");
	
	cout << "\nPresione una tecla para volver...";
	getch();
}
void retiro(){
	
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, auxMonto, auxT, var;
	int ret, aux;
	system("cls");
	leer.open("Registro.txt", ios::in);
	escribir.open("var.txt", ios::app | ios::out);
	
	if(leer.fail()){
		cout<<"Error 1";
		exit(1);
	}
	if(escribir.fail()){
		cout<<"Error 2";
		exit(1);
	}
	cout << "Ingrese el Numero de Cuenta: ";
	var = esEntero(29,0);
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		leer >> auxMonto;
		leer >> auxT;
		if(var == auxNumeroDeCuenta){
			cout << "Ingrese el monto a retirar: ";
			ret = atoi(esEntero(28,1).c_str());
			aux = atoi(auxMonto.c_str());
			aux -= ret;
			if (aux < 0){
				aux = 0;
			}
			cout << "Retiro completado";
			escribir << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta;
			escribir << " " << aux << " "<< auxT << endl;
		}else{
			escribir << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta;
			escribir << " " << auxMonto << " "<< auxT << endl;
		}
		leer >> auxNombre;
	}
	
	leer.close();
	escribir.close();
	remove("Registro.txt");
	rename("var.txt","Registro.txt");
	cout << "\nPresione una tecla para volver...";
	getch();
}
void ingresoDinero(){
	
	string auxNombre, auxApellido, auxDni, auxEdad, auxNumeroDeCuenta, auxMonto, auxT, var;
	int ret, aux;
	system("cls");
	leer.open("Registro.txt", ios::in);
	escribir.open("var.txt", ios::app | ios::out);
	
	if(leer.fail()){
		cout<<"Error";
		exit(1);
	}
	if(escribir.fail()){
		cout<<"Error";
		exit(1);
	}
	cout << "Ingrese el Numero de Cuenta: ";
	var = esEntero(29,0);
	leer >> auxNombre;
	while(!leer.eof()){
		leer >> auxApellido;
		leer >> auxDni;
		leer >> auxEdad;
		leer >> auxNumeroDeCuenta;
		leer >> auxMonto;
		leer >> auxT;
		if(var == auxNumeroDeCuenta){
			cout << "Ingrese el monto: ";
			ret = atoi(esEntero(18,1).c_str());
			aux = atoi(auxMonto.c_str());
			aux += ret;
			cout << "Ingreso completado";
			escribir << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta;
			escribir << " " << aux << " "<< auxT << endl;
		}else{
			escribir << auxNombre << " " << auxApellido << " " << auxDni << " " << auxEdad << " " << auxNumeroDeCuenta;
			escribir << " " << auxMonto << " "<< auxT << endl;
		}
		leer >> auxNombre;
	}
	
	leer.close();
	escribir.close();
	remove("Registro.txt");
	rename("var.txt","Registro.txt");
	cout << "Presione una tecla para volver...";
	getch();
}


