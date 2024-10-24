#ifndef MATHEXPRINTEPRETER_H
#define MATHEXPRINTEPRETER_H
#include "parserbase.h"
#include <cctype>

class MathExprIntepreter:ParserBase
{
public:
    MathExprIntepreter(string source);
    ~MathExprIntepreter();
    double NUMBER();
    double Group();
    double Mult();
    double Add();
    double Result();
    double Execute();
    static double Execute(string source);
};

#endif // MATHEXPRINTEPRETER_H
