#include<time.h>
#include "ArbolAVL.hpp"



void imprimir(string e) {
	cout << " " << e;
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

int main() {

	ArbolAVL <string>* tree;

	tree = new ArbolAVL<string>(imprimir);

	vector<int> vec;
	vec.push_back(15);
	vec.push_back(20);
	vec.push_back(24);
	vec.push_back(10);
	vec.push_back(13);
	vec.push_back(7);
	vec.push_back(30);
	vec.push_back(36);
	vec.push_back(25);
	srand(time(NULL));

	vector <vector<string>> vs;
	for (int i = 0; i < vec.size(); i++)
	{
		vector<string> aux;
		aux.push_back(to_string(rand()%51));
		aux.push_back(to_string(vec[i]));
		vs.push_back(aux);
	}

	for (int i = 0; i < vec.size(); i++)
	{		
		tree->Insertar(to_string(vec[i]), [=](string v1, string v2)
			{
				if (isNum(v1))
				{
					return stoi(v1) - stoi(v2);
				}
				else
				{
					if (v1 < v2) {
						return -1;
					}
					else if (v1 > v2)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			});
	}

	

	cout << "Impresion inOrden de elementos: " << endl;
	tree->inOrden();
	cout << endl;
	tree->Eliminar("15", [=](string v1, string v2)
		{
			if (isNum(v1))
			{
				return stoi(v1) - stoi(v2);
			}
			else
			{
				if (v1 < v2) {
					return -1;
				}
				else if (v1 > v2)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		});
	tree->Insertar("14", [=](string v1, string v2)
		{
			if (isNum(v1))
			{
				return stoi(v1) - stoi(v2);
			}
			else
			{
				if (v1 < v2) {
					return -1;
				}
				else if (v1 > v2)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		});
	tree->inOrden();
	cout << endl;
	cout << "Impresion inOrden de alturas: " << endl;
	tree->inOrdenH();

	cin.get();

	return 0;
}