#ifndef INCLUDES_H
#define INCLUDES_H
#include <iostream>
#include <string>
#include <math.h>
#include <thread>
#include <vector>

using namespace std;

typedef string expr;
typedef double value;
typedef unsigned int position;


inline expr name_column_from_number(int column)
{
    expr columnString = "";
    position columnNumber = column+1;
    while (columnNumber > 0)
    {
        position currentLetterNumber = (columnNumber-1) % 26;
        columnString = (char)(currentLetterNumber + 65)+ columnString;
        columnNumber = (columnNumber - (currentLetterNumber+1)) / 26;
    }
    return columnString;
}

inline int NumberFromExcelColumn(string column)
{

    for(auto &iter: column)
        iter=char (toupper(iter));

    string col = column;
    double result = 0;
    for (int iChar = col.length() - 1; iChar >= 0; --iChar)
    {
        int colNum = col[iChar] - 64;
        result += colNum * (pow(26, col.length()-(iChar + 1)));
    }
    return result-1;
}

inline bool is_number(expr token) //buscar
{
    if(token=="")
        return false;
    int dot_counter = 0;

    for (register unsigned i=0;i<token.length();i++)
    {
        if (token[i]=='.')
        {
            ++dot_counter;
            if(dot_counter>=2)
                return false;
        }
        else if(isdigit(token[i])==false)
            return false;
    }
    return true;
}
#endif // INCLUDES_H
