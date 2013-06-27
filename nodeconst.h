#ifndef NODECONST_H
#define NODECONST_H
#include "node.h"
#include <stdlib.h>

class NodeConst:public Node
{
    public:
        /**
         * @brief NodeConst constructor
         * @param constant constant number
         */
        NodeConst(value constant):m_constant(constant){}

        /**
         * @brief ~NodeConst destructor
         */
        virtual ~NodeConst(){}

        /**
         * @brief returns the final value of the node
         * @return m_constant
         */
        virtual value get_value(){return m_constant;}
    private:
        value m_constant;/**< number const */
};

#endif // NODECONST_H
