#include "main.h"
# define MAXVALUE 15
# define MINVALUE -15

void task2()
{
    int matrix1[5][5];
    printf("Матрица 5х5:\n");
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            matrix1[i][j]=(i==j) ?1:0;
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }
    int matrix2[8][8];
    srand(8888);
    int rezult=0;
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0);
    printf("Матрица 8х8:\n");
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            matrix2[i][j]=static_cast<int>(rand() * fraction * (MAXVALUE-MINVALUE+1) +MINVALUE);
            rezult=(i<j) ?rezult+matrix2[i][j]:rezult;
            printf("%3d ",matrix2[i][j]);
        }
        printf("\n");
    }
    printf("Cумма элементов матрицы, лежащих выше главной диагонали:%d\n",rezult);
}
