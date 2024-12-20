#include "modelexo.h"

ModeleXO::ModeleXO()
{

}

void ModeleXO::UpdateSimvol()
{
    if (Simvol=='X') Simvol='O';
    else if (Simvol=='O') Simvol='X';
}

bool ModeleXO::CheckWin()
{
    QString winhoraiz="";
    QString winvert[SIZEPOLE];
    QString windiag1="";
    QString windiag2="";
    for (int i = 0; i < SIZEPOLE; i++)
    {
        for (int j = 0; j < SIZEPOLE; j++)
        {
            if(i==j)windiag1+=pole[i][j];
            if(i+j+1==SIZEPOLE)windiag2+=pole[i][j];
            winvert[j]+=pole[i][j];
            winhoraiz+=pole[i][j];
        }
       if(winhoraiz.count(Simvol)==SIZEPOLE) return true;
       winhoraiz="";
    }
    for(int j=0;j<SIZEPOLE;j++)
    {
        if(winvert[j].count(Simvol)==SIZEPOLE) return true;
    }
   if(windiag1.count(Simvol)==SIZEPOLE) return true;
   if(windiag2.count(Simvol)==SIZEPOLE) return true;
   return false;
}

void ModeleXO::Restart()
{
    for (int i = 0; i < SIZEPOLE; i++)
    {
        for (int j = 0; j < SIZEPOLE; j++)
        {
            pole[i][j]='_';
        }
    }
}
void ModeleXO::UpdatePole(int index)
{
    pole[index/SIZEPOLE][index%SIZEPOLE-1]=Simvol;
}
