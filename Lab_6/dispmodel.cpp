#include <QComboBox>
#include "dispmodel.h"

ModelDisp::ModelDisp(QVector<Flight> & _flight, QObject *parent = nullptr) : QStandardItemModel(parent)
{
    myFlight=&_flight;
    initialize();
};
void ModelDisp::initialize()
{
    setColumnCount(1);
    setRowCount((*myFlight).size());
    for (int row = 0; row < rowCount(); ++row)
    {
        QStandardItem* item = new QStandardItem("Заявка "+QString::number((*myFlight).at(row).GetNumber()));
        QList<QStandardItem*> items;
        QStandardItem* internalItem = new QStandardItem(QString::number((*myFlight).at(row).GetNumber()));
        internalItem->setFlags(Qt::ItemIsEnabled);
        items << internalItem;
        internalItem = new QStandardItem((*myFlight).at(row).GetStartPoint());
        internalItem->setFlags(Qt::ItemIsEnabled);
        items << internalItem;
        internalItem = new QStandardItem((*myFlight).at(row).GetStopPoint());
        internalItem->setFlags(Qt::ItemIsEnabled);
        items << internalItem;
        internalItem = new QStandardItem("");
        items << internalItem;
        item->appendColumn(items);
        setItem(row, item);
    }
      setVerticalHeaderLabels(QStringList() << "Номер" << "Начало пути"<<"Конец пути"<<"Водитель");
}
