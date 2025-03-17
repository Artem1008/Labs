1) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
class TwoPowerGenrator {
public:
    TwoPowerGenrator(int pow) power(pow) {}
    void reset() { power = 0; }
    int operator{
    return power = 0;
}
int operator(int arg1, int arg2) {
    if (power > 15)
        power = 0;
    return (1 << power++);
}
private
int power;
}
int main () {
    TwoPowerGenrator generate1, generate2;
    std::cout << "[client 1]" << generate1(1,2) << std::endl;
    std::cout << "[client 2]" << generate2() << std::endl;
}
```
Рабочий вариант
```cpp
#include <iostream>
class TwoPowerGenrator {
public:
    TwoPowerGenrator(){};
    TwoPowerGenrator(int pow):power(pow) {}
    void reset() { power = 0; }
    int operator()(){ return power = 0;}

    int operator()(int arg1, int arg2) {
        if (power > 15)
            power = 0;
        return (1 << power++);
    }
private:
    int power;
};
int main () {
    TwoPowerGenrator generate1, generate2;
    std::cout << "[client 1]" << generate1(1,2) << std::endl;
    std::cout << "[client 2]" << generate2() << std::endl;
}

```
2) Сделайте чтобы приложение вывело
1
2
3
4
5
можно только добавлять что-то, но удалять нельзя.
```cpp
```
Рабочий вариант
```cpp
```
3) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
```
Рабочий вариант
```cpp
```
4) Сделайте свой классы (ios, istream, и тд) и реализуйте наследование как показано на
рисунке иерархии классов потокового ввода-вывода:

![image](https://github.com/user-attachments/assets/1652645b-9df2-4bd5-b647-c2f623a3d8e8)
```cpp
```
Рабочий вариант
```cpp
```
5) Сделайте свой классы и реализуйте наследование как показано на рисунке иерархии
классов:
![image](https://github.com/user-attachments/assets/8b968fc2-5cfc-401f-9986-4d49f1e320f9)
```cpp
```
Рабочий вариант
```cpp
```
6) Допустим, есть онлайн-магазин с делающий различные принты на вещах. Есть три вида
товаров: футболки, кружки и блокноты. Задача — сделать так, чтобы все их можно было
складывать в корзину и сайт каждый раз автоматически выдавал покупателю сообщение:
«Товар такой-то добавлен в корзину». Как это сделать?
Есть два варианта. Можно писать свою версию метода «добавить в корзину» на каждую
категорию товара — но это долго, да и код получится неопрятный. А можно написать
один полиморфный метод, а потом использовать его для каждого нового объекта — и вот
это как раз наш случай. Допишите необходимый код чтобы программа выводила.
```cpp
```
Рабочий вариант
```cpp
```
