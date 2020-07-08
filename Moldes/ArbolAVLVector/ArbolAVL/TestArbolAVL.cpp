#include<time.h>
#include "ArbolAVL.hpp"


using namespace std;
void imprimir(vector<string> e) {

	cout << " ";
	for (int i = 0; i < e.size(); i++)
	{
		cout << e[i]<< " ";
	}
	cout << endl;

	//cout << "Fin de lista";
	
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

int Menu(int col) {
	int op;
	do
	{
		system("cls");
		cout << "\t\tMENU\n";
		cout << "1.Generar lista\n";
		cout << "2.Ver Lista\n";
		cout << "3.Ordenar por columna\n";
		cout << "4.Eliminar elemento "<< ((col==0)? "(Debe generar datos)": ("(La columna seleccionada es: " + to_string(col)+ ")")) << endl ;
		cout << "5.Salir\n";
		cout << "Ingrese una opcion: ";
		cin >> op;
		
	} while (op<0||op>5);
	
	return op;

}


int main() {
	srand(time(NULL));
	ArbolAVL <vector<string>>* tree;
	
	vector<string> vec;
	string eliminar;
	
	vector <vector<string>> vs;
	int col=0;
	string element;
	vector<string> elim;
	int op;
	do
	{
		op = Menu(col);
		switch (op)
		{
		case 1:

			vec.push_back("Luis");
			vec.push_back("Alfonso");
			vec.push_back("Pedro");
			vec.push_back("Jose");
			vec.push_back("Carlos1");
			vec.push_back("Jorge");
			vec.push_back("Carlos2");
			vec.push_back("Jesus");
			vec.push_back("Judith");


			ArbolAVL <vector<string>>* treeSelec;
			treeSelec = new ArbolAVL<vector<string>>(imprimir);
			for (int i = 0; i < vec.size(); i++)
			{
				vector<string> aux;
				eliminar = to_string(rand() % 51);
				aux.push_back(eliminar);
				aux.push_back(vec[i]);
				aux.push_back(to_string(rand() % 51));
				vs.push_back(aux);
			}
			cout << eliminar << endl;

			for (int i = 0; i < vs.size(); i++)
			{
				treeSelec->Insertar(vs[i], [=](vector<string> v1, vector<string> v2, int columna)
					{
						if (isNum(v1[columna]))
						{
							return stoi(v1[columna]) - stoi(v2[columna]);
						}
						else
						{
							if (v1[columna] < v2[columna]) {
								return -1;
							}
							else if (v1[columna] > v2[columna])
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
					}, 0);
			}
			tree = treeSelec;
			col = 1;
			cin.get();
			break;
		case 2:
			cout << "Impresion inOrden de elementos: " << endl;
			tree->inOrden();
			cout << endl;
			cin.get();
			break;
		case 3:
			ArbolAVL <vector<string>>* treeSelec2;
			treeSelec2 = new ArbolAVL<vector<string>>(imprimir);
			cout << "Columna a ordenar: ";
			cin >> col;
			for (int i = 0; i < vs.size(); i++)
			{
				treeSelec2->Insertar(vs[i], [=](vector<string> v1, vector<string> v2, int columna)
					{
						if (isNum(v1[columna]))
						{
							return stoi(v1[columna]) - stoi(v2[columna]);
						}
						else
						{
							if (v1[columna] < v2[columna]) {
								return -1;
							}
							else if (v1[columna] > v2[columna])
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
					}, col - 1);
			}
			tree = treeSelec2;
			tree->inOrden();
			cout << endl;
			cin.get();
			break;
		case 4:
			cout << "La columna seleccionada actual es: "<< col<<endl;
			

			for (int i = 0; i < 3; i++)
			{
				elim.push_back("");
			}
			cout << "Ingrese el valor a eliminar correspondiente a dicha columna: ";
			cin >> eliminar;
			elim[col - 1] = eliminar;
			tree->Eliminar(elim, [=](vector<string> v1, vector<string> v2, int columna)
				{
					if (isNum(v1[columna]))
					{
						return stoi(v1[columna]) - stoi(v2[columna]);
					}
					else
					{
						if (v1[columna] < v2[columna]) {
							return -1;
						}
						else if (v1[columna] > v2[columna])
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
				}, col-1);
			cin.get();
			break;
		default:
			break;
		}
		cin.get();


	} while (op!=5);
	
	
	
	

	

	
	
	/*tree->Insertar({ eliminar ,"Fred"}, [=](vector<string> v1, vector<string> v2, int columna)
		{
			if (isNum(v1[columna]))
			{
				return stoi(v1[columna]) - stoi(v2[columna]);
			}
			else
			{
				if (v1[columna] < v2[columna]) {
					return -1;
				}
				else if (v1[columna] > v2[columna])
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		},0);
	tree->inOrden();
	cout << endl;
	cout << "Impresion inOrden de alturas: " << endl;
	tree->inOrdenH();*/

	
	return 0;
}