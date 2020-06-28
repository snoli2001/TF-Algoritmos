#pragma once
#include "Tabla.h"

Table* generarTabla(string fl)
{
	string filename= fl;
	int filas, columnas;

	return (new Table(filename));
}

Table* ordenarPorColumna(Table* objDataFrame, int columna, string t)
{
	string tipo = t;	
	Table* df = objDataFrame->ordenar(columna - 1, tipo);
	return df;
}



