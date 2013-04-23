#include "Celda.h"

int convertir (char caracter)
{
    return (int)caracter-64;
}
char convStoCH (string ss)
{
	char x = ss[0];
	return x;
}

Celda::Celda(string cadena)
{
    fila =0;
    *pCadena="";
    int taman=cadena.length();
    columna=atoi(cadena.substr(taman-1,taman).c_str());
    cadena.erase(taman-1,taman);

    int exp = 0;
    string buffer ="";
    while(cadena!=""){
        buffer = cadena.substr(taman-1,taman);
        fila=fila+(pow(26,exp)*convertir(convStoCH(buffer)));
        cadena.erase(taman-1,taman);
        exp++;
        taman--;
    }
    fila--;
}
void Celda::set_contenido(string cadena)
{
    pCadena=&cadena;
}
int Celda::get_fila()
{
    return fila;
}
int Celda::get_columna()
{
    return columna;
}
string Celda::contenido()
{
    return (*pCadena);
}




