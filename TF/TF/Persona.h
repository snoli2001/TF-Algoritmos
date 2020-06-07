#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
class Persona
{
public:
	string nombre;
	string equipo;
	int edad;
	char sexo;
	int numero;
public:
	Persona(string n, string e, int y, char s,int num ){
		nombre = n;
		equipo = e;
		edad = y;
		sexo = s;
		numero = num;
	}
	~Persona(){}




};

