#ifndef NODECELL_H
#define NODECELL_H
#include "node.h"
#include "Cell.h"


//using namespace op;

class NodeCell:public Node
{
    public:
        NodeCell(Cell* _cell_ptr):cell(_cell_ptr){}
        virtual ~NodeCell();
        inline virtual value get_value(){return (cell->get_val());}
    private:
        Cell* cell;

};

#endif // NODECELL_H
