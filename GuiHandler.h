//Pragma
#pragma once

//Inclusions
#include "MainScreen.h"
#include "HelpScreen.h"
#include "NumberSearchScreen.h"

//Class
class GuiHandler {
public:
	GuiHandler();
	virtual ~GuiHandler();

protected:
	Gtk::Window *guiWindow;	//Window pointer

	//Screen pointers
	MainScreen *mainScreen;
	HelpScreen *helpScreen;
	NumberSearchScreen *numberSearch;

	//Methods
	void toHelp();
	void toMain();
	void toNumberSearch();

	//Temporary methods
	void showWip();
};