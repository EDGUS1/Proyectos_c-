#include <iostream>
#include <fstream> //archivos
#include <sstream> //stringstream
#include <windows.h> //Sleep
#include <conio.h> //getch

using namespace std;

//Clases
class Persona{
	private:
		string nombre, apellido, dni;
		int edad;
	public:
		Persona(){
			nombre = "Desconocido";
			apellido = "Desconocido";
			dni = "--------";
			edad = 0;
		}
		Persona(string n, string a, string d, int e){
			nombre = n;
			apellido = a;
			dni = d;
			edad = e;
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
		string to_String(){
			stringstream s;
			s << "Nombre:\t" << nombre << "\nApellido:\t" << apellido << "\nDNI:\t\t" << dni << "\nEdad:\t\t" << edad << endl;
			return s.str();
		}
};

//funciones
void nuevaCuenta();
void eliminarCuenta();
void modificarCuenta();
void ingresarCuenta();
bool esEntero();

//variables globales
ifstream leer;
ofstream escribir;

int main(){
	int opc;
	
	//MENU
	do{
		system("cls");
		cout << "\t\tMENU\n1. Aniadir cuenta\n2. Eliminar cuenta\n3. Modificar cuenta\n4. Ingresar a la cuenta (estado,traspaso,etc)\n0. Salir\nOpcion: ";
		cin >> opc;
		switch(opc){
			case 0: break;
			case 1: nuevaCuenta();break;
			case 2: eliminarCuenta();break;
			case 3: modificarCuenta();break;
			case 4: ingresarCuenta;
			default: cout << "Opcion no valida\n"; Sleep(800);
		}
	}while(opc != 0);
	
	
	return 0;
}

void nuevaCuenta(){
	
	string nombre, apellido, dni;
	int edad;
	escribir.open("Registro.txt",ios::app);
	
	if(escribir.fail()){
		cout << "Error al abrir el archivo";
		exit(1);
	}
	
	fflush(stdin);
	system("cls");
	cout << "\tNUEVO REGISTRO\n";
	cout << "Nombre:   "; getline(cin, nombre);
	cout << "Apellido: "; getline(cin, apellido);
	cout << "DNI:      "; getline(cin, dni); //validar
	cout << "Edad:     "; cin >> edad; //validar
	
	Persona p(nombre,apellido,dni,edad);
	
	escribir << p.getNombre() <<" "<< p.getApellido() <<" "<< p.getDni() <<" "<< p.getEdad() << endl; 
	escribir.close();
	
	cout << "Registrado....\nPresione una tecla para volver al menu anterior....";
	getch();
}
void eliminarCuenta(){
	
}
void modificarCuenta(){
	
}
void ingresarCuenta(){
	
}
bool esEntero(){
	
}
