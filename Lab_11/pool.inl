#include "pool.h"

template<class Type>
Pool<Type>::Pool(size_t _size):point(0),size(_size)
{
    pObj=static_cast<Type*>(operator new[] (size * sizeof(Type)));
    printf("pObj 0x%x\n",pObj);
    employed=new bool[size]();
}
template<class Type>
void Pool<Type>::free()
{

}
template<class Type>
Pool<Type>::~Pool()
{
    for(int i=0;i<size;++i)
    {
        if(employed[i])
        pObj[i].~Type();
    }
    delete[] employed;
}
