#ifndef __ARBOLAVL_HPP__
#define __ARBOLAVL_HPP__

#include "NodoAVL.hpp"

template<class T>
class ArbolAVL {
	
private:
	Nodo<T>* raiz;
	void(*procesar)(T);
	
	

private:
	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;

		nodo = p;
	}

	void _rotarIzquierda(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;

		nodo = p;
	}
	void _balanceo(Nodo<T>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) { 
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) { 
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) { 
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(Nodo<T>*& nodo, T e, function<int(T&, T&)> comparar) {
		
		
		if (nodo == nullptr) {
			
			nodo = new Nodo<T>();
			nodo->elemento = e;
			return true;
		}
		else if (comparar(nodo->elemento, e) == 0)
			return false;
		else if (comparar(nodo->elemento, e)>0) {
			_insertar(nodo->izq, e,comparar);
		}
		else if (comparar(nodo->elemento, e)<0) {
			_insertar(nodo->der, e,comparar);
		}
		_balanceo(nodo);
		return true;
	}
	
	void _inOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		procesar(nodo->elemento);
		_inOrden(nodo->der);
	}

	void _inOrdenH(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		procesar(to_string(nodo->altura));
		_inOrdenH(nodo->der);
	}
	bool _eliminar(Nodo<T>*& nodo, T e, function<int(T&, T&)> comparar) {
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r < 0) {
				return _eliminar(nodo->der, e, comparar);
			}
			else if (r > 0) {
				return _eliminar(nodo->izq, e, comparar);
			}
			else { // r==0 es porque se encontró el elemento e en el arbol
				if (nodo->der == nullptr && nodo->izq == nullptr) {//caso 1
					nodo = nullptr;
					delete nodo;
					return true;
				}
				else if (nodo->izq == nullptr) { //caso 2
					nodo = nodo->der;
					return true;
				}
				else if (nodo->der == nullptr) { //caso 3
					nodo = nodo->izq;
					return true;
				}
				else { //caso 4
					Nodo<T>* aux = nodo->der; //Se establece buscar el menor elemento por la derecha
					while (aux->izq != nullptr)
					{
						aux = aux->izq; //Se obtiene la hoja menor
					}
					nodo->elemento = aux->elemento; //Se actualiza el elemento en el nodo raiz y
					return _eliminar(nodo->der, aux->elemento, comparar); //se envía a eliminar el elemento en el arbol por la derecha
				}
			}
		}

	}

public:
	ArbolAVL(void(*nuevaFuncion)(T)) {
		this->procesar = nuevaFuncion;
		this->raiz = nullptr;		
		
	}

	bool Insertar(T e, function<int(T&, T&)>f) {
		return _insertar(raiz, e,f);
	}
	void inOrden() {
		_inOrden(raiz);
	}
	void inOrdenH() {
		_inOrdenH(raiz);
	}
	bool Eliminar(T e, function<int(T&, T&)>f) {
		bool val = _eliminar(raiz, e, f);
		if (val) {
			_balanceo(raiz);
		}
		return val;
		
	}
	
};
#endif // !__ARBOLAVL_HPP__

