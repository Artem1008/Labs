#include <thread>
#include <queue>
#define MAXSIZE 5
#include <mutex>

std::mutex mutex;

static int index=0;
class Klient
{
private:
    std::string Name;
public:
    std::string getName(){return Name;}
    Klient(std::string _name)
    {
        index++;
        Name=_name+"_"+std::to_string(index);
    };
};
class Barber
{
public:
    enum State {sleep, cut };
    Barber(std::string _name,int _size):Name(_name),size(_size){estate=sleep;};
    State getState(){return estate;};
    std::string getName(){return Name;}
    void setState(State _state){estate=_state;};
    //��������� ������ � ��।�
private:
    std::string Name;
    State estate;
    int size; //ࠧ��� ��।�
};
std::queue<Klient *> vKlient;

void addKlient()
{
    Klient *_klient;
    while(1)
    {
        _klient= new Klient("������");
        if((int)vKlient.size()<MAXSIZE)
        {
           mutex.lock();
           vKlient.push(_klient);
           mutex.unlock();
           printf("������ %s ������� � �ਥ����,� ��।� %d 祫����\n", _klient->getName().c_str(),vKlient.size());
        }
        else
        {
            printf("������ %s ���\n", _klient->getName().c_str());
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void subKlient(Barber& _barber)
{
    while(1)
    {
        if (vKlient.size()>0)
        {
            _barber.setState(Barber::cut);
            printf("������ %s �����ਣ�����, � ��।� %d 祫����\n", vKlient.front()->getName().c_str(),vKlient.size());
            mutex.lock();
            vKlient.pop();
            mutex.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(4));
            if(vKlient.size()==0)
            {
                printf("��ࡥ� %s ᯨ�\n", _barber.getName().c_str());
                _barber.setState(Barber::sleep);
            }
        }
    }
}

void task2()
{
    Barber pBarber("����",3);
    std::thread t1(addKlient);
    std::thread t2(subKlient,std::ref(pBarber));
    t1.join();
    t2.join();
}
