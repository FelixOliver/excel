#ifndef NODECELL_H
#define NODECELL_H
#include "node.h"
#include "Cell.h"


class NodeCell:public Node
{
    public:
        /**
         * @brief NodeCell constructor
         * @param cell_ptr cell pointer
         */
        NodeCell(expr name):Node(name){}

        /**
         * @brief ~NodeCell destructor
         */
        virtual ~NodeCell(){}

        /**
         * @brief returns the final value of the node
         * @return cell content
         */
        inline virtual value get_value(){return //m_cell->get_content()
                                                    2;}/**< valor fantsma por resolver */

    //private:
        //expr m_name_cell;/**< cell pointer */

};

#endif // NODECELL_H
