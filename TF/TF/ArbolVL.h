#pragma once
#include <vector>
#include <string>
#include <functional>
using namespace std;

template <typename T>
struct Nodo
{
	T data;
	Nodo* izq = nullptr;
	Nodo* der = nullptr;
	int altura_xd = 0;
	Nodo(T data) : data(data) {}
};

template <class T>
class ArbolAVL
{
private:
	Nodo<T>* raiz;
private:
	void _rotar_right(Nodo<T>* x, Nodo<T>*& y, Nodo<T>*& z)
	{
		z = y;
		x->der = y->izq;
		z->izq = x;
	}
	void _rotar_left(Nodo<T>*& x, Nodo<T>* y, Nodo<T>*& z)
	{
		z = x;
		y->izq = x->der;
		z->der = y;
	}
	int _calcularAltura(Nodo<T>* nodo)
	{
		if (nodo == nullptr)
			return -1;
		return nodo->altura_xd;
	}

	void _agregar(Nodo<T>*& nodo, T e, function<bool(T, T)> f)
	{
		if (nodo == nullptr)
		{
			nodo = new Nodo<T>(e);
		}
		else
			if (f(e, nodo->data))
			{
				_agregar(nodo->izq, e, f);
			}
			else
			{
				_agregar(nodo->der, e, f);
			}
		int hl = _calcularAltura(nodo->izq);
		int hr = _calcularAltura(nodo->der);
		int dif = hr - hl;
		if (dif > 1)
		{
			int tl = _calcularAltura(nodo->der->izq);
			int tr = _calcularAltura(nodo->der->der);
			if (tl > tr)
			{
				_rotar_right(nodo->der->izq, nodo->der, nodo->der);
			}
			_rotar_left(nodo, nodo->der, nodo);
		}
		else
			if (dif < -1)
			{
				int tl = _calcularAltura(nodo->izq->izq);
				int tr = _calcularAltura(nodo->izq->der);
				if (tr > tl)
				{
					_rotar_left(nodo->izq, nodo->izq->der, nodo->izq);
				}
				_rotar_right(nodo->izq, nodo, nodo);
			}

	}
	void _inOrder(Nodo<T>* nodo, vector<T> & v)
	{
		if (nodo == NULL) return;
		_inOrder(nodo->izq, v);
		v.push_back(nodo->data);
		_inOrder(nodo->der, v);
	}

	T _search(Nodo<T>*nodo, T e, function<bool(T, T)>f)
	{
		if (nodo == nullptr)
			return 0;
		if (f(e, nodo->data))
			return nodo->data;
		else
		{
			return _search(f(e, nodo->data)>0 ? nodo->der : nodo->izq, e, f);
		}
	}
	Nodo<T> _remove_min(Nodo<T>* nodo, Nodo<T>*& link)
	{
		if (nodo == nullptr)
			return nullptr;
		if (nodo->izq == nullptr)
		{
			link = nodo->der;
			nodo->der = nullptr;
			return nodo;
		}
		else
		{
			return _remove_min(nodo->izq, nodo->izq);
		}

	}
	Nodo<T> _remove_max(Nodo<T>* nodo, Nodo<T>*& link)
	{
		if (nodo == nullptr)
			return nullptr;
		if (nodo->der == nullptr)
		{
			link = nodo->izq;
			nodo->izq = nullptr;
			return nodo;
		}
		else
		{
			return _remove_max(nodo->der, nodo->der);
		}
	}
	void _remove(Nodo<T>*nodo, Nodo<T>*& link, T e, function <bool(T, T)> f)
	{
		if (f(e, nodo->data))
		{
			int hl = _calcularAltura(nodo->izq);
			int hr = _calcularAltura(nodo->der);
			if (hl == -1 & hr == -1)
			{
				link = nullptr;
				delete nodo;
			}
			else
				if (hl > hr)
				{
					Nodo<T>* temp = _remove_max(nodo->izq, nodo->izq);
					temp->izq = nodo->izq;
					temp->der = nodo->der;
					link = temp;
					delete nodo;
				}
				else
				{
					Nodo<T>* temp = _remove_min(nodo->der, nodo->der);
					temp->izq = nodo->izq;
					temp->der = nodo->der;
					link = temp;
					delete nodo;
				}
		}
		else
			if (f(e, nodo->data) && nodo->der != nullptr)
			{
				return _remove(nodo->der, nodo->der, e, f);
			}
			else
				if (f(e, nodo->data) && nodo->izq != nullptr)
				{
					return _remove(nodo->izq, nodo->izq, e, f);
				}
	}
public:
	ArbolAVL() : raiz(nullptr) {}
	void agregar(T e, function<bool(T&, T&)> f) { _agregar(raiz, e, f); }
	void inOrder(vector<T> & v) { _inOrder(raiz, v); }
	int calcularAltura() { _calcularAltura(raiz); }
	T buscar(T e, function<bool(T&, T&)>f) { return _search(raiz, e, f); }
	void remove(T e, function<bool(T&, T&)>f) { return _remove(e, raiz, raiz, f); }
};