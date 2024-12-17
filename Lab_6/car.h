/*
 * Класс машины
 * TODO не сипользуется 
*/
#ifndef CAR_H
#define CAR_H
#include <QString>
enum StatusCar
{
    Repair,
    Free,
    Work
};
class Car
{
private:
    //название машины
    QString Name;
    //номер машины
    int Number;
    //состояние
    StatusCar Status;
public:
    Car(int _number,QString _name,StatusCar _status=Free);
    void setStatus(StatusCar _value){Status=_value;}
    QString getName(){return Name;}
};

#endif // CAR_H
