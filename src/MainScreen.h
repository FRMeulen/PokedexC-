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
#include "ResultsEntry.h"

//	Class interface.
class CMainScreen {
protected:
	//	Gui pointers.
	CDexGui* m_gui;

	//	Data-related fields.
	sql::ResultSet* m_queryRes;
	std::string m_query;

	//	Child widget pointers.
	Gtk::Box* m_framesVBox;
		Gtk::Frame* m_resultsFrame;
			Gtk::ScrolledWindow* m_scrollWindow;
				Gtk::Box* m_resultsListVBox;
					std::vector<CResultsEntry*>* m_resultsEntries;
					CResultsEntry* m_resEntry;

		Gtk::Frame* m_specifyFrame;
			Gtk::Box* m_specifyHBox;
				Gtk::Box* m_filterOneVBox;
					Gtk::Label* m_filterOneLabel;
					Gtk::Button* m_filterOneButton;
				
				Gtk::Box* m_filterTwoVBox;
					Gtk::Label* m_filterTwoLabel;
					Gtk::Button* m_filterTwoButton;
				
				Gtk::Button* m_searchButton;
public:
	//	Constructors & desctructor.
	CMainScreen(CDexGui *parmGui);
	CMainScreen(const CMainScreen& main);
	CMainScreen& operator=(const CMainScreen& main);
	virtual ~CMainScreen();

	//	Methods.
	void swapScreen(std::string newScreen);
	void appendResultsEntry(CResultsEntry* entry);
	void updateQuery();

	//	Getters.
	void getQueryResults(std::string query);

	//	Setters.
	void setQuery(std::string newQuery);
	void setFilter(int filterNum, std::string filter);
};