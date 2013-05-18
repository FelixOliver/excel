#include "Operations.h"

value addition (value i,value j)
{
    return i+j;
}
value subtraction (value i,value j)
{
    return i-j;
}
value multiplication (value i,value j)
{
    return i*j;
}
value division (value i,value j)
{
    return (j==0)?0:i/j;
}
value sin(value i,value )
{
    return ::sin(i);
}

void insertar_Funciones(map<expr,value(*)(value,value)>& a)
{
  a.insert( simbolo_Funcion("+",&addition) );
  a.insert( simbolo_Funcion("-",&subtraction) );
  a.insert( simbolo_Funcion("*",&multiplication) );
  a.insert( simbolo_Funcion("/",&division) );
  a.insert( simbolo_Funcion("sin",&sin) );
}
