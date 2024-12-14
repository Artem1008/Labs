#ifndef LISTMODELFLIGHT_H
#define LISTMODELFLIGHT_H
#include <QStandardItemModel>
#include <QDebug>
#include "flight.h"
#include "dispatcher.h"
#include "driver.h"
#include "car.h"

class TreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(Dispatcher& _disp,QVector<Driver>& _drivers, QVector<Car>&_cars,QVector<Flight> & _flight, QObject *parent);
    void initialize();
    void SetFlight(Flight _value);
   QVariant data(const QModelIndex& index, int nRole) const;
private:
    Dispatcher* muDisp;
    QVector<Driver>* myDrivers;
    QVector<Car>* myCar;
    QVector<Flight>* myFlight;
};

#endif // LISTMODELFLIGHT_H

