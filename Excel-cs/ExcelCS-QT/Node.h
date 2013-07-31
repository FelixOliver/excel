#ifndef NODE_H
#define NODE_H
#include "Includes.h"
class Node
{
    public:
        /**
         * @brief Node Constructor
         */
        Node(){}
        /**
         * @brief Node constructor with parameters
         * @param content node content
         */
        Node(expr expression):m_expression(expression){}

        /**
         * @brief ~Node destrutor
         */
        virtual ~Node(){}


        inline expr get_expression(){return m_expression;}
        /**
         * @brief pure virtual function
         * @return the final value of the node
         */
        virtual value get_value()=0;

        unique_ptr<Node> m_left_node=0;/**< pointer to left child */
        unique_ptr<Node> m_right_node=0;/**< pointer to right child */
        expr m_expression;/**< node content */



};
#endif // NODE_H
