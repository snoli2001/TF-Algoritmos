#pragma once
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int NroColumnas(ifstream & in, char separador)
{
	string line;
	std::getline(in, line);
	int columnas = std::count(line.begin(), line.end(), separador);
	in.seekg(0, ios::beg);
	return columnas;
}

int NroFilas(ifstream & in)
{
	int cantidad = 0;
	string line;
	while (!in.eof())
	{
		std::getline(in, line);
		cantidad++;
	}
	in.seekg(0, ios::beg);
	return cantidad;
}

bool isNum(string number) {
	if (!((number[0] >= '0' && number[0] <= '9') || number[0] == '-' || number[0] == '+'))
		return false;

	for (int i = 1; number[i] != '\0'; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return false;
	}

	return true;
}