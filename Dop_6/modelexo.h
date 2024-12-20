#ifndef MODELEXO_H
#define MODELEXO_H
#define SIZEPOLE 3
 #include <QString>
 #include <QDebug>

class ModeleXO
{
private:
    char Simvol='X';
    bool FlagWin=false;
public:
    ModeleXO();
    char GetSimvol(){return Simvol;}
    void UpdateSimvol();
    bool CheckWin();
    void Restart();
    void UpdatePole(int);
    char pole[SIZEPOLE][SIZEPOLE];

};

#endif // MODELEXO_H
