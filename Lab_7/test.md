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

![image](https://github.com/user-attachments/assets/25eba7c7-13e2-427e-adfd-da7406d2fb1b)
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
4) Перенесите рисунок представленный ниже на программный код:

 ![image](https://github.com/user-attachments/assets/1f8e0574-99bb-48b4-a493-931c60ad1ae7)
Рабочий вариант
```cpp
#include <thread>
#include <mutex>
#include <iostream>

std::mutex g_lock;
void threadFunction(int time ) {
std::cout<<"start "<<time<<"\n";
std::this_thread::sleep_for(std::chrono::seconds(time));
}
int main() {
std::cout<<"11111\n";
std::thread t1(threadFunction,3);
std::thread t2(threadFunction,1);
std::thread t3(threadFunction,10);
t1.join();
std::cout<<"end11\n";
t2.join();
std::cout<<"end22\n";
t3.join();
std::cout<<"end333\n";
return 0;
}
```
4) Исправьте ошибки в программе.
```cpp
void task1(string msg) {
    cout << "task1 says: " << msg;
}
int main() {
    thread t1(task1);
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <thread>

using namespace std;
void task1(string msg) {
    cout << "task1 says: " << msg;
}
int main() {
    thread t1(task1,"hello world");
    t1.join();
}

```
5) Исправьте ошибки в программе.
```cpp
static const int num_threads = 10;
//This function will be called from a thread
void call_from_thread(int tid) {
    std::cout << "Launched by thread " << tid << std::endl;
}
int main() {
    std::thread t[num_threads];
    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread();
    }
    std::cout << "Launched from the main\n";
    //Join the threads with the main thread
    for (int i = 0; i < ; ++i) {
        t[i].join();
    }
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <thread>
static const int num_threads = 10;
//This function will be called from a thread
void call_from_thread(int tid) {
    std::cout << "Launched by thread " << tid << std::endl;
}
int main() {
    std::thread t[num_threads];
    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(call_from_thread,i);
    }
    std::cout << "Launched from the main\n";
    //Join the threads with the main thread
    for (int i = 0; i <num_threads ; ++i) {
        t[i].join();
    }
}

```
6) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
constexpr int COUNT_DATA{15};
// a global variable
static int myList[COUNT_DATA];
// a global instance of std::mutex to protect global variable
std::mutex myMutex;
void addToList(int max, int interval) {
    // the access to this function is mutually exclusive
    std::lock_guard guard(myMutex);
    
    for (int i = 0; i < max; i++) {
        if( (i % interval) == 0) myList[i] = i;
    }
}
void printList() {
    // the access to this function is mutually exclusive
    std::lock_guard<> (myMutex);
    for (auto itr{0}; itr < COUNT_DATA; ++itr ) {
        cout << myList[itr] << ", ";
    }
}
int main() {
    int max = 100;
    std::thread t1(addToList, max);
    std::thread t2(addToList, max);
    std::thread t3(printList);
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <thread>
#include <mutex>

constexpr int COUNT_DATA{15};
// a global variable
static int myList[COUNT_DATA];
// a global instance of std::mutex to protect global variable
std::mutex myMutex;
void addToList(int max, int interval) {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(myMutex);
    for (int i = 0; i < max; i++) {
        if( (i % interval) == 0) myList[i] = i;
    }
}
void printList() {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(myMutex);
    for (auto itr{0}; itr < COUNT_DATA; ++itr ) {
        std::cout << myList[itr] << ", ";
    }
}
int main() {
    int max = 100;
    std::thread t1(addToList, max,6);
    std::thread t2(addToList, max,5);
    std::thread t3(printList);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
```
7) Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
```cpp
// Global mutex to protect shared_data
mutex mtx;
// Shared data variable
int shared_data = 0;
// Function to increment shared_data
void increment_data() {
    // Create a unique_lock object, but defer locking the mutex
    unique_lock<> (mtx, defer_lock);
    // Critical section: safely modify shared_data
    shared_data += 2;
}
int main() {
    // Create two threads that run the increment_data function
    thread t1();
    thread t2();
    // Wait for both threads to finish
    t1.join();
    // Output the value of shared_data
    cout << "Value of shared variable: " << shared_data;
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// Global mutex to protect shared_data
mutex mtx;
// Shared data variable
int shared_data = 0;
// Function to increment shared_data
void increment_data() {
    // Create a unique_lock object, but defer locking the mutex
    unique_lock<mutex> (mtx, defer_lock);
    // Critical section: safely modify shared_data
    shared_data += 2;
}
int main() {
    // Create two threads that run the increment_data function
    thread t1(increment_data);
    thread t2(increment_data);
    // Wait for both threads to finish
    t1.join();
    t2.join();
    // Output the value of shared_data
    cout << "Value of shared variable: " << shared_data;
}

```
8) Найдите ошибки в коде, и сделайте чтобы вывод в терминале был: new faild.
```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int a,b;
void f1() {
    lock_guard lock(m);
    a = 1;
    try {
        int * ptr = new int[10];
    }catch(...) {
        cout <<"new faild"<<endl;
    }
    // still locked
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //2s
    b = 2;
}
void f2() {
    lock_guard<> (m);
    cout << a <<" : "<<b <<endl;
}
int main() {
    std::thread T1(f1);
    std::thread T2(f2);
}
```
Рабочий вариант
```cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
std::mutex m;
int a,b;
void f1() {
    lock_guard<mutex> lock(m);
    a = 1;
    try {
        int * ptr = new int[10];
    }catch(...) {
        cout <<"new faild"<<endl;
    }
    // still locked
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //2s
    b = 2;
}
void f2() {
    lock_guard<mutex> lock(m);
    cout << a <<" : "<<b <<endl;
}
int main() {
    std::thread T1(f1);
    std::thread T2(f2);
    T1.join();
    T2.join();
}
```
