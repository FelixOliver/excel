#include <iostream>
#include "node.h"
#include <vector>

using namespace std;

int main()
{

    vector <int> hola;
    hola.push_back(1);
    hola.push_back(2);

    //NodeOperator o;
    //o.operador;


    cout <<"hola"<< endl;

    insertar_Funciones(lista_Funciones);

    string simbolo;
    value a=0,b=0;
    cout<<"Ingrese simbolo : ";
    cin>>simbolo;
    cout<<"Ingrese primer digito : ";
    cin>>a;
    cout<<"Ingrese segundo digito : ";
    cin>>b;
    cout<<"----------------------------------"<<endl;
    pMap=lista_Funciones.find(simbolo);
    if(pMap != lista_Funciones.end())
    cout<<"El resultado es "<<(pMap->second)(a,b)<<endl;
    else
    cout<<"El simbolo "<<simbolo<<" no se encontro"<<endl;
    return 0;
}
