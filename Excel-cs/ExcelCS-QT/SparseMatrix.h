#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Includes.h"
#include "LexicalError.h"
template <typename T>
class SparseMatrix
{
    typedef map<position, map<position , T > > map_of_maps;

    public:
        SparseMatrix(){}
        SparseMatrix(position size):m_row(size),m_column(size){}

        SparseMatrix(position row, position column):m_row(row), m_column(column){}

        void set_row(position t_row){this->m_row=t_row;}

        void set_column(position t_row){this->m_column=t_row;}

        position get_row(){return m_row;}

        position get_column(){return m_column;}

        void insert(position row,position column,T& content);

        inline bool exist(position row,position column);

        inline T& get_element(position row, position column);

        inline void erase(position row, position column);



private:
    map_of_maps m_esparsa;
    position m_row=0;
    position m_column=0;
    Syntax_Error m_syntax_error;
};

template<typename T>
void SparseMatrix<T>::insert(position row,position column,T& content)
{
    if(row>=m_row || column>=m_column)
        throw;
    m_esparsa[row][column]= content;
}

template<typename T>
bool SparseMatrix<T>::exist(position row,position column)
{
    if(row>=m_row || column>=m_column)
        throw m_syntax_error;
    return m_esparsa[row][column].get_expression()[0];
}

template<typename T>
T& SparseMatrix<T>::get_element(position row,position column)
{
    if(row>=m_row || column>=m_column)
        throw m_syntax_error;
    return m_esparsa[row][column];
}

template<typename T>
void SparseMatrix<T>::erase(position row,position column)
{
    m_esparsa[row].erase(column);
}

#endif // SPARSEMATRIX_H
