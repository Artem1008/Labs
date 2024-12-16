#ifndef MODELDRIVER_H
#define MODELDRIVER_H
#include <QStandardItemModel>
#include <QDebug>
#include "flight.h"
//Класс отвечающий за всех водетелей
class ModelDriver: public QStandardItemModel
{
    Q_OBJECT
public:
    explicit ModelDriver(QMap<QString,Driver>& _drivers, QVector<Flight> & _flight, QObject *parent);  
    void initialize();

private:
    QMap<QString,Driver>* myDrivers;
    QVector<Flight>* myFlight;
};

#endif // MODELDRIVER_H
