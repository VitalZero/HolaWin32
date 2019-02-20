#include "CWindow.h"
#include <windowsx.h>
//#include <string>

LRESULT CWindow::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        HANDLE_MSG(hWnd, WM_CREATE, this->OnCreate);
        HANDLE_MSG(hWnd, WM_CTLCOLORSTATIC, this->OnCtlColorStatic);
        HANDLE_MSG(hWnd, WM_COMMAND, this->OnCommand);
        HANDLE_MSG(hWnd, WM_PAINT, this->OnPaint);
        HANDLE_MSG(hWnd, WM_DESTROY, this->OnDestroy);
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

void CWindow::OnDestroy(HWND in_hWnd)
{
    UnregisterClass(ClassName(), hInst);

    PostQuitMessage(0);
}

BOOL CWindow::OnCreate(HWND hWnd_in, LPCREATESTRUCT)
{
    GetWindowRect(hWnd, &rect);

    return TRUE;
}

HBRUSH CWindow::OnCtlColorStatic(HWND hWndP, HDC hdc, HWND hWndCtl, int nIdCtl)
{
	SetBkMode(hdc, TRANSPARENT);

	return HBRUSH(GetStockObject(NULL_BRUSH) );
}

BOOL CWindow::OnCommand(HWND hWndP, int id, HWND hWndCtl, UINT notifyCode)
{
    return FALSE;
}

int CWindow::OnPaint(HWND hWndP)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWndP, &ps);
	//FillRect(hdc, &ps.rcPaint,HBRUSH(COLOR_WINDOW) );
	EndPaint(hWndP, &ps);

	return 0;
}

