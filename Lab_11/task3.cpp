#include <iostream>
void goodmorning();
void goodevening();
void(*message(unsigned))();
int task3() {
    void(*action)();
    // указатель на выбранную функцию
    // выполняем полученную функцию
   action=message(10);
    action(); // Good Morning!
    action = message(16); // получаем новую функцию
    //action(); // Good Evening!
};
void(*message(unsigned hour))() {
    if (hour > 15)
        return goodevening;
    else
        return goodmorning;
}
void goodmorning(){
    std::cout << "Good Morning!" << std::endl;
}
void goodevening(){
    std::cout << "Good Evening!" << std::endl;
}
