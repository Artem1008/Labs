#include "belarusianhen.h"

std::string BelarusianHen::getDescription()
{
   return Hen::getDescription()+" ��� ��࠭� - "+country+". � ���� "+ std::to_string(getCountOfEggsPerMonth()) +" �� � �����.";
}
