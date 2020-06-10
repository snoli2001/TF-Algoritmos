#pragma once

template <class T>
class Nodo {
public:
	T valComparativo;
	T registro;
	Nodo<T> izq;
	Nodo<T> der;

	Nodo() {
		izq = nullptr;
		der = nullptr;
	}

};