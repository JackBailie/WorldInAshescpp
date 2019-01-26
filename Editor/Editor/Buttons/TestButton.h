#pragma once
#include "Button.h"

class TestButton : public Button
{
public:
	TestButton();
	virtual void Initialise();
	virtual void OnClicked();
};