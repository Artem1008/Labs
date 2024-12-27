#ifndef ERRORS_H
#define ERRORS_H

namespace ret {
enum erorrs {
    Ok                  =  0,     // Хорошо
    ErrIO              = -1,     // Привышено число попыток ввода данных
    ErrSize           = -2,     // Привышен размер
};
}
#endif // ERRORS_H
