#ifndef ERRORS_H
#define ERRORS_H
#include <stdio.h>

namespace ret {
enum : int {
    Ok                  =  0,     // Хорошо
    ErrWSA         = -1,     // WSAStart error
    ErrSock         = -2,     //Socket error
    ErrAddress    = -3,     // Invalid address
    ErrConnect    = -4,     //Connect error
    ErrBind           = -5,     // Error bind
    ErrListen         = -6      //Error listen
};
}
#endif // ERRORS_H
