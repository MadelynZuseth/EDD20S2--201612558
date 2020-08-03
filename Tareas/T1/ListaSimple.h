#pragma once
#include "pch.h"
#include <string>
#include <iostream>

using namespace std;
class ListaSimple
{
public:
	NodoLista *cabecera;

	void Insertar(int carne, string nombre);
	NodoLista *Buscar(int carne);
	void Eliminar(int carne);
	void mostrar();
	void Menu();

};

