#ifndef LEXICALANALIZER_H
#define LEXICALANALIZER_H

#include "Operations.h"

class LexicalAnalizer
{
    public:
        LexicalAnalizer(){}
        LexicalAnalizer(expr text){set_expression(text);}
        bool get_result();
        inline void set_expression(expr text){ expression=text;}
        inline expr get_expression(){return expression;}
        virtual ~LexicalAnalizer(){}

    private:
        expr expression;
        bool result=false;
        expr buffer; /**< Almacena el nombre de las funciones unarias */

        void details();
        bool lexer();
};

#endif // LEXICALANALIZER_H
