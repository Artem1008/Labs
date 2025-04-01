#ifndef POOL_H
#define POOL_H
#include <iostream>

template<class Type>
class Pool
{
private:
    Type* pObj;
    size_t size;
    bool* employed;
    unsigned int point;

public:
    Pool(size_t _size);
    template<typename... Args>
    Type& alloc(Args&&... args)
    {
       new (pObj+point) Type(args...);
       employed[point]=true;
       if (point<size) return pObj[point++];
       else
           throw std::overflow_error("Пул переполнен");

    }
    void free();
    void free(int index);
    virtual ~Pool();
};
#include <pool.inl>
#endif // POOL_H
