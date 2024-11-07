#include <iostream>

void task6()
{
    int x{6666};
    float y{1333.2324};
    double z{21474347.123};
    unsigned short k{12};
    int i=static_cast<int>((x+y)*z+k) ;
    std::cout<<"static_cast<int>((x+y)*z+k : "<<i<<'\n';
    std::cout<<"k = x-y/z : "<<(k=x-y/z)<<'\n';
    std::cout<<"z = x*y+z/x : "<<(z=(double)x*y+z/x)<<'\n';
    unsigned int ui=(unsigned int)x/y+k;
    std::cout<<"ui = x/y+k : "<<ui<<'\n';
    short s=x%(int)(x/y);
    std::cout<<"s = x%(x/y) :"<<s;
}
