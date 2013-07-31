#ifndef NODECONST_H
#define NODECONST_H

#include "Node.h"


class NodeConst:public Node
{
    public:
        /**
         * @brief NodeConst constructor
         * @param constant constant number
         */
        NodeConst(expr expression):Node(expression){}

        /**
         * @brief ~NodeConst destructor
         */
        virtual ~NodeConst(){}

        /**
         * @brief returns the final value of the node
         * @return m_constant
         */
        virtual value get_value(){return stod(m_expression);}
};
#endif // NODECONST_H
