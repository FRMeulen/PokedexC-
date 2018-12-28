//	Project:	PokedexC++.
//	PokeInfoSub.h	--	Interface for the CPokeInfoSub class.
//	Revisions:
//	2018-12-10	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include <cppconn/resultset.h>
#include "../../DexGui.h"

//	Class interface.
class CPokeInfoSub {
protected:
	//	Gui pointer.
	CDexGui* m_gui;

	//	Resultset pointer.
	sql::ResultSet* m_res;

	//	Data holder.
	std::string m_strPokeNum;
	int currentSprite = 0;

	//	Child widget pointers.
	Gtk::Box* m_pokeMainVBox;
		Gtk::Box* m_pokeMainHBox;
			Gtk::Frame* m_pokeSpriteFrame;
				Gtk::Box* m_pokeSpriteVBox;
					std::vector<Gtk::Image*>* m_pokeSpriteList;
					Gtk::Box* m_pokeSpritesHBox;
						Gtk::Box* m_pokePrevSpriteButtonHolder;
							Gtk::Button* m_pokePrevSpriteButton;

						Gtk::Box* m_pokeSpriteHolder;
							Gtk::Image* m_pokeSprite;
						
						Gtk::Box* m_pokeNextSpriteButtonHolder;
							Gtk::Button* m_pokeNextSpriteButton;

					Gtk::Frame* m_pokeSpeciesFrame;
						Gtk::Label* m_pokeSpecies;
				
			Gtk::Frame* m_pokeInfoFrame;
				Gtk::Box* m_pokeInfoVBox;
					Gtk::Frame* m_pokeNumFrame;	
						Gtk::Box* m_pokeNumHBox;
							Gtk::Label* m_pokeNumText;
							Gtk::Label* m_pokeNum;

					Gtk::Frame* m_pokeNameFrame;
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
						Gtk::Frame* m_pokeHeightFrame;
							Gtk::Box* m_pokeHeightVBox;
								Gtk::Label* m_pokeHeightText;
								Gtk::Label* m_pokeHeight;

						Gtk::Frame* m_pokeWeightFrame;
							Gtk::Box* m_pokeWeightVBox;
								Gtk::Label* m_pokeWeightText;
								Gtk::Label* m_pokeWeight;

		Gtk::Frame* m_pokeEntryFrame;
			Gtk::Label* m_pokeEntry;

	//	Methods.
	void prevSprite();
	void nextSprite();

public:
	//	Constructors & destructor.
	CPokeInfoSub(CDexGui* parmGui, std::string pokeNum);
	virtual ~CPokeInfoSub();

	//	Getters.
	Gtk::Box* getMainBox();
};