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
