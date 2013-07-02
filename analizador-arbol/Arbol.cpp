#include "Arbol.h"


Arbol::Arbol(string expre)
{
	set_exprecion(expre);

}


Arbol::~Arbol(void)
{
}

void Arbol::set_exprecion(string expre)
{
	vector<string> l;
	l=get_vector(expre);
	if(l.empty())
	{
		cout<<"error de sintaxis"<<endl;
		return;
	}
	postfijo=l=convertir(l);

	crear_arbol(l);
}
void Arbol::crear_arbol(vector<string> v)
{
	for(int i=0;i<v.size();i++)
	{
		pila.push(v[i]);
	}
	Nodo *aux=raiz=new Nodo(pila.top());
	pila.pop();

	insertar(aux);
}
void Arbol::insertar( Nodo*aux)
{
	if(!pila.size())
		return;

	if(aux->info[0]=='n')
		return;

		string temp=pila.top();
		aux->rigth=new Nodo(temp);
		pila.pop();
		insertar(aux->rigth);

		temp=pila.top();
		aux->left=new Nodo(temp);
		pila.pop();
		insertar(aux->left);

}


float Arbol::resultado()
{
	cout<<"el resultado postfijo es: "<<endl;
	for(int i=0;i<postfijo.size();i++)
		cout<<postfijo[i]<<" ";
	cout<<"\nlas n indican que el valor es un numero"<<endl;
	cout<<"\n el resultado es: ";
	return raiz->get();
}
vector<string> Arbol::get_vector(string expre)
{
	vector<string> v;

	string temp="";
	for(unsigned int i=0;i<expre.length();i++)
	{
		if(expre[i]>='0' &&  expre[i]<='9')
		{
			temp="n";
			while(i<expre.length() && (  (expre[i]>='0' &&  expre[i]<='9') || expre[i]=='.' ))
			{
				temp=temp+expre[i];
				i++;
			}
			v.push_back(temp);
			i--;
		}
		else
		{
			switch(expre[i])
			{
			case'+':
				v.push_back("+");
				break;
			case'-':
				v.push_back("-");
				break;
			case'*':
				v.push_back("*");
				break;
			case'/':
				v.push_back("/");
				break;
			case'^':
				v.push_back("^");
				break;
			case'(':
				v.push_back("(");
				break;
			case')':
				v.push_back(")");
				break;
			default:
				vector<string> vacio;
				return vacio;
			}
		}
	}



	return v;
}
int Arbol::peso(char k)
{
	switch(k)
	{
		case'+':return 1;
		case'-':return 1;
		case'*':return 2;
		case'/':return 2;
		case'^':return 3;
		case '(': return 0;
		case ')':return 0;

	}
}
vector<string> Arbol::convertir(vector<string> v)
{
	stack<string> op,op2;
	vector<string> vt;
	string temp;
	for(unsigned int i=0;i<v.size();i++)
	{
		switch(v[i][0])
		{
			case 'n':
				vt.push_back(v[i]);
			break;
			case '(':
				op.push("(");
				break;
			case ')':
				temp=op.top();
				while(op.size()>0 && (temp.compare("(")!=0)	)
				{
					vt.push_back(temp);
					op.pop();
					temp=op.top();

				}
				if(temp.compare("(")==0)
				{
					op.pop();
				}
				else
				{
					cout<<"error"<<endl;
					vector<string> vacio;
					return vacio;
				}
			break;
			//*  (
			default:
				while(op.size()>0 && peso(op.top()[0])>=peso(v[i][0]))
				{
					temp=op.top();
					vt.push_back(temp);
					op.pop();
				}
				op.push(v[i]);
		}

	}
	while(op.size())
		{
			vt.push_back(op.top());
			op.pop();
		}
		//cout<<vt<<endl;
	return vt;
}
