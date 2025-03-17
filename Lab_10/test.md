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
#include <iostream>
void printer(auto func) {
    func();
}
class Message {
public:
    Message(const std::string& text): text{text} {}
    void print() {
        printer([this](){ std::cout << text << std::endl;});
    }
private:
    std::string text;
};
int main() {
    auto hello2 ([](){std::cout << "4" << std::endl;});
    Message hello{"2"};
    auto hello3 { [](){std::cout << "1" << std::endl;} };
    auto hello1 = [](){std::cout << "3" << std::endl;};
    hello3();
    [](const std::string& text){std::cout << text << std::endl;} ("5");
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <functional>
class Message;
void printer(std::function<void()> func) {
    func();
}
class Message {
public:
    Message(const std::string& text): text{text} {}
    void print() {
        printer([this](){ std::cout << text << std::endl;});
    }
private:
    std::string text;
};

int main() {
    auto hello2 ([](){std::cout << "4" << std::endl;});
    Message hello{"2"};
    auto hello3 { [](){std::cout << "1" << std::endl;} };
    auto hello1 = [](){std::cout << "3" << std::endl;};
    hello3();
    hello.print();
    hello1();
    hello2();
    [](const std::string& text){std::cout << text << std::endl;} ("5");
}
```
3) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
class Sum {
public:
    int operator()(int, int){ return a + b;}
}
int subtract(int, int){return a - b;}
std::function<int(int,int)> operation;
int main(){
    operation = Sum{};
    std::cout << operation(10) << endl;
    operation = subtract;
    std::cout << operation(10, 6) << endl;
    auto multiply = [](int a, int b){return a * b;};
    operation = multiply;
    cout << operation(10, 6) << endl;
    auto mLambda = [](int v) -> int {
        std::cout << "mLambda: " << v << '\n';
        return v;
    }
    mLambda(5);
    auto abs=[](int a)->int{
        return (a>0)?(a):(-a);
    };
    std::cout << "abs: " << abs << '\n';
    auto gtc=[](){
        puts("Press enter to continue...");
        getchar();
    };
    std::cout << "abs: " << abs(5) << "\n";
    cout << "abs: " << abs() << "\n";
    gtc();
}

```
Рабочий вариант
```cpp
#include <iostream>
#include <functional>
class Sum {
public:
    int operator()(int a, int b){ return a + b;}
    int operator()(int a){ return a;}
};
int subtract(int a, int b){return a - b;}
std::function<int(int,int)> operation;
std::function<int(int)> operation2;
int main(){
    operation2 = Sum();
    std::cout << operation2(10) << std::endl;
    operation = subtract;
    std::cout << operation(10, 6) <<std:: endl;
    auto multiply = [](int a, int b){return a * b;};
    operation = multiply;
    std::cout << operation(10, 6) <<std:: endl;
    auto mLambda = [](int v) -> int {
        std::cout << "mLambda: " << v << '\n';
        return v;
    };
    mLambda(5);
    auto abs=[](int a=0)->int{
        return (a>0)?(a):(-a);
    };
    std::cout << "abs: " << abs << '\n';
    auto gtc=[](){
        puts("Press enter to continue...");
        getchar();
    };
    std::cout << "abs: " << abs(5) << "\n";
    std::cout << "abs: " << abs() << "\n";
    gtc();
}
```
4) Сделайте свой классы (ios, istream, и тд) и реализуйте наследование как показано на
рисунке иерархии классов потокового ввода-вывода:

