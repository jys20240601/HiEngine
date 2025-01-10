#pragma once
#include <windows.h>

class DoubleBuffer
{
public:
    DoubleBuffer();
    ~DoubleBuffer();

    bool Initialize(HWND hWnd, int width, int height);
    void BeginDraw();
    void EndDraw();
    HDC GetBackDC() const { return m_backDC; }
    void Cleanup();

private:
    HWND m_hWnd;
    int m_width;
    int m_height;
    HDC m_hdc;
    HDC m_backDC;
    HBITMAP m_backBitmap;
};