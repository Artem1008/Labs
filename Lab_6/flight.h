#ifndef FLIGHT_H
#define FLIGHT_H
#include <QString>
#include <QVariant>
#include "driver.h"

class Flight
{
private:
    int Number;
    QString StartPoint;
    QString StopPoint;
    Driver *driver;
public:
    static int Index;
    Flight(int _num=-1,QString _startpoint="",QString _stoppoint="");
    void SetNumber(int _value){Number=_value;}
    int GetNumber() const {return Number;}
    void SetStartPoint(QString _value){StartPoint=_value;}
    QString GetStartPoint() const {return StartPoint;}
    void SetStopPoint(int _value){StopPoint=_value;}
    QString GetStopPoint() const {return StopPoint;}
};

#endif // FLIGHT_H
