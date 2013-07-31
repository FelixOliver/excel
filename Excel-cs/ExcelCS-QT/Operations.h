#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <map>
#include "Includes.h"


typedef value(*function_ptr)(value ,value );
typedef map < expr, pair <function_ptr,value> > map_operator;
//typedef int position;


/**
 * @brief declaration of basic operations
 */
inline value addition (value i,value j){return i+j;}
inline value subtraction (value i,value j){return i-j;}
inline value multiplication (value i,value j){return i*j;}
inline value division (value i,value j){return (j==0)?0:i/j;}
inline value power(value i,value j){return pow(i,j);}
inline value square_root(value i,value) {return sqrt(i);}
inline value sine(value i,value ){return sin(i);}
inline value cosine(value i,value ){return cos(i);}
inline value tangent(value i,value ){return tan(i);}


static map_operator functions_list={{"+",{&addition,3}},{"-",{&subtraction,3}},{"*",{&multiplication,2}},{"/",{&division,2}},
                                    {"^",{&power,1}},{"sqrt",{&square_root,-1}},{"sin",{&sine,-2}},{"cos",{&cosine,-2}},
                                    {"tan",{&tangent,-3}},{"(",{0,5}},{")",{0,5}}};

/**
 * @brief search operation symbol
 * @param symbol operation symbol
 * @return true if the symbol was found,
 *         otherwise false
 */
bool is_operator(char symbol);


inline bool is_unary_operator(string& unary)
{
    return (functions_list[unary].second);
}

inline bool is_binary_operator(char c){
    string strn = string(1,c);
    return (functions_list[strn].second > 0 && functions_list[strn].second<5);
}

/**
 * @brief searchs the priority of an operator
 * @param symbol operation symbol
 * @return operator priority
 */
value priority(expr symbol);

/**
 * @brief returns function of the operator
 * @param symbol operator of function to search
 * @return function poiter
 */
function_ptr get_function(expr symbol);


#endif // OPERATIONS_H

