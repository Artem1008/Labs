#ifndef SCREEN_H
#define SCREEN_H
#include <qt_windows.h>
#include <fstream>

class Screen
{
private:
    HBITMAP hBitmap;
    int TakeScreenshot();
public:
    Screen():hBitmap(NULL){};
    HBITMAP getScreenshot();
};

#endif // SCREEN_H
