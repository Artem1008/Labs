/*
 * Класс комплексных чисел
*/
#ifndef COMBOBOXDELEGAT_H
#define COMBOBOXDELEGAT_H
#include <QObject>
#include <QItemDelegate>
#include <QStyleOptionViewItem>
#include <QComboBox>
#include "driver.h"

class ComboBoxDelegat:public QItemDelegate
{
    Q_OBJECT
 private:
    QMap<QString,Driver> myDrivers;
public:
    ComboBoxDelegat(QMap<QString,Driver>& _drivers,QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // COMBOBOXDELEGAT_H
