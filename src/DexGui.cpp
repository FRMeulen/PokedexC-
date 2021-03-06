//	Project:	PokedexC++
//	DexGui.cpp	--	Implementation of the CDexGui class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.
//	2018-12-04	--	F.R. van der Meulen --	Fixed copying DexGui instead of referencing it.

//	Include files.
#include "DexGui.h"
#include <iostream>

//	Definitions.
#define mainScreenPage		0
#define filterScreenPage	1
#define pokemonScreenPage	2

//	Constructor.
//	Parameters:	none.
CDexGui::CDexGui() {
	//	Tracing.
	std::cout << "[DEXGUI]	--	constructor called." << std::endl;

	//	Create app & window.
	app = Gtk::Application::create();
	m_window = new Gtk::Window();
	m_pages = new Gtk::Notebook();
	
	//	Configure window.
	m_window->set_title("PokedexC++");
	m_window->set_default_size(1024, 768);
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
	//	Tracing.
	std::cout << "[DEXGUI]	--	destructor called." << std::endl;
}

//	start	--	Starts application.
//	Parameters:	none.
//	Returns:	void.
void CDexGui::start() {
	//	Tracing.
	std::cout << "[DEXGUI]	--	start called." << std::endl;
	
	m_pages->set_current_page(mainScreenPage);
	m_window->show_all_children();
	app->run(*m_window);
}

//	swapScreen	--	Switches active screen.
//	Parameters:
//		newScreen	--	String of screen name.
//	Returns:	void.
void CDexGui::swapScreen(std::string newScreen) {
	//	Tracing.
	std::cout << "[DEXGUI]	--	swapScreen called -> newScreen=" << newScreen << "." << std::endl;

	if (newScreen == "mainscreen")
		m_pages->set_current_page(mainScreenPage);
	else if (newScreen == "filterscreen")
		m_pages->set_current_page(filterScreenPage);
	else if (newScreen == "pokemonscreen")
		m_pages->set_current_page(pokemonScreenPage);

	//	Update GUI.
	m_window->show_all_children();
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
Gtk::Notebook* CDexGui::getNotebook() {
	return m_pages;
}

//	getDex	--	Returns pointer to dexconnector.
//	Parameters:	none.
//	Returns:	pointer to dexconnector.
CDexConnector* CDexGui::getDex() {
	return m_dex;
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

//	getPokemonScreen	--	Returns pointer to pokemon screen.
//	Parameters:	none.
//	Returns:	pointer to pokemon screen.
CPokemonScreen* CDexGui::getPokemonScreen() {
	return m_pokemonScreen;
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

//	setPokemonScreen	--	Sets gui pokemon screen.
//	Parameters:
//		pokemon	--	pointer to pokemon screen object.
//	Returns:	void.
void CDexGui::setPokemonScreen(CPokemonScreen* pokemon) {
	m_pokemonScreen = pokemon;
}