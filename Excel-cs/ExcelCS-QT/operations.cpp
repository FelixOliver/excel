#include "Operations.h"

bool is_operator(char symbol)
{
    expr _symbol= expr(1,symbol);
    return functions_list[_symbol].second;
}

function_ptr get_function(expr symbol)
{
    return functions_list[symbol].first;
}

value priority(expr symbol)
{
    return (functions_list[symbol]).second;
}



