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
	void SetFocus() const;
	//std::string GetText();
    HWND Window() const { return hWnd;}

	// virtuales
	virtual void Create(const HWND hWndParent, int x, int y, int w, int h,
						int id, LPCTSTR txt = "") = 0;
protected:
    void SetText(LPCTSTR controlText);
	void GetText(LPTSTR lpText) const;
	int TextLength() const;

protected:
	HWND hWnd;
private:
	int x, y;
	int width, height;
};

#endif // CONTROLS_H
