#include "SyntaxAnalizer.h"


bool SyntaxAnalizer::expr_is_correct()
{
    m_check.set_expression(m_expression);
    if(m_check.get_result())
    {
        m_expression=m_check.get_expression();
        cout<<m_expression<<endl; /**< Solo para ver como quedo */
        return true;
    }
    else
    {
        cout<<m_check.get_wrong_expression()<<endl; /**< Solo para ver como quedo */
        return false;
    }
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

void SyntaxAnalizer::add_prefix(expr &atom)
{
    if(isdigit(atom[0]))
        atom="#"+atom;
    else if(isupper(atom[0]))
        atom="$"+atom;
}

void SyntaxAnalizer::divided_into_atoms ()
{
    expr atom="";
    for (register auto &iter:m_expression)
    {
        if(!is_operator(iter))
            atom.push_back(iter);
        else
        {
            if(atom=="")
                m_atoms.push_back(expr(1,iter));
            else
            {
                add_prefix(atom);
                m_atoms.push_back(atom);
                m_atoms.push_back(expr(1,iter));
                atom="";
            }
        }
    }
    if(atom!="")
    {
        add_prefix(atom);
        m_atoms.push_back(atom);
    }
}

void SyntaxAnalizer::convert_to_postfix()
{
    stack_for_eval pila_temp;
    expr temp;
    for(register auto &iter:m_atoms)
    {
        if ((iter[0]=='#')||(iter[0]=='$'))
            m_postfix.push_back(iter);
        else if(iter=="(")
            pila_temp.push(iter);
        else if(iter==")")
        {
            temp=pila_temp.top();
            while(pila_temp.size()>0 && (temp!="("))
            {
                m_postfix.push_back(temp);
                pila_temp.pop();
                temp=pila_temp.top();
            }
            if(temp=="(")
                pila_temp.pop();
        }
        else
        {
            while(pila_temp.size()>0 && priority(pila_temp.top())<=priority(iter))
            {
                temp=pila_temp.top();
                m_postfix.push_back(temp);
                pila_temp.pop();
            }
            pila_temp.push(iter);
        }
    }
    while(pila_temp.size())
    {
        m_postfix.push_back(pila_temp.top());
        pila_temp.pop();
    }
}

Node* SyntaxAnalizer::new_node(expr token)
{
    if(token[0]=='#')
        return new NodeConst (token.erase(0,1));
    if(token[0]=='$')
        return new NodeCell (token.erase(0,1));
    else
        return new NodeOperator (token);
}


void SyntaxAnalizer::insert_node(Node* root)
{
    if(m_postfix.empty())
        return;

    if(isdigit(root->m_expression[0])||isupper(root->m_expression[0]))
            return;

    /*thread thread1([&root,this]{*/root->m_right_node=new_node(m_postfix.back());
                                m_postfix.pop_back();
                                insert_node(root->m_right_node);//});

    /*thread thread2([&root,this]{*/root->m_left_node=new_node(m_postfix.back());
                                m_postfix.pop_back();
                                insert_node(root->m_left_node);//});

    //thread1.join();
    //thread2.join();
}

Node* SyntaxAnalizer::parse()
{
    if(expr_is_correct())
    {
        thread thread1([this]{clear_spaces();
                           clean_all();});
        thread thread2([this]{divided_into_atoms();
                             for(auto&i:m_atoms)
                                cout<<i<<",";
                             cout<<endl;
                             convert_to_postfix();
                             for(auto&i:m_postfix)
                                cout<<i<<",";});
        thread1.join();
        thread2.join();

        m_root=new_node(m_postfix.back());
        m_postfix.pop_back();
        insert_node(m_root);

        return m_root;
    }
}
