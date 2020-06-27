#pragma once
#include <iostream>
#include "ArbolVL.h"
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

using namespace std;

class Table
{
protected:
	vector<vector<string>> contenido;
public:
	Table(string filename, char separador = ',')
	{
		ifstream in(filename);
		if (!in.is_open()) return;
		else
		{
			contenido.resize(NroFilas(in));
			int posicion = 0;

			int nroColumnas = NroColumnas(in, separador);

			while (!in.eof())
			{
				string line;
				contenido[posicion].resize(nroColumnas);
				for (int i = 0; i < nroColumnas; i++)
				{
					std::getline(in, line, separador);
					contenido[posicion][i] = line;
				}
				std::getline(in, line);
				posicion++;
			}
		}
		in.close();
	}

	Table(vector<vector<string>> datos) : contenido(datos) {}

	

	Table* ordenar(int columna, string tipo)
	{
		ArbolAVL<vector<string>>* bt = new ArbolAVL<vector<string>>();
		for (int i = 0; i < contenido.size(); i++)
			bt->agregar(contenido[i], [=](vector<string> v1, vector<string> v2)
		{
			if (isNum(v1[columna]))
			{
				if (tipo == "ASC") return (stoi(v1[columna]) < stoi(v2[columna]));
				else return (stoi(v1[columna]) > stoi(v2[columna]));
			}
			else
			{
				if (tipo == "ASC")
					return (v1[columna] < v2[columna]);
				return (v1[columna] > v2[columna]);
			}
		});


		vector<vector<string>> n_cuadro;
		bt->inOrder(n_cuadro);

		delete bt;
		return (new Table(n_cuadro));
	}

	Table* seleccionarColumnas(vector<int> columnas)
	{
		vector<vector<string>> n_cuadro(contenido.size());

		for (int i = 0; i < contenido.size(); i++)
		{
			for (int columna : columnas)
				n_cuadro[i].push_back(contenido[i][columna]);
		}

		return (new Table(n_cuadro));
	}

	Table* Filtro_ComienzaCon(int columna, string cadena)
	{
		if (isNum(contenido[0][columna]))
		{
			
			return NULL;
		}

		vector<vector<string>> n_cuadro = contenido;
		

		for (int i = n_cuadro.size() - 1; i >= 0; i--)
		{
			if (!n_cuadro[i][columna].find(cadena) == 0)
				n_cuadro.erase(n_cuadro.begin() + i);
		}

		return (new Table(n_cuadro));
	}

	Table* Filtro_TerminaCon(int columna, string cadena)
	{
		if (isNum(contenido[0][columna]))
		{
			
			return NULL;
		}

		vector<vector<string>> n_cuadro = contenido;

		for (int i = n_cuadro.size() - 1; i >= 0; i--)
		{
			int posicion = (n_cuadro[i][columna]).find(cadena);
			if (posicion == -1 || !(posicion == n_cuadro[i][columna].length() - cadena.length()))
				n_cuadro.erase(n_cuadro.begin() + i);
		}

		return (new Table(n_cuadro));
	}

	Table* Filtro_Menor_que(int columna, int search)
	{
		if (!isNum(contenido[0][columna]))
		{
			
			return NULL;
		}

		int var;
		var = 0;

		vector<vector<string>> n_cuadro = contenido;

		for (int i = n_cuadro.size() - 1; i >= 0; i--)
		{
			var = stoi(n_cuadro[i][columna]);
			if (var >= search)
			{
				n_cuadro.erase(n_cuadro.begin() + i);
			}
		}

		return (new Table(n_cuadro));
	}

	Table* Filtro_Mayor_que(int columna, int search)
	{
		if (!isNum(contenido[0][columna]))
		{
			
			return NULL;
		}

		int var;
		var = 0;

		vector<vector<string>> n_cuadro = contenido;

		for (int i = n_cuadro.size() - 1; i >= 0; i--)
		{
			var = stoi(n_cuadro[i][columna]);
			if (var <= search)
			{
				n_cuadro.erase(n_cuadro.begin() + i);
			}
		}

		return (new Table(n_cuadro));
	}

	Table* Filtro_Igual_que(int columna, string cadena)
	{
		vector<vector<string>> n_cuadro = contenido;

		for (int i = n_cuadro.size() - 1; i >= 0; i--)
		{
			if (!(n_cuadro[i][columna] == cadena))
				n_cuadro.erase(n_cuadro.begin() + i);
		}

		return (new Table(n_cuadro));
	}

	Table* Filtro_Contiene(int columna, string cadena)
	{
		vector<vector<string>> n_cuadro = contenido;

		for (int i = n_cuadro.size() - 1; i >= 0; i--)
		{
			if (n_cuadro[i][columna].find(cadena) == -1)
				n_cuadro.erase(n_cuadro.begin() + i);
		}

		return (new Table(n_cuadro));
	}

	Table* Filtro_No_Contiene(int columna, string cadena)
	{
		vector<vector<string>> n_cuadro = contenido;

		for (int i = n_cuadro.size() - 1; i >= 0; i--)
		{
			if (!(n_cuadro[i][columna].find(cadena) == -1))
				n_cuadro.erase(n_cuadro.begin() + i);
		}

		return (new Table(n_cuadro));
	}

	void exportar(string filename, char separador = ',')
	{
		ofstream out;
		out.open(filename);
		if(out.is_open())
		{
			for (int i = 0; i < contenido.size() - 1; i++)
			{
				for (int j = 0; j < contenido[i].size(); j++)
					out << contenido[i][j] << separador;
				out << endl;
			}

			for (int j = 0; j < contenido[contenido.size() - 1].size(); j++)
				out << contenido[contenido.size() - 1][j] << separador;
		}
		out.close();
	}

	bool isEmpty() { return contenido.size() == 0; }

	vector<vector<string>> get_content() {
		return contenido;
	}
	void print()
	{
		for (int i = 0; i < contenido.size() - 1; i++)
		{
			for (int j = 0; j < contenido[i].size(); j++)
				cout << contenido[i][j] << setw(20);
			cout << endl;
		}

		for (int j = 0; j < contenido[contenido.size() - 1].size(); j++)
			cout << contenido[contenido.size() - 1][j] << setw(20);
	}
	bool generado() { return contenido.size() != 0; }

	void insertar(vector<string> datos) {
		contenido.push_back(datos);
	}

	private:
		int NroColumnas(ifstream& in, char separador)
		{
			string line;
			std::getline(in, line);
			int columnas = std::count(line.begin(), line.end(), separador);
			in.seekg(0, ios::beg);
			return columnas;
		}

		int NroFilas(ifstream& in)
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

	
};