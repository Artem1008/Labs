#ifndef VECTOR_H
#define VECTOR_H
#include <fstream>
#include <vector>
#include <iostream>
#include <thread>

namespace Mystl {
template <typename T>
class vector
{
private:
    std::string filename;
    std::fstream file;
    std::shared_ptr<std::vector<T>> readbuf;
    std::shared_ptr<std::vector<T>> writebuf;
    //размера файла
    size_t sizefile;
    //размер окна
    size_t size;
    //функция проверки индекса для выхода за пределы вектора
    bool checkindex(size_t);
    //последний индекс вектора
    size_t Lastindex;
    //смещение от начала фаила для текущего окна на чтение
    size_t seekRead;
    //смещение от начала фаила для текущего окна на запись
    size_t seekWrite;
public:    
    vector(const std::string& _fileName, size_t size = 1024 * 1024);
    vector(const std::string& _fileName, const std::string& mode);
    ~vector();
    void read();
    void write();

    typedef typename std::vector<T>::iterator vec_iterator;
    typedef typename std::vector<T>::const_iterator vec_const_iterator;

    class iterator
    {
    private:
        friend class vector;
        vec_iterator it;
        size_t index;
    public:
        iterator(vec_iterator it, size_t index);
        T& operator*();
        iterator& operator++();
        bool operator!=(const iterator& other);
    };
    class const_iterator {
        friend class vector;
        vec_const_iterator it;
        size_t index;
    public:
        const_iterator(vec_const_iterator it, size_t index);
        const T& operator*();
        const_iterator& operator++();
        bool operator!=(const const_iterator& other);
    };

    iterator begin() { return iterator((*readbuf).begin(), seekRead); }
    iterator end() { return iterator((*readbuf).begin() + size, seekRead + size); }
    const_iterator begin() const { return const_iterator((*readbuf).begin(), seekRead); }
    const_iterator end() const { return const_iterator((*readbuf).begin() + size, seekRead + size); }

    T& operator[](size_t index);
    T& at(size_t index);
    void resize(size_t  newIndex);
    void push_back(const T& value);
    T pop_back();
    void seek_window(size_t index);
    void flush();
};

}
#include "vector.inl"
#endif // VECTOR_H
