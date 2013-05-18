#ifndef NODEOPERATOR_H
#define NODEOPERATOR_H
#include "node.h"


class NodeOperator:public Node
{
    public:
        NodeOperator(Node* _left_ptr, // cbh
                     function _function_ptr,  // poiter to & add,&substraccion,&multipl...
                     Node* _right_ptr=0):
                     left_node(_left_ptr),
                     function_ptr(_function_ptr),
                     right_node(_right_ptr)
                     {};
        virtual ~NodeOperator();
        virtual value eval(value,value){};

        virtual value get_value()
        {
            value l=left_node->get_value();
            value r=0;
            if(right_node)
                value r=right_node->get_value();
            return (*function_ptr)(l,r);
        }
    private:
        Node* left_node;
        function function_ptr;
        Node* right_node;
};

#endif // NODEOPERATOR_H