![image](https://github.com/user-attachments/assets/1652645b-9df2-4bd5-b647-c2f623a3d8e8)
```cpp
class ios
{
};
class istream:public ios
{
};
class ostream:public ios
{
};
class ifstream:public istream
{
};
class istringstream:public istream
{
};
class iostream:public istream,public ostream
{
};
class ofstream:public ostream
{
};
class ostringstream:public ostream
{
};
class fstream:public iostream
{
};
class stringstream:public iostream
{
};
int main(){
}
```
5) Сделайте свой классы и реализуйте наследование как показано на рисунке иерархии
классов:
![image](https://github.com/user-attachments/assets/8b968fc2-5cfc-401f-9986-4d49f1e320f9)
```cpp
class DerivedClassOne
{
public:
    DerivedClassOne()=default;
    virtual ~DerivedClassOne()=default;
};
class DerivedClassSecond
{
public:
    DerivedClassSecond()=default;
    virtual ~DerivedClassSecond()=default;
};
class DerivedClass:public DerivedClassOne,public DerivedClassSecond
{
public:
    DerivedClass()=default;
    virtual ~DerivedClass()=default;
};
class BaseClass:public DerivedClassSecond
{
public:
    BaseClass()=default;
    virtual ~BaseClass()=default;
};
class BaseClassOne:public DerivedClass
{
public:
    BaseClassOne()=default;
    virtual ~BaseClassOne()=default;
};
class BaseClassSecond:public DerivedClass
{
public:
    BaseClassSecond()=default;
    virtual ~BaseClassSecond()=default;
};
int main(){
}
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
#include <iostream>
#include <string>
class Product { // Объявляем класс Товар
public:
    std::string name; // Указываем свойство. Название
    // Создаём метод. Добавить в корзину.
    // Virtual означает, что метод потом можно будет дополнить под нужды конкретного товара.
public:
    virtual void AddToCart() {
        std::cout << "Товар: " << name << " добавлен в корзину";
    }
};
class Cup : public Product { // Создаём класс. Кружка.
public:
    int volume; // Вводим дополнительное свойство. Объём.
    void AddToCart() {
        // Override переопределяем метод
        //AddToCart и добавляем ему новую функциональность
        std::cout << "Кружка: " + name + ", объёмом "
                  << volume << " мл добавлена в корзину\n";
    }
};
class Note : public Product { // Создаём класс.Блокнот.
public:
    int pages; // Добавляем свойство.Количество страниц.
    void AddToCart() {
        std::cout << "Блокнот: " + name + ", на " << pages <<
                     ", страниц добавлен в корзину\n";
    }
};
class Shirt : public Product { // Создаём класс.Футболка.
public:
    int size; // Добавляем свойство.Размер.
    void AddToCart() {
        std::cout << "Футболка: " + name + ", размером "
                  << size << ", добавлена в корзину\n";
    }
};
int main() {
    // Создаём объекты для каждого товара
    //...
    // Создаём массив из всех трёх объектов
    //...
    // С помощью цикла вызываем метод. Добавить в корзину, для каждого товара
    for(int i = 0; i < 3; ++i) {
        pgoods[i]->AddToCart();
    }
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <string>
class Product { // Объявляем класс Товар
public:
    std::string name; // Указываем свойство. Название
    // Создаём метод. Добавить в корзину.
    // Virtual означает, что метод потом можно будет дополнить под нужды конкретного товара.
    Product(std::string _name):name(_name){}
public:
    virtual void AddToCart() {
        std::cout << "Товар: " << name << " добавлен в корзину\n";
    }
};
class Cup : public Product { // Создаём класс. Кружка.
public:
    int volume; // Вводим дополнительное свойство. Объём.
     Cup(int _volume,std::string _name):Product(_name),volume(_volume){}
 /*   void AddToCart() {
        // Override переопределяем метод
        //AddToCart и добавляем ему новую функциональность
        std::cout << name + ", объёмом "
                  << volume << " мл добавлена в корзину\n";
    }*/
};
class Note : public Product { // Создаём класс.Блокнот.
public:
    int pages; // Добавляем свойство.Количество страниц.
    Note(int _pages,std::string _name):Product(_name),pages(_pages){}
 /*   void AddToCart() {
        std::cout << name + ", на " << pages <<
                     ", страниц добавлен в корзину\n";
    }*/
};
class Shirt : public Product { // Создаём класс.Футболка.
public:
    int size; // Добавляем свойство.Размер.
    Shirt(int _size,std::string _name):Product(_name),size(_size){}
   /* void AddToCart() {
        std::cout << name + ", размером "
                  << size << ", добавлена в корзину\n";
    }*/
};
int main() {
   Product* pgoods[3];
    pgoods[0]= new Cup(1,"Кружка");
    pgoods[1]= new Note(20,"Блокнот");
    pgoods[2]= new Shirt(36,"Футболка");

    for(int i = 0; i < 3; ++i) {
        pgoods[i]->AddToCart();
    }
}

```
