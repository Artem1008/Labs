#include "driver.h"
void Driver::UpdateStatusCar(StatusCar _statuscar)
{
    mycar->setStatus(_statuscar);
}

QString Driver::GetNameCar() const
{
    if (mycar!=nullptr) return mycar->getName();
    else return "не назначена";
}
