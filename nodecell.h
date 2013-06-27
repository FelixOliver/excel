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
        NodeCell(Cell<int>* cell_ptr):m_cell(cell_ptr){}

        /**
         * @brief ~NodeCell destructor
         */
        virtual ~NodeCell(){}

        /**
         * @brief returns the final value of the node
         * @return cell content
         */
        inline virtual value get_value(){return (m_cell->get_content());}

    private:
        Cell<int>* m_cell;/**< cell pointer */

};

#endif // NODECELL_H
