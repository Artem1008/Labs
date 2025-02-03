1) Заполните таблицы 1 и 2, систематизирующие информацию о классах STL. Не стесняйтесь занимать место на страницах; убедитесь, что подробно
прочитали вопросы в левом столбце. Информация о классе pair приведена в качестве образца.

Таблица 1.

| Название класса | Пара (pair) | Массив (array) | Вектор (vector) | Список (list) |
| ---             | ---         | ---            | ---             | ---           |
| Какую библиотеку подключить | \<utility\> | \<array\> | \<vector\> | \<list\> |
| Синтаксис инициализации | std::pair\<std::string,std::string\> myName(“Ivan”,“Ivanov”); | std::array\<int,4\> point = {1,2,3,4}; | std::vector\<int\> ={1,2,3,4}| std::list\<int\> list = {1,2,3,4} | 
| Какими способами можно получить доступ к произвольному элементу класса? | В паре может быть всего два элемента. Доступ получается с помощью .first для первого элемента и .second для второго. Например: myName.first = “Ivan”, myName.second = “Ivanov”.| к любому элементу по индексу(итератор произвольно доступа) | к любому элементу по индексу(итератор произвольно доступа) | перебор элементов до нужного (двунаправленый итератор)| 
| Можно ли добавлять новые элементы? Если да, то каким образом? С какой стороны разрешено их добавлять? | Нельзя.| | | | 
| Можно ли удалять элементы? Если да, то каким образом? С какой стороны разрешено их удалять?| Нельзя. | | | | 
| Каким способом можно узнать количество элементов в классе? | Класс «пара» всегда подразумевает наличие двух элементов. | | | | 
| Предлагает ли класс автоматическую сортировку данных? Если да, то какую? | Не предлагает. | | | | 
| При каком условии объект этого класса может содержать два или более одинаковых значений? | Всегда может. | | | | 
| Какие специфичные функции можно применять к классу? Что они делают? (только из того, что мы изучали на лекции) | Функция std::make_pair(value, value) позволяет быстро создавать пары из двух значений. | | | | 

Таблица 2.

| Название класса | Односвязный список (forward list) | Дек (deque) | Словарь (map/multimap) | Набор (set/multiset) |
| ---             | ---         | ---            | ---             | ---           |
| Какую библиотеку подключить | <utility> | | | |
| Синтаксис инициализации | std::pair <std::string, std::string> myName(“Ivan”,“Ivanov”); | | | | 
| Какими способами можно получить доступ к произвольному элементу класса? | В паре может быть всего два элемента. Доступ получается с помощью .first для первого элемента и .second для второго. Например: myName.first = “Ivan”, myName.second = “Ivanov”.| | | | 
| Можно ли добавлять новые элементы? Если да, то каким образом? С какой стороны разрешено их добавлять? | Нельзя.| | | | 
| Можно ли удалять элементы? Если да, то каким образом? С какой стороны разрешено их удалять?| Нельзя. | | | | 
| Каким способом можно узнать количество элементов в классе? | Класс «пара» всегда подразумевает наличие двух элементов. | | | | 
| Предлагает ли класс автоматическую сортировку данных? Если да, то какую? | Не предлагает. | | | | 
| При каком условии объект этого класса может содержать два или более одинаковых значений? | Всегда может. | | | | 
| Какие специфичные функции можно применять к классу? Что они делают? (только из того, что мы изучали на лекции) | Функция std::make_pair(value, value) позволяет быстро создавать пары из двух значений. | | | | 

2) Разместите адреса (заполните адресное пространство)(заполните следующую таблицу), для примера представленного ниже:

| 0x402db0 | text | 
| 0x404010 | Data | 
| 0x408030 | Data (bss) | 
| 0x60fdf0 | Heap | 
| 0x1031790 | Stack | 

```cpp
#include <iostream>
#include <vector>
#include <array>
const int CONSTT{3};
int g_val{4};
int g_val1;
int main () {
int v = 3;
std::vector<int> vk;
vk.push_back(1);
vk.push_back(2);
vk.push_back(3);
std::array<int,3> ak;
std::cout << "\n1 Heap is at " << &vk;
std::cout << "\n2 Stack is at " << &vk.front();
std::cout << "\n3 Heap is at " << &vk;
std::cout << "\n4 Heap is at " << &ak.front();
std::cout << "\n5 Heap is at " << &v;
std::cout << "\n6 Stack is at " << malloc(8);
std::cout << "\n7 Data is at " << &g_val;
std::cout << "\n8 bss is at " << &g_val1;
std::cout << "\n9 Data is at " << &CONSTT;
std::cout << "\n10 Text is at " << reinterpret_cast<void*>(main) << "\n";
}
```

3) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
class Dollars {
private:
    int m_dollars;
public:
    Dollars(int dollars) { m_dollars = dollars; }
    // выполняем Dollars + Dollars через дружественную функцию
    friend Dollars operator+(const Dollars &d1, const Dollars &d2);
    // выполняем Dollars - Dollars через дружественную функцию
    Dollars operator-(const Dollars &d1, const Dollars &d2);
    Dollars operator*(const Dollars &d1, const Dollars &d2);
    Dollars operator/(const Dollars &d1, const Dollars &d2);
    int getDollars() const { return m_dollars; }
}
// Примечание: Эта функция не является методом класса!
Dollars +(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator+(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars + d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator-(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator-(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars - d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator*(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator*(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars * d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars /(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator/(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars / d2.m_dollars);
}
int main() {
    Dollars dollars1();
    Dollars dollars2();
    std::cout << "+: " << (dollars1 + dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "-: " << (dollars1 - dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "*: " << (dollars1 * dollars2).getDollars() << " dollars." << std::endl;
    
    std::cout << "/: " << (dollars1 / dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "/: " << (dollars1 + 3).getDollars() << " dollars." << std::endl;
}
```
Рабочий вариант
```cpp
#include <iostream>

class Dollars {
private:
    int m_dollars;
public:
    Dollars(int dollars=0) { m_dollars = dollars; }
    // выполняем Dollars + Dollars через дружественную функцию
    friend Dollars operator+(const Dollars &d1, const Dollars &d2);
    // выполняем Dollars - Dollars через дружественную функцию
    friend Dollars operator-(const Dollars &d1, const Dollars &d2);
    friend Dollars operator*(const Dollars &d1, const Dollars &d2);
    friend Dollars operator/(const Dollars &d1, const Dollars &d2);
    int getDollars() const { return m_dollars; }
};
// Примечание: Эта функция не является методом класса!
Dollars operator +(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator+(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars + d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator-(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator-(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars - d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator*(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator*(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars * d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator/(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator/(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars / d2.m_dollars);
}
int main() {
    Dollars dollars1;
    Dollars dollars2;
    std::cout << "+: " << (dollars1 + dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "-: " << (dollars1 - dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "*: " << (dollars1 * dollars2).getDollars() << " dollars." << std::endl;

    std::cout << "/: " << (dollars1 / dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "/: " << (dollars1 + 3).getDollars() << " dollars." << std::endl;
}
```
4) Сделайте код программы рабочим, причем элементы массива выводим с использованием цикла foreach.
```cpp
#include <iostream>
int sumArray(int array) {
    int result = 0;
    for (const auto &number : array)
        result += number;
    return result;
}
int main() {
    int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
    std::cout << sumArray(array);
    return 0;
}
```
Рабочий вариант
```cpp
#include <iostream>
int sumArray(int (&array)[7]) {
    int result = 0;
    for (const auto &number : array)
        result += number;
    return result;
}
int main() {
    int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
    std::cout << sumArray(array);
    return 0;
}

```
4) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
void (*pfunc)();
void print(int i) {
    std::cout << i << " ";
}
int main() {
    int data[]{1,2,3,4,5};
    int len = sizeof(data)/sizeof(data[0]);
    std::for_each(data, data+len, pfunc);
    return 0;
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <algorithm>

void (*pfunc)(int );
void print(int i) {
    std::cout << i << " ";
}
int main() {
    int data[]{1,2,3,4,5};
    pfunc=print;
    int len = sizeof(data)/sizeof(data[0]);
    std::for_each(data, data+len, pfunc);
    return 0;
}
```
5) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
class Number {
private:
    int m_number;
    Number(int number=0): m_number(number) {}
    Number& operator++();
    Number& operator--();
    Number operator++(int);
    Number operator--(int);
    friend std::ostream& operator<< (std::ostream &out, const Number &n);
}
Number ::operator++() {
    ++m_number;
    return *this;
}
Number operator--(){
    --m_number;
    
    return *this;
}
Number Number::operator++(int){
    Number temp(m_number);
    ++(*this);
    return temp;
}
Number Number::operator--(int){
    Number temp(m_number);
    --(*this);
    return temp;
}
std::ostream& operator<< (std::ostream &out, const Number &d){
    out << d.m_number << "\n";
    return out;
}
int main(){
    Number number(6);
    std::cout << ++number;
    std::cout << number++;
    std::cout << number;
    std::cout << --number;
    std::cout << number--;
    std::cout << number;
}
```
Рабочий вариант
```cpp
#include <iostream>

class Number {
private:
    int m_number;
public:
    Number(int number=0): m_number(number) {}
    Number& operator++();
    Number& operator--();
    Number operator++(int);
    Number operator--(int);
    friend std::ostream& operator<< (std::ostream &out, const Number &n);
};
Number& Number::operator++() {
    ++m_number;
    return *this;
}
Number& Number::operator--(){
    --m_number;

    return *this;
}
Number Number::operator++(int){
    Number temp(m_number);
    ++(*this);
    return temp;
}
Number Number::operator--(int){
    Number temp(m_number);
    --(*this);
    return temp;
}
std::ostream& operator<< (std::ostream &out, const Number &d){
    out << d.m_number << "\n";
    return out;
}
int main(){
    Number number(6);
    std::cout << ++number;
    std::cout << number++;
    std::cout << number;
    std::cout << --number;
    std::cout << number--;
    std::cout << number;
}
```
6) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
    for (auto iter = begin(); iter != end(); iter++) {
        std::cout << *iter << "\t";
    }
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        std::cout << *iter << "\t";
    }
}
```
7) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
int main() {
    std::list<int> li;
    for (int nCount = 0; nCount < 5; ++nCount)
        li.push_back(nCount);
    std::list<int>::iter it;
    it = min_element(li.begin(), li.end());
    std::cout << "min: " << it << ' ';
    it = max_element(li.begin(), li.end());
    std::cout << "max: " << it << ' ';
}
```
Рабочий вариант
```cpp
#include <algorithm>
#include <iostream>
#include <list>

int main() {
    std::list<int> li;
    for (int nCount = 0; nCount < 5; ++nCount)
        li.push_back(nCount);
    std::list<int>::iterator it;
    it = min_element(li.begin(), li.end());
    std::cout << "min: " << *it << ' ';
    it = max_element(li.begin(), li.end());
    std::cout << "max: " << *it << ' ';
}
```
