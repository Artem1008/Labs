#ifndef LISTMODELFLIGHT_H
#define LISTMODELFLIGHT_H
#include <QStandardItemModel>
#include "flight.h"
#include "dispatcher.h"
#include "driver.h"
#include "car.h"

class TreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(Dispatcher& _disp,QVector<Driver>& _drivers, QVector<Car>&_cars, QObject *parent);
    void initialize();
private:
    Dispatcher* muDisp;
    QVector<Driver>* myDrivers;
    QVector<Car>* myCar;
    QVector<QPair<QString, Flight>>myFlight{
        {"Заявка 1", {1,"Томск","Новосибирск" }},
        {"Заявка 2", {2,"Новосибирск","Кемерово" }},
        {"Заявка 3", {3,"Кемерово","Топки" }},
    };
};

#endif // LISTMODELFLIGHT_H
