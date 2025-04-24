#include "controller.h"

int main()
{
       setlocale(LC_ALL, "");
        // Создаем светофор с начальным состоянием
        Controller controller;
        controller.run();
        return 0;
}
