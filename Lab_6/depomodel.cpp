//#include <QSpacerItem>
#include <QComboBox>
#include "depomodel.h"

TreeModel::TreeModel(Dispatcher& _disp,QVector<Driver>& _drivers, QVector<Car>&_cars, QObject *parent = nullptr) : QStandardItemModel(parent)
{
    muDisp=&_disp;
    myDrivers=&_drivers;
    myCar=&_cars;
    initialize();
};

void TreeModel::initialize()
{
    setColumnCount(1);
    setRowCount(myFlight.size());
    for (int row = 0; row < rowCount(); ++row)
    {
        QStandardItem* item = new QStandardItem(myFlight[row].first);
        QList<QStandardItem*> items;
        QStandardItem* internalItem = new QStandardItem(QString::number(myFlight[row].second.GetNumber()));
        internalItem->setFlags(Qt::ItemIsEnabled);
        items << internalItem;
        internalItem = new QStandardItem(myFlight[row].second.GetStartPoint());
        internalItem->setFlags(Qt::ItemIsEnabled);
        items << internalItem;
        internalItem = new QStandardItem(myFlight[row].second.GetStopPoint());
        internalItem->setFlags(Qt::ItemIsEnabled);
        items << internalItem;
        internalItem = new QStandardItem("");
        items << internalItem;
        item->appendColumn(items);
        setItem(row, item);
    }
    setVerticalHeaderLabels(QStringList() << "Номер" << "Начало пути"<<"Конец пути"<<"Водитель");
}
