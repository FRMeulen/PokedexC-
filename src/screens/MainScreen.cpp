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
CMainScreen::CMainScreen(Gtk::Notebook& par, sql::ResultSet* res) : parent(&par), m_queryRes(res) {
	//	Build screen.
	this->pack_start(m_framesVBox, Gtk::PACK_EXPAND_WIDGET, 5);

	m_framesVBox.pack_start(m_resultsFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_resultsFrame.add(m_scrollWindow);
			m_scrollWindow.add(m_resultsListVBox);
				displayResultsEntries();

	m_framesVBox.pack_start(m_specifyFrame, Gtk::PACK_SHRINK, 10);
		m_specifyFrame.add(m_specifyHBox);
			m_specifyHBox.pack_start(m_filterOneButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_specifyHBox.pack_start(m_filterTwoButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_specifyHBox.pack_start(m_searchButton, Gtk::PACK_EXPAND_WIDGET, 10);

	//	Configure widgets.
	m_resultsFrame.set_border_width(10);
	m_specifyFrame.set_border_width(10);

	//	Signal handlers.
	m_filterOneButton.signal_clicked().connect(sigc::mem_fun(*this, &CMainScreen::toFilterScreen));
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
void CMainScreen::displayResultsEntries() {
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
//	Parameters:	none.
//	Returns:	void.
void CMainScreen::toFilterScreen() {
	parent->set_current_page(posFilterScreen);
}

//	toPokemonScreen	--	Sets notebook page to pokemon screen.
//	Parameters:
//		--	num	--	String of Pokemon number
//	Returns:	void.
void CMainScreen::toPokemonScreen(std::string num) {
	parent->set_current_page(posPokemonScreen);
}