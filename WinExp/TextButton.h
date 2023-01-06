#pragma once
#include<string>
#include<functional>
#include"WindowComponent.h"


class TextButton : public WindowComponent
{
public:
	std::function<void(TextButton& button)> OnClick = nullptr;
	std::function<void(TextButton& button)> OnDblClick = nullptr;
public:
	TextButton(auto& parent_window, const std::string& Title, int pos_x, int pos_y, int width, int height)
	{
		component_handle = CreateWindowEx(0, "Button", Title.c_str(), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON ,pos_x,pos_y,width,height, parent_window.window_handle, nullptr, GetModuleHandle(nullptr), nullptr);
		SetWindowLongPtr(component_handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	}
	~TextButton()
	{
		DestroyWindow(component_handle);
	}
	void PerformCommand(int hi_word) override
	{
		if (hi_word == BN_CLICKED && OnClick != nullptr)
		{
			OnClick(*this);
		}
		else if (hi_word == BN_DBLCLK && OnDblClick != nullptr)
		{
			OnDblClick(*this);
		}
	}
};