#ifndef CELL_H
#define CELL_H

#include <vector>
#include <algorithm>
#include "node.h"
#include "includes.h"

typedef string cell_name;

class Cell
{
    public:
        /**
         * @brief Cell constructor
         */
        Cell(){}
        /**
         * @brief constructor
         * @param expression expression
         * @param row row number
         * @param column column number
         */
        Cell(expr expression,position row,position column);

        /**
         * @brief copy Constructor
         * @param _new a cell
         */
        Cell(const Cell& _new){} //por q?


        /**
         * @brief operator =
         * @param _new cell to copy
         * @return new cell
         */
        Cell operator=(Cell& _new);

        /**
         * @brief destructor
         */
        virtual ~Cell(){}

        /**
         * @brief get_row
         * @return returns max row number
         */
        position get_row(){return m_row;}  //checkearn las 4 funciones
        position get_column(){return m_column;}

        void add_To_list_used_cells(cell_name _cell) {   m_list_used_cells.push_back(_cell); }

        vector<cell_name> get_list_cells_used() {   return m_list_used_cells;   }

        vector<cell_name> get_dependencies_list()   {   return m_dependencies_list;   }

        void delete_cellTo_list_dependencies(expr & name_cell);

        inline void update_list_cells_used();

        /**
         * @brief renews cell expression
         * @param expression new expression
         */
        void set_expression(expr new_expression);

        /**
         * @brief updates the final value of the cell
         * @sa get_result()
         */
        void set_result(value result);

        /**
         * @brief returns the cell value
         * @return m_content, final value of the cell
         * @sa get_expression() and get_name()
         */
        value get_result()  {   return m_result;    }

        /**
         * @brief returns the cell expression
         * @return m_expression
         * @sa get_content(), get_name() and m_expression
         */
        expr get_expression()   {   return m_expression;  }

        bool is_text(){return m_is_text;}

    private:
        position m_row;/**< row number */
        position m_column;/**< column number */
        vector <cell_name> m_dependencies_list;/**< dependencies list of the cell */
        vector <cell_name> m_list_used_cells;/**< list used cells in the cell expression */
        expr m_expression;/**< cell expression */
        value m_result;/**< final cell value */
        //unique_ptr<Node> m_tree_ptr;
        bool m_is_text ;

};
#endif // CELL_H
