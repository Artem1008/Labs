#include <matrix.h>

int task1()
{
    try
    {
        Matrix<int> mtrx1(3,3);
        Matrix<int> mtrx2(3,3);
        std::cout<<"Матрица1:\n"<<mtrx1<<'\n';
        std::cout<<"Матрица2:\n"<<mtrx2<<'\n';
        //умножение c изминением
         std::cout<<"Матрица2 умножить на 3:\n"<<mtrx2.multiply(3)<<'\n';
        //сложение
        std::cout<<"Матрица1 сложить с Матрица2 :\n"<<mtrx1+mtrx2<<'\n';
        //вычитание
        std::cout<<"Матрица1 вычесть из Матрица2 :\n"<<mtrx2-mtrx1<<'\n';
        //умножени
        std::cout<<"Умножить на 3 :\n"<<mtrx1*(3.2)<<'\n';
        std::cout<<"Матрица1 умножить на Матрица2 :\n"<<mtrx1*mtrx2<<'\n';
        //сложение
        std::cout<<"к Матрица1 прибавить Матрица2 :\n"<<mtrx1.add(mtrx2)<<'\n';
        //вычитание
        std::cout<<"из Матрица1 вычесть Матрица2 :\n"<<mtrx1.sub(mtrx2)<<'\n';
        //присваивание
        std::cout<<"Матрица1:\n"<<mtrx1<<'\n';
        mtrx1=mtrx2;
        std::cout<<"Матрица1:\n"<<mtrx1<<'\n';
        return 1;
    }
    catch (int param)
    {
        if (param==-1) printf("Ошибка вычисления, матрицы разного размера");
    }
   return 1;
}
