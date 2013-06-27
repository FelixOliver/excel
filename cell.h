 #ifndef CELL_H
#define CELL_H
#include <vector>
#include "Node.h"
#include "SyntaxAnalizer.h"

typedef string expr;

using namespace std;

template <typename T>
class Cell
{
    typedef T type_content;
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
        virtual ~Cell();

        //inline void create tree(){}

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
        expr get_name();
    private:
        value m_row;/**< row number */
        value m_column;/**< column number */
        vector <Cell<type_content>*> m_depend;/**< dependencies list of the cell */
        expr m_expression;/**< cell expression */
        type_content m_content;/**< final cell value */
        Node* m_tree_ptr;/**< operations tree pointer */
};

#endif // CELL_H
