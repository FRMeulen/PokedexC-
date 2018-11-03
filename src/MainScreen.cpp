//	Project:	PokedexC++.
//	MainScreen.cpp	--	Implementation of the CMainScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Include files.
#include "MainScreen.h"
#include <iostream>

//	Constructor.
//	Parameters:
//		parmGui	--	Gui containing this screen.
CMainScreen::CMainScreen(CDexGui parmGui) : m_gui(&parmGui) {
	//	Build child widgets.
	m_framesVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_resultsFrame = new Gtk::Frame("Results");
			m_scrollWindow = new Gtk::ScrolledWindow();
				m_resultsListVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

		m_specifyFrame = new Gtk::Frame("Specify");
			m_specifyHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_filterOneVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_filterOneLabel = new Gtk::Label("Filter one: ---");
					m_filterOneButton = new Gtk::Button("SELECT");
				
				m_filterTwoVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_filterTwoLabel = new Gtk::Label("Filter two: ---");
					m_filterTwoButton = new Gtk::Button("SELECT");
				
				m_searchButton = new Gtk::Button("Search");

	//	Build screen.
	m_framesVBox->pack_start(*m_resultsFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_resultsFrame->add(*m_scrollWindow);
			m_scrollWindow->add(*m_resultsListVBox);
				getQueryResults("SELECT * FROM pokemon;");

	m_framesVBox->pack_start(*m_specifyFrame, Gtk::PACK_SHRINK, 10);
		m_specifyFrame->add(*m_specifyHBox);
			m_specifyHBox->pack_start(*m_filterOneVBox, Gtk::PACK_EXPAND_WIDGET, 10);
				m_filterOneVBox->pack_start(*m_filterOneLabel, Gtk::PACK_SHRINK, 10);
				m_filterOneVBox->pack_start(*m_filterOneButton, Gtk::PACK_SHRINK, 10);

			m_specifyHBox->pack_start(*m_filterTwoVBox, Gtk::PACK_EXPAND_WIDGET, 10);
				m_filterTwoVBox->pack_start(*m_filterTwoLabel, Gtk::PACK_SHRINK, 10);
				m_filterTwoVBox->pack_start(*m_filterTwoButton, Gtk::PACK_SHRINK, 10);
			
			m_specifyHBox->pack_start(*m_searchButton, Gtk::PACK_EXPAND_WIDGET, 10);

	//	Configure widgets.
	m_resultsFrame->set_border_width(10);
	m_specifyFrame->set_border_width(10);

	//	Signal handlers.
	m_filterOneButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CMainScreen::swapScreen), "filterscreen1"));
	m_filterTwoButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CMainScreen::swapScreen), "filterscreen2"));

	//	Make self known to Gui.
	m_gui->setMainScreen(this);
	m_gui->getNotebook()->append_page(*m_framesVBox);
}

//	Destructor.
//	Parameters:	none.
CMainScreen::~CMainScreen() {
	m_gui->setMainScreen(NULL);

	m_resultsEntries.clear();
}

//	swapScreen	--	Tells the window to switch screens.
//	Parameters:
//		newScreen	--	String of new screen name.
//	Returns:	void.
void CMainScreen::swapScreen(std::string newScreen) {
	if (newScreen == "filterscreen1") {
		std::cout << "MainScreen: setting filter num to 1" << std::endl;
		m_filterScreen->setFilterNum(1);
		swapScreen("filterscreen");
	} else if (newScreen == "filterscreen2") {
		m_filterScreen->setFilterNum(2);
		swapScreen("filterscreen");
	} else {
		m_gui->swapScreen(newScreen);
	}
}

//	appendResultsEntry	--	Appends results entry to vector.
//	Parameters:
//		--	num		--	String of Pokemon number.
//		--	name	--	String of Pokemon name.
//		--	pritype	--	String of Pokemon primary type.
//		--	sectype	--	String of Pokemon secondary type.
//	Returns:	void.
void CMainScreen::appendResultsEntry(CResultsEntry* entry) {
	m_resultsEntries.push_back(entry);
	Gtk::Frame* entryFrame = entry->getMainFrame();
	m_resultsListVBox->pack_start(*entryFrame, Gtk::PACK_SHRINK, 5);
}

//	updatePointers	--	Updates pointers to other screens.
//	Parameters:
//		newFilterScreen	--	Filter Screen
//	Returns:	none.
void CMainScreen::updatePointers(CFilterScreen newFilterScreen) {
	m_filterScreen = &newFilterScreen;
}

//	displayResultsEntries	--	Displays vector contents on screen.
//	Parameters:	none.
//	Returns:	void.
void CMainScreen::getQueryResults(std::string newQuery) {
	//	Clear vector.
	m_resultsEntries.clear();

	//	Update resultset
	m_queryRes = m_gui->getDex()->retrieveData(newQuery);

	while (m_queryRes->next()) {
		m_resEntry = new CResultsEntry();

		std::string _num = m_queryRes->getString("pokemon_number");
		std::string _name = m_queryRes->getString("pokemon_name");
		std::string _pritype = m_queryRes->getString("pokemon_primary_type");
		std::string _sectype = m_queryRes->getString("pokemon_secondary_type");

		m_resEntry->setEntryData(_num, _name, _pritype, _sectype);
		appendResultsEntry(m_resEntry);
	}
}

//	setQuery	--	Sets query string.
//	Parameters:
//		newQuery	--	String of new query.
//	Returns:	void.
void CMainScreen::setQuery(std::string newQuery) {
	m_query = newQuery;
}

//	setFilter	--	Sets filter string.
//	Parameters:
//		filterNum	--	Int deciding which filter is filled.
//		filter	--	String containing filter.
//	Returns:	void.
void CMainScreen::setFilter(int filterNum, std::string filter) {
	if (filterNum == 1) {
		m_filterOneLabel->set_text("Filter 1: " + filter);
	} else if (filterNum == 2) {
		m_filterTwoLabel->set_text("Filter 2: " + filter);
	}
}