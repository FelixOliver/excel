#include "Save_Load.h"

void Save_Load::save(string file_name)
{
    FILE* spreadsheet;
    if(file_name.substr(file_name.length()-4)!=".csv")
        spreadsheet=fopen((file_name+".csv").c_str(),"w");
    else
        spreadsheet=fopen((file_name).c_str(),"w");

    for (register unsigned i=0;i<m_matrix_ptr->get_row();++i)
    {
        for (register unsigned j=0;j<m_matrix_ptr->get_column();++j)
        {
            if(m_matrix_ptr->exist(i,j))
                fwrite(m_matrix_ptr->get_element(i,j).get_expression().c_str(),sizeof(char),m_matrix_ptr->get_element(i,j).get_expression().length(),spreadsheet);
            else
                fwrite(",",sizeof(char),1,spreadsheet);
        }
        fwrite("\n",sizeof(char),1,spreadsheet);
    }
    fclose(spreadsheet);
}

void Save_Load::open(string file_name)
{
    FILE* spreadsheet;
        spreadsheet=fopen(file_name.c_str(),"r");

        int row=0;
        while(fgetc(spreadsheet)!=EOF)
        {
            int column=0;
            while(fgetc(spreadsheet)!='\n')
            {
                string expression;

                while(fgetc(spreadsheet)!=',')
                {
                    expression.push_back(fgetc(spreadsheet));
                }
                if(expression[0])
                {
                    Cell _new(expression,row,column);
                    m_matrix_ptr->insert(row,column,_new);
                }

                ++column;
            }
            std::cout<<row<<endl;
            ++row;
        }
        fclose(spreadsheet);
}
