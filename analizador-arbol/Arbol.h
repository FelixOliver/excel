#ifndef ARBOL_EXPRE
#define ARBOL_EXPRE


#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include "Nodo.h"
using namespace std;


class Arbol
{
private:
	stack<string> pila;
	Nodo *raiz;
	vector<string> postfijo;
	vector<string> get_vector(string expre);
	vector<string> convertir(vector<string> v);
	int peso(char);
	void insertar(Nodo*aux);
	void crear_arbol(vector<string> v);
public:
	Arbol(string expre="");
	void set_exprecion(string expre);
	float resultado();
	~Arbol(void);
};


#endif
