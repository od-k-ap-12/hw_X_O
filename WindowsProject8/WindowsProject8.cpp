// WindowsProject8.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WindowsProject8.h"

#define MAX_LOADSTRING 100

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hClick[9], hPic[9];
HBITMAP hBmp[2];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    //wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT8);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

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


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp) {

    TCHAR str[100];
    int Answers[9];
    static int Order = 0;
    switch (message)
    {
    case WM_CLOSE:
        EndDialog(hWnd, 0);
        return TRUE;

    case  WM_INITDIALOG:
        for (int i = 0; i < 9; i++) {
            hClick[i] = GetDlgItem(hWnd, IDC_BUTTON1+i);
        }
        for (int i = 0; i < 9; i++) {
            hPic[i] = GetDlgItem(hWnd, IDC_STATIC1 + i);
        }
        hBmp[0] = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1)); //Х
        hBmp[1] = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2)); //О
        return TRUE;

    case WM_COMMAND: {
        if (LOWORD(wp) == IDC_BUTTON1)
        {
            if (Order == 0) {
                SendMessage(hPic[0], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[0], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON2)
        {
            if (Order == 0) {
                SendMessage(hPic[1], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[1], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON3)
        {
            if (Order == 0) {
                SendMessage(hPic[2], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[2], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON4)
        {
            if (Order == 0) {
                SendMessage(hPic[3], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[3], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON5)
        {
            if (Order == 0) {
                SendMessage(hPic[4], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[4], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON6)
        {
            if (Order == 0) {
                SendMessage(hPic[5], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[5], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON7)
        {
            if (Order == 0) {
                SendMessage(hPic[6], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[6], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON8)
        {
            if (Order == 0) {
                SendMessage(hPic[7], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[7], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
        if (LOWORD(wp) == IDC_BUTTON9)
        {
            if (Order == 0) {
                SendMessage(hPic[8], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                Order = 1;
            }
            else {
                SendMessage(hPic[8], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                Order = 0;
            }
        }
    }
    return TRUE;
    }
    return FALSE;
}
