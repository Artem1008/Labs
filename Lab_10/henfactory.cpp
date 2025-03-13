#include "henfactory.h"

std::unique_ptr<Hen> HenFactory::getHen(counrtynum index)
{

    switch(index) {
    case Russian:
        return  std::make_unique<RussianHen>();
        break;
    case Ukrainian:
        return std::make_unique<UkrainianHen>();
        break;
    case Moldovan:
        return std::make_unique<MoldovanHen>();
        break;
    case Belarusian:
        return std::make_unique<BelarusianHen>();
        break;
    default:
        printf("неверно выбран тип курицы");
        return nullptr;
        break;
    }
}
