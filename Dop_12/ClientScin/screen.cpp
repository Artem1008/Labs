#include "screen.h"

int Screen::TakeScreenshot()
{
    try {


    // Получаем дескриптор окна рабочего стола
    HWND hDesktop = GetDesktopWindow();
    HDC hdcScreen = GetDC(hDesktop);
    HDC hdcMemDC = CreateCompatibleDC(hdcScreen);

    // Получаем размеры экрана
    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    // Создаем буфер для скриншота
    hBitmap = CreateCompatibleBitmap(hdcScreen, width, height);
    SelectObject(hdcMemDC, hBitmap);

    // Делаем скриншот
    BitBlt(hdcMemDC, 0, 0, width, height, hdcScreen, 0, 0, SRCCOPY);

    // Освобождаем ресурсы (кроме hBitmap)
    DeleteDC(hdcMemDC);
    ReleaseDC(hDesktop, hdcScreen);
    }
    catch (...)
    {
        hBitmap=NULL;
        return -1;
    }
    return 1;
}
HBITMAP Screen::getScreenshot()
{
    if (TakeScreenshot()==-1) return NULL;
    if (hBitmap == NULL) return NULL;
   return  hBitmap;
}
