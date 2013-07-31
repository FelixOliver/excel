#ifndef SYNTAXANALIZER_H
#define SYNTAXANALIZER_H
#include <stack>

#include "LexicalAnalizer.h"

#include "LexicalError.h"
#include "NodeConst.h"
#include "NodeOperator.h"
#include "Includes.h"
#include "SparseMatrix.h"
#include "NodeCell.h"

typedef vector<expr> list_for_eval;

typedef SparseMatrix<Cell> matrix;

class SyntaxAnalizer
{
    public:

        SyntaxAnalizer(){}
        /**
         * @brief SyntaxAnalizer constructor
         * @param expression an expression
         * @sa set_expression()
         */
        SyntaxAnalizer(expr expression){set_expression(expression);}

        /**
         * @brief SyntaxAnalizer destructor
         */
        virtual ~SyntaxAnalizer(){}

        /**
         * @brief renews the data member m_expression
         * @param expression an expression
         */
        void set_expression(expr expression){clean_all();m_expression=expression;}

        /**
         * @brief cleans the lists m_atoms and m_dependencies
         * @sa clean_depend() and clean_atoms_list()
         */
        inline void clean_all(){clean_postfix();clean_atoms_list();}

        /**
         * @brief set matrix pointer
         * @param _matrix matrix pointer
         */
        void set_matrix(matrix* _matrix){m_matrix_ptr=_matrix;}
        /**
         * @brief cleans m_postfix
         */
        inline void clean_postfix(){m_postfix.clear();}

        /**
         * @brief cleans m_atoms
         */
        inline void clean_atoms_list(){m_atoms.clear();}

        /**
         * @brief expr_is_correct
         * @return true if the expression is correct
         */
        bool expr_is_correct();

        /**
         * @brief divides an expression in atoms and stores them in a vector
         * @param txt expression to divide
         */
        void divided_into_atoms ();

        /**
         * @brief add a prefix for nodes
         * @param atom node for eval
         */
        void add_prefix(expr &atom);

        /**
         * @brief convert the atom list to postfix
         */
        void convert_to_postfix();

        /**
         * @brief create different nodes type
         * @param token part of list for eval
         * @return node pointer
         */
        unique_ptr<Node> new_node(expr token);

        /**
         * @brief inserts a node into tree
         * @param token node to insert
         */
        void insert_node(unique_ptr<Node>& token);

        /**
         * @brief calls the functions for create tree
         * @return node pointer
         * @sa clear_spaces(), clean_all(),divided_into_atoms(),convert_to_postfix() and insert_node();
         */
        unique_ptr<Node>& parse();

        /**
         * @brief returns m_expression
         * @return m_expression
         */
        expr get_expression(){return m_expression;}

    private:
        LexicalAnalizer m_check;
        list_for_eval m_atoms;/**< tokens vector of the expression */
        list_for_eval m_postfix;/**< tokens vector of the expression in post-order*/
        expr m_expression; /**< expression */
        unique_ptr<Node> m_root;/**< tree poiter */
        Lexical_Error m_lexical_error;
        Valor_Text m_error_text;
        Syntax_Error m_syntax_error;
        matrix* m_matrix_ptr;
};
#endif // SYNTAXANALIZER_H
