#include "mathexprintepreter.h"

MathExprIntepreter:: MathExprIntepreter(string source):  ParserBase(source)
{
}
double MathExprIntepreter::Execute(string source)
{
    MathExprIntepreter* mei = new MathExprIntepreter(source);
    return mei->Execute();
}
double MathExprIntepreter::Execute()
{
    double result = Result();
    if (End())
        return result;
}
double MathExprIntepreter::Result()
{
    return Add();
}
double MathExprIntepreter::Add()
{
    double result = Mult();
    while (IsMatch("+-"))
    {
        char oper = Match("+-");
        double temp = Mult();
        result = (oper == '+')? result + temp: result - temp;
    }
    return result;
}
double MathExprIntepreter::Mult()
{
    double result = Group();
    while (IsMatch("*/"))
    {
         char oper = Match("*/");
         double temp = Group();
         result = (oper == '*') ? result * temp: result / temp;
    }
    return result;
}
double MathExprIntepreter::Group()
{
    if (IsMatch("("))
    {
        Match("(");
        double result = Add();
        Match(")");
        return result;
    }
    else
    {
        return NUMBER();
    }
}
double MathExprIntepreter::NUMBER()
{
    string number = "";
    while (Current() == '.' || isdigit(Current()))
    {
        number += Current();
        Next();
    }
    if (number.length()==0) cout<<"Ожидалось число pos="<<getPos()<<"\n";
    return stod(number);
}
