1) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
int main() {
    time_t now = time();
    char* dt = ctime(now);
    cout << "The local date and time is: " << dt << endl;
    tm *gmtm = gmtime();
    dt = asctime(gmtm);
    cout << "The UTC date and time is:"<< dt << endl;
}
```
Рабочий вариант
```cpp
#include <ctime>
#include <iostream>

int main() {
    time_t now = time(NULL);
    char* dt = ctime(&now);
    std::cout << "The local date and time is: " << dt <<  std::endl;
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
     std::cout << "The UTC date and time is:"<< dt << std:: endl;
}
```
2) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
int main() {
    auto current_time = chrono::system_clock::now();
    std::time current_time_t = chrono::system_clock(current_time);
    std::cout << "current time is: " << ctime(current_time_t);
}
```
Рабочий вариант
```cpp
#include <chrono>
#include <iostream>

int main() {
    auto current_time = std::chrono::system_clock::now();
    std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_time);
    std::cout << "current time is: " << ctime(&current_time_t);
}
```
3) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя. Вывод приложения и время выполнения,
например на моей машине, такой:
first: operation time: 4000 ms
```cpp
class cLogDuration {
    cLogDuration(std::string id)
        : id_(std::move(id)) {
    }
    ~cLogDuration() {
        const auto end_time = std::chrono::steady_clock;
        const auto dur = end_time - start_time_;
        cout << id_ << ": ";
        std::cout << "operation time"
                  << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur)
                  << " ms" << std::endl;
    }
    std::chrono::duration <int, std::ratio<1,1>> seconds;
    void sleep(uint xsec) {
        seconds s{xsec};
        this_thread::sleep_for();
    }
private:
    const std::string id_;
    const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock;
};
int main() {
    LogDuration LogDuration("first");
    LogDuration.sleep(4);
}
```
Рабочий вариант
```cpp
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

class cLogDuration {
public:
    cLogDuration(std::string id): id_(std::move(id)), start_time_(std::chrono::steady_clock::now()) {}
    ~cLogDuration()
    {
        const auto end_time = std::chrono::steady_clock::now();
        const auto dur = end_time - start_time_;
        std::cout << id_ << ": ";
        std::cout << "operation time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
                  << " ms" << std::endl;
    }
    typedef unsigned int uint;
    typedef  std::chrono::duration <int, std::ratio<1,1>> seconds;
    void sleep(uint xsec) {
        seconds s{xsec};
        std::this_thread::sleep_for(s);
    }
private:
    const std::string id_;
    const std::chrono::steady_clock::time_point start_time_;
};
int main() {
    cLogDuration LogDuration("first");
    LogDuration.sleep(4);
    return 1;
}
```
4) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя. Вывод приложения и время выполнения,
например на моей машине, такой:
Fibonacci(42): 267914296
Elapsed time: 1.61558s
```cpp
long Fibonacci(unsigned ) {
    return n < 2 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main() {
    const auto start{std::chrono::steady_clock};
    
    const auto fb{Fibonacci(42)};
    const auto end{std::chrono::steady_clock};
    const std::chrono::duration<double> elapsed_seconds{end - start};
    std::cout << "Fibonacci(42): " << fb << "\nElapsed time: ";
    std::cout << elapsed_seconds<< "s\n"; // < C++20
    //std::cout << elapsed_seconds << '\n'; // > C++20's
}
```
Рабочий вариант
```cpp
#include <chrono>
#include <iostream>

long Fibonacci(unsigned int n) {
    return n < 2 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main() {
    const auto start{std::chrono::steady_clock::now()};

    const auto fb{Fibonacci(42)};
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};
    std::cout << "Fibonacci(42): " << fb << "\nElapsed time: ";
    std::cout << elapsed_seconds.count()<< "s\n"; // < C++20
    //std::cout << elapsed_seconds << '\n'; // > C++20's
}
```
5) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
template <T> class Array {
    Array(unsigned size) : data{ new T [size] } {}
    ~Array(){
        if(data){
            std::cout << "Freeing memory..." << std::endl;
            delete data;
        }
    }
    Array(const Array&) = delete;
    Array operator=(const Array&) = delete;
    T& operator(unsigned index) { return data[index]; }
    T* get() const { return data; }
    T* release(){
        int* result = data;
        data = nullptr;
        return result;
    }
private:
    T* data;
}
int main() {
    const unsigned count {5};
    Array values{count};
    for (unsigned i {}; i < count; ++i) {
        values[i] = i;
    }
    for (unsigned i {}; i < count; ++i) {
        std::cout << values[i] << "\t";
    }
    std::cout << std::endl;
```
Рабочий вариант
```cpp
#include <iostream>

template <class T>
class Array {
public:
    Array(size_t size): data{ new T [size] } {}
    ~Array(){
        if(data){
            std::cout << "Freeing memory..." << std::endl;
            delete[] data;
        }
    }
    Array(const Array&) = delete;
    Array operator=(const Array&) = delete;
    T& operator[](unsigned int index) { return data[index]; };
    T* get() const { return data; }
    T* release(){
        int* result = data;
        data = nullptr;
        return result;
    }
private:
    T* data;
};
int main() {
    const size_t count {5};
    Array<unsigned int> values{count};
    for (unsigned int i {}; i < count; ++i)
    {
        values[i] = i;
    }
    for (unsigned i {}; i < count; ++i) {
        std::cout << values[i] << "\t";
    }
    std::cout << std::endl;
    return 1;
}

```
6) Найдите ошибки в «точке входа»:
```cpp
#include <iostream>
void print(const std::string&& text) {
    std::cout << text << std::endl;
}
int main() {
    print("hello");
    print(message);
}
```
Рабочий вариант
```cpp
#include <iostream>
void print(const std::string&& text) {
    std::cout << text << std::endl;
}
int main() {
    print("hello");
    print("message");
    return 1;
}
```
7) Найдите ошибки в «точке входа»: Вывод приложения должен быть такой:
In f(const MemBlck&). This version can't modify the parameter.
In f(MemBlck&&). This version can modify the parameter.
```cpp
#include <iostream>
using namespace std;
class MemBlck {
};
void f(const MemBlck&) {
    cout << "In f(const MemBlck&). This version can't modify the parameter." << endl;
}
void f(MemBlck&&) {
    cout << "In f(MemBlck&&). This version can modify the parameter." << endl;
}
int main() {
    
    MemBlck block;
    f();
    f();
}
```
Рабочий вариант
```cpp
#include <iostream>
using namespace std;
class MemBlck {
};
void f(const MemBlck&) {
    cout << "In f(const MemBlck&). This version can't modify the parameter." << endl;
}
void f(MemBlck&&) {
    cout << "In f(MemBlck&&). This version can modify the parameter." << endl;
}
int main() {
    MemBlck block;
    f(block);
    f(std::move(block));
}

```
