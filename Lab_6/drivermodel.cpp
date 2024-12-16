#include "drivermodel.h"

ModelDriver::ModelDriver(QMap<QString,Driver>& _drivers, QVector<Flight> & _flight, QObject *parent = nullptr) : QStandardItemModel(parent)
{
    myDrivers=&_drivers;
    myFlight=&_flight;
    initialize();
}

void ModelDriver::initialize()
{
    setColumnCount(1);
    setRowCount((*myDrivers).size());
    int row=0;
    QMap<QString,Driver>::const_iterator it = (*myDrivers).begin();
    for(;it != (*myDrivers).end(); ++it)
    {
      QStandardItem* item = new QStandardItem(it.key());
      QList<QStandardItem*> items;
      QStandardItem* internalItem = new QStandardItem(it.value().GetName());
      items << internalItem;
      internalItem = new QStandardItem(it.value().GetNameCar());
      items << internalItem;
      internalItem = new QStandardItem(it.value().GetRequest());
      items << internalItem;
      item->appendColumn(items);
      setItem(row++, item);

    }
      setVerticalHeaderLabels(QStringList() << "Имя" << "Машина"<<"Заявка");

}
