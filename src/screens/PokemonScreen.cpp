//	Project:	PokedexC++.
//	PokemonScreen.cpp	--	Implementation of the CPokemonScreen class.
//	Revisions:
//	2018-12-06	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "PokemonScreen.h"
#include <iostream>

//	Constructor.
//	Parameters:
//		parmGui	--	Gui containing this screen.
CPokemonScreen::CPokemonScreen(CDexGui *parmGui) : m_gui(parmGui) {
	//	Tracing.
	std::cout << "[POKEMONSCREEN]	--	constructor called." << std::endl;

	//	Build child widgets.
	m_mainVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_subScreenBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);

		m_optionsFrame = new Gtk::Frame("Options");
			m_optionsHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_infoButton = new Gtk::Button("Info");
				m_movesButton = new Gtk::Button("Moves");
				m_matchupButton = new Gtk::Button("Matchups");
				m_statsButton = new Gtk::Button("Stats");
				m_backButton = new Gtk::Button("Back");

	//	Build screen.
	m_mainVBox->pack_start(*m_subScreenBox, Gtk::PACK_EXPAND_WIDGET, 10);
	m_mainVBox->pack_start(*m_optionsFrame, Gtk::PACK_SHRINK, 10);
		m_optionsFrame->add(*m_optionsHBox);
			m_optionsHBox->pack_start(*m_infoButton, Gtk::PACK_EXPAND_WIDGET, 5);
			m_optionsHBox->pack_start(*m_movesButton, Gtk::PACK_EXPAND_WIDGET, 5);
			m_optionsHBox->pack_start(*m_matchupButton, Gtk::PACK_EXPAND_WIDGET, 5);
			m_optionsHBox->pack_start(*m_statsButton, Gtk::PACK_EXPAND_WIDGET, 5);
			m_optionsHBox->pack_start(*m_backButton, Gtk::PACK_EXPAND_WIDGET, 5);

	//	Set frame borders.
	m_optionsFrame->set_border_width(10);

	//	Signal handlers.
	m_backButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CPokemonScreen::swapScreen), "mainscreen"));

	//	Make self known to Gui.
	m_gui->setPokemonScreen(this);
	m_gui->getNotebook()->append_page(*m_mainVBox);
}

//	Destructor.
//	Parameters:	none.
CPokemonScreen::~CPokemonScreen() {
	//	Tracing.
	std::cout << "[POKEMONSCREEN]	--	destructor called." << std::endl;

	//	Remove from Gui.
	m_gui->setPokemonScreen(NULL);
}

//	swapScreen	--	Tells the window to switch screens.
//	Parameters:
//		newScreen	--	String of new screen name.
//	Returns:	void.
void CPokemonScreen::swapScreen(std::string newScreen) {
	//	Tracing.
	std::cout << "[POKEMONSCREEN]	--	swapScreen called -> " << newScreen << "." << std::endl;

	//	Tell gui to swap screen.
	m_gui->swapScreen(newScreen);
}

//	swapSubScreen	--	Tells the window to switch subscreens.
//	Parameters:
//		newSubScreen	--	String of new sub screen name.
//	Returns:	void.
void CPokemonScreen::swapSubScreen(std::string newSubScreen) {
	//	Tracing.
	std::cout << "[POKEMONSCREEN]	--	swapSubScreen called -> " << newSubScreen << "." << std::endl;

	//	Determine new sub screen.
	if (newSubScreen == "info") {
		m_currentSubScreen = "info";
		m_pokeInfoSub = new CPokeInfoSub(m_gui, m_queryRes);
		Gtk::Box* tempBox = m_pokeInfoSub->getMainBox();
		m_subScreenBox->pack_start(*tempBox);
	} else if (newSubScreen == "moves") {
		m_currentSubScreen = "moves";
	} else if (newSubScreen == "matchup") {
		m_currentSubScreen = "matchup";
	} else if (newSubScreen == "stats") {
		m_currentSubScreen = "stats";
	}

	//	Update GUI.
	m_gui->getWindow()->show_all_children();
}

//	setPokemon	--	Sets target Pokemon.
//	Parameters:
//		num	--	string of Pokemon number.
//	Returns:	void.
void CPokemonScreen::setPokemon(sql::ResultSet* res) {
	//	Tracing.
	std::cout << "[POKEMONSCREEN]	--	setPokemon called." << std::endl;

	//	Store database results.
	m_queryRes = res;

	//	Set starting screen.
	swapSubScreen("info");
}