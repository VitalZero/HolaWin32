#ifndef CEDIT_H
#define CEDIT_H
#include "Controls.h"

// Edit Box
class CEdit : public Controls
{
public:
	CEdit(){}
	~CEdit(){}
	int GetInt();
	float GetFloat();
	bool IsEmpty() const;
	void Create(const HWND hWndParent, int x, int y, int w, int h,
				int id, LPCTSTR txt = "");
	using Controls::GetText;
	using Controls::SetText;
	using Controls::TextLength;
protected:
};

#endif // _CEDIT_H_
