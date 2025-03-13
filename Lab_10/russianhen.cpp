#include "russianhen.h"

std::string RussianHen::getDescription()
{
   return Hen::getDescription()+" Моя страна - "+country+". Я несу "+ std::to_string(getCountOfEggsPerMonth()) +" яиц в месяц.";
}
