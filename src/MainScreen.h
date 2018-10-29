//	Project:	PokedexC++.
//	MainScreen.h	--	Interface for the CMainScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include <cppconn/resultset.h>
#include "DexConnector.h"
#include "ResultsEntry.h"

//	Class interface.
class CMainScreen : public Gtk::Box {
protected:
	//	Parent notebook pointer.
	Gtk::Notebook* parent;
	CDexConnector* m_dex;
	sql::ResultSet* m_queryRes;
	std::string m_query;
	std::string m_filterOne;
	std::string m_filterTwo;

	//	Child widgets.
	Gtk::Box m_framesVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		Gtk::Frame m_resultsFrame = Gtk::Frame("Results");
			Gtk::ScrolledWindow m_scrollWindow;
				Gtk::Box m_resultsListVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					std::vector<CResultsEntry*> m_resultsEntries;
					CResultsEntry *m_resEntry;

		Gtk::Frame m_specifyFrame = Gtk::Frame("Specify");
			Gtk::Box m_specifyHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				Gtk::Button m_filterOneButton	=	Gtk::Button("Filter 1: ---");
				Gtk::Button m_filterTwoButton	=	Gtk::Button("Filter 2: ---");
				Gtk::Button m_searchButton		=	Gtk::Button("Search");
public:
	//	Constructors & desctructor.
	CMainScreen(Gtk::Notebook& par, CDexConnector* dex, std::string query);
	virtual ~CMainScreen();

	//	Methods.
	void appendResultsEntry(std::string num, std::string name, std::string pritype, std::string sectype);
	void setResultEntries(std::string query);
	void toFilterScreen();
	void addFilter(int filterNum, std::string filter);
	void toPokemonScreen(std::string num);
};