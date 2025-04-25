1) Необходимо чтобы при построении проекта компилятор выдал предупреждения представленные ниже (Этот метод устарел, используйте любой другой подход), можно
только добавлять что-то, но убирать нельзя.
```cpp
[[deprecated]]
int multiply(int a, int b) {
    return a * b;
}
int main() {
    int a = 2, b = 4;
    multiply(a, b);
}
```
Рабочий вариант
```cpp
[[deprecated("Этот метод устарел, используйте любой другой подход")]]
int multiply(int a, int b) {
    return a * b;
}
int main() {
    int a = 2, b = 4;
    multiply(a, b);
}
```
2) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
только добавлять что-то, но убирать нельзя.
```cpp
template <>
class value_category {
public:
    value_category () { std::cout << "#expr"<< " is a: " << value << '\n'; }
    static constexpr char const* value = "prvalue";
};
template <>
class value_category<T&> {
public:
    value_category () { std::cout << "#expr"<< " is a: " << value << '\n'; }
    static constexpr char const* value = "lvalue";
};
template <>
class value_category<T&&> {
public:
    value_category () { std::cout << "#expr"<< " is a: " << value << '\n'; }
    static constexpr char const* value = "xvalue";
};
int main() {
    ::value_category<decltype()> a;
    ::value_category<decltype()> b;
    ::value_category<decltype()> c;
}
```
Рабочий вариант
```cpp
#include <iostream>
template <typename T>
class value_category {
public:
    value_category () { std::cout << "#expr"<< " is a: " << value << '\n'; }
    static constexpr char const* value = "prvalue";
};

template <typename T>
class value_category<T&> {
public:
    value_category () { std::cout << "#expr"<< " is a: " << value << '\n'; }
    static constexpr char const* value = "lvalue";
};
template <typename T>
class value_category<T&&> {
public:
    value_category () { std::cout << "#expr"<< " is a: " << value << '\n'; }
    static constexpr char const* value = "xvalue";
};
int main() {
    ::value_category<decltype(int())> a;
    ::value_category<decltype("a")> b;
    ::value_category<decltype(std::move("a"))> c;
}
```
3) Сделайте обработку аргументов командной строки чтобы вывод был следующим.
   
   ![image](https://github.com/user-attachments/assets/1eaf1205-1376-4f1e-91d6-2091e877fa9d)
   
Рабочий вариант
```cpp
#include <iostream>
int main(int argc, char *argv[])
{
    if(argc<1) return 1;
    for(int i=1;i<argc;++i)
   {
        std::cout<<"Argument "<<i-1<<" : "<<argv[i]<<'\n';
    }
}
```
4) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
void foo() {throw -1;}
void boo() {}
void goo() noexcept {}
struct S{
};
constexpr bool a{ noexcept() };
constexpr bool b{ noexcept() };
constexpr bool c{ noexcept() };
constexpr bool d{ noexcept() };
constexpr bool e{ noexcept() };
int main() {
    cout << a << '\n';
    cout << b << '\n';
    cout << c << '\n';
    cout << d << '\n';
    cout << e << '\n';
}
```
Рабочий вариант
```cpp
#include <iostream>
// проверяемых объекта 4 а переменных 5
void foo() {throw -1;}
void boo() {}
void goo() noexcept {}
struct S{
};
constexpr bool a{ noexcept(goo()) };
constexpr bool b{ noexcept(S()) };
constexpr bool c{ noexcept(int()) };
constexpr bool d{ noexcept(foo()) };
constexpr bool e{ noexcept(boo()) };
int main() {
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';
    std::cout << e << '\n';
}

```
5) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя. Добавьте что-то в класс Auto_ptr1 чтобы в стоке Auto_ptr1<Item> item2(item1); была ошибка компиляции не позволяющее данное
```cpp
template<class>
class Auto_ptr1{
    T* m_ptr;
public:
    Auto_ptr1(T* ptr=nullptr) :m_ptr(ptr) {}
    ~Auto_ptr1() {
        delete m_ptr;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};
class Item {
public:
    Item() { cout << "Item acquired\n"; }
    ~Item() { cout << "Item destroyed\n"; }
};
int main() {
    Auto_ptr1<Item> item1(new Item);
    Auto_ptr1<Item> item2(item1);
}

```
Рабочий вариант
```cpp
#include <iostream>

template<class T>
class Auto_ptr1{
    T* m_ptr;
public:
    Auto_ptr1(T* ptr=nullptr) :m_ptr(ptr) {}
    Auto_ptr1(const Auto_ptr1& obj)=delete;
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};
class Item {
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }
};
int main() {
    Auto_ptr1<Item> item1(new Item);
    Auto_ptr1<Item> item2(item1);
}

```
6) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
int test(double x, double y);
int test(int x, int y);
int test(char x, int y);
int main() {
    std::cout << decltype(test) << std::endl;
}
```
Рабочий вариант
```cpp
#include <iostream>

int test(double x, double y);
int test(int x, int y);
int test(char x, int y);
int main()
{
    std::cout << typeid(decltype(test(1,2))).name() << std::endl;
}
```
7) Сделайте вывод текущего времени в таком формате: Tue Feb 10 17:13:25 2024 +07
 Рабочий вариант
```cpp  
#include <iostream>
#include <chrono>

int main()
{
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    std::tm* timeinfo = std::localtime(&end_time);

    char buffer[100];
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y %z", timeinfo);

    std::cout << buffer << std::endl;

    return 0;
}
```
