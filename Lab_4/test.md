a)
```cpp
#include <iostream>
int main() {
short array[5]{1,3,5,7,9};
short *ptr = array;
*ptr = 111;
for (int i = 0; i < sizeof(array); ++i)
std::cout << array[i] << '\n';
}
```
Рабочий вариант
```cpp
#include <iostream>
int main() {
short array[5]{1,3,5,7,9};
short *ptr = array;
*ptr = 111;
for (int i = 0; i < sizeof(array)/sizeof(*array); ++i)
std::cout << array[i] << '\n';
}
```
b)
```cpp
#include <iostream>
const int size = 5;
void Func(int *ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << *ptr[i] << '\n';
}
int main() {
int array[size]{1,3,5,7,9};
Func(&array, size);
}
```
Рабочий вариант
```cpp
#include <iostream>
const int size = 5;
void Func(int *ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << ptr[i] << '\n';
}
int main() {
int array[size]{1,3,5,7,9};
Func(array, size);
}
```
c)
```cpp
#include <iostream>
int main() {
short value;
short *p;
p = value;
*p = value;
*p = &value;
*p = *&value;
}
```
Рабочий вариант
```cpp
#include <iostream>
int main() {
short value;
short *p;
p = &value;
*p = value;
*p = value;
*p = *&value;
}
```
e)
```cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref;
const short &ref1 = value;
const short &ref2 = 78;
ref1 = 3;
*&value = 4;
const *short const p3;
}
```
Рабочий вариант
```cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref=value;
const short &ref1 = value;
const short &ref2 = 78;
*&value = 4;
const short *const p3=&value1;
}
```
f)
```cpp
#include <iostream>
int main() {
short value = 13;
short value_1 = 100;
short *ptr = &value;
std::cout << &value << '\n';
std::cout << (value +=1) << '\n';
*ptr = 9;
std::cout << (value = value_1 + *ptr) << '\n';
std::cout << "Результат: " << value << '\n';
return 0;
}
```
Рабочий вариант
```cpp
```
g)
```cpp
int main() {
int value = 45;
int *ptr = &value;
*ptr = &value;
ptr = value;
}
```
Рабочий вариант
```cpp
#include <iostream>
int main() {
int value = 45;
int *ptr = &value;
*ptr = value;
ptr =&value;
}
```
Что выведет программа:

a)
```cpp
#include <cstdlib> // нужно для функции exit()
#include <iostream>
int main() {
std::cout << "Hi !\n";
exit(0); // завершает выполнение программы и возвращает операционной системе 0
std::cout << 3;
}
```
Ответ: Hi !

b)
```cpp
#include <iostream>
int main() {
switch (2) {
case 1: // Не совпадает!
std::cout << 1 << '\n'; // пропускается
case 2: // Совпало!
std::cout << 2 << '\n'; // выполнение кода начинается здесь
case 3:
std::cout << 3 << '\n'; // это также выполнится
case 4:
std::cout << 4 << '\n'; // и это
default:
std::cout << 5 << '\n'; // и это
}}
```
Ответ:
2
3
4
5
c)
```cpp
#include <iostream>
const int size = 5;
void Func(int *ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << ptr[i] << '\n';
*ptr = 5;
std::cout << '\n';
for (int i = 0; i < size; ++i)
std::cout << *(ptr++) << '\n';
*ptr = 55;
std::cout << '\n';
}
int main() {
int array[size]{1,3,5,7,9};
Func(array, size);
for (int i = 0; i < size; ++i)
std::cout << array[i] << '\n';
}
```
Ответ:
1
3
5
7
9

5
3
5
7
9

5
3
5
7
9
