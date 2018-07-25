//Pragma
#pragma once

//Inclusions
#include "MainScreen.h"
#include "HelpScreen.h"

//Class
class GuiHandler {
public:
	GuiHandler();
	virtual ~GuiHandler();

protected:
	Gtk::Window *guiWindow;
	MainScreen *mainScreen;
	HelpScreen *helpScreen;
	void toHelp();
	void toMain();

	void showWip();
};