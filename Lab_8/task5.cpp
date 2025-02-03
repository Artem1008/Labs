#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node* next=nullptr;
    Node<T>& operator++()
    {
        return *next;
    };
    const Node<T>& operator++(int);
    Node(T _data=0):data(_data){};
};
template<typename T>
std::ostream& operator << (std::ostream& os, const Node<T>& node)
{
    return  os<<node.data;
}
template <typename T>
const Node<T>& Node<T>::operator++(int)
{
    Node<T> temp(data);
    ++(*this);
    return temp;
}
template <typename T=int>
class Buffer
{
private:
    int size;
    int CreateBufer(int);
public:
    Node<T>* begin=nullptr;
    Node<T>* end=nullptr;
    Node<T>* setpointer=nullptr;
    Node<T>* getpointer=nullptr;
    explicit  Buffer(int _size):size(_size)
    {
        CreateBufer(size);
    }
    Buffer(const Buffer&)= delete;
    void Add(T);
    void operator+ (T);
    T& operator[] (const int index);
    void pritfAll()
    {
        getpointer=begin;
        for(int i=1;i<=size;++i)
        {
            printf("%d ",getpointer->data);
            getpointer=getpointer->next;
        }
        printf("\n");
    }
};
template <typename T>
void Buffer<T>::operator+ (T _data)
{
    setpointer->data=_data;
    setpointer=setpointer->next;
}
template <typename T>
T& Buffer<T>::operator[] (const int index)
{
    Node<T>* temp=begin;
    for(int i=1;i<=index;++i)
    {
        temp=temp->next;
    }
    return temp->data;
}
template <typename T>
void Buffer<T>:: Add(T _data)
{
    setpointer->data=_data;
    setpointer=setpointer->next;
}
template <typename T>
int Buffer<T>:: CreateBufer(int size)
{
    Node<T>* temp;
    try
    {
        temp=new Node<T>[size];
    }
    catch (...)
    {
        printf("Ошибка выделения памяти");
        return -1;
    }
    for(int i=0;i<size;++i,++temp)
    {
        if(begin==nullptr)
        {
            getpointer=setpointer=begin=end=temp;
        }
        else
        {
            temp->next=begin;
            end->next=temp;
            end=temp;
        }
    }
    return 1;
}
int task5()
{
    double sizeBuf=10;
    Buffer<> bufers(sizeBuf);
    for(int i=1;i<=sizeBuf;++i)
    {
        //bufers.Add(i);
        bufers+i;
    }
    bufers.pritfAll();
    std::cout<<bufers[0]<<' ';
    std::cout<<bufers[1]<<'\n';
    //проверка заколдованности)
    for(int i=0;i<sizeBuf*3;++i)
    {
        std::cout<<bufers[i]<<' ';
    }
    return 1;
}
