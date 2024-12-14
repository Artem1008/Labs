#ifndef DRIVER_H
#define DRIVER_H
#include <QString>
#include "car.h"

class Driver
{
private:
    QString Name;
    //назначеный автомобиль
   Car *mycar;
   //назначенная заявка
   QString *Request;
public:
   Driver(QString _name):Name(_name){}
    //обновить статус машины
    void UpdateStatusCar(StatusCar);
    QString GetName(){return Name;}
    void SetRequest(QString &value){Request=&value;}
    void SetCar(Car &value){mycar=&value;}
};

#endif // DRIVER_H
