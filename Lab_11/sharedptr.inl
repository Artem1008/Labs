#include "sharedptr.h"

// Конструктор по умолчанию
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR():m_ptr(nullptr), count(nullptr)
{
    printf("Конструктор по умолчанию\n");
}

// Конструктор с передачей указателя
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(Type *pObj):m_ptr(pObj), count(nullptr)
{
     printf("Конструктор с передачей указателя\n");
    AddCount();
}

// Конструктор перемещения
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(SharedPTR<Type, TDeleter> &&uniquePTR) noexcept:m_ptr(uniquePTR.m_ptr),count(uniquePTR.count),deleter(std::move(uniquePTR.deleter))
{
    printf("Конструктор перемещения\n");
    uniquePTR.m_ptr = nullptr;
    uniquePTR.count = nullptr;
}

// Конструктор копирования
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(const SharedPTR<Type, TDeleter>& other): m_ptr(other.m_ptr), count(other.count), deleter(other.deleter)
{
    printf("Конструктор копирования\n");
    AddCount();
}
// Деструктор
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::~SharedPTR()
{
    printf("Деструктор\n");
    SubCount();
    if (m_ptr && count == nullptr) {
        deleter(m_ptr);
    }
}
// Оператор присваивания перемещения
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(SharedPTR<Type, TDeleter> &&sharedPTR) noexcept
{
    printf("Оператор присваивания перемещения\n");
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
    printf("Оператор присваивания указателя\n");
    if (m_ptr == pObject) return *this;
    m_ptr = pObject;
    AddCount();
    return *this;
}
// Оператор присваивания
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(const SharedPTR<Type, TDeleter>& sharedPTR)
{
    printf(" Оператор присваивания\n");
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
