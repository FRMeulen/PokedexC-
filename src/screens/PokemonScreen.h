//	Project:	PokedexC++.
//	PokemonScreen.h	--	Interface for the CPokemonScreen class.
//	Revisions:
//	2018-12-06	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include <cppconn/resultset.h>
#include "../DexGui.h"
#include "MainScreen.h"
#include "subscreens/PokeInfoSub.h"

//	Class interface.
class CPokemonScreen {
protected:
	//	Gui pointer.
	CDexGui* m_gui;

	//	Subscreen pointers.
	CPokeInfoSub* m_pokeInfoSub;

	//	Pokemon information.
	sql::ResultSet* m_queryRes;

	//	Data related variables.
	std::string m_currentSubScreen = "info";

	//	Child widget pointers.
	Gtk::Box* m_mainVBox;
		Gtk::Box* m_subScreenBox;

		Gtk::Frame* m_optionsFrame;
			Gtk::Box* m_optionsHBox;
				Gtk::Button* m_infoButton;
				Gtk::Button* m_movesButton;
				Gtk::Button* m_matchupButton;
				Gtk::Button* m_statsButton;
				Gtk::Button* m_backButton;

public:
	//	Constructors & destructor.
	CPokemonScreen(CDexGui *parmGui);
	virtual ~CPokemonScreen();

	//	Methods.
	void swapScreen(std::string newScreen);
	void swapSubScreen(std::string newSubScreen);

	//	Setters.
	void setPokemon(sql::ResultSet *res);
};