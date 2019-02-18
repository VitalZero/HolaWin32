#ifndef CONTROLS_H
#define CONTROLS_H
#define OEMRESOURCE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//#include <string>
#include <cassert>

// Clase padre
class Controls
{
public:
	Controls();
	virtual ~Controls(){}

	// funciones
	void Resize(int w, int h) const;
	void Move(int x, int y) const;
    virtual void SetText(LPCTSTR controlText);
	virtual void GetText(LPTSTR lpText) const;
	void SetFocus() const;
	//std::string GetText();
	int TextLength() const;
    HWND Window() const { return hWnd;}

	// virtuales
	virtual void Create(const HWND hWndParent, int x, int y, int w, int h,
						int id, LPCTSTR txt = "") = 0;
protected:
	HWND hWnd;
	int x, y;
	int width, height;
};

#endif // CONTROLS_H