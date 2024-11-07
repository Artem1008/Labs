неправильный код 
``` cpp
#include <iostream>
nt main() {
int a ;
int 5 = 4;
int л = 4;
}
```
исправленный код
``` cpp
#include <iostream>

int main() {
int a ;
int b = 4;
int l = 4;
}
```
2)
программный код
``` cpp
#include <iostream>
int main() {
int x = 5;
x = x - 2;
//a
std::cout << x << std::endl; // #a
int y = x;
//b
std::cout << y << std::endl; // #b
//c
std::cout << x + y << std::endl; // #c
//d
std::cout << x << std::endl; // #d
int z;
//e
std::cout << z << std::endl; // #e
}
```
// вывод приложения 3 3 6 3 произвольное

программный код
``` cpp
#include <iostream>
int main() {
int x = 1;
x = x++;
std::cout << x << "\n";
}
```
// вывод приложения
1

программный код
``` cpp
#include <iostream>
int main(){
int x = 1;
std::cout << ++x << "\n";
}
```
//вывод приложения
2

программный код
``` cpp
#include <iostream>
#include <bitset>
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8 = 7;
int main() {
std::bitset<8> bits(0x4);
bits.set(option_1);
bits.flip(option_3);
bits.reset(option_7);
std::cout << "Bit 1 has value: " << bits.test(option_1) << '\n';
std::cout << "Bit 3 has value: " << bits.test(option_3) << '\n';
std::cout << "Bit 7 has value: " << bits.test(option_7) << '\n';
std::cout << "All the bits: " << bits << '\n';
}
```
//вывод приложения
1 0 0 0000 0001 

программный код
``` cpp
#include <iostream>
int main() {
uint8_t a(1), b(1), c(3);
a = a << 1;
printf("a: %d \n", a);
b <<= 1;
printf("b: %d \n", b);
c |= 1;
printf("c: %d \n", c);
}
```
//вывод приложения
2 2 3

программный код
``` cpp
#include <iostream>
int main() {
int x = (08); 
std::cout << "x: " << x << std::endl;
int y = 0x5;
std::cout << "y: " << y << std::endl;
int bin(0);
bin = 0b101;
std::cout << "bin 0b101: " << bin << std::endl;
}
``` 
//Ошибка! в 8-ой системк не может быть 8

программный код
``` cpp
#include <iostream>
int main() {
int x{8};
std::cout << "hex: " << std::hex << x << std::endl;
std::cout << "oct: " << std::oct << x << std::endl;
std::cout << "dec: " << std::dec << x << std::endl;
}
``` 
//вывод приложения
8 10 8

//3
a) (true или false):
(true && true) || false Ответ: true
(false && true) || true  Ответ: true
(false && true) || false || true Ответ: false
(5 > 6 || 4 > 3) && (7 > 8)  Ответ: false
!(7 > 6 || 3 > 4) Ответ: false
b) Какой результат 0110 >> 2 в двоичной системе счисления? Ответ: 0001
c) Какой результат 5 & 12 в десятичной системе счисления? Ответ: 4
d) Какой результат 5 ^ 12 в десятичной системе счисления? Ответ: 9
e) Конвертируйте двоичное число 0100 1101 в десятичную систему счисления Ответ: 77
