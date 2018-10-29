//	Project:	PokedexC++.
//	DexGui.h	--	Interface for the CDexGui class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include <cppconn/resultset.h>
#include "screens/MainScreen.h"
#include "screens/FilterScreen.h"
#include "DexConnector.h"

//	Class interface.
class CDexGui {
protected:
	//	Child object pointers.
	Gtk::Notebook *m_screens;
	CDexConnector *m_dex;

	//	Screen object pointers.
	CMainScreen *m_mainScreen;
	CFilterScreen *m_filterScreen;
public:
	//	Constructors & destructor.
	CDexGui();
	virtual ~CDexGui();

	//	Methods.
	Gtk::Notebook& getScreens();
	CMainScreen* getMainScreen();
	CFilterScreen* getFilterScreen();
};