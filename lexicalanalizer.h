#ifndef LEXICALANALIZER_H
#define LEXICALANALIZER_H

#include "Operations.h"
class LexicalAnalizer
{
    public:
        LexicalAnalizer(){}
        LexicalAnalizer(expr text){set_expression(text);}
        bool get_result();
        inline expr get_wrong_expression(){return wrong_expression;}
        inline void set_expression(expr text){ expression=text;}
        inline expr get_expression(){return expression;}
        virtual ~LexicalAnalizer(){}
    private:
        expr expression;
        bool result=false;
        expr wrong_expression="";
        vector<unsigned> lower_positions;
        expr operator_unary;
        void update_lowerTOupper();
        void details();
        bool lexer();
};

#endif // LEXICALANALIZER_H
