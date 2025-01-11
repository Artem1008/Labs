#ifndef ERRORS_H
#define ERRORS_H

namespace ret {
enum erorrs {
        Ok                  =  0,   // Хорошо
        ErrIO              = -1,    // Привышено число попыток ввода данных
        ErrSize           = -2,     // Привышен размер
        ErrTrans         = -3,    // Ошибка транзакции
    };
}
#endif // ERRORS_H
