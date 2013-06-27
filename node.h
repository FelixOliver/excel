#ifndef NODE_H
#define NODE_H
#include "Operations.h"


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
        Node(expr content):m_content(content){}
        /**
         * @brief ~Node destrutor
         */
        virtual ~Node(){}

        /**
         * @brief pure virtual function
         * @return the final value of the node
         */
        virtual value get_value()=0;
    protected:
        expr m_content;/**< node content */

};

#endif // NODE_H

