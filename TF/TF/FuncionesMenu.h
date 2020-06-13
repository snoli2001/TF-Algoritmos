#pragma once
#include "Tabla.h"

Table* generarDataFrame()
{
	string filename= "archivo.csv";
	int filas, columnas;

	return (new Table(filename));
}

Table* ordenarPorColumna(Table* objDataFrame)
{
	int columna;
	string tipo;

	cout << "\tOrdenar columnas Nro: ";
	cin >> columna;

	do
	{
		cout << "\tOrdenar de forma [ASC, DES]: ";
		cin >> tipo;
	} while (tipo != "ASC" &&tipo != "DES");

	Table* df = objDataFrame->ordenar(columna - 1, tipo);
	return df;
}

Table* seleccionarColumnas(Table* objDataFrame)
{
	string datos;
	cout << "\tColumnas a seleccionar [eg. 1,2,3]: ";
	cin >> datos;

	vector<int> columnas;

	while (datos != "")
	{
		int fin = datos.find(',');
		if (fin == -1) fin = datos.size();
		columnas.push_back(stoi(datos.substr(0, fin)) - 1);
		if (fin != datos.length())
			datos = datos.substr(fin + 1);
		else datos = "";
	}

	Table* df = objDataFrame->seleccionarColumnas(columnas);
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
