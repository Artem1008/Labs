#ifndef SHAREDPTR_H
#define SHAREDPTR_H
#include <iostream>
#include <memory>

template<class Type,class TDeleter=std::default_delete<Type>>
class SharedPTR {
    Type* m_ptr;
    TDeleter deleter;
    size_t* count;
    typedef SharedPTR<Type, TDeleter> t_SharedPTR;
    void SubCount();
    void AddCount();
public:
    SharedPTR();
    SharedPTR(Type *pObj);
    SharedPTR(t_SharedPTR &&uniquePTR) noexcept;
    SharedPTR(const t_SharedPTR&);
    ~SharedPTR();
    t_SharedPTR& operator=(t_SharedPTR &&sharedPTR) noexcept;
    t_SharedPTR& operator=(Type *pObject);
    t_SharedPTR& operator=(const t_SharedPTR& sharedPTR);
    Type& operator*() const; //+
    Type* operator->() const;//+
    Type* get() const;
    TDeleter& get_deleter();
    operator bool() const;
    size_t getcount();
    void release();
    void reset(Type *pObject = nullptr);
    void swap(t_SharedPTR &sharedPTR);
};
#include "sharedptr.inl"
#endif // SHAREDPTR_H


