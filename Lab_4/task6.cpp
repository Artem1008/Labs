#include "main.h"

int task6()
{
    int m;
    float fx;
    char cht;
    printf("������ 3 �᫠ �१ �஡�� int float char:\n");
    scanf("%d %f %c",&m,&fx,&cht);
    printf("�����⥫�: �த�������஢��� �ᯮ�짮����� �����஢ & � *:\n");
    int* pm=&m;
    float* pfx=&fx;
    char* pcht=&cht;
    printf("--------------------------------------------------------\n");
    printf("m = %d\n",*pm);
    printf("fx = %0.3f\n",*pfx);
    printf("cht = %c\n",*pcht);
    printf("�ᯮ�짮����� & ������:\n");
    printf("--------------------------------------------------------\n");
    printf("���� m = 0x%x\n",&m);
    printf("���� fx = 0x%x\n",&fx);
    printf("���� cht = 0x%x\n",&cht);
    printf("�ᯮ���� ������� & � *:\n");
    printf("--------------------------------------------------------\n");
    printf("���祭�� �� ����� m = %d\n",*(&m));
    printf("���祭�� �� ����� fx = %0.3f\n",*pfx);
    printf("���祭�� �� ����� cht = %c\n",cht);
    printf("�ᯮ���� ⮫쪮 ��६����� 㪠��⥫�:\n");
    printf("--------------------------------------------------------\n");
    printf("���� m = 0x%x\n",pm);
    printf("���� fx = 0x%x\n",pfx);
    printf("���� cht = 0x%x\n",pcht);
    printf("�ᯮ�짮����� ⮫쪮 ������ 㪠��⥫�:\n");
    printf("--------------------------------------------------------\n");
    printf("���祭�� �� ����� m = %d\n",*pm);
    printf("���祭�� �� ����� fx = %0.3f\n",*pfx);
    printf("���祭�� �� ����� cht = %c\n",*pcht);
    int *Arr =new int[5]{5,7,2,9,8};
    for(int i=0;i<5;i++)
    {
        printf("Arr[%d]=0x%x, *Arr[%d]=%d \n",i,Arr,i,*Arr);
        Arr++;
    }
}
template<typename T>
int ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        std::cin>>Value;
        std::cin.ignore(32767,'\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<"�� ����� ����४⭮� ���祭��\n";
        }
        else return 1;
    }
    std::cout<<"�ਢ�襭� �᫮ ����⮪ ����� ������\n";
    return -1;
}
