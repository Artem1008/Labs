#include "parserbase.h"

ParserBase::ParserBase(string source)
{
    this->source=source;
}
char ParserBase::operator[](int index)
{
    return (index < source.length())? source[index] : '\n';
}
void ParserBase::Next()
{
    if (!End())  pos++;
}
bool ParserBase::IsMatch(string terms)
{
    int pos = getPos();
    char result = MatchNoExcept(terms);
    this->pos = pos;
    return result != '\0';
}
char ParserBase::MatchNoExcept(string terms)
{
    int pos = getPos();
    // bool match = true;
    for (char c : terms)
    {
        if (Current() == c)
        {
            Next();
            return c;
        }
    }
    return '\0';
}
char ParserBase::Match(string terms)
{
    char result = MatchNoExcept(terms);
    if (result == '\0')
    {
        std::cout<<"ParserBase::Match result == null";
    }
    return result;
}
