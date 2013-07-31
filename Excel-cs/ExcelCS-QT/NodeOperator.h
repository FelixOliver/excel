#ifndef NODEOPERATOR_H
#define NODEOPERATOR_H

#include "node.h"
#include "Operations.h"

class NodeOperator:public Node
{
    public:
        /**
         * @brief NodeOperator constructor
         * @param function_ptr function pointer (operations)
         */
        NodeOperator(expr symbol):Node(symbol){}

        /**
         * @brief ~NodeOperator destructor
         */
        virtual ~NodeOperator(){}


        /**
         * @brief returns the final value of the node
         * @return the result of the operation
         */
        virtual value get_value()
        {
            value l=m_left_node->get_value();
            value r=0;
            if(m_right_node)
                r=m_right_node->get_value();
            return get_function(m_expression)(l,r);
        }
};
#endif // NODEOPERATOR_H
