#include "LexicalAnalizer.h"

void LexicalAnalizer::details()
{
    for(register unsigned i=0;i<expression.length();++i)
    {
        if(expression[i]==' ')   /**< borra espacios */
        {
            expression.erase(i,1);
            --i;
        }
        else if(islower(expression[i]))   /**< convierte la minuscula en mayuscula */
            expression[i]=toupper(expression[i]);
    }
}

bool LexicalAnalizer::lexer()
{
    bool indicator_point=false; /**< Indica que solo debe de existir un solo punto en un atomo */
    int counter_parenthesis=0;
    register unsigned i=0;
    /*---------------------------------------------*/
    if(is_binary_operator(expression[0]))  /**< No debe empesar con Operaor Binario : *,/,^ y ) */
        return false;
    if(expression[0]=='.') /**< Si empiesa con '.' que agregue un 0 adelante */
    {
        expression.insert(0,"0");
        ++i;
    }
    for( ;i<expression.length()-1;++i)
    {
        if(isupper(expression[i]))/**< ----- Si es Letra (mayuscula) ----- */
        {
            buffer.push_back(expression[i]);
            if(isdigit(expression[i+1]) && expression[i+1]!='0') /**< A1 o B2 no existe celda A0 */
            {
                indicator_point=true;
                if(!buffer.empty())  /**< Se sabe que es una celda entonces borra el buffer si es que esta vacio */
                    buffer.clear();
            }
            else if(expression[i+1]=='(')  /**< Si encuentra '(' indica q se debe buscar la funcion unaria, ejem: SQRT( */
            {
                if(is_unary_operator(buffer))
                    buffer.clear();
                else return false;
            }
            else if(!isupper(expression[i+1])) /**< Si el siguiente de una letra no es una letra,'(' o numero(!=0) es False*/
                return false;
        }
        else if(isdigit(expression[i])) /**< ----- Si es Numero ------ */
        {
            if(isupper(expression[i+1]) || expression[i+1]=='(')
                return false;
            if(indicator_point && (is_operator(expression[i+1]) || expression[i+1]==')') ) /**< Si habia un punto */
                indicator_point=false; /**< Lo vuelve false debido que le sigue un operador o ')' */
        }
        else if(expression[i]==')') /**< ----- Si es ) ------ */
        {
            if(!(expression[i+1]==')' || is_operator(expression[i+1])) ) /**< Si NO le sigue un operador o el mismo ')' */
                return false;
            --counter_parenthesis;
        }
        else if(expression[i]=='.' && isdigit(expression[i+1]) && !indicator_point) /**< -Si es Punto y el indicador false - */
        {
            if(is_operator(expression[i-1]) || expression[i-1]=='(') /**< Si el anterior a el es operador o '(' se agrega 0 */
            {
                expression.insert(i,"0");
                ++i;
            }
            indicator_point=true; /**< Lo vuelve True para no validar otro punto en un mismo atomo */
        }
        else if(is_operator(expression[i]) || expression[i]=='(') /**< ---- Si es Operador o '(' ---- */
        {
            if(is_binary_operator(expression[i+1]))  /**< Si le sigue un operador binario */
                return false;
            if(expression[i]=='(')
                ++counter_parenthesis;
        }
        else return false; /**< ----- No se encontro ese caracter ------ */
    }
    if(expression.back()==')') /**< ----- Si el ultimo es ')'  ------ */
    {
        --counter_parenthesis;
        return (!counter_parenthesis); /**< True: contador de parentesis = 0 */
    }
    return (!counter_parenthesis && isdigit(expression.back())); /**< Debe terminar con numero y contador de parentesis = 0 */
}

bool LexicalAnalizer::get_result()
{
    details();
    result=lexer();
    return result;
}

