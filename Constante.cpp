#include "Constante.h"

Constante::Constante()
{
    //ctor
}
void Constante::set_numero(tipoNum num)
{
    numero=num;
}
tipoNum Constante::get_numero()
{
    return numero;
}
void Constante::set_cadena(string cadena)
{
    numero=atoi(cadena.c_str());
}
string Constante::get_cadena()
{
    string cadena;
    stringstream buffer;
    buffer<<numero;
    cadena=buffer.str();
    return cadena;
}
