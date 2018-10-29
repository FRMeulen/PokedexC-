//	Project:	PokedexC++.
//	MainScreen.cpp	--	Implementation of the CMainScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "MainScreen.h"

//	Definitions.
#define	posMainScreen		0
#define	posFilterScreen		1
#define posPokemonScreen	2

//	Constructor.
CMainScreen::CMainScreen(Gtk::Notebook& par, CDexConnector* dex, std::string query) : parent(&par), m_dex(dex), m_query(query) {
	//	Build screen.
	this->pack_start(m_framesVBox, Gtk::PACK_EXPAND_WIDGET, 5);

	m_framesVBox.pack_start(m_resultsFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_resultsFrame.add(m_scrollWindow);
			m_scrollWindow.add(m_resultsListVBox);
				setResultEntries(m_query);

	m_framesVBox.pack_start(m_specifyFrame, Gtk::PACK_SHRINK, 10);
		m_specifyFrame.add(m_specifyHBox);
			m_specifyHBox.pack_start(m_filterOneButton, Gtk::PACK_EXPAND_WIDGET, 10);
				if (!m_filterOne.empty())
					m_filterOneButton.set_label(m_filterOne);

			m_specifyHBox.pack_start(m_filterTwoButton, Gtk::PACK_EXPAND_WIDGET, 10);
				if (!m_filterTwo.empty())
					m_filterTwoButton.set_label(m_filterTwo);

			m_specifyHBox.pack_start(m_searchButton, Gtk::PACK_EXPAND_WIDGET, 10);

	//	Configure widgets.
	m_resultsFrame.set_border_width(10);
	m_specifyFrame.set_border_width(10);

	//	Signal handlers.
	m_filterOneButton.signal_clicked().connect(sigc::mem_fun(*this, &CMainScreen::toFilterScreen));
	m_filterTwoButton.signal_clicked().connect(sigc::mem_fun(*this, &CMainScreen::toFilterScreen));
}

//	Destructor.
CMainScreen::~CMainScreen() {
	m_resultsEntries.clear();
	if (m_resEntry != NULL) {
		delete m_resEntry;
	}
}

//	appendResultsEntry	--	Appends results entry to vector.
//	Parematers:
//		--	num		--	String of Pokemon number.
//		--	name	--	String of Pokemon name.
//		--	pritype	--	String of Pokemon primary type.
//		--	sectype	--	String of Pokemon secondary type.
//	Returns:	void.
void CMainScreen::appendResultsEntry(std::string num, std::string name, std::string pritype, std::string sectype) {
	m_resEntry = new CResultsEntry();
	m_resEntry->setEntryData(num, name, pritype, sectype);
	m_resultsEntries.push_back(m_resEntry);
}

//	displayResultsEntries	--	Displays vector contents on screen.
//	Parameters:	none.
//	Returns:	void.
void CMainScreen::setResultEntries(std::string newQuery) {
	//	Update resultset
	m_queryRes = m_dex->retrieveData(m_query);

	//	Clear vector.
	m_resultsEntries.clear();

	//	Append new entries.
	while (m_queryRes->next()) {
		std::string _num = m_queryRes->getString("pokemon_number");
		std::string _name = m_queryRes->getString("pokemon_name");
		std::string _pritype = m_queryRes->getString("pokemon_primary_type");
		std::string _sectype = m_queryRes->getString("pokemon_secondary_type");
		appendResultsEntry(_num, _name, _pritype, _sectype);
	}

	for (int i = 0; i < m_resultsEntries.size(); i++) {
		m_resEntry  = m_resultsEntries.at(i);
		m_resultsListVBox.pack_start(*m_resEntry, Gtk::PACK_SHRINK, 5);
	}
}

//	toFilterScreen	--	Sets notebook page to filter screen.
//	Parameters:
//		--	num	--	Filter number.
//	Returns:	void.
void CMainScreen::toFilterScreen() {
	parent->set_current_page(posFilterScreen);
}

//	addFilter	--	Adds filter to query results.
//	Parameters:
//		--	filterNum	--	Number of filter.
//		--	filter		--	String of filter.
//	Returns:	void.
void CMainScreen::addFilter(int filterNum, std::string filter) {
	if (filterNum == 1) {
		//	Set first filter.
	} else if (filterNum == 2) {
		//	Set second filter.
	} else {
		//	Invalid filter num.
	}
}

//	toPokemonScreen	--	Sets notebook page to pokemon screen.
//	Parameters:
//		--	num	--	String of Pokemon number.
//	Returns:	void.
void CMainScreen::toPokemonScreen(std::string num) {
	parent->set_current_page(posPokemonScreen);
}