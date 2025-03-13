#include "moldovanhen.h"

std::string MoldovanHen::getDescription()
{
    return Hen::getDescription()+" Моя страна - "+country+". Я несу "+ std::to_string(getCountOfEggsPerMonth()) +" яиц в месяц.";
}
