#include "CWindow.h"
#include <windowsx.h>
//#include <iostream>
#include <string>

LRESULT CWindow::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        HANDLE_MSG(hWnd, WM_CREATE, OnCreate); // @suppress("Symbol is not resolved")
        HANDLE_MSG(hWnd, WM_CTLCOLORSTATIC, OnCtlColorStatic);// @suppress("Symbol is not resolved")
        HANDLE_MSG(hWnd, WM_COMMAND, OnCommand);// @suppress("Symbol is not resolved")
        HANDLE_MSG(hWnd, WM_PAINT, OnPaint);// @suppress("Symbol is not resolved")
        HANDLE_MSG(hWnd, WM_DESTROY, OnDestroy);// @suppress("Symbol is not resolved")
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

void CWindow::OnDestroy(HWND in_hWnd)
{
    PostQuitMessage(0);
}

BOOL CWindow::OnCreate(HWND in_hWnd, LPCREATESTRUCT)
{
	hdc = GetWindowDC(hWnd);

    //TEXTMETRIC tm;
	//float y, x;
	hFont = HFONT(SelectObject(hdc, HFONT(GetStockObject(DEFAULT_GUI_FONT)) ) );

	//GetTextMetrics(hdc, &tm);

    //x = float(LOWORD(GetDialogBaseUnits()) /4.0f);
    //y = float((WORD)tm.tmHeight/8.0f);

	SelectObject(hdc, hFont);

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

void CWindow::OnBtnDesglose()
{
}

int CWindow::OnPaint(HWND hWndP)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWndP, &ps);
	FillRect(hdc, &ps.rcPaint,HBRUSH(COLOR_WINDOW) );
	EndPaint(hWndP, &ps);

	return 0;
}

