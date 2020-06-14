#pragma once
#include "Tabla.h"

Table* generarTabla()
{
	string filename= "archivo.csv";
	int filas, columnas;

	return (new Table(filename));
}

Table* ordenarPorColumna(Table* objDataFrame, int columna)
{
	string tipo;
	do
	{
		tipo = "ASC";
	} while (tipo != "ASC" &&tipo != "DES");
	Table* df = objDataFrame->ordenar(columna - 1, tipo);
	return df;
}



