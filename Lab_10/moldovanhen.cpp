#include "moldovanhen.h"

std::string MoldovanHen::getDescription()
{
    return Hen::getDescription()+" ��� ��࠭� - "+country+". � ���� "+ std::to_string(getCountOfEggsPerMonth()) +" �� � �����.";
}
