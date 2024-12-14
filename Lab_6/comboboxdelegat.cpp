#include "comboboxdelegat.h"

ComboBoxDelegat::ComboBoxDelegat(QVector<Driver>& _drivers,QObject *parent)
    : QItemDelegate(parent)
{
    myDrivers=_drivers;
}
QWidget *ComboBoxDelegat::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    QComboBox *editor = new QComboBox(parent);
    for(auto var:myDrivers)
    {
        editor->addItem(var.GetName());
    }
    return editor;
}
void ComboBoxDelegat::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *cBox = static_cast<QComboBox*>(editor);
    cBox->setCurrentIndex(cBox->findText(value));
}
void ComboBoxDelegat::setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const
{
    QComboBox *cBox = static_cast<QComboBox*>(editor);
    QString value = cBox->currentText();

    model->setData(index, value, Qt::EditRole);
}

void ComboBoxDelegat::updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}
