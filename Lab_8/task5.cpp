#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node* next=nullptr;
    const Node<T>& operator++()
    {
      return *next;
    };
    const Node<T>& operator++(int);
    friend std::ostream& operator<< (std::ostream &out, const Node &n);
    Node(T _data):data(_data){};
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
    void CreateBufer(int);
public:
    Node<T>* begin=nullptr;
    Node<T>* end=nullptr;
    Node<T>*  pointer=nullptr;
    explicit  Buffer(int _size):size(_size)
    {
        CreateBufer(size);
    }
    Buffer(const Buffer&) = delete;
    void pritfbuf()
    {
        pointer=begin;
        for(int i=1;i<=size;++i)
        {
            printf("%d ",pointer->data);
            //pointer=pointer->next;
            ++pointer;
        }
    }
};
template <typename T>
void Buffer<T>:: CreateBufer(int size)
{
    for(int i=1;i<=size;++i)
    {
        Node<T>* temp=new Node<T>(i);
        if(begin==nullptr)
        {
            begin=end=temp;
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
    Buffer<> bufers(3);
    bufers.pritfbuf();
}
