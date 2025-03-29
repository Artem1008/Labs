#include "sharedptr.h"

// ��������� �� 㬮�砭��
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR():m_ptr(nullptr), count(nullptr)
{
    printf("��������� �� 㬮�砭��\n");
}

// ��������� � ��।�祩 㪠��⥫�
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(Type *pObj):m_ptr(pObj), count(nullptr)
{
     printf("��������� � ��।�祩 㪠��⥫�\n");
    AddCount();
}

// ��������� ��६�饭��
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(SharedPTR<Type, TDeleter> &&uniquePTR) noexcept:m_ptr(uniquePTR.m_ptr),count(uniquePTR.count),deleter(std::move(uniquePTR.deleter))
{
    printf("��������� ��६�饭��\n");
    uniquePTR.m_ptr = nullptr;
    uniquePTR.count = nullptr;
}

// ��������� ����஢����
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(const SharedPTR<Type, TDeleter>& other): m_ptr(other.m_ptr), count(other.count), deleter(other.deleter)
{
    printf("��������� ����஢����\n");
    AddCount();
}
// ��������
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::~SharedPTR()
{
    printf("��������\n");
    SubCount();
    if (m_ptr && count == nullptr) {
        deleter(m_ptr);
    }
}
// ������ ��ᢠ������ ��६�饭��
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(SharedPTR<Type, TDeleter> &&sharedPTR) noexcept
{
    printf("������ ��ᢠ������ ��६�饭��\n");
    if (&sharedPTR == this) return *this;
    m_ptr = sharedPTR.m_ptr;
    count=sharedPTR.count;
    deleter=std::move(sharedPTR.deleter);
    sharedPTR.m_ptr = nullptr;
    sharedPTR.count = nullptr;
    return *this;
}
// ������ ��ᢠ������ 㪠��⥫�
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(Type *pObject)
{
    printf("������ ��ᢠ������ 㪠��⥫�\n");
    if (m_ptr == pObject) return *this;
    m_ptr = pObject;
    AddCount();
    return *this;
}
// ������ ��ᢠ������
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>& SharedPTR<Type, TDeleter>::operator=(const SharedPTR<Type, TDeleter>& sharedPTR)
{
    printf(" ������ ��ᢠ������\n");
    if (&sharedPTR == this) return *this;
    m_ptr = sharedPTR.m_ptr;
    count = sharedPTR.count;
    deleter=sharedPTR.deleter;
    AddCount();
    return *this;
}
// ������ ࠧ묥�������
template<class Type,class TDeleter>
Type& SharedPTR<Type, TDeleter>::operator*() const
{
    return *m_ptr;
}
// ������ ����㯠 � 童���
template<class Type,class TDeleter>
Type* SharedPTR<Type, TDeleter>::operator->() const
{
    return m_ptr;
}
// ����祭�� 㪠��⥫�
template<class Type,class TDeleter>
Type* SharedPTR<Type, TDeleter>::get() const
{
    return m_ptr;
}
// ����祭�� 㤠��⥫�
template<class Type,class TDeleter>
TDeleter& SharedPTR<Type, TDeleter>::get_deleter() {
    return deleter;
}
// �८�ࠧ������ � bool
template<class Type,class TDeleter>
SharedPTR<Type, TDeleter>::operator bool() const
{
    return (m_ptr!=nullptr);
}
// �᢮�������� ��������
template<class Type,class TDeleter>
void SharedPTR<Type, TDeleter>::release()
{
    SubCount();
    m_ptr = nullptr;
}
// ���� 㪠��⥫�
template<class Type,class TDeleter>
void SharedPTR<Type, TDeleter>::reset(Type *pObject)
{
    if (m_ptr != pObject) {
        m_ptr = pObject;
        SubCount();
        count=nullptr;

    }
}
// ����� � ��㣨� 㬭� 㪠��⥫��
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
