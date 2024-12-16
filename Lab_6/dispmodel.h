#ifndef LISTMODELFLIGHT_H
#define LISTMODELFLIGHT_H
#include <QStandardItemModel>
#include <QDebug>
#include <QMap>
#include "flight.h"
#include "driver.h"
//Класс диспетчера
class ModelDisp : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit ModelDisp(QVector<Flight> & _flight, QObject *parent);
    void initialize();
private:
    QString Name;
    QVector<Flight>* myFlight;
};

#endif // LISTMODELFLIGHT_H

