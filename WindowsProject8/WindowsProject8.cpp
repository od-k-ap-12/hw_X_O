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
HBITMAP hBmp[3];

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp) {
    int MapSize = 3 * 3;
    int Answer[9]{9}; //хранит ответы для проверки результата
    static bool IfClicked[9]{0}; //проверяет есть ли уже на этом месте крестик или нолик
    static int Order = 0; //определяет показать крестик или нолик
    switch (message)
    {
    case WM_CLOSE:
        EndDialog(hWnd, 0);
        return TRUE;

    case  WM_INITDIALOG:
        for (int i = 0; i < MapSize; i++) {
            hClick[i] = GetDlgItem(hWnd, IDC_BUTTON1+i);
        }
        for (int i = 0; i < MapSize; i++) {
            hPic[i] = GetDlgItem(hWnd, IDC_STATIC1 + i);
        }
        hBmp[0] = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1)); //Х
        hBmp[1] = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2)); //О
        hBmp[2] = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP3)); //Start pic
        return TRUE;

    case WM_COMMAND: {
        if (LOWORD(wp)<= IDC_BUTTON9 && LOWORD(wp) >= IDC_BUTTON1) {
            for (int i = 0; i < MapSize; i++) {
                if (LOWORD(wp) == IDC_BUTTON1+i)
                {
                    if (IfClicked[i]==0) {
                        if (Order == 0) {
                            SendMessage(hPic[i], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[0]));
                            Order = 1;
                            IfClicked[i] = 1;
                            Answer[i] = 0;
                        }
                        else {
                            SendMessage(hPic[i], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[1]));
                            Order = 0;
                            IfClicked[i] = 1;
                            Answer[i] = 1;
                        }
                   }
                }
            }
        }
        if (LOWORD(wp) == IDFINISH) {
            if ((Answer[0] == Answer[1] == Answer[2]==0) || (Answer[3] == Answer[4] == Answer[5]==0) || 
                (Answer[6] == Answer[7] == Answer[8]==0) || (Answer[0] == Answer[3] == Answer[6]==0) || 
                (Answer[1] == Answer[4] == Answer[7]==0) || (Answer[2] == Answer[5] == Answer[8]==0) || 
                (Answer[3] == Answer[4] == Answer[5]==0) || (Answer[0] == Answer[4] == Answer[8]==0) ||
                (Answer[2] == Answer[4] == Answer[6]==0)) {
                MessageBox(hWnd, TEXT("X player wins"), TEXT("Results"), MB_OK | MB_ICONINFORMATION);
            }
            else if ((Answer[0] == Answer[1] == Answer[2]==1) || (Answer[3] == Answer[4] == Answer[5]==1) ||
                (Answer[6] == Answer[7] == Answer[8]==1) || (Answer[0] == Answer[3] == Answer[6]==1) ||
                (Answer[1] == Answer[4] == Answer[7]==1) || (Answer[2] == Answer[5] == Answer[8]==1) ||
                (Answer[3] == Answer[4] == Answer[5]==1) || (Answer[0] == Answer[4] == Answer[8]==1) || 
                (Answer[2] == Answer[4] == Answer[6]==1)) {
                MessageBox(hWnd, TEXT("O player wins"), TEXT("Results"), MB_OK | MB_ICONINFORMATION);
            }
            else {
                MessageBox(hWnd, TEXT("No one wins"), TEXT("Results"), MB_OK | MB_ICONINFORMATION);
            }
        }
        if (LOWORD(wp) == IDRESTART) {
            for (int i = 0; i < MapSize; i++) {
                SendMessage(hPic[i], STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[2]));
                IfClicked[i] = 0;
                Answer[i] = 9;
            }
        }
        
    }
    return TRUE;
    }
    return FALSE;
}
