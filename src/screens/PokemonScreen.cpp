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
		m_pokeMainVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
			m_pokeMainHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_pokeSpriteFrame = new Gtk::Frame();
					m_pokeSpriteVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
						m_pokeSprite = new Gtk::Image();
						m_pokeSpeciesFrame = new Gtk::Frame();
							m_pokeSpecies = new Gtk::Label();

				m_pokeInfoFrame = new Gtk::Frame("Information");
					m_pokeInfoVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
						m_pokeNumHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_pokeNumText = new Gtk::Label("Number: ");
							m_pokeNum = new Gtk::Label();

						m_pokeNameHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_pokeNameText = new Gtk::Label("Name: ");
							m_pokeName = new Gtk::Label();

						m_pokeTypesVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
							m_pokeTypesText = new Gtk::Label("Types");
							m_pokeTypesHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
								m_pokePriTypeFrame = new Gtk::Frame();
									m_pokePriType = new Gtk::Label();

								m_pokeSecTypeFrame = new Gtk::Frame();
									m_pokeSecType = new Gtk::Label();

						m_pokeHeightWeightHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_pokeHeightVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
								m_pokeHeightText = new Gtk::Label("Height");
								m_pokeHeight = new Gtk::Label();

							m_pokeWeightVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
								m_pokeWeightText = new Gtk::Label("Weight");
								m_pokeWeight = new Gtk::Label();

			m_pokeEntryFrame = new Gtk::Frame();
				m_pokeEntryLabel = new Gtk::Label();

		m_optionsFrame = new Gtk::Frame("Options");
			m_optionsHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_infoButton = new Gtk::Button("Info");
				m_movesButton = new Gtk::Button("Moves");
				m_matchupButton = new Gtk::Button("Matchups");
				m_statsButton = new Gtk::Button("Stats");
				m_backButton = new Gtk::Button("Back");

	//	Configure widgets.
	m_pokeSpriteFrame->set_border_width(10);
	m_pokeInfoFrame->set_border_width(10);
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
	std::cout << "[POKEMONSCREEN]	--	swapScreen called -> newScreen='" << newScreen << "'." << std::endl;

	m_gui->swapScreen(newScreen);
}

//	setPokemon	--	Sets target Pokemon.
//	Parameters:
//		num	--	string of Pokemon number.
//	Returns:	void.
void CPokemonScreen::setPokemon(sql::ResultSet* res) {
	//	Tracing.
	std::cout << "[POKEMONSCREEN]	--	setPokemon called." << std::endl;

	//	Get results.

	//	Set label texts.
}