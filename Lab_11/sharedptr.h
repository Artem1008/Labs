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
    void SubCount()
    {
        if (count != nullptr) {
            if (*count == 1)
            {
                delete count;
                count = nullptr;
            }
            else
            {
                --(*count);
            }
        }
    }
    void AddCount()
    {
        if (count==nullptr)
        {
            count=new size_t(1);
        }
        else
        {
            ++(*count);
        }
    }
public:
    SharedPTR();//+
    SharedPTR(Type *pObj);//+
    SharedPTR(t_SharedPTR &&uniquePTR) noexcept; //+
    SharedPTR(const t_SharedPTR&);
    ~SharedPTR();
public: // Assignment.
    t_SharedPTR& operator=(t_SharedPTR &&sharedPTR) noexcept;
    t_SharedPTR& operator=(Type *pObject);
    t_SharedPTR& operator=(const t_SharedPTR& sharedPTR);
public: // Observers.
    Type& operator*() const; //+
    Type* operator->() const;//+
    Type* get() const;
    TDeleter& get_deleter();
    operator bool() const;
    size_t getcount();
public: // Modifiers.
    void release(); // Release ownership of any stored pointer.
    void reset(Type *pObject = nullptr); // Replace the stored pointer.
    void swap(t_SharedPTR &sharedPTR); // Exchange the pointer with another object.
};
#include "sharedptr.inl"
#endif // SHAREDPTR_H


