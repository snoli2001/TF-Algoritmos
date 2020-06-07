#pragma once

template <class T>
class Nodo {
public:
	T val;
	Nodo<T> izq;
	Nodo<T> der;

};