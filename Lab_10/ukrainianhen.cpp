#include "ukrainianhen.h"

std::string UkrainianHen::getDescription()
{
    return Hen::getDescription()+" ��� ��࠭� - "+country+". � ���� "+ std::to_string(getCountOfEggsPerMonth()) +" �� � �����.";
}
