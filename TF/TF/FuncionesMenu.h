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



void exportarDatos(Table* objDataFrame)
{
	string filename;
	cout << "\tIngrese el nombre del archivo: ";
	cin >> filename;
	objDataFrame->exportar(filename);
	cout << "\tDatos exportados satisfactoriamente" << endl;
}
