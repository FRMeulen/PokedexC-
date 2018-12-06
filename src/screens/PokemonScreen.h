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

//	Class interface.
class CPokemonScreen {
protected:
	//	Gui pointer.
	CDexGui* m_gui;

	//	Pokemon information.
	sql::ResultSet* m_queryRes;

	//	Child widget pointers.
	Gtk::Box* m_mainVBox;
		Gtk::Box* m_pokeMainVBox;
			Gtk::Box* m_pokeMainHBox;
				Gtk::Frame* m_pokeSpriteFrame;
					Gtk::Box* m_pokeSpriteVBox;
						Gtk::Image* m_pokeSprite;
						Gtk::Frame* m_pokeSpeciesFrame;
							Gtk::Label* m_pokeSpecies;
				
				Gtk::Frame* m_pokeInfoFrame;
					Gtk::Box* m_pokeInfoVBox;
						Gtk::Box* m_pokeNumHBox;
							Gtk::Label* m_pokeNumText;
							Gtk::Label* m_pokeNum;

						Gtk::Box* m_pokeNameHBox;
							Gtk::Label* m_pokeNameText;
							Gtk::Label* m_pokeName;

						Gtk::Box* m_pokeTypesVBox;
							Gtk::Label* m_pokeTypesText;
							Gtk::Box* m_pokeTypesHBox;
								Gtk::Frame* m_pokePriTypeFrame;
									Gtk::Label* m_pokePriType;

								Gtk::Frame* m_pokeSecTypeFrame;
									Gtk::Label* m_pokeSecType;

						Gtk::Box* m_pokeHeightWeightHBox;
							Gtk::Box* m_pokeHeightVBox;
								Gtk::Label* m_pokeHeightText;
								Gtk::Label* m_pokeHeight;

							Gtk::Box* m_pokeWeightVBox;
								Gtk::Label* m_pokeWeightText;
								Gtk::Label* m_pokeWeight;

			Gtk::Frame* m_pokeEntryFrame;
				Gtk::Label* m_pokeEntryLabel;

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

	//	Setters.
	void setPokemon(sql::ResultSet *res);
};