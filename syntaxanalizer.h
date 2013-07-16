#ifndef SYNTAXANALIZER_H
#define SYNTAXANALIZER_H

#include <stack>
#include "NodeConst.h"
#include "NodeOperator.h"
#include "nodecell.h"
#include "lexicalanalizer.h"
#include <thread>


typedef vector<Node*> list_depend;
typedef vector<expr> list_for_eval;
typedef stack<expr> stack_for_eval;

class SyntaxAnalizer
{
    public:
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
        inline void set_expression(expr expression){clean_all();m_expression=expression;}

        /**
         * @brief cleans the lists m_atoms and m_dependencies
         * @sa clean_depend() and clean_atoms_list()
         */
        inline void clean_all(){clean_postfix();clean_atoms_list();}

        /**
         * @brief cleans m_postfix
         */
        inline void clean_postfix(){m_postfix.clear();}
        /**
         * @brief cleans m_atoms
         */
        inline void clean_atoms_list(){m_atoms.clear();}

        /**
         * @brief deletes white spaces of an expression
         */

        bool expr_is_correct();

        void clear_spaces();

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
        Node* new_node(expr token);

        /**
         * @brief inserts a node into tree
         * @param token node to insert
         */
        void insert_node(Node* token);

        /**
         * @brief calls the functions for create tree
         * @return node pointer
         * @sa clear_spaces(), clean_all(),divided_into_atoms(),convert_to_postfix() and insert_node();
         */
        Node* parse();

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
        Node* m_root;/**< tree poiter */
};

#endif // SYNTAXANALIZER_H
