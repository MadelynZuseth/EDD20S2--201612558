#include "pch.h"
#include <iostream>
#include <string>
//#include "ListaSimple.h"
using namespace std;


void ListaSimple::Insertar(int carne, string nombre){
	
	if (cabecera == nullptr) {
		cabecera = new NodoLista(carne, nombre);
		cabecera->siguiente = nullptr;
	}
	else {
		NodoLista *auxiliar = cabecera;
		while (auxiliar->siguiente != nullptr) {
			auxiliar = auxiliar->siguiente;
		}
		NodoLista *extra = new NodoLista(carne, nombre);
		auxiliar->siguiente = extra;
		extra->siguiente = nullptr;
	}
}

NodoLista *ListaSimple::Buscar(int carne) {
	NodoLista *auxiliar = cabecera;
	if (auxiliar != nullptr) {
		while (auxiliar->carne != carne) {
			auxiliar = auxiliar->siguiente;
		}
	}
	if (auxiliar != nullptr) {
		cout << "dato encontrado" << endl;
		cout << auxiliar->carne << endl;
		cout << auxiliar->nombre << endl;
	}
	else {
		cout << "Dato no encontrado" << endl;
	}
	return auxiliar;
}

void ListaSimple::Eliminar(int carne) {
	NodoLista *auxiliar = Buscar(carne);
	if (auxiliar != nullptr) {
		if (auxiliar == cabecera) {
			if (auxiliar->siguiente != nullptr) {
				cabecera = auxiliar->siguiente;
			}
			else {
				cabecera = nullptr;
			}
		}
		else {
			NodoLista *extra = cabecera;
			while (extra->siguiente != auxiliar) {
				extra = extra->siguiente;
			}
			if (auxiliar->siguiente != nullptr) {
				extra->siguiente = auxiliar->siguiente;

			}
			else {
				extra->siguiente = nullptr;
			}
		}

	}
	else {
		cout << "Dato no encontrado, no se puede eliminar" << endl;
	}
}


void ListaSimple::mostrar() {
	int opcion;
	NodoLista *aux = cabecera;
	while (aux != nullptr) {
		cout << aux->carne;
		cout << " "+ aux->nombre;
		aux = aux->siguiente;
	}
	cin >> opcion;
	Menu();
}

void ListaSimple::Menu() {
	int opcion;
	int carne;
	string nombre;
	system("cls");
	cout << "MENU" << endl;
	cout << "1. Insertar dato " << endl;
	cout << "2. Buscar dato " << endl;
	cout << "3. Eliminar dato" << endl;
	cout << "4. Mostrar dato" << endl;
	cin >> opcion;
	switch (opcion) {
	case 1:
		cout << "Ingresar carne" << endl;
		cin >> carne;
		cout << "Ingresar nombre" << endl;
		cin >> nombre;
		Insertar(carne, nombre);
		cout << "DATO INGRESADO CORRECTAMENTE" << endl;
		Menu();
		break;
	case 2:
		cout << "No. Carne" << endl;
		cin >> carne;
		Buscar(carne);
		Menu();
		break;
	case 3:
		cout << "Carne a eliminar" << endl;
		cin >> carne;
		Eliminar(carne);
		Menu();
		break;
	case 4:
		mostrar();
	}
}