#include "DoubleBuffer.h"

DoubleBuffer::DoubleBuffer() : m_hWnd(NULL), m_width(0), m_height(0), m_hdc(NULL), m_backDC(NULL), m_backBitmap(NULL)
{
}

DoubleBuffer::~DoubleBuffer()
{
    Cleanup();
}

bool DoubleBuffer::Initialize(HWND hWnd, int width, int height)
{
    m_hWnd = hWnd;
    m_width = width;
    m_height = height;

    m_hdc = GetDC(m_hWnd);
    m_backDC = CreateCompatibleDC(m_hdc);
    m_backBitmap = CreateCompatibleBitmap(m_hdc, m_width, m_height);
    SelectObject(m_backDC, m_backBitmap);

    return true;
}

void DoubleBuffer::BeginDraw()
{
    PatBlt(m_backDC, 0, 0, m_width, m_height, WHITENESS);
}

void DoubleBuffer::EndDraw()
{
    BitBlt(m_hdc, 0, 0, m_width, m_height, m_backDC, 0, 0, SRCCOPY);
}

void DoubleBuffer::Cleanup()
{
    if (m_backBitmap)
    {
        DeleteObject(m_backBitmap);
        m_backBitmap = NULL;
    }
    if (m_backDC)
    {
        DeleteDC(m_backDC);
        m_backDC = NULL;
    }
    if (m_hdc)
    {
        ReleaseDC(m_hWnd, m_hdc);
        m_hdc = NULL;
    }
}