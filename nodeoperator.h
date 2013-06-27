#ifndef NODEOPERATOR_H
#define NODEOPERATOR_H
#include "node.h"


class NodeOperator:public Node
{
    public:
        /**
         * @brief NodeOperator constructor
         * @param left_ptr pointer to left child
         * @param function_ptr function pointer (operations)
         * @param right_ptr pointer to right child
         */
        NodeOperator(Node* left_ptr,
                     function function_ptr,
                     Node* right_ptr=0):
                     m_left_node(left_ptr),
                     m_function_ptr(function_ptr),
                     m_right_node(right_ptr)
                     {};

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
            return (*m_function_ptr)(l,r);
        }
    private:
        Node* m_left_node;/**< pointer to left child */
        function m_function_ptr;/**< operation pointer */
        Node* m_right_node;/**< pointer to right child */
};

#endif // NODEOPERATOR_H
