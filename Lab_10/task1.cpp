#include <iostream>

class Product
{
    const char* Name;
    int Price;
    float Weight;
public:
    Product()
    {
      Name="Неизвестен";
      Price=0;
      Weight=0;
    };
    Product(const char* _name,int _price,int _weight):Name(_name),Price(_price),Weight(_weight){};
    const char* getName(){return Name;}
    int getPrice(){return Price;}
    int getWeight(){return Weight;}
    void setName(const char* str){Name=str;}
    void setPrice(int value){Price=value;}
    void setWeight(int value){Weight=value;}
};
class Buy:public Product
{
    int Counter;
    int SumPrice;
    int SumWeight;
public:
    Buy()
    {
        Counter=0;
        SumPrice=0;
        SumWeight=0;
    };
    Buy(const char* _name,int _price,int _weight,int _counter):Product(_name,_price,_weight),Counter(_counter)
    {
        SumPrice=_counter*_price;
        SumWeight=_counter*_weight;
    };
    int getCounter(){return Counter;}
    int getSumPrice(){return SumPrice;}
    int getSumWeight(){return SumWeight;}
    void setCounter(int value)
    {
        Counter=value;
        SumPrice=value*getPrice();
        SumWeight=value*getWeight();
    }
};
class Check :public Buy
{
public:
    Check(){}
    Check(const char* _name,int _price,int _weight,int _counter):Buy( _name, _price,_weight,_counter){}
    void print()
    {
        printf("%10s | %10s | %10s | %10s | %10s | %10s \n","Название","Цена ед.","Вес ед.","Количество","Цена общ.","Вес общ.");
        printf("%10s | %10d | %10d | %10d | %10d | %10d \n",getName(),getPrice(),getWeight(),getCounter(), getSumPrice(),getSumWeight());

    }
};

int task1() {
    Check cher;
    cher.print();
    printf("\n");
    cher.setName("Арбуз");
    cher.setPrice(10);
    cher.setWeight(21);
    cher.setCounter(5);
    cher.print();
    printf("\n");
    Check cher2("Дыня",15,6,3);
    cher2.print();
    printf("\n");
    return 1;
}

