#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

typedef double value;
typedef string expr;
typedef pair<expr,value(*)(value ,value )> simbolo_Funcion;
typedef value(*function)(value ,value );


value addition (value i,value j);
value subtraction (value i,value j);
value multiplication (value i,value j);
value division (value i,value j);
value sin(value i,value );

/*static value  power (value& i,value& j)
{
  return i^j;
}*/

static map<expr,value(*)(value,value)> lista_Funciones;
static map<expr,value(*)(value,value)>::iterator pMap;


//en una clase
//map<expr,value(*)(value,value)> lista_Funciones;
//map<expr,value(*)(value,value)>::iterator pMap;


void insertar_Funciones(map<expr,value(*)(value,value)> &a);




#endif // OPERATIONS_H
