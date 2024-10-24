#ifndef PARSERBASE_H
#define PARSERBASE_H
#include <string>
#include <iostream>
using namespace std;

class ParserBase
{
public:
    ParserBase(string source);
     const string DEFAULT_WHITESPACES = " \n\r\t";
     string getSource(){ return source; };
     int getPos(){return pos;};
     char operator[](int);
     char Current(){return source[pos];};
     bool End(){return Current() == '\0';};
     void Next();
     char MatchNoExcept(string terms);
     bool IsMatch(string terms);
     char Match(string terms);
     ~ParserBase();
private:
     string source;
     int pos = 0;
};

#endif // PARSERBASE_H
