#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

typedef double value;
typedef string expr;
typedef value(*function)(value ,value );
typedef pair<expr,function> simbolo_Funcion;


/**
 * @brief declaration of operations
 */
inline value addition (value i,value j);
inline value subtraction (value i,value j);
inline value multiplication (value i,value j);
inline value division (value i,value j);
inline value pow(value i,value j);
inline value sin(value i,value );
inline value cos(value i,value );
inline value tan(value i,value );


static map<expr,function> lista_Funciones;
static map<expr,function>::iterator pMap;

/**
 * @brief inserts Functions into the map
 * @param _map map
 */
void insert_Functions(map<expr,function> &_map);
/**
 * @brief search operation symbol
 * @param symbol operation symbol
 * @param function_ptr an pointer function
 * @return true if the symbol was found,
 *         otherwise false
 */
bool find_symbol(expr symbol,function &function_ptr);

#endif // OPERATIONS_H

