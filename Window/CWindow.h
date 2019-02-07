#ifndef CWINDOW_H
#define CWINDOW_H

#include "CFrame.h"


#define IDC_DESGLOSE 1200

class CWindow : public CFrame
{
public:
    CWindow()
        :
        hLib(nullptr)
    {
    }
    ~CWindow()
    {
    }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
    HMODULE hLib;

protected:
    const char* ClassName() { return "SampleClass"; }
    void OnDestroy(HWND in_hWnd);
	int OnPaint(HWND hWndP);
	BOOL OnCreate(HWND in_hWnd, LPCREATESTRUCT);
	HBRUSH OnCtlColorStatic(HWND hWndP, HDC hdc, HWND hWndCtl, int color);
	BOOL OnCommand(HWND hWndP, int id, HWND hWndCtl, UINT notifyCode);
};

#endif // CWINDOW_H
