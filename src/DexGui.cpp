//	Project:	PokedexC++
//	DexGui.cpp	--	Implementation of the CDexGui class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Include files.
#include "DexGui.h"

//	Definitions.
#define mainScreenPage 0
#define filterScreenPage 1

//	Constructor.
//	Parameters:	none.
CDexGui::CDexGui() {
	//	Create app & window.
	app = Gtk::Application::create();
	m_window = new Gtk::Window();
	m_pages = new Gtk::Notebook();
	
	//	Configure window.
	m_window->set_title("PokedexC++");
	m_window->set_default_size(800, 600);
	m_window->set_resizable(false);
	m_window->add(*m_pages);
	m_window->show_all_children();

	//	Configure notebook.
	m_pages->set_show_tabs(false);

	//	Create dex connector.
	m_dex = new CDexConnector();
}

//	Destructor.
CDexGui::~CDexGui() {
	
}

//	start	--	Starts application.
//	Parameters:	none.
//	Returns:	void.
void CDexGui::start() {
	m_pages->set_current_page(mainScreenPage);
	m_window->show_all_children();
	app->run(*m_window);
}

//	swapScreen	--	Switches active screen.
//	Parameters:
//		newScreen	--	String of screen name.
//	Returns:	void.
void CDexGui::swapScreen(std::string newScreen) {
	if (newScreen == "mainscreen")
		m_pages->set_current_page(mainScreenPage);
	else if (newScreen == "filterscreen")
		m_pages->set_current_page(filterScreenPage);
}

//	fillEntries	--	Fills main screen with entries.
//	Parameters:
//		query	--	Query to make entries with.
//	Returns:	void.
void CDexGui::fillEntries(std::string query) {
	m_queryRes = m_dex->retrieveData(query);

	while (m_queryRes->next()) {
		m_entry = new CResultsEntry(*m_mainScreen);

		std::string _num = m_queryRes->getString("pokemon_number");
		std::string _name = m_queryRes->getString("pokemon_name");
		std::string _pritype = m_queryRes->getString("pokemon_primary_type");
		std::string _sectype = m_queryRes->getString("pokemon_secondary_type");

		m_entry->setEntryData(_num, _name, _pritype, _sectype);
		m_entry->appendToScreen();
	}
}

//	getWindow	--	Returns pointer to window.
//	Parameters:	none.
//	Returns:	pointer to app window.
Gtk::Window* CDexGui::getWindow() {
	return m_window;
}

//	getNotebook	--	Returns pointer to notebook.
//	Parameters:	none.
//	Returns:	pointer to notebook containing screens.
Gtk::Notebook& CDexGui::getScreens() {
	return *m_screens;
}

//	getMainScreen	--	Returns pointer to main screen.
//	Parameters:	none.
//	Returns:	pointer to main screen.
CMainScreen* CDexGui::getMainScreen() {
	return m_mainScreen;
}

//	getFilterScreen	--	Returns pointer to filter screen.
//	Parameters:	none.
//	Returns:	pointer to filter screen.
CFilterScreen* CDexGui::getFilterScreen() {
	return m_filterScreen;
}

//	setMainScreen	--	Sets gui main screen.
//	Parameters:
//		main	--	pointer to main screen object.
//	Returns:	void.
void CDexGui::setMainScreen(CMainScreen* main) {
	m_mainScreen = main;
}

//	setFilterScreen	--	Sets gui filter screen.
//	Parameters:
//		filter	--	pointer to filter screen object.
//	Returns:	void.
void CDexGui::setFilterScreen(CFilterScreen* filter) {
	m_filterScreen = filter;
}