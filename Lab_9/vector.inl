#include "vector.h"

namespace Mystl {
template<typename T>
vector<T>::vector(const std::string& _fileName, size_t _size):size(_size),filename(_fileName)
{
    file.open(filename,std::ios::in|std::ios::out|std::ios::binary);
    file.seekg(0, std::ios::end);
    sizefile=file.tellg();
    file.seekg(0,std::ios::beg);
    Lastindex=(sizefile/sizeof (T))-1;
    readbuf=std::make_shared<std::vector<T>>(Lastindex+1);
    seekRead=0;
    seekWrite=0;
    read();
}
template<typename T>
void vector<T>::read()
{
    readbuf=std::make_shared<std::vector<T>>(size/sizeof (T));
    if (!file.is_open())
    {
        std::cout << "фаил test.dat не прочитан" <<  std::endl;
        exit(1);
    }
    file.seekp(seekRead);
    file.read((char*)&(*readbuf)[0],size);
}
template<typename T>
void vector<T>::write()
{   
    if (!file.is_open())
    {
        std::cout << "фаил test.dat не прочитан" <<  std::endl;
        exit(1);
    }
    file.seekp(seekWrite);
    file.write((char*)&(*writebuf)[0],size);
    (*writebuf).clear();
}
template<typename T>
bool vector<T>::checkindex(size_t index)
{
    return (Lastindex>=index);
}
template<typename T>
T &vector<T>::operator[](size_t index)
{
    if (!checkindex(index)) {
        throw std::out_of_range("Индекс находится за пределами вектора");
    }
    int StartIndex=(seekRead/sizeof (T));
    if ((index<StartIndex)||(index>=(int)(StartIndex+size/sizeof (T))))
    {
        seekWrite=seekRead;
        seekRead=(index+size/sizeof (T)<Lastindex)?(index/(size/sizeof (T)))*size:(sizefile-size);
        writebuf=std::move(readbuf);
        std::thread buffWrite(&vector<T>::write,this);
        std::thread readRead(&vector<T>::read,this);
        buffWrite.detach();
        readRead.join();
    }
    return (*readbuf)[(index%(size/sizeof (T)))];
}
template<typename T>
T &vector<T>::at(size_t index)
{
    if (!checkindex(index)) {
        throw std::out_of_range("Индекс находится за пределами вектора");
    }
    int StartIndex=(seekRead/sizeof (T));
    if (index<StartIndex||index>=StartIndex+size/sizeof (T))
    {
        seekWrite=seekRead;
        seekRead=(index+size/sizeof (T)<Lastindex)?(index/(size/sizeof (T)))*size:(sizefile-size);
        writebuf=std::move(readbuf);
        std::thread buffWrite(&vector<T>::write,this);
        std::thread readRead(&vector<T>::read,this);
        buffWrite.detach();
        readRead.join();
        write();
        read();
    }
    return (*readbuf)[(index%(size/sizeof (T)))];
}
template<typename T>
void vector<T>::resize(size_t  newIndex)
{
    file.close();

    int updatesize;
    if (newIndex>Lastindex+1)
    {
        file.open(filename,std::ios::in|std::ios::out|std::ios::binary|std::ios::app);
        file.seekg(0,std::ios::end);
        updatesize=newIndex*sizeof(T)-sizefile;
        T* temp=new T[newIndex-Lastindex-1]{0};
        file.write((char*)&temp[0],(newIndex-Lastindex-1)*sizeof(T));
    }
    else
    {
        file.open(filename,std::ios::in|std::ios::out|std::ios::binary);
        file.seekg(newIndex*sizeof(T),std::ios::beg);
        updatesize=sizefile-newIndex*sizeof(T);
        T* temp=new T[Lastindex+1-newIndex]{0};
        file.write((char*)&temp[0],updatesize);
    }
    file.close();
    file.open(filename,std::ios::in|std::ios::out|std::ios::binary);
    file.seekg(0, std::ios::end);
    sizefile=file.tellg();
    file.seekg(0,std::ios::beg);
}
template<typename T>
void vector<T>::push_back(const T &value)
{
}
template<typename T>
T vector<T>::pop_back()
{
}
template<typename T>
void vector<T>::seek_window(size_t _size)
{
    size=_size;
}
template<typename T>
void vector<T>::flush()
{
    seekWrite=seekRead;
    writebuf=std::move(readbuf);
    write();
    file.flush();
}
template<typename T>
vector<T>::~vector()
{
    seekWrite=seekRead;
    writebuf=std::move(readbuf);
    write();
    file.close();
}
template<typename T>
vector<T>::iterator::iterator(vector<T>::vec_iterator it, size_t index) : it(it), index(index)
{}
template<typename T>
T &vector<T>::iterator::operator*()
{ return *it; }

template<typename T>
typename vector<T>::iterator &vector<T>::iterator::operator++()
{ ++it; return *this; }

template<typename T>
bool vector<T>::iterator::operator!=(const vector<T>::iterator &other)
{ return it != other.it; }

template<typename T>
vector<T>::const_iterator::const_iterator(vector<T>::vec_const_iterator it, size_t index) : it(it), index(index)
{}

template<typename T>
const T &vector<T>::const_iterator::operator*()
{ return *it; }

template<typename T>
typename vector<T>::const_iterator &vector<T>::const_iterator::operator++() { ++it; return *this; }

template<typename T>
bool vector<T>::const_iterator::operator!=(const vector<T>::const_iterator &other)
{ return it != other.it; }

}

