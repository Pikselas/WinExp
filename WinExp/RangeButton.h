#pragma once
#include"WindowComponent.h"

class RangeButton : public WindowComponent
{
private:
	int min_value = 0;
	int max_value = 100;
	int current_value = 0;
public:
	std::function<void(RangeButton&)> OnSlide = nullptr;
public:
	RangeButton(WindowT auto& wnd,int min_range,int max_range, int pos_x, int pos_y, int width, int height) : min_value(min_range) , max_value(max_range)
	{
		component_handle = CreateWindowEx(0, TRACKBAR_CLASS, "Trackbar Control",
			WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,
			pos_x, pos_y, width, height,
			wnd.window_handle, (HMENU)1, GetModuleHandle(nullptr), nullptr);
		SendMessage(component_handle, TBM_SETRANGE,
			(WPARAM)TRUE,                   // redraw flag 
			(LPARAM)MAKELONG(min_range, max_range));  // min. & max. positions
		SendMessage(component_handle, TBM_SETTICFREQ, (WPARAM)10, 0);
		UpdateWindow(wnd.window_handle);
		SetWindowLongPtr(component_handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	}
	~RangeButton()
	{
		DestroyWindow(component_handle);
	}
	void PerformCommand(int wparam) override
	{
		current_value = SendMessage(component_handle, TBM_GETPOS, 0, 0);
		if (OnSlide != nullptr)
		{
			OnSlide(*this);
		}
	}
	int GetCurrentPos() const
	{
		return current_value;
	}
	int GetMaxPos() const
	{
		return max_value;
	}
	int GetMinPos() const
	{
		return min_value;
	}
};