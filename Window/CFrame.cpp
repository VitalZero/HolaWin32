#include "CFrame.h"
#include <assert.h>
#include <windowsx.h>
#define MAINMENU_MENU 3
// FUNCIONES PUBLICAS
void CFrame::Show(int nCmdShow) const
{
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
}

int CFrame::MsgBox(LPCTSTR lpMsg, LPCTSTR lpTitle, int nButtons)
{
    return MessageBox(hWnd, lpMsg, lpTitle, nButtons);
}

HWND CFrame::Window() const
{
    return hWnd;
}

int CFrame::Run()
{
    while(GetMessage(&msg, NULL, 0,0 ))
    {
        if(!IsDialogMessage(hWnd, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        //if(msg.message == WM_QUIT)
           // return false;
    }

    return msg.wParam;
}

BOOL CFrame::ResizeWindow(int width_in, int height_in)
{
	RECT tmpRect = { 0, 0, width_in, height_in };

	AdjustWindowRect(&tmpRect, WS_OVERLAPPEDWINDOW, FALSE);
    BOOL resized = SetWindowPos(hWnd, NULL, 0, 0,
    		tmpRect.right - tmpRect.left, tmpRect.bottom - tmpRect.top, SWP_NOMOVE | SWP_NOZORDER );

    if(resized == TRUE)
    {
    	rect = tmpRect;
    }

    return resized;
}

RECT CFrame::GetRect() const
{
	return rect;
}

BOOL CFrame::GetDlgUnits()
{
	TEXTMETRIC tm;
	hdc = GetWindowDC(hWnd);
	assert(hdc != NULL);

	hMainFont = HFONT(SelectObject(hdc, HFONT(GetStockObject(DEFAULT_GUI_FONT)) ) );
	assert(hMainFont != NULL);

	GetTextMetrics(hdc, &tm);
	cx = float(LOWORD(GetDialogBaseUnits()) /4.0f);
    cy = float((WORD)tm.tmHeight/8.0f);

    SelectObject(hdc, hMainFont);

    if(DeleteObject(hMainFont) && ReleaseDC(hWnd, hdc) )
    	return TRUE;

    return FALSE;
}

bool CFrame::Create(LPCTSTR lpTitle, DWORD dwStyle, DWORD dwExStyle,
                    int x, int y, int width, int height, HWND hWndParent, HMENU hMenu)
{
    wcx.cbSize = sizeof(WNDCLASSEX); 		// @suppress("Field cannot be resolved")
    wcx.lpfnWndProc =  CFrame::WndProc; 		// @suppress("Field cannot be resolved")
    wcx.hInstance = hInst; 						// @suppress("Field cannot be resolved")
    wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION); // @suppress("Field cannot be resolved")
    wcx.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // @suppress("Field cannot be resolved")
    wcx.hCursor = LoadCursor(NULL, IDC_ARROW); 	// @suppress("Field cannot be resolved")
    wcx.hbrBackground = HBRUSH(COLOR_WINDOW); // @suppress("Field cannot be resolved")
    wcx.lpszClassName = ClassName(); 			// @suppress("Field cannot be resolved")
    //wcx.lpszMenuName = "MAINMENU";

    if(!Register())
    {
        MsgBox("Error de registro, \nNo se pudo registrar la ventana", "error!!!");
        return false;
    }

    hWnd = CreateWindowEx(dwExStyle, ClassName(), lpTitle, dwStyle,
                            x, y, width, height, hWndParent, hMenu, hInst, this);
    assert(hWnd != NULL);

    if(hWnd == NULL)
    {
    	MsgBox("No se pudo crear la ventana", "Error!");
    	return false;
    }

    return true;
}

LRESULT WINAPI CFrame::WndProc(HWND hWndProc, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    CFrame* pThis = nullptr;

    if(uMsg == WM_NCCREATE)
    {
        LPCREATESTRUCT lpCreate = (LPCREATESTRUCT)lParam;
        pThis = (CFrame*)lpCreate->lpCreateParams;
        pThis->hWnd = hWndProc;

        assert(pThis != nullptr);

        SetWindowLongPtr(hWndProc, GWLP_USERDATA, (LONG_PTR)pThis);
        SetWindowLongPtr(hWndProc, GWLP_WNDPROC, (LONG_PTR)&CFrame::WndProcFwd);

        return pThis->HandleMessage(uMsg, wParam, lParam);
    }

    return DefWindowProc(hWndProc, uMsg, wParam, lParam);
}

LRESULT WINAPI CFrame::WndProcFwd(HWND hWndProc, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    CFrame* const pThis = (CFrame*)GetWindowLongPtr(hWndProc, GWLP_USERDATA);
    return pThis->HandleMessage(uMsg, wParam, lParam);
}

// FUNCIONES PRIVADAS
bool CFrame::Register()
{
    ATOM aReg = RegisterClassEx(&wcx);
    assert(aReg != 0);

    return (aReg != 0);
}

BOOL CFrame::SetFont(HWND hWndChild, LPARAM font)
{
    SendMessage(hWndChild, WM_SETFONT, (WPARAM)font, TRUE);
    return TRUE;
}
