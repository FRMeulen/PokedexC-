//	Project:	PokedexC++.
//	MainScreen.cpp	--	Implementation of the CMainScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "MainScreen.h"

//	Definitions.
#define	posMainScreen	0
#define	posFilterScreen	1

//	Constructor.
CMainScreen::CMainScreen(Gtk::Notebook& par) : parent(&par) {
	//	Build screen.
	this->pack_start(m_framesVBox, Gtk::PACK_EXPAND_WIDGET, 5);

	m_framesVBox.pack_start(m_resultsFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_resultsFrame.add(m_placeholder);

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

}

//	toFilterScreen	--	Sets notebook page to filter screen.
//	Parameters:	none.
//	Returns:	void.
void CMainScreen::toFilterScreen() {
	parent->set_current_page(1);
}