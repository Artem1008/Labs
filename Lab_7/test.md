1) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только
добавлять что-то, но убирать нельзя.
```cpp
#include <iostream>
class Integer {
    Integer(int number) {
        value=number;
        std::cout << "Object created." << std::endl;
    }
    int getValue() { return value; }
    void setValue(int number) { value = number; }
    void print() {
        std::cout << "Value: " << value << std::endl;
    }
    private
    int value;
}
    int main() {
    Integer integer;
    setValue(3);
    std::cout << "Value: " << getValue() << std::endl;
}
#include<iostream>
```
Рабочий вариант
```cpp
#include <iostream>
class Integer {
public:
    Integer(int number=0)
    {
        value=number;
        std::cout << "Object created." << std::endl;
    }
    int getValue() { return value; }
    void setValue(int number) { value = number; }
    void print() {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};
int main() {
    Integer integer;
    integer.setValue(3);
    std::cout << "Value: " << integer.getValue() << std::endl;
}
```
