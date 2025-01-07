1) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
std::mutex g_lock;
void threadFunction() {
std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
g_lock.unlock();
}
int main() {
srand((unsigned int)time(0));
std::thread t1(threadFunction);
std::thread t2(threadFunction);
std::thread t3();
return 0;
}
```
Рабочий вариант
```cpp
#include <mutex>
#include <thread>
#include <iostream>

std::mutex g_lock;
void threadFunction() {
g_lock.lock();
std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
g_lock.unlock();
}
int main() {
srand((unsigned int)time(0));
std::thread t1(threadFunction);
std::thread t2(threadFunction);
std::thread t3(threadFunction);
t1.join();
t2.join();
t3.join();
return 0;
}
```
2) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
using namespace std;
int main() {
try {
domain_error("Your domain is in error!");
}
(const exception& e) {
cerr << "Caught: " << e.what() << endl;
cerr << "Type: " << typeid(e).name() << endl;
}
}
```
Рабочий вариант
```cpp
#include <iostream>
using namespace std;
int main() {
    try {
        throw domain_error("Your domain is in error!");
    }
    catch (const exception& e) {
        cerr << "Caught: " << e.what() << endl;
        cerr << "Type: " << typeid(e).name() << endl;
    }
}
```
3) Перенесите рисунок представленный ниже на программный код t задается
пользователем в сек:
```cpp
![image](https://github.com/user-attachments/assets/25eba7c7-13e2-427e-adfd-da7406d2fb1b)
```
Рабочий вариант
```cpp
#include <thread>
#include <mutex>
#include <iostream>

std::mutex g_lock;
void threadFunction() {
g_lock.lock();
std::this_thread::sleep_for(std::chrono::seconds(7));
g_lock.unlock();
}
int main() {
std::cout<<"11111\n";
std::thread t1(threadFunction);
t1.join();
std::cout<<"22222";
return 0;
}
```
4) Исправьте ошибки в программе.
```cpp
```
Рабочий вариант
```cpp
```
5) Исправьте ошибки в программе.
```cpp
```
Рабочий вариант
```cpp
```
6) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
```
Рабочий вариант
```cpp
```
7) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
```
Рабочий вариант
```cpp
```
8) Найдите ошибки в коде, и сделайте чтобы вывод в терминале был: new faild.
```cpp
```
Рабочий вариант
```cpp
```
