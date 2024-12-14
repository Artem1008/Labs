#include "dispatcher.h"

void Dispatcher::SetApplicationDriver(Driver & _drviver, QString _str)
{
    _drviver.SetRequest(_str);
}
void SetCarDriver(Driver & _drviver, Car &_str)
{
    _drviver.SetCar(_str);
}
