#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H
#include <stdio.h>
#include "SyntaxAnalizer.h"

class Save_Load
{
    public:
        Save_Load(){}
        ~Save_Load(){}

        inline void set_matrix(matrix* _matrix){m_matrix_ptr=_matrix;}
        void save(string file_name);
        void open(string file);
    private:
        matrix* m_matrix_ptr;

};
#endif // SAVE_LOAD_H
