#include <iostream>
#include <list>
#include <array>
#include <set>
int task6() {


    std::set<int> myarray2{ 10, 8, 6, 5 };
   myarray2.erase(8);
    for(auto var:myarray2)
    {
           std::cout << var<< " ";
    }


    return 0;
}
