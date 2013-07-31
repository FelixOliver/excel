#include "SyntaxAnalizer.h"
//#include "NodeCell.h"

bool SyntaxAnalizer::expr_is_correct()
{
    m_check.set_expression(m_expression);
    if(m_check.get_result())
    {
        m_expression=m_check.get_expression();
        return true;
    }
    else
        return false;
}

void SyntaxAnalizer::add_prefix(expr &atom)
{
    if(isdigit(atom[0]))
        atom="#"+atom;
    else if (is_unary_operator(atom))
        return;
    else if(isupper(atom[0]))
    {
        /*expr letters_temp;
        position row;
        for (unsigned it=0;it<atom.length();++it){
            if(isalpha(atom[it]))
                    letters_temp.push_back(atom[it]);
            else{
                row=atoi(atom.substr(it).c_str());break;
            }
        }
        add_to_container(atom,"",row,NumberFromExcelColumn(letters_temp));*/
        atom="$"+atom;
    }
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
    stack<expr> pila_temp;
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

unique_ptr<Node> SyntaxAnalizer::new_node(expr token)
{
    if(token[0]=='#')
        return unique_ptr<NodeConst>(new NodeConst(token.erase(0,1)));
    else if(token[0]=='$')
    {
        expr letters_temp="";
        position row=0;
        for (register int it=0;it<token.substr(1).length();++it){
            if(isalpha(token.substr(1)[it]))
                letters_temp.push_back(token.substr(1)[it]);
            else{
                row=atoi(token.substr(it+1).c_str());break;
            }
        }

        int column=NumberFromExcelColumn(letters_temp);

        if(m_matrix_ptr->exist(row-1,column))
        {
            if((m_matrix_ptr->get_element(row-1,column).is_text())&&(m_atoms.front()==m_atoms.back())){
                m_error_text.set_text(m_matrix_ptr->get_element(row-1,column).get_expression());
                throw m_error_text;}
            else if((m_matrix_ptr->get_element(row-1,column).is_text())&&(m_atoms.front()!=m_atoms.back()))
                throw m_syntax_error;
            else
                return unique_ptr<NodeCell>(new NodeCell(&(m_matrix_ptr->get_element(row-1,column)),token.erase(0,1)));
        }
        else
            return unique_ptr<NodeCell>(new NodeCell(nullptr,token.erase(0,1)));
    }
    else
        return unique_ptr<NodeOperator>(new NodeOperator(token));
}


void SyntaxAnalizer::insert_node(unique_ptr<Node>& root)
{
    if(m_postfix.empty())
        return;

    if(isdigit(root->m_expression[0])||isupper(root->m_expression[0]))
        return;

    root->m_right_node=new_node(m_postfix.back());
    m_postfix.pop_back();
    insert_node(root->m_right_node);

    root->m_left_node=new_node(m_postfix.back());
    m_postfix.pop_back();
    insert_node(root->m_left_node);
}

unique_ptr<Node>& SyntaxAnalizer::parse()
{
    if(expr_is_correct())
    {
        clean_all();
        divided_into_atoms();
        for(auto&i:m_atoms)
            cout<<i<<",";
        cout<<endl;
        convert_to_postfix();
        for(auto&i:m_postfix)
            cout<<i<<",";

        m_root=new_node(m_postfix.back());
        m_postfix.pop_back();
        insert_node(m_root);

        cout<<endl<<"resulta: "<<m_root->get_value()<<endl;
        return m_root;
    }
    else
        throw m_lexical_error;
}

