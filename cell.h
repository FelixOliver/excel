#ifndef CELL_H
#define CELL_H
#include <vector>
#include "Node.h"
#include <memory>
#include <algorithm>

typedef string expr;
typedef string cell_name;
static const unsigned int letters_total = 26; /**< El numero total de letras*/


using namespace std;

template <typename T>
class Cell
{
    typedef T type_content;
    typedef shared_ptr<Cell<type_content>> cell_ptr;

    public:
        /**
         * @brief constructor
         * @param expression expression
         * @param row row number
         * @param column column number
         */
        Cell(expr expression,value row,value column)
        :m_expression(expression),m_row(row),m_column(column){}

        /**
         * @brief destructor
         */
        virtual ~Cell(){}

        inline position get_row(){return m_row;}
        inline position get_column(){return m_column;}

        inline void set_cell_expression(expr _cell_expression){m_expression = _cell_expression;}
        inline expr get_cell_expression(){return m_expression;}

        void generate_name(){m_name=name_column_from_number(m_column)+to_string(m_row);}
        inline cell_name get_name(){return m_name;}

        inline void update_cell_value(value _cell_value){m_content=_cell_value;}

        inline void add_To_list_cell_used(cell_ptr & cell_pointer) {m_list_cells_used.push_back(move(cell_pointer)); }
        inline vector<cell_ptr> get_list_cells_used(){return m_list_cells_used;}

        void delete_cellTo_list_dependencies(expr &);
                void update_list_cells_used();

        /**
         * @brief updates the value of the cell
         * @sa get_content()
         */
        inline void update_content(){m_content = m_tree_ptr->get_value();}

        /**
         * @brief renews cell expression
         * @param expression new expression
         */
        inline void set_expression(expr expression){m_expression=expression;}

        /**
         * @brief returns the cell value
         * @return m_content
         * @sa get_expression() and get_name()
         */
        inline value get_content(){return m_content;}

        /**
         * @brief returns the cell expression
         * @return m_expression
         * @sa get_content(), get_name() and m_expression
         */
        inline expr get_expression(){return m_expression;}

        /**
         * @brief returns the name of the cell
         * @return name of the cell
         * @sa get_content() and get_expression()
         */

    private:
        expr m_name;
        position m_row;/**< row number */
        position m_column;/**< column number */
        vector <cell_ptr> m_dependencies_list;/**< dependencies list of the cell */
        vector <cell_ptr> m_list_cells_used;
        expr m_expression;/**< cell expression */
        type_content m_content;/**< final cell value */
        Node* m_tree_ptr;/**< operations tree pointer */

};

#endif // CELL_H


/*
template <typename T>
void Cell<T>::generate_name()
{
    position _column = m_column;
    auto residue = _column%letters_total;
    m_name = letters[residue];
    _column /= letters_total;
    if(_column!=0)
    {
        while(_column>0)
        {
            residue = _column%letters_total;
            if(residue==0)
            {
                _column/=letters_total;
                m_name=letters[letters_total-1]+m_name;
                if(_column<letters_total)
                    _column=0;
            }
            else
            {
                m_name=letters[residue-1]+m_name;
                _column/=letters_total;
            }
        }
    }
    stringstream ss;
    ss<< m_row+1;
    m_name+=ss.str();
}
*/
template <typename T>
void Cell<T>::delete_cellTo_list_dependencies(expr &name_cell){
    typename vector <shared_ptr<Cell<T> > >::iterator it;
    for (register auto &i: m_dependencies_list )
        if (i->get_name)
    it= find_if(m_dependencies_list.begin(),m_dependencies_list.end(),
                [name_cell](cell_ptr &cell_pointer){return name_cell==cell_pointer->get_name();}); /**< funcion lambda*/
    m_dependencies_list.erase(it,it+1);
}
template <typename T>
void Cell<T>::update_list_cells_used(){
    for(register auto &i : m_list_cells_used)
        i->delete_cellTo_list_dependencies(m_name);
    m_list_cells_used.clear();
}


