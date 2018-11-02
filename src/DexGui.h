//	Project:	PokedexC++.
//	DexGui.h	--	Interface for the CDexGui class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include <cppconn/resultset.h>
#include "DexConnector.h"

//	Predefinitions.
class CMainScreen;
class CFilterScreen;
class CResultsEntry;

//	Class interface.
class CDexGui {
protected:
	//	App-required pointers.
	Glib::RefPtr<Gtk::Application> app;
	Gtk::Window* m_window;
	Gtk::Notebook* m_pages;
	CDexConnector* m_dex;
	sql::ResultSet* m_queryRes;
	CResultsEntry* m_entry;

	//	Screen object pointers.
	CMainScreen* m_mainScreen;
	CFilterScreen* m_filterScreen;
public:
	//	Constructors & destructor.
	CDexGui();
	virtual ~CDexGui();

	//	Methods.
	void start();
	void swapScreen(std::string newScreen);

	//	Getters.
	Gtk::Window* getWindow();
	Gtk::Notebook* getNotebook();
	CDexConnector* getDex();
	CMainScreen* getMainScreen();
	CFilterScreen* getFilterScreen();

	//	Setters.
	void setMainScreen(CMainScreen* main);
	void setFilterScreen(CFilterScreen* filter);
};