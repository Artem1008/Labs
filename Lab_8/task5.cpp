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
    friend std::ostream& operator<< (std::ostream &out, const Node &n);
    Node(T _data=0):data(_data){};
};

template <typename T>
const Node<T>& Node<T>::operator++(int)
{
    Node<T> temp(data);
    ++(*this);
    return temp;
}
template <typename T>
std::ostream& operator<< (std::ostream &out, const Node<T>&n) {
    out << n.data << "\n";
    return out;
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
    Buffer(const Buffer&) = delete;
    void Add(T);
    void pritfbuf()
    {
        getpointer=begin;
        for(int i=1;i<=size;++i)
        {
            printf("%d ",getpointer->data);
            ++getpointer;
        }
    }
};
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
}

int task5()
{
    Buffer<> bufers(10);
    for(int i=1;i<=10;++i)
    {
        bufers.Add(i);
    }
    bufers.pritfbuf();
    return 1;
}
