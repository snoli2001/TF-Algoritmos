#pragma once
#include <vector>
#include <string>
#include <functional>
using namespace std;

template <typename T>
struct Nodo
{
	T data;
	Nodo* left = nullptr;
	Nodo* right = nullptr;
	int altura_xd = 0;
	Nodo(T data) : data(data) {}
};

template <class T>
class ArbolAVL
{
	Nodo<T>* raiz;
	void _rotar_right(Nodo<T>* x, Nodo<T>*& y, Nodo<T>*& z)
	{
		z = y;
		x->right = y->left;
		z->left = x;
	}
	void _rotar_left(Nodo<T>*& x, Nodo<T>* y, Nodo<T>*& z)
	{
		z = x;
		y->left = x->right;
		z->right = y;
	}
	int _update(Nodo<T>* nodo)
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
				_agregar(nodo->left, e, f);
			}
			else
			{
				_agregar(nodo->right, e, f);
			}
		int hl = _update(nodo->left);
		int hr = _update(nodo->right);
		int dif = hr - hl;
		if (dif > 1)
		{
			int tl = _update(nodo->right->left);
			int tr = _update(nodo->right->right);
			if (tl > tr)
			{
				_rotar_right(nodo->right->left, nodo->right, nodo->right);
			}
			_rotar_left(nodo, nodo->right, nodo);
		}
		else
			if (dif < -1)
			{
				int tl = _update(nodo->left->left);
				int tr = _update(nodo->left->right);
				if (tr > tl)
				{
					_rotar_left(nodo->left, nodo->left->right, nodo->left);
				}
				_rotar_right(nodo->left, nodo, nodo);
			}

	}
	void _inOrder(Nodo<T>* nodo, vector<T> & v)
	{
		if (nodo == NULL) return;
		_inOrder(nodo->left, v);
		v.push_back(nodo->data);
		_inOrder(nodo->right, v);
	}

	T _search(Nodo<T>*nodo, T e, function<bool(T, T)>f)
	{
		if (nodo == nullptr)
			return 0;
		if (f(e, nodo->data))
			return nodo->data;
		else
		{
			return _search(f(e, nodo->data)>0 ? nodo->right : nodo->left, e, f);
		}
	}
	Nodo<T> _remove_min(Nodo<T>* nodo, Nodo<T>*& link)
	{
		if (nodo == nullptr)
			return nullptr;
		if (nodo->left == nullptr)
		{
			link = nodo->right;
			nodo->right = nullptr;
			return nodo;
		}
		else
		{
			return _remove_min(nodo->left, nodo->left);
		}

	}
	Nodo<T> _remove_max(Nodo<T>* nodo, Nodo<T>*& link)
	{
		if (nodo == nullptr)
			return nullptr;
		if (nodo->right == nullptr)
		{
			link = nodo->left;
			nodo->left = nullptr;
			return nodo;
		}
		else
		{
			return _remove_max(nodo->right, nodo->right);
		}
	}
	int _remove(Nodo<T>*nodo, Nodo<T>*& link, T e, function <bool(T, T)> f)
	{
		if (f(e, nodo->data))
		{
			int hl = _update(nodo->left);
			int hr = _update(nodo->right);
			if (hl == -1 & hr == -1)
			{
				link = nullptr;
				delete nodo;
			}
			else
				if (hl > hr)
				{
					Nodo<T>* temp = _remove_max(nodo->left, nodo->left);
					temp->left = nodo->left;
					temp->right = nodo->right;
					link = temp;
					delete nodo;
				}
				else
				{
					Nodo<T>* temp = _remove_min(nodo->right, nodo->right);
					temp->left = nodo->left;
					temp->right = nodo->right;
					link = temp;
					delete nodo;
				}
		}
		else
			if (f(e, nodo->data) && nodo->right != nullptr)
			{
				return _remove(nodo->right, nodo->right, e, f);
			}
			else
				if (f(e, nodo->data) && nodo->left != nullptr)
				{
					return _remove(nodo->left, nodo->left, e, f);
				}
	}
public:
	ArbolAVL() : raiz(nullptr) {}
	void agregar(T e, function<bool(T&, T&)> f) { _agregar(raiz, e, f); }
	void inOrder(vector<T> & v) { _inOrder(raiz, v); }
	int update() { _update(raiz); }
	T buscar(T e, function<bool(T&, T&)>f) { return _search(raiz, e, f); }
	int remove(T e, function<bool(T&, T&)>f) { return _remove(e, raiz, raiz, f); }
};