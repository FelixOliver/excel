#include "SyntaxAnalizer.h"
#include "Operations.h"
#include <sstream>


bool SyntaxAnalizer::is_const(expr str)
{
    int dot_counter = 0;
    for (register unsigned i=0;i<str.length();i++)
    {
        if (str[i]=='.')
        {
            ++dot_counter;
            if(dot_counter>=2)
                return false;
        }
        else if(isdigit(str[i])==false)
            return false;
    }
    return true;
}


bool SyntaxAnalizer::is_cell(expr str)
{
    if(isalpha(str[0])==false)
        return false;

    int num=0;

    for (register unsigned i=1;i<str.length();i++)
    {
        if(isdigit(str[i]))
            ++num;
        else if ((isalpha(str[i]))&&(num!=0))
            return false;
        else if (isalpha(str[i])==false)
            return false;
    }
    if (num>0)
        return true;
    else return false;
}


bool SyntaxAnalizer::expr_is_correct()
{
    bool is_correct=true;
    for(register unsigned i=0;i<m_atoms.size();i++ )
    {
        if (m_atoms[i][0]=='.')
            is_correct=is_correct and is_const(m_atoms[i]);
        else if (isdigit(m_atoms[i][0]))
            is_correct=is_correct and is_const(m_atoms[i]);

        else if (isalpha(m_atoms[i][0]))
            is_correct=is_correct and is_cell(m_atoms[i]);
    }
    return is_correct;
}

void SyntaxAnalizer::clear_spaces()
{
    for (register unsigned i=0;i< m_expression.length();i++ )
        if(m_expression[i] == ' ')
        {
            m_expression.erase(i,1);
            i--;
        }
}

void SyntaxAnalizer::divided_into_atoms (expr txt)
{
    //int count_parenthesis=0;
    expr atom="";
    for (register unsigned i=1;i<txt.length();i++)
    {
        function funct_ptr;
        stringstream ss;
        string s;
        string actual;
        ss << txt[i];
        ss>>actual;

        if ((find_symbol(actual,funct_ptr)==false))
        {
            if(i==txt.length()-1)
            {
                atom=atom+actual;
                m_atoms.push_back(atom);
            }
            else if((actual=="(") || (actual==")"))
                if (atom=="")
                    m_atoms.push_back(actual);
                else
                {
                    m_atoms.push_back(atom);
                    m_atoms.push_back(actual);
                    atom="";
                }
            else
            atom=atom+actual;
        }
        else
        {
            if (atom!="")
                m_atoms.push_back(atom);
            m_atoms.push_back(actual);
            atom="";
        }
    }
}

Node* SyntaxAnalizer::parse()
{

    clear_spaces();
    clean_depend();
    divided_into_atoms(m_expression);

    //etapa4: arbolito

    //for()


     return new NodeOperator(new NodeConst(9),&addition,new NodeConst(3));
}
