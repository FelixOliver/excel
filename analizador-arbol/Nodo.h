#ifndef NODO_EX
#define NODO_EX


#include <string>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class Nodo
{
private:
	string info;
	Nodo *left,*rigth;
public:
	Nodo(string text);
	~Nodo(void);
	float get();

	friend class Arbol;
};
#endif
