#ifndef MATRIX_H
#define MATRIX_H
#include "Cell.h"


template <typename T>
class Matrix
{
    typedef T type_content;
    public:
        /**
         * @brief Matrix constructor
         * @param n_rows total rows number
         * @param n_columns total columns number
         */
        Matrix(value n_rows, value n_columns)
              :m_matrix(n_rows,vector < Cell <type_content> > (n_columns)){}

        /**
         * @brief returns total rows number
         * @return total rows number
         * @sa get_n_columns()
         */
        value get_n_rows();

        /**
         * @brief returns total columns number
         * @return total columns number
         * @sa get_n_rows()
         */
        value get_n_columns();

        /**
         * @brief creates a new cell in a specific position
         * @param row number row
         * @param column number column
         * @param expression expression of the new cell
         */
        void insert(value row,value column,type_content expression);

        /**
         * @brief erases a specific cell
         * @param row number row
         * @param column number column
         */
        inline void erase(value row,value column){m_matrix[row][column]=NULL;}

        /**
         * @brief resizes the matrix
         * @param new_n_rows new rows number
         * @param new_n_colums new columns number
         */
        void matrix_resize(value new_n_rows, value new_n_colums);

    private:
        vector < vector < Cell <type_content> > > m_matrix;/**< container */

};
#endif // MATRIX_H

template <typename T>
void Matrix<T>::insert(value row,value column,T expression)
{
    if (m_matrix[row][column]==NULL)
    {
        Cell<T> new_cell(expression,row,column);

    }
    else
        m_matrix[row][column].set_expression(expression);
}
