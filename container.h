#ifndef CONTAINER_H
#define CONTAINER_H

#include "cell.h"

template <typename T>
class Container
{
    public:
        Container();
        inline Cell<T> is_used_cell(expr name){return m_container[name];}
        void add_to_container(expr name,expr expression,position row,position column);



    private:
        map<expr,Cell<T>> m_container;


};

#endif // CONTAINER_H
