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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp) {

    TCHAR str[100];
    int Answers[9]; //хранит ответы для проверки результата
    static bool IfClicked[9]{0}; //проверяет есть ли уже на этом месте крестик или нолик
    static int Order = 0; //определяет показать крестик или нолик
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
        if (LOWORD(wp)) {
            for (int i = 0; i < 9; i++) {
                if (LOWORD(wp) == IDC_BUTTON1+i)
                {
                    if (IfClicked[i]==0) {
                        if (Order == 0) {
                            SendMessage(hPic[i], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                            Order = 1;
                            IfClicked[i] = 1;
                        }
                        else {
                            SendMessage(hPic[i], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                            Order = 0;
                            IfClicked[i] = 1;
                        }
                   }
                }
            }
        }
        
    }
    return TRUE;
    }
    return FALSE;
}
