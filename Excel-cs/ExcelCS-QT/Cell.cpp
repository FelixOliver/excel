#include "Cell.h"
Cell::Cell(expr expression,position row,position column)
{
    this->m_row=row;
    this->m_column=column;
    set_expression(expression);
}

Cell Cell::operator=(Cell& _new)
{
    m_expression=_new.get_expression();
    m_row=_new.get_row();
    m_column=_new.get_column();
    m_result=_new.get_result();
    m_dependencies_list=_new.get_dependencies_list();
    m_list_used_cells=_new.get_list_cells_used();
    m_is_text=_new.is_text();
    return *this;
}


void Cell::delete_cellTo_list_dependencies(expr & name_cell)
{
    for (register auto &i: m_dependencies_list )
        if (i==name_cell)
            return;
            //m_dependencies_list.erase(i,i);
    /*it= find_if(m_dependencies_list.begin(),m_dependencies_list.end(),
                [name_cell](cell_ptr &cell_pointer){return name_cell==cell_pointer->get_name();});
    m_dependencies_list.erase(it,it+1);*/
}

void Cell::update_list_cells_used()
{
    //for(register auto &i : m_list_cells_used)
      //  i.delete_cellTo_list_dependencies(m_name);
    //m_list_cells_used.clear();
}

void Cell::set_expression(expr new_expression)
{
    m_expression.clear();
    update_list_cells_used();
    m_expression=new_expression;
    if(m_expression[0]=='=' || is_number(m_expression))
        m_is_text=false;
    else
        m_is_text=true;

}

/**
 * @brief updates the value of the cell
 * @sa get_content()
 */
void Cell::set_result(value result)
{
    m_result=result;
}

