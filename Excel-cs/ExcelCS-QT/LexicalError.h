#ifndef LEXICALERROR_H
#define LEXICALERROR_H

struct Lexical_Error : std::exception
{
  const char* what() const noexcept {return "Lexical Error!!!\n";}
};

struct Syntax_Error : std::exception
{
  const char* what() const noexcept {return "Syntax Error!!!\n";}
};

struct Valor_Text: std::exception
{
  const char* what() const noexcept {return "is text!!!\n";}
  void set_text(string value){m_value=value;}
  string get_text(){return m_value;}
  string m_value;
};
#endif // LEXICALERROR_H
