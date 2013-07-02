#include "Arbol.h"

int main()
{
	Arbol n("18*(10+450)-32+10^2");
	cout<<n.resultado()<<endl;


	stack<int> v;
	v.push(3);
	v.push(5);
	v.push(7);
//	int a=v.pop();

	cout<<"top"<<v.top()<<endl;
     v.pop();
     cout<<"top"<<v.top()<<endl;
     cout<<true<<" "<<false<<endl;





	return 0;
}
