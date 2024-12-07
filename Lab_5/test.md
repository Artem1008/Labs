1)
```cpp
#include<iostream>
int main() {
float a=3.14;
char *pj;
pj = (char*)&a;
std::cout << *pj << '\n';
}
#include<iostream>
```
Рабочий вариант
```cpp
#include<iostream>
int main() {
float a=3.14;
float *pj=&a;
std::cout << *pj << '\n';
}
```
2)
```cpp
int main(){
int a=10, *pj;
void *pk;
pj = pk = &a;
pj++;
k++;
std::cout << pk << '\n';
std::cout << pj << '\n'
```
Рабочий вариант
```cpp
#include<iostream>
int main(){
int a=10;
int* pj;
void *pk;
pk=&a;
pj =(int*)pk;
pj++;
std::cout << pj <<" "<<*pj << '\n';
std::cout << pk<<" "<<*(int *)pk <<'\n';
}
```
3) Помогите другу разработчику доработайте или исправьте код, который сделал:
Номер телефона, например (212) 767-8900, можно условно разделить на три части: код
города (212), номер телефонной станции (767) и номер абонента (8900). Разработана
программа с использованием двух структур phone, позволяющую раздельно хранить эти три
части телефонного номера. Инициализацию одной из них производится самостоятельно, а
значения для другой запрашивается с клавиатуры. Затем выводится содержимое обеих
переменных на экран. Результат работы программы должен выглядеть так:
Введите код города, номер станции и номер абонента: 415 555 1212
Мой номер: (212) 767-8900
Ваш номер: (415) 555-1212
```cpp
#include <iostream>
using namespace std;
struct phone{
int kod ;
int nom ;
int mom_abon ;
};
struct new_phone{
int kod1;
int nom1;
int mom_abon1;
};
int main() {
setlocale (LC_ALL, "rus" );
phone object;
new_phone new_object;
wcout << L"Введите код города, номер станции и номер абонента: ";
int mas_all[11];
cin >> mas_all[11];
int mas_a[2];
mas_a[0] = mas_all[0];
mas_a[1] = mas_all[1];
mas_a[2] = mas_all[2];
new_object.kod1 = mas_a[2];
int mas_b[2];
mas_b[0] = mas_all[4];
mas_b[1] = mas_all[5];
mas_b[2] = mas_all[6];
new_object.nom1 = mas_b[2];
int mas_c[3];
mas_c[0] = mas_all[8];
mas_c[1] = mas_all[9];
mas_c[2] = mas_all[10];
mas_c[3] = mas_all[11];
new_object.mom_abon1= mas_b[2];
object.kod = 123;
object.nom = 456;
object.mom_abon = 7890;
wcout << L"Мой номер телефона : " << object.kod << " " << object.nom << " " << object.mom_abon << endl;
wcout << L"Ваш номер : " << new_object.kod1 << " " << new_object.nom1 << " " << new_object.mom_abon1 << endl;
return 0;
}
```
Рабочий вариант
```cpp
#include <iostream>
using namespace std;
struct phone{
    int kod ;
    int nom ;
    int mom_abon ;
};
struct new_phone{
    int kod1;
    int nom1;
    int mom_abon1;
};
int main() {
    setlocale (LC_ALL, "rus" );
    phone object;
    new_phone new_object;
    wcout << L"Введите код города, номер станции и номер абонента: ";
    int mas_all[11];
    cin >>new_object.kod1>>new_object.nom1>>new_object.mom_abon1;
    object.kod = 123;
    object.nom = 456;
    object.mom_abon = 7890;
    wcout << L"Мой номер телефона : " << object.kod << " " << object.nom << " " << object.mom_abon << endl;
    wcout << L"Ваш номер : " << new_object.kod1 << " " << new_object.nom1 << " " << new_object.mom_abon1 << endl;
    return 0;
}
```
4) Найдите 2е ошибки и измените код чтобы он был рабочим:
```cpp
#include <iostream>
using namespace std;
int main() {
    setlocale (LC_ALL, "rus" );
    const int n = 5;
    const int m = 10;
    int *a;
    int *b;
    a = new int*[n];
    b = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        b[i] = new int[m];
        cout << &a[i][0] << endl;
        cout << &b[i][0] << endl;
    }
}
```
Рабочий вариант
```cpp
#include <iostream>
using namespace std;
int main() {
    setlocale (LC_ALL, "rus" );
    const int n = 5;
    const int m = 10;
    int **a;
    int **b;
    a = new int*[n];
    b = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        b[i] = new int[m];
        cout << &a[i][0] << endl;
        cout << &b[i][0] << endl;
    }
}
```
5) Найдите ошибки и измените код чтобы он был рабочим и выведите все строки заданные разными способами:
```cpp
#include <iostream>
using namespace std;
int main() {
    setlocale (LC_ALL, "rus" );
    char s[] = "char s[]: text";
    char* ps = "char* ps: text";
    std::string str = "std::string str: text";
    s = "another text";
    str = "std::string str: another text";
    char *s_1 = "char *s_1: text";
    const char *s_2 = "const char *s_2: text";
    wcout << L"Вывод строк : "
}
```
Рабочий вариант
```cpp
#include <iostream>
using namespace std;
int main() {
    setlocale (LC_ALL, "rus" );
    char s[] = "char s[]: text";
    char* ps = "char* ps: text";
    std::string str = "std::string str: text";
    str = "another text";
    str = "std::string str: another text";
    char *s_1 = "char *s_1: text";
    const char *s_2 = "const char *s_2: text";
    wcout << L"Вывод строк : \n";
    wcout<<s<<'\n';
    wcout<<ps<<'\n';
    wcout<<str.c_str()<<'\n';
    wcout<<s_1<<'\n';
    wcout<<s_2<<'\n';
}
```
6) Измените код программы чтобы был следующий вывод, причом нельзя использовать при выводе строку s:
    Why is you? : I'am an developer
```cpp
#include <iostream>
using namespace std;
int main() {
    setlocale (LC_ALL, "rus" );
    wstring s = L"I'am an developer";
    wstring
            s1 = s.substr(0, 3),
            s2 = s.substr(1, 3),
            s3 = s.substr(0, s.length()-1),
            s4 = s.substr(1);
    wcout << L"Why is you? : " << s1+s2+s3+s4 << '\n';
}
```
Рабочий вариант s не используется
```cpp
#include <iostream>
using namespace std;
int main() {
setlocale (LC_ALL, "Russian");
wstring s = L"I'am an developer";
wstring
        s1 = s.substr(0, 3),
        s2 = s.substr(1, 3),
        s3 = s.substr(0, s.length()-1),
        s4 = s.substr(1);
        wcout << L"Why is you? : " << s1+s2+s3+s4 << '\n';
  }
```
