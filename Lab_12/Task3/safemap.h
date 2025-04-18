#ifndef SAFEMAP_H
#define SAFEMAP_H
#include <map>
#include <mutex>
#include <iostream>

class SafeMap {
private:
    typedef std::map<int,int> koordinats;
    koordinats data;
    std::mutex mutex;
public:
    static int count;
    koordinats getAll();
    int getNum(int num);
    void insert(int position);
    void remove(int num);
    size_t size();
    void print();
};
#endif // SAFEMAP_H
