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
