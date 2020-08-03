#pragma 
#include "pch.h"
#include <string>
#include <iostream>

using namespace std;
class NodoLista
{
public:
	int carne;
	string nombre;
	NodoLista *siguiente;

	NodoLista(int carne_, string nombre_ ) {
		carne = carne_;
		nombre = nombre_;
		siguiente = nullptr;
	}


};

