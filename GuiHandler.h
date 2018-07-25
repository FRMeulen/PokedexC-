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

/*

	<< ID LIST >>
ID 0 == Main
ID 1 == Search by Number
ID 2 == Search by Name
ID 3 == Search by Primary Type
ID 4 == Search by Secondary Type
ID 5 == Search by Generation
ID 6 == Show Dual-Types
ID 7 == Show Legendaries
ID 8 == Show All
ID 9 == Help

*/