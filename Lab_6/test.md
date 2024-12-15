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
2) Найдите ошибки в программе, которая будет заниматься учетом успеваемости студентов в
группе, чтобы программа представленная ниже заработала, можно только добавлять что-то,
но убирать нельзя.
```cpp
class Students {
    public
    // Установка имени студента
    void set_name(string student_name) {
    name = student_name;
}
    // Получение имени студента
    std::string get_name() {
    return name;
}
    // Установка фамилии студента
    void set_last_name(std::string student_last_name) {
    last_name = student_last_name;
}
    // Получение фамилии студента
    std::string get_last_name() {
    return last_name;
}
    // Установка промежуточных оценок
    void set_scores(int student_scores[]) {
    for (int i = 0; i < 5; ++i) {
    scores[i] = student_scores[i];
}
}
    // Установка среднего балла
    void set_average_ball(float ball) {
    average_ball = ball;
}
    // Получение среднего балла
    float get_average_ball() {
    return average_ball;
}
    Students();
    private
    // Промежуточные оценки
    int scores[5];
    // Средний балл
    float average_ball;
    // Имя
    std::string name;
    // Фамилия
    std::string last_name;
}
    main() -> int {
    // Создание объекта класса Student
    Students ;
    std::string name;
    string last_name;
    // Ввод имени с клавиатуры
    cout << "Name: ";
    getline(std::cin, name);
    // Ввод фамилии
    std::cout << "Last name: ";
    getline(cin, last_name);
    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);
    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;
    // Ввод промежуточных оценок
    for (int i = 0; i < 5; ++i) {
    std::cout << "Score " << i+1 << ": ";
    std::cin >> scores[i];
    // суммирование
    sum += scores[i];
}
    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);
    // Считаем средний балл
    float average_ball = sum / 5.0;
    // Сохраняем средний балл в объект класса Students
    set_average_ball(average_ball);
    // Выводим данные по студенту
    std::cout << "Average ball for " << student.get_name() << " "
    << student.get_last_name() << " is "
    << student.get_average_ball() << std::endl;
}
```
Рабочий вариант
```cpp
#include <string>
#include <iostream>

class Students {
public:
    Students(){};
    // Установка имени студента
    void set_name(std::string student_name) {
        name = student_name;
    }
    // Получение имени студента
    std::string get_name() {
        return name;
    }
    // Установка фамилии студента
    void set_last_name(std::string student_last_name) {
        last_name = student_last_name;
    }
    // Получение фамилии студента
    std::string get_last_name() {
        return last_name;
    }
    // Установка промежуточных оценок
    void set_scores(int student_scores[]) {
        for (int i = 0; i < 5; ++i) {
            scores[i] = student_scores[i];
        }
    }
    // Установка среднего балла
    void set_average_ball(float ball) {
        average_ball = ball;
    }
    // Получение среднего балла
    float get_average_ball() {
        return average_ball;
    }

private:
    // Промежуточные оценки
    int scores[5];
    // Средний балл
    float average_ball;
    // Имя
    std::string name;
    // Фамилия
    std::string last_name;
};
auto main() -> int {
    // Создание объекта класса Student
    Students student;
    std::string name;
    std::string last_name;
    // Ввод имени с клавиатуры
    std::cout << "Name: ";
    getline(std::cin, name);
    // Ввод фамилии
    std::cout << "Last name: ";
    getline(std::cin, last_name);
    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);
    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;
    // Ввод промежуточных оценок
    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << i+1 << ": ";
        std::cin >> scores[i];
        // суммирование
        sum += scores[i];

    }
    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);
    // Считаем средний балл
    float average_ball = sum / 5.0;
    // Сохраняем средний балл в объект класса Students
    student.set_average_ball(average_ball);
    // Выводим данные по студенту
    std::cout << "Average ball for " << student.get_name() << " "
              << student.get_last_name() << " is "
              << student.get_average_ball() << std::endl;
    return 1;
}
```
3) Исправьте ошибки в программе.
```cpp
#include <iostream>
struct Vec2f {
    float x = 0;
    float y = 0;
    Vec2f (float x, float y) ::x(x)
    , y(y) {
        this.x = x;
        this.y = y;
    }
    float getLength() const {
        const float lengthSquare = x * x + y * y;
        return std::sqrt(lengthSquare);
    }
}vect2f
int main() {
    cout << vect2f.getLength() << '\n';
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <cmath>

struct Vec2f {
    float x = 0;
    float y = 0;
    Vec2f (float x=0, float y=0):x(x)
    , y(y) {}
    float getLength() const {
        const float lengthSquare = x * x + y * y;
        return std::sqrt(lengthSquare);
    }
}vect2f;
int main() {
   std::cout << vect2f.getLength() << '\n';
}
```
4) Исправьте ошибки в программе.
```cpp
class BufferedIO {
public:
    enum IOError { None, Access, General, Erro = -1};
    class Date {
        unsigned short nWeekDay : 3, // 0..7 (3 bits)
        unsigned short nMonthDay : 6, // 0..31 (6 bits)
        unsigned short nMonth : 5, // 0..12 (5 bits)
        unsigned short nYear : 8, // 0..100 (8 bits)
    }
          // Declare nested class BufferedInput.
          class BufferedInput {
            BufferedInput();
            public:
            int read() {}
            int Ngood() {
                return _inputerror == Erro;
            }
            private:
            int _inputerror;
        }
        // Declare nested class BufferedOutput.
        class BufferedOutput {
            BufferedOutput();
        public:
            int Ngood() {
                return _inputerror == Erro;
            }
        private:
            int _inputerror;
        }
    };
        int main() {
            BufferedIO _inputerror;
            BufferedInput buffIn;
            BufferedOutput buffOut;
            std::cout << _inputerror.nWeekDay << '\n';
        }
```
Рабочий вариант
```cpp
#include <iostream>
class BufferedIO {
public:
    enum IOError { None, Access, General, Erro = -1};
    struct Date {
        unsigned short nWeekDay : 3; // 0..7 (3 bits)
        unsigned short nMonthDay : 6; // 0..31 (6 bits)
        unsigned short nMonth : 5; // 0..12 (5 bits)
        unsigned short nYear : 8; // 0..100 (8 bits)
    }data;
    // Declare nested class BufferedInput.
    class BufferedInput {
    public:
        BufferedInput(){};
        int read() {}
        int Ngood() {
            return _inputerror == Erro;
        }
    private:
        int _inputerror;
    };
    // Declare nested class BufferedOutput.
    class BufferedOutput {
    public:
        BufferedOutput(){};
        int Ngood() {
            return _inputerror == Erro;
        }
    private:
        int _inputerror;
    };
};
    int main() {
        BufferedIO _inputerror;
        BufferedIO::BufferedInput buffIn;
        BufferedIO::BufferedOutput buffOut;
        std::cout << _inputerror.data.nWeekDay << '\n';
    }
```
5_2)Исправьте ошибки в программе причем нельзя убирать const у функции getFlag().
Программа должна вывести 4.
```cpp
class X {
    X(int flag) : m_flag(flag) {}
    bool getFlag() const {
        m_accessCount++;
        return m_flag + m_accessCount;
    }
private:
    int m_flag;
    int m_accessCount{0};
};
int main() {
    X x(new X);
    std::cout << x.getFlag << '\n';
}
```
Рабочий вариант
```cpp
#include <iostream>
class X {
public:
    X(int flag=0) : m_flag(flag) {};
    bool getFlag() const {
        m_accessCount++;
        return m_flag + m_accessCount;
    }
private:
    int m_flag;
    static int m_accessCount;
};
int X::m_accessCount=0;
int main() {
    X x(*new X);
    std::cout << x.getFlag() << '\n';
}

```
6) Исправьте ошибки в программе.
```cpp
#include <iostream>
using namespace std;
namespace box {
class Box {
    double length; // Length of a box
    double breadth; // Breadth of a box
    double height; // Height of a box
};
};
int main() {
    Box Box1; // Declare Box1 of type Box
    Box Box2; // Declare Box2 of type Box
    box::Box Box3(new Box); // Declare Box2 of type Box
    double volume = 0.0; // Store the volume of a box here
    // box 1 specification
    box::Box1.height = 5.0;
    box::Box1.length = 6.0;
    box::Box1.breadth = 7.0;
    // box 2 specification
    box::Box2.height = 10.0;
    box::Box2.length = 12.0;
    box::Box2.breadth = 13.0;
    // volume of box 1
    volume = box::Box1.height * box::Box1.length * box::Box1.breadth;
    cout << "Volume of Box1 : " << volume <<endl;
    // volume of box 2
    volume = box::Box2.height * box::Box2.length * box::Box2.breadth;
    cout << "Volume of Box2 : " << volume <<endl;
    delete box::Box3[];
}
```
Рабочий вариант
```cpp
#include <iostream>
using namespace std;
namespace box {
class Box {
public:
    double length; // Length of a box
    double breadth; // Breadth of a box
    double height; // Height of a box
};
};
int main() {
    box::Box Box1; // Declare Box1 of type Box
    box::Box Box2; // Declare Box2 of type Box
    box::Box* Box3(new box::Box); // Declare Box2 of type Box
    double volume = 0.0; // Store the volume of a box here
    // box 1 specification
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;
    // box 2 specification
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;
    // volume of box 1
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Volume of Box1 : " << volume <<endl;
    // volume of box 2
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Volume of Box2 : " << volume <<endl;
    delete Box3;
}
```
7) Исправьте ошибки. Добавьте операторы * & в объявлении указателя на член класса.
```cpp
class Window {
public:
    Window(); // Default constructor.
    Window( int x1, int y1, int x2, int y2 ) {} // Constructor specifying Window size.
    bool SetCaption( const char *szTitle ) { return 0; } // Set window caption.
    const char *GetCaption() {} // Get window caption.
    char *szWinCaption; // Window caption.
};
// Declare a pointer
char Window::*pwCaption = &Window::szWinCaption;
const char * (Window::* pfnwGC)() = Window::GetCaption;
bool (Window:: pfnwSC)( const char * ) = &Window::SetCaption;
Window wMainWindow;
Window pwChildWindow = new Window;
char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);
int main() {
}
```
Рабочий вариант
```cpp
#include <cstring>
class Window {
public:
    Window(); // Default constructor.
    Window( int x1, int y1, int x2, int y2 ) {} // Constructor specifying Window size.
    bool SetCaption( const char *szTitle ) { return 0; } // Set window caption.
    const char *GetCaption() {} // Get window caption.
    char *szWinCaption; // Window caption.
};
// Declare a pointer
//пример из https://learn.microsoft.com/ru-ru/cpp/cpp/pointers-to-members?view=msvc-170
char *Window::*pwCaption = &Window::szWinCaption; // в курсе про это небыло
const char * (Window::* pfnwGC)() = &Window::GetCaption; //в курсе про это небыло
bool (Window:: *pfnwSC)( const char * ) = &Window::SetCaption;// в курсе про это небыло

Window wMainWindow;
Window* pwChildWindow = new Window;
const char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);
int main() {
}
```
