#ifndef NODECONST_H
#define NODECONST_H
#include "node.h"
#include <stdlib.h>

class NodeConst:public Node
{
    public:
        NodeConst(value _constant):constant(_constant){}
        virtual ~NodeConst();
        void set_val(){}
        virtual value get_value(){return constant;}
    private:
        value constant;
};

#endif // NODECONST_H
