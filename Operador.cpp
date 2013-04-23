#include "Operador.h"

typedef int tipo;

float suma(tipo i,tipo j){
	return i+j;
}
float resta(tipo i,tipo j){
	return i-j;
}
float multiplicacion(tipo i,tipo j){
	return i*j;
}
float division(tipo i,tipo j){
	if(j!=0)
		return i/j;
	else
		return 0;
}

float (*pFuncion[])(tipo,tipo)={&::suma,&::resta,&::multiplicacion,&::division};

Operador::Operador(char caracter)
{
    simbolo=caracter;
}
int Operador::orden_operacion()
{
    int ascii = (int)simbolo;
    if(ascii==43)
        return 0;
    else{
        if(ascii == 42)
            return 2;
        else
            return ascii-44;
    }
}
float Operador::resultado(int x,int y,int op)
{
     return (*pFuncion[op])(x,y);
}


