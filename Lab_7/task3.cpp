#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
using namespace std;

mutex mutex2;
class Check
{
    ostringstream out;
    int Summ;
    wstring name;
public:
    Check(int _sum,wstring _name):Summ(_sum),name(_name){};
    Check(const Check& copy_check)
    {
       Summ= copy_check.Summ;
       name= copy_check.name;
    }
    Check& operator=(const Check& check)
    {
        if (this != &check)
        {
           Summ = check.Summ;
           name = check.name;
        }
        return *this;
    }
    void addSumm(int _summa){ Summ+=_summa;};
    void subSumm(int _summa){ Summ-=_summa;};
    wstring GetName() const {return name;};
    int GetSumm() const {return Summ;};
};

void transaction(Check& CheckOut,Check& CheckIn,unsigned int sum)
{
    Check* temp1=nullptr;
    Check* temp2=nullptr;
    try
    {
        const std::lock_guard<std::mutex> lock(mutex2);
        temp1=new Check(CheckOut);
        temp2=new Check(CheckIn);
        CheckOut.subSumm(sum);
        CheckIn.addSumm(sum);
        wcout << CheckOut.GetName().c_str()<<L" состояние счёта:"<<CheckOut.GetSumm()<<"\n";
        wcout <<CheckIn.GetName().c_str()<<L" состояние счёта:"<<CheckIn.GetSumm()<<"\n";
        //throw(-1);
        this_thread::sleep_for(chrono::seconds(1));
    }
    // возвращение счётов в исходное состояние при сработавшем исключении
    catch (...) {
        if(temp1!=nullptr)
        CheckOut=*temp1;
        if(temp2!=nullptr)
        CheckIn=*temp2;
        wcout << CheckOut.GetName().c_str()<<L" состояние счёта:"<<CheckOut.GetSumm()<<"\n";
        wcout <<CheckIn.GetName().c_str()<<L" состояние счёта:"<<CheckIn.GetSumm()<<"\n";
    }
}

void task2()
{
     setlocale(LC_ALL, "");
    Check check1(5000,L"Вася");
    Check check2(4000,L"Петя");
    thread(transaction,std::ref(check1),std::ref(check2),500).join();
    thread(transaction,std::ref(check2),std::ref(check1),1200).join();

}
