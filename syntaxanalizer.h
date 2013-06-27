#ifndef SYNTAXANALIZER_H
#define SYNTAXANALIZER_H
#include "NodeConst.h"
#include "NodeOperator.h"
//#include "Cell.h"


typedef vector<Node*> list_depend;
typedef vector<expr> list_for_eval;

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
        inline void set_expression(expr expression){clean_depend();m_expression=expression;}

        /**
         * @brief cleans the lists m_atoms and m_dependencies
         * @sa clean_depend() and clean_atoms_list()
         */
        inline void clean_all(){clean_depend();clean_atoms_list();}

        /**
         * @brief cleans m_dependencies
         */
        inline void clean_depend(){m_dependencies.empty();}
        /**
         * @brief cleans m_atoms
         */
        inline void clean_atoms_list(){m_atoms.empty();}

        /**
         * @brief deletes white spaces of an expression
         */
        void clear_spaces();

        /**
         * @brief divides an expression in atoms and stores them in a vector
         * @param txt expression to divide
         */
        void divided_into_atoms (expr txt);

        /**
         * @brief checks if the token is cell or not
         * @param str an token of the expression
         * @return true ,if the token is cell, otherwise
         *         false
         */
        bool is_cell(expr str);

        /**
         * @brief checks if the token is constant or not
         * @param str an token of the expression
         * @return true ,if the token is const, otherwise
         *         false
         */
        bool is_const(expr str);

        /**
         * @brief checks if the tokens is correct
         * @return true if the tokens is correct, otherwise
         *         false
         * @sa is_cell() and is_const()
         */
        bool expr_is_correct();

        /**
         * @brief checks if the expression is correct
         * @return node pointer
         * @sa clear_spaces(), clean_all(), expr_is_correct() and divided_into_atoms()
         */
        Node* parse();

        /**
         * @brief returns the list m_dependencies
         * @return m_dependencies
         */
        list_depend get_dependencies(){return m_dependencies;}

        /**
         * @brief returns m_expression
         * @return m_expression
         */
        expr get_expression(){return m_expression;}


    private:
        expr m_expression; /**< expression */
        list_for_eval m_atoms;/**< tokens vector of the expression */
        list_depend m_dependencies; /**< cell dependencies */
};

#endif // SYNTAXANALIZER_H
