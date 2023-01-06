#pragma once
#include<Windows.h>

class WindowComponent
{
	friend class Window;
protected:
	HWND component_handle;
protected:
	virtual void PerformCommand(int hi_word) = 0;
};