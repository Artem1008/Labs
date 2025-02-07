#include "myfuct.h"

int rand32()
{
    static unsigned long long rand = time(NULL);
    rand *= 134775813;
    rand += 1;
    return (int) (rand >> 32);
}


