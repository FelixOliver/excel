#ifndef NODECELL_H
#define NODECELL_H

#include "Node.h"
#include "Cell.h"


class NodeCell:public Node
{
    public:
        /**
         * @brief NodeCell constructor
         * @param cell_ptr cell pointer
         */
        NodeCell(Cell* cell_ptr,expr expression):Node(expression),m_cell_ptr(cell_ptr){}

        /**
         * @brief ~NodeCell destructor
         */
        virtual ~NodeCell(){}

        /**
         * @brief returns the final value of the node
         * @return cell content
         */
        inline virtual value get_value(){
            if(m_cell_ptr)
                return m_cell_ptr->get_result();
            else
                return 0;
        }

    private:
        Cell* m_cell_ptr;
};

#endif // NODECELL_H
