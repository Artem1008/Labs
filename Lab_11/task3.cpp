#include <iostream>
void goodmorning();
void goodevening();
void(*message(unsigned))();
int task3() {
    void(*action)();
    // 㪠��⥫� �� ��࠭��� �㭪��
    // �믮��塞 ����祭��� �㭪��
   action=message(10);
    action(); // Good Morning!
    action = message(16); // ����砥� ����� �㭪��
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
