#include "russianhen.h"

std::string RussianHen::getDescription()
{
   return Hen::getDescription()+" ��� ��࠭� - "+country+". � ���� "+ std::to_string(getCountOfEggsPerMonth()) +" �� � �����.";
}
