#pragma once
#include"WindowComponent.h"

class RangeButton : public WindowComponent
{
public:
	RangeButton(WindowT auto& wnd, int pos_x, int pos_y, int width, int height)
	{
		component_handle = CreateWindowEx(0, TRACKBAR_CLASS, "Trackbar Control",
			WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,
			pos_x, pos_y, width, height,
			wnd.window_handle, (HMENU)1, GetModuleHandle(nullptr), nullptr);
	}
	~RangeButton()
	{
		DestroyWindow(component_handle);
	}
	void PerformCommand(int hi_word) override
	{
		
	}
};