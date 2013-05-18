#ifndef SYNTAXANALIZER_H
#define SYNTAXANALIZER_H
#include "node.h"

typedef vector<Node*> list_depend;

class SyntaxAnalizer
{
    public:
        SyntaxAnalizer(expr _txt){set_txt(_txt);}
        virtual ~SyntaxAnalizer();
        inline void clean(){dependencies.empty();}
        inline void set_txt(expr _txt){clean();txt=_txt;}
        Node* parse();
        list_depend get_dependencies();


    private:
        expr txt;
        list_depend dependencies;
};

#endif // SYNTAXANALIZER_H
