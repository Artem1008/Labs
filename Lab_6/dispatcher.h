#ifndef DISPATCHER_H
#define DISPATCHER_H
#include <QString>
#include "driver.h"

class Dispatcher
{
private:
    QString Name;
public:
    Dispatcher(QString _name):Name(_name){}
    //назначение водителю заявки
    void SetApplicationDriver(Driver & _drviver, QString _str);
    //назначение водителю машину
    void SetCarDriver(Driver & _drviver, Car &_str);
};

#endif // DISPATCHER_H
