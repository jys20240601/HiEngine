#include "framework.h"
#include "HiyoEngine.h"
#include "DoubleBuffer.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "SceneManager.h"
#include <vector> 

#define MAX_LOADSTRING 100

//전역변수 포인터

DoubleBuffer g_DoubleBuffer;

Player* g_pPlayer = nullptr;
Monster* g_pMonster = nullptr;

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_HIYOENGINE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HIYOENGINE));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HIYOENGINE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HIYOENGINE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        {
            g_pPlayer = new Player(100, 100, 50, 50);
            g_pMonster = new Monster(200, 300, 50, 50);

            g_DoubleBuffer.Initialize(hWnd, 800, 600);

            SceneManager::GetInstance().ChangeScene(SceneManager::SceneType::Title);

            SetTimer(hWnd, 1, 16, NULL);

            return 0;
        }

    case WM_TIMER:
    {
        if (g_pPlayer)
        {
            g_pPlayer->Update();
        }

        if (g_pMonster)
        {
            g_pMonster->Update();
        }

        SceneManager::GetInstance().Update();

        InvalidateRect(hWnd, NULL, FALSE);

        return 0;
    }

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            g_DoubleBuffer.BeginDraw();
            HDC backDC = g_DoubleBuffer.GetBackDC();

            if (g_pPlayer)
            {
                g_pPlayer->Render(backDC);
            }
            if (g_pMonster)
            {
                g_pMonster->Render(backDC);
            }

            SceneManager::GetInstance().Render(backDC);

            g_DoubleBuffer.EndDraw();

            EndPaint(hWnd, &ps);

        }
        break;

    case WM_DESTROY:

        KillTimer(hWnd, 1);

        if (g_pPlayer)
        {
            delete g_pPlayer;
            g_pPlayer = nullptr;
        }
        if (g_pMonster)
        {
            delete g_pMonster;
            g_pMonster = nullptr;
        }
        g_DoubleBuffer.Cleanup();

        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
