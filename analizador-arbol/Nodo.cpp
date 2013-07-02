#include "Nodo.h"


Nodo::Nodo(string text)
{
	this->info=text;
	left=rigth=NULL;
}


Nodo::~Nodo(void)
{
}
float Nodo::get()
{
	
	switch(info[0])
	{
		case'+':if(left &&rigth)
					return left->get()+rigth->get();
		case'-':if(left &&rigth)
					return left->get()-rigth->get();
		case'*':if(left &&rigth)
					return left->get()*rigth->get();
		case'/':if(left &&rigth)
					return left->get()/rigth->get();
		case'^':if(left &&rigth)
					return pow(left->get(),rigth->get());
		case'n':
			float f;
			sscanf(&(info[1]), "%f", &f);
			return f;
		default:
			return 0;
	}

}