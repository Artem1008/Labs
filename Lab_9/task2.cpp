#include "vector.h"

int task2()
{
    try
    {
        Mystl::vector<int> vec("test.dat", 1024 * 1024);
        printf("vec[333]=%d\n",vec[333]);
        printf("vec[9999999]=%d\n",vec[9999999]);
        vec[9999999]=345345;
        printf("vec[333]=%d\n",vec[333]);
        printf("vec[9999999]=%d\n",vec[9999999]);
        vec.resize(2000000);
        vec.push_back(332233);
        return 1;
    }
    catch (const char* error_message)
    {
        printf("%s",error_message);
         return -1;
    }
}
