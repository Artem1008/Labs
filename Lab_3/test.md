1
а)
``` cpp

#include <iostream>
int return 5(){
return 5;
}
int return8(){
return;
}
int main(){
std::cout << (return5() + return8() ) << std::endl;
return 0
}
```
Рабочий вариант
``` cpp
#include <iostream>
int return5(){
return 5;
}
int return8(){
return 8;
}
int main(){
std::cout << (return5() + return8() ) << std::endl;
return 0;
}
``` 
Ответ :13

b)
``` cpp
int return() {
  return 5;
    int return()
    {
      int k ;
      k{3};
      return k;
    }
  }
int main(){
std::cout << return() << std::endl;
std::cout << return() << std::endl;
}
```
возможно так, но идею кода не понял
``` cpp
#include <iostream>
int return5() {
    return 5; 
}
int returnk()
{
    int k{3} ;
    return k;
}
int main(){
    std::cout << return5() << std::endl;
    std::cout << returnk() << std::endl;
}
```
Ответ: 5 3

c)
``` cpp
#include <iostream>
void prints
()
{
std::cout << 'O_o' << std::endl;
}
int main ()
{
std::cout << prints() << std::endl;
return 0;
}
```
Рабочий вариант
``` cpp
#include <iostream>
void prints()
{
std::cout << 'O_o' << std::endl;
}

int main ()
{
prints();
return 0;
}
```
Ответ: O_o

d)
``` cpp
#include <iostream>
int getNumbers()
{
return 6;
return 8;
}
int main()
{
std::cout << getNumbers() << std::endl;
std::cout << getNumbers() << std::endl;
std::cout << getNumbers << std::endl;
return 0;
}
```
Рабочий вариант
``` cpp
#include <iostream>
int getNumbers()
{
return 6;
return 8;
}
int main()
{
std::cout << getNumbers() << std::endl;
std::cout << getNumbers() << std::endl;
std::cout << getNumbers() << std::endl;
return 0;
}
```
Ответ: 6 6 6

e)
``` cpp
int main()
{
std::cout << multiply(7, 8) << std::endl;
return 0;
}
void multiply(int a)
{
return a * b
}
int main() {
int x;
std::cin >> x;
constexpr int y(x); // в дальнейшем переменная usersAge не может быть изменена
std::cout << y << std::endl;
return 0;
}
```
Рабочий вариант
``` cpp
#include <iostream>

int multiply(int a,int b)
{
return a * b;
}

int main2()
{
std::cout << multiply(7, 8) << std::endl;
return 0;
}
int main() {
int x;
std::cin >> x;
const int& y=1; // в дальнейшем переменная usersAge не может быть изменена
const_cast<int&>(y)=x;
std::cout << y << std::endl;
return 0;
}
```

f)
``` cpp
#include <iostream>
#define VALUE 1
int main() {
#if (VALUE == 0)
std::cout << VALUE <<"\n";
#elif (VALUE == 1)
std::cout << VALUE <<"\n";
#else
std::cout << VALUE <<"\n";
#endif
}
```
Ответ: 1

g)
``` cpp
#include <iostream>
namespace Mix {
enum class Fruits {
LEMON,
APPLE
};
enum class Colors {
RED,
BLACK
};
}
int main() {
Fruits fruit = Fruits::LEMON;
std::cout << "MIX\n";
return 1;
}
```
Рабочий вариант
``` cpp
#include <iostream>
namespace Mix {
enum class Fruits {
LEMON,
APPLE
};
enum class Colors {
RED,
BLACK
};
}
int main() {
Mix::Fruits fruit = Mix::Fruits::LEMON;
std::cout << "MIX\n";
return 1;
}
```
Ответ: MIX

h)
Исходный код
``` cpp
#include <iostream>
namespace DoMath
{
int subtract(int x, int y)
{
return x , y;
}
}
namespace DoMath
{
int add(int x, int y)
{
return x | y;
}
}
int main(void)
{
std::cout << DoMath::add(5, 4) << '\n';
std::cout << DoMath::subtract(5, 4) << '\n';
return 0;
}
```
Ответ: 5 4
2

1 #include <iostream>
2 int tmp = 1;
3 int getNumbers( {
4 int tmp = 1;
5 return 8;
6 }
7 int main()
8 {
9 int tmp = 3;
10
11 std::cout << tmp << "Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять 
12
13 и
14
15 комментировать "
16 << std::endl;
17
18 return 0;
19
//Ответ:
#include <iostream>
int tmp = 1;
int getNumbers( ){
int tmp = 1;
return 8;
}
int main()
{
int tmp = 3;

std::cout << tmp << "Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять"

"и"

"комментировать "
<< std::endl;

return 0;
}
