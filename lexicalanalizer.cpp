#include "lexicalanalizer.h"


void LexicalAnalizer::update_lowerTOupper(){
    for(register auto &i : lower_positions)
        expression[i]=toupper(expression[i]);
}

void LexicalAnalizer::details(){
    bool entry=false;//por defecto
    bool found_lowers=false;//por defecto
    for (register unsigned i=0;i<expression.length();++i){
        if(found_lowers){        /**< Empiesa a almacenar las posiciones de la minusculas y dependiendo volverlas mayusculas */
            if(isdigit(expression[i])){
                found_lowers=false;
                update_lowerTOupper();
                lower_positions.clear();
                entry=true;
            }
            if(!entry && islower(expression[i])){
                lower_positions.push_back(i);
                entry=true;
            }
            else{
                if(!isupper(expression[i])){
                    found_lowers=false;
                    lower_positions.clear();
                }
            }
        }
        if(!entry && expression[i]==' '){  /**< Elimina los espacios */
            expression.erase(i,1);
            --i;
            entry=true;
        }
        if(!entry && expression[i]=='.'){  /**< Agrega el 0 cuando no precede ningun numero al "." */
            if((is_operator(expression[i-1]) || (expression[i-1]=='(')) && isdigit(expression[i+1])){
                expression.insert(i,"0");
                ++i;
            }
            entry=true;
        }
        if(!entry && isalpha(expression[i]) && found_lowers==false){ /**< Encuentra una letra por primera vez*/
            if(islower(expression[i]))
                lower_positions.push_back(i);
            found_lowers=true;
        }
        entry=false;
    }
    lower_positions.clear();
}

bool LexicalAnalizer::lexer(){
    wrong_expression="";
    operator_unary="";
    bool exist_number=false , entry=false , found_point=false , found_fUnary=false , found_cell=false;
    int i=0,counter_parenthesis=0;
    char actual=expression[i],next=expression[i+1];
    /*---------------------------------------------*/
    if(is_binary_operator(actual)){
        wrong_expression="ERROR: El primer caracter es operador.";
        return false;
    }
    while(next){
        if(actual=='('){
            if(is_binary_operator(next) || isdigit(expression[i-1]) || isupper(expression[i-1])){
                wrong_expression=
                "ERROR: Verifique que el anterior no sea numero o mayuscula y el posterior no sea operador binario en cada '(' .";
                return false;
            }
            else{
                if(islower(expression[i-1])){
                    if(is_unary_operator(operator_unary))
                        found_fUnary=false;
                    else{
                        wrong_expression="ERROR: No existe ("+operator_unary+
                                         ") antes del '(' Nro. "+intToString(++counter_parenthesis)+".";
                        return false;
                    }
                    operator_unary.clear();
                }
                ++counter_parenthesis;
            }
            entry=true;
        }
        if(actual==')'){
            if((is_operator(next)|| next==')') && (isdigit(expression[i-1])|| expression[i-1]==')') ){
                found_cell=false;
                --counter_parenthesis;
            }
            else{
                wrong_expression="ERROR: Verifique que el anterior sea numero y el posterior sea operador binario en cada ')' .";
                return false;
            }
            entry=true;
        }
        if(found_fUnary){
            if(islower(actual))
                operator_unary.push_back(actual);
            else{
                wrong_expression="ERROR: Los operadores unarios se escriben en minuscula en su totalidad, corregir caracter Nro. "+
                                  intToString(++i)+".";
                return false;
            }
            entry=true;
        }
        if(!entry && found_fUnary==false && islower(actual)){
            if(is_operator(expression[i-1]) || (expression[i-1]=='(') || i==0){
                found_fUnary=true;
                operator_unary.push_back(actual);
            }
            else{
                wrong_expression="ERROR: Si escribe una celda o un operador con minuscula debe antecederlo un operador, corregir caracter Nro. "
                                  +intToString(i)+".";
                return false;
            }
            entry=true;
        }
        if(!entry && actual=='.' && found_point==false && found_cell==false){
            if(! ( (isdigit(expression[i-1]) && isdigit(next)) )){
                wrong_expression="ERROR: El caracter '.' Nro."+intToString(++i)+" debe econtrarse entre numeros";
                return false;
            }
            found_point=true;
            entry=true;
        }
        if(!entry && isdigit(actual)){
            if(isupper(next)){
                wrong_expression="ERROR: El caracter Nro. "+intToString(++i)+", el posterior de ese numero es una letra.";
                return false;
            }
            if(is_operator(next)){
                found_point=false;
                found_cell=false;
            }
            exist_number=true;
            entry=true;
        }
        if(!entry && isupper(actual)){
            if (is_operator(next) || next=='0'){
                wrong_expression="ERROR: Despues de una letra no puede seguir un operador o el digito 0.";
                return false;
            }
            found_cell=true;
            entry=true;
        }
        if(!entry && is_operator(actual)){
            if(is_binary_operator(next)){
                wrong_expression="ERROR: Un operador no puede ser antecedido por otro, ver el caracter Nro. "+
                                  intToString(++i)+".";
                return false;
            }
            entry=true;
        }
        if(entry==false){
            wrong_expression="ERROR: El caracter Nro. "+intToString(++i)+" no existe o esta en una posicion incorrecta.";
            return false;
        }
        ++i;
        actual=expression[i];
        next=expression[i+1];
        entry=false;
    }
    if(actual==')')
        --counter_parenthesis;
    if(counter_parenthesis==0){
        if(isdigit(actual) || (exist_number && actual==')') )
            return true;
        else{
            wrong_expression="ERROR: El ultimo caracter no es un numero o no es ')', pueda que no exista ni un digito en la expresion.";
            return false;
        }
    }
    wrong_expression="ERROR: No termino de cerrar todos los parentesis.";
    return false;
}

bool LexicalAnalizer::get_result(){
    details();
    result=lexer();
    return result;
}
