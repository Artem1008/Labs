#include "main.h"

void getAnimalName(Animal &data)
{
    switch (data)
    {
    case 0:
        std::cout<<"pig\n";
        break;
    case 1:
        std::cout<<"chicken\n";
        break;
    case 2:
        std::cout<<"goat\n";
        break;
    case 3:
        std::cout<<"cat\n";
        break;
    case 4:
        std::cout<<"dog\n";
        break;
    default:
        std::cout<<"Нет такого животного\n";
    }
}
void printNumberOfLegs(Animal &data)
{
    switch (data)
    {
    case pig:
        std::cout<<"4 копыта\n";
        break;
    case chicken:
        std::cout<<"2 лапы\n";
        break;
    case goat:
        std::cout<<"4  копыта\n";
        break;
    case cat:
        std::cout<<"4 лапы\n";
        break;
    case dog:
        std::cout<<"4 лапы\n";
        break;
    default:
        std::cout<<"Нет такого животного\n";
    }
}
