#include "sharedptr.h"

// Конструктор по умолчанию
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR():m_ptr(nullptr), count(nullptr){}
// Конструктор с передачей указателя
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(Type *pObj):m_ptr(pObj), count(nullptr)
{
    AddCount();
}
// Конструктор перемещения
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(SharedPTR<Type, TDeleter> &&uniquePTR) noexcept:m_ptr(uniquePTR.m_ptr),count(uniquePTR.count),deleter(std::move(uniquePTR.deleter))
{
    uniquePTR.m_ptr = nullptr;
    uniquePTR.count = nullptr;
}
// Конструктор копирования
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(const SharedPTR<Type, TDeleter>& other): m_ptr(other.m_ptr), count(other.count), deleter(other.deleter)
{
    AddCount();
}
// Деструктор
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::~SharedPTR()
{
    SubCount();
    if (m_ptr && count == nullptr) {
        deleter(m_ptr);
    }
}
// Оператор присваивания перемещения
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(SharedPTR<Type, TDeleter> &&sharedPTR) noexcept
{
    if (&sharedPTR == this) return *this;
    m_ptr = sharedPTR.m_ptr;
    count=sharedPTR.count;
    deleter=std::move(sharedPTR.deleter);
    sharedPTR.m_ptr = nullptr;
    sharedPTR.count = nullptr;
    return *this;
}
// Оператор присваивания указателя
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(Type *pObject)
{
    if (m_ptr == pObject) return *this;
    m_ptr = pObject;
    AddCount();
    return *this;
}
// Оператор присваивания
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(const SharedPTR<Type, TDeleter>& sharedPTR)
{
    if (&sharedPTR == this) return *this;
    m_ptr = sharedPTR.m_ptr;
    count = sharedPTR.count;
    deleter=sharedPTR.deleter;
    AddCount();
    return *this;
}
// Оператор разыменования
template<class Type,class TDeleter>
Type& SharedPTR<Type, TDeleter>::operator*() const
{
    return *m_ptr;
}
// Оператор доступа к членам
template<class Type,class TDeleter>
Type* SharedPTR<Type, TDeleter>::operator->() const
{
    return m_ptr;
}
// Получение указателя
template<class Type,class TDeleter>
Type* SharedPTR<Type, TDeleter>::get() const
{
    return m_ptr;
}
// Получение удалителя
template<class Type,class TDeleter>
TDeleter& SharedPTR<Type, TDeleter>::get_deleter() {
    return deleter;
}
// Преобразование в bool
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::operator bool() const
{
    return (m_ptr!=nullptr);
}
// Освобождение владения
template<class Type,class TDeleter>
void SharedPTR<Type, TDeleter>::release()
{
    SubCount();
    m_ptr = nullptr;
}
// Сброс указателя
template<class Type,class TDeleter>
void SharedPTR<Type, TDeleter>::reset(Type *pObject)
{
    if (m_ptr != pObject) {
        m_ptr = pObject;
        SubCount();
        count=nullptr;
    }
}
// Обмен с другим умным указателем
template<class Type,class TDeleter>
void SharedPTR<Type, TDeleter>::swap(t_SharedPTR &sharedPTR)
{
    std::swap(m_ptr, sharedPTR.m_ptr);
    std::swap(count, sharedPTR.count);
    std::swap(deleter, sharedPTR.deleter);
}
template<class Type,class TDeleter>
size_t SharedPTR<Type, TDeleter>::getcount()
{
    return (*count);
}
template<class Type,class TDeleter>
void SharedPTR<Type, TDeleter>::SubCount()
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
template<class Type,class TDeleter>
void SharedPTR<Type, TDeleter>::AddCount()
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
