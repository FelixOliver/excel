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
value pow(value i,value j)
{   value result=1;
    if(j==0)
        return result;
    for (int it=1;it<=j;it++)
        result=result*i;

    return result;
}
value cos(value i,value )
{
    return ::cos(i);
}
value tan(value i,value )
{
    return ::tan(i);
}

void insert_Functions(map<expr,function> &_map)
{
  _map.insert( simbolo_Funcion("+",&addition));
  _map.insert( simbolo_Funcion("-",&subtraction));
  _map.insert( simbolo_Funcion("*",&multiplication));
  _map.insert( simbolo_Funcion("/",&division));
  _map.insert( simbolo_Funcion("^",&pow));
  _map.insert( simbolo_Funcion("sin",&sin));
  _map.insert( simbolo_Funcion("cos",&cos));
  _map.insert( simbolo_Funcion("tan",&tan));
}

bool find_symbol(string _symbol,function &function_ptr)
{
    insert_Functions(lista_Funciones);
    pMap=lista_Funciones.find(_symbol);
    if(pMap != lista_Funciones.end())
    {
        function_ptr=(pMap->second);
        return true;
    }
    else
        return false;
}

