//	Project:	PokedexC++.
//	MainScreen.h	--	Interface for the CMainScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include <cppconn/resultset.h>
#include "DexGui.h"
#include "DexConnector.h"
#include "FilterScreen.h"

//	Predefinitions.
//class CResultsEntry;

//	Class interface.
class CMainScreen {
protected:
	//	Gui pointer.
	CDexGui* m_gui;

	//	Data-related fields.
	sql::ResultSet* m_queryRes;
	std::string m_query;
	std::string m_filterOne;
	std::string m_filterTwo;

	//	Child widget pointers.
	Gtk::Box* m_framesVBox;
		Gtk::Frame* m_resultsFrame;
			Gtk::ScrolledWindow* m_scrollWindow;
				Gtk::Box* m_resultsListVBox;
					//std::vector<CResultsEntry*> m_resultsEntries;
					//CResultsEntry* m_resEntry;

		Gtk::Frame* m_specifyFrame;
			Gtk::Box* m_specifyHBox;
				Gtk::Button* m_filterOneButton;
				Gtk::Button* m_filterTwoButton;
				Gtk::Button* m_searchButton;
public:
	//	Constructors & desctructor.
	CMainScreen(CDexGui parmGui);
	virtual ~CMainScreen();

	//	Methods.
	void swapScreen(std::string newScreen);
	//void appendResultsEntry(CResultsEntry* entry);
	
	//	Getters.
	void getQueryResults(std::string query);

	//	Setters.
	void setQuery(std::string newQuery);
	void setFilter(int filterNum, std::string filter);
};