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
    enum CustomRoles{
           FlightRole=Qt::UserRole+1,
           DriversRole,
           CarRole,
       };
    explicit TreeModel(QVector<Driver>& _drivers,QVector<Flight> & _flight, QObject *parent);
    void initialize();
private:
    QVector<Driver>* myDrivers;
    QVector<Car>* myCar;
    QVector<Flight>* myFlight;
};

#endif // LISTMODELFLIGHT_H

