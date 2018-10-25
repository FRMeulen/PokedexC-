#include "MainScreen.h"

CMainScreen::CMainScreen() {
	//Build screen
	this->pack_start(m_framesVBox, Gtk::PACK_EXPAND_WIDGET, 5);

	m_framesVBox.pack_start(m_resultsFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_resultsFrame.add(m_placeholder);

	m_framesVBox.pack_start(m_specifyFrame, Gtk::PACK_SHRINK, 10);
		m_specifyFrame.add(m_specifyHBox);
			m_specifyHBox.pack_start(m_filterOneButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_specifyHBox.pack_start(m_filterTwoButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_specifyHBox.pack_start(m_searchButton, Gtk::PACK_EXPAND_WIDGET, 10);

	//Configure widgets
	m_resultsFrame.set_border_width(10);
	m_specifyFrame.set_border_width(10);
}

CMainScreen::~CMainScreen() {

}