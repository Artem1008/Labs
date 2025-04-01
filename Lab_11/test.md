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

```
4) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя. Вывод приложения и время выполнения,
например на моей машине, такой:
Fibonacci(42): 267914296
Elapsed time: 1.61558s
```cpp
```
Рабочий вариант
```cpp

```
