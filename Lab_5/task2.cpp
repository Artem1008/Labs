#include "main.h"
struct newtype
{
    struct { std::string type; int count;}head;
    struct { std::string type; int count;}eyes;
   int countpaw;
   std::string skin;
   std::string tail;
}Animal;

void task2()
{
  printf("������ ᢮� ����⭮�\n");
  printf("������ ⨯ ������ � �� ������⢮:");
  std::cin>>Animal.head.type>>Animal.head.count;
  printf("������ ⨯ ���� � �� ������⢮:");
  std::cin>>Animal.eyes.type>>Animal.eyes.count;
  printf("������ ������⢮ ���:");
   std::cin>>Animal.countpaw;
   //std::cin.clear();
   std::cin.ignore(32767,'\n');
  printf("������ ⨯ ����:");
  std::getline(std::cin,Animal.skin);
  printf("������ ⨯ 墮��:");
   std::getline(std::cin,Animal.tail);
  printf("� ��襣� ����⢠:\n");
  printf("%d %s �����, %d %s ����,%d ���,%s ��ன � %s 墮�⮬",Animal.head.count,Animal.head.type.c_str(),Animal.eyes.count,Animal.eyes.type.c_str(),Animal.countpaw,Animal.skin.c_str(),Animal.tail.c_str());
}
