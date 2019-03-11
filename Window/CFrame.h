#ifndef CFRAME_H_INCLUDED
#define CFRAME_H_INCLUDED

#include "../VZWin.h"


class CFrame
{
protected:
    HWND hWnd;
    RECT rect;
    HINSTANCE hInst;
    WNDCLASSEX wcx;
    HDC hdc;
    MSG msg;
    unsigned long dwBaseUnits;
    HFONT hMainFont;
    float cx, cy;

public:
    CFrame()
        :
        hWnd(nullptr),
        rect({0}),
        hInst(GetModuleHandle(nullptr)),
        wcx({0}),
        hdc(nullptr),
        msg({0}),
		dwBaseUnits(GetDialogBaseUnits()),
    	hMainFont(nullptr),
		cx(0), cy(0)
    {
    }
    CFrame(const CFrame&) = delete;
    CFrame& operator=(const CFrame&) = delete;
    virtual ~CFrame()
    {
    }

public:
    void Show(int nCmdShow) const;
    int MsgBox(LPCTSTR lpMsg, LPCTSTR lpTitle, int nButtons = 0);
    HWND Window() const;
    int Run();
    BOOL ResizeWindow(int width_in, int height_in);
    RECT GetRect() const;
    BOOL GetDlgUnits();
    bool Create(LPCTSTR lpTitle, DWORD dwStyle, DWORD dwExStyle = 0,
                int x = CW_USEDEFAULT, int y = CW_USEDEFAULT,
                int width = CW_USEDEFAULT, int height = CW_USEDEFAULT, HWND hWndParent = 0, HMENU hMenu = 0);
    static LRESULT WINAPI WndProc(HWND hWndProc, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT WINAPI WndProcFwd(HWND hWndProc, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
    bool Register();
    BOOL SetFont(HWND hWndChild, LPARAM font);
    virtual LPCSTR ClassName() = 0;
    virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
};


#endif // CFRAME_H_INCLUDED
