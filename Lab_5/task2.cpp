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
  printf("Создай своё животное\n");
  printf("Введите тип головы и их количество:");
  std::cin>>Animal.head.type>>Animal.head.count;
  printf("Введите тип глаз и их количество:");
  std::cin>>Animal.eyes.type>>Animal.eyes.count;
  printf("Введите количество лап:");
   std::cin>>Animal.countpaw;
   //std::cin.clear();
   std::cin.ignore(32767,'\n');
  printf("Введите тип шкуры:");
  std::getline(std::cin,Animal.skin);
  printf("Введите тип хвоста:");
   std::getline(std::cin,Animal.tail);
  printf("У вашего существа:\n");
  printf("%d %s голов, %d %s глаз,%d лап,%s шкурой и %s хвостом",Animal.head.count,Animal.head.type.c_str(),Animal.eyes.count,Animal.eyes.type.c_str(),Animal.countpaw,Animal.skin.c_str(),Animal.tail.c_str());
}
