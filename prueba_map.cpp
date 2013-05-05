#include <iostream>
#include <map>
#include <utility>

using namespace std;
typedef float numero;
typedef pair<char,numero(*)(numero,numero)> simbolo_Funcion;

numero Suma (numero i,numero j){
	return i+j;
} 
numero Resta (numero i,numero j){
	return i-j;
}
numero Multiplicacion (numero i,numero j){
	return i*j;
}
numero Division (numero i,numero j){
	return (j==0)?0:i/j;
}

//numero (*pFuncion[])(numero,numero)={&::Suma,&::Resta,&::Multiplicacion,&::Division};
map<char,numero(*)(numero,numero)> lista_Funciones;
map<char,numero(*)(numero,numero)>::iterator pMap;

void insertar_Funciones(){
	lista_Funciones.insert( simbolo_Funcion('+',&Suma) );	
	lista_Funciones.insert( simbolo_Funcion('-',&Resta) );
	lista_Funciones.insert( simbolo_Funcion('*',&Multiplicacion) );
	lista_Funciones.insert( simbolo_Funcion('/',&Division) );
}

int main() {
    insertar_Funciones();
	char simbolo=' ';
	int a=0,b=0;
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

