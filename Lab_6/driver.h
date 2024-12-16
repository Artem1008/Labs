#ifndef DRIVER_H
#define DRIVER_H
#include <QString>

#include "car.h"
//
class Driver
{
private:
   QString Name;
    //назначеный автомобиль
   Car *mycar=nullptr;
   //назначенная заявка
   QString Request;
public:
   Driver(QString _name):Name(_name){}
    //обновить статус машины
    void UpdateStatusCar(StatusCar);
    QString GetName() const {return Name;}
    QString GetNameCar() const;
    void SetRequest(QString value){Request=value;}
    QString GetRequest() const {return Request;}
    void SetCar(Car &value){mycar=&value;}
};

#endif // DRIVER_H
