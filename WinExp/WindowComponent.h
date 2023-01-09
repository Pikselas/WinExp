#pragma once
#include<Windows.h>
#include<CommCtrl.h>
#include<functional>

class WindowComponent
{
	friend class Window;
protected:
	HWND component_handle;
protected:
	WindowComponent() = default;
	virtual void PerformCommand(int wparam) = 0;
};

template<typename T>
concept WindowT = std::is_same_v<T, class Window>;