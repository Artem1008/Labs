#include "main.h"
#include <string>

struct Address {
std::string Country;
std::string City;
std::string Street;
std::string House;
};
void Parse(const std::string& line, Address* const address)
{

}
void Unify(Address* const address)
{

}
std::string Format(const Address& address)
{

}

void task8()
{
    std::string line;
    Address* address;
    while (getline(std::cin, line)) {
    Parse(line, address);
    Unify(address);
    std::cout << Format(*address) << "\n";
    }
}
