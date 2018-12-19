//	Project:	PokedexC++.
//	PokeInfoSub.cpp	--	Implementation of the CPokeInfoSub class.
//	Revisions:
//	2018-12-10	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "PokeInfoSub.h"
#include <iostream>

//	Constructor.
//	Parameters:
//		parmGui	--	pointer to GUI.
//		res		--	pointer to ResultSet containing Pokemon Info.
CPokeInfoSub::CPokeInfoSub(CDexGui *parmGui, sql::ResultSet *res) : m_gui(parmGui), m_res(res) {
	//	Tracing.
	std::cout << "[POKEINFOSUB]	--	constructor called." << std::endl;

	//	Get information.
	m_res->next();

	//	Store information.
	std::string strPokeNum = m_res->getString("pokemon_number");
	std::string strPokeName = m_res->getString("pokemon_name");
	std::string strPokePriType = m_res->getString("pokemon_primary_type");
	std::string strPokeSecType = m_res->getString("pokemon_secondary_type");
	std::string strPokeHeight = m_res->getString("pokemon_height");
	std::string strPokeWeight = m_res->getString("pokemon_weight");
	std::string strPokeSpecies = m_res->getString("pokemon_species");
	std::string strSpritePath = "res/sprites/" + strPokeNum + ".png";

	//	Get pokedex entry.
	std::string entryQuery = "SELECT * FROM pokedex_entries WHERE pokemon_number = '" + res->getString("pokemon_number") + "';";
	sql::ResultSet* dexEntry = m_gui->getDex()->retrieveData(entryQuery);
	dexEntry->next();
	std::string strPokeEntry = dexEntry->getString("pokemon_description");

	//	Build child widgets.
	m_pokeMainVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_pokeMainHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			m_pokeSpriteFrame = new Gtk::Frame();
				m_pokeSpriteVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_pokeSprite = new Gtk::Image(strSpritePath);
					m_pokeSpeciesFrame = new Gtk::Frame();
						m_pokeSpecies = new Gtk::Label(strPokeSpecies);

			m_pokeInfoFrame = new Gtk::Frame("Information");
				m_pokeInfoVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_pokeNumFrame = new Gtk::Frame();
						m_pokeNumHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_pokeNumText = new Gtk::Label("Number: ");
							m_pokeNum = new Gtk::Label(strPokeNum);

					m_pokeNameFrame = new Gtk::Frame();
						m_pokeNameHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_pokeNameText = new Gtk::Label("Name: ");
							m_pokeName = new Gtk::Label(strPokeName);

					m_pokeTypesVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
						m_pokeTypesText = new Gtk::Label("Types");
						m_pokeTypesHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_pokePriTypeFrame = new Gtk::Frame();
								m_pokePriType = new Gtk::Label(strPokePriType);

							m_pokeSecTypeFrame = new Gtk::Frame();
								m_pokeSecType = new Gtk::Label(strPokeSecType);

					m_pokeHeightWeightHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
						m_pokeHeightFrame = new Gtk::Frame();
							m_pokeHeightVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
								m_pokeHeightText = new Gtk::Label("Height");
								m_pokeHeight = new Gtk::Label(strPokeHeight);

						m_pokeWeightFrame = new Gtk::Frame();
							m_pokeWeightVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
								m_pokeWeightText = new Gtk::Label("Weight");
								m_pokeWeight = new Gtk::Label(strPokeWeight);

		m_pokeEntryFrame = new Gtk::Frame();
			m_pokeEntry = new Gtk::Label(strPokeEntry);

	//	Build screen.
	m_pokeMainVBox->pack_start(*m_pokeMainHBox, Gtk::PACK_EXPAND_WIDGET, 5);
		m_pokeMainHBox->pack_start(*m_pokeSpriteFrame, Gtk::PACK_EXPAND_WIDGET, 5);
			m_pokeSpriteFrame->add(*m_pokeSpriteVBox);
				m_pokeSpriteVBox->pack_start(*m_pokeSprite, Gtk::PACK_EXPAND_WIDGET, 5);
				m_pokeSpriteVBox->pack_start(*m_pokeSpeciesFrame, Gtk::PACK_SHRINK, 5);
					m_pokeSpeciesFrame->add(*m_pokeSpecies);

		m_pokeMainHBox->pack_start(*m_pokeInfoFrame, Gtk::PACK_EXPAND_WIDGET, 5);
			m_pokeInfoFrame->add(*m_pokeInfoVBox);
				m_pokeInfoVBox->pack_start(*m_pokeNumFrame, Gtk::PACK_EXPAND_WIDGET, 5);
					m_pokeNumFrame->add(*m_pokeNumHBox);
						m_pokeNumHBox->pack_start(*m_pokeNumText, Gtk::PACK_EXPAND_WIDGET, 5);
						m_pokeNumHBox->pack_start(*m_pokeNum, Gtk::PACK_EXPAND_WIDGET, 5);

				m_pokeInfoVBox->pack_start(*m_pokeNameFrame, Gtk::PACK_EXPAND_WIDGET, 5);
					m_pokeNameFrame->add(*m_pokeNameHBox);
						m_pokeNameHBox->pack_start(*m_pokeNameText, Gtk::PACK_EXPAND_WIDGET, 5);
						m_pokeNameHBox->pack_start(*m_pokeName, Gtk::PACK_EXPAND_WIDGET, 5);
					
				m_pokeInfoVBox->pack_start(*m_pokeTypesVBox, Gtk::PACK_EXPAND_WIDGET, 5);
					m_pokeTypesVBox->pack_start(*m_pokeTypesText, Gtk::PACK_EXPAND_WIDGET, 5);
					m_pokeTypesVBox->pack_start(*m_pokeTypesHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_pokeTypesHBox->pack_start(*m_pokePriTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
							m_pokePriTypeFrame->add(*m_pokePriType);

						m_pokeTypesHBox->pack_start(*m_pokeSecTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
							m_pokeSecTypeFrame->add(*m_pokeSecType);

				m_pokeInfoVBox->pack_start(*m_pokeHeightWeightHBox, Gtk::PACK_EXPAND_WIDGET, 5);
					m_pokeHeightWeightHBox->pack_start(*m_pokeHeightFrame, Gtk::PACK_EXPAND_WIDGET, 5);
						m_pokeHeightFrame->add(*m_pokeHeightVBox);
							m_pokeHeightVBox->pack_start(*m_pokeHeightText, Gtk::PACK_EXPAND_WIDGET, 5);
							m_pokeHeightVBox->pack_start(*m_pokeHeight, Gtk::PACK_EXPAND_WIDGET, 5);

					m_pokeHeightWeightHBox->pack_start(*m_pokeWeightFrame, Gtk::PACK_EXPAND_WIDGET, 5);
						m_pokeWeightFrame->add(*m_pokeWeightVBox);
							m_pokeWeightVBox->pack_start(*m_pokeWeightText, Gtk::PACK_EXPAND_WIDGET, 5);
							m_pokeWeightVBox->pack_start(*m_pokeWeight, Gtk::PACK_EXPAND_WIDGET, 5);

	m_pokeMainVBox->pack_start(*m_pokeEntryFrame, Gtk::PACK_SHRINK, 5);
		m_pokeEntryFrame->add(*m_pokeEntry);

	//	Set frame borders.
	m_pokeSpriteFrame->set_border_width(10);
	m_pokeSpeciesFrame->set_border_width(5);
	m_pokeNumFrame->set_border_width(5);
	m_pokeNameFrame->set_border_width(5);
	m_pokePriTypeFrame->set_border_width(5);
	m_pokeSecTypeFrame->set_border_width(5);
	m_pokeHeightFrame->set_border_width(5);
	m_pokeWeightFrame->set_border_width(5);
	m_pokeInfoFrame->set_border_width(10);
	m_pokeEntryFrame->set_border_width(10);

	//	Configure labels.
	m_pokeEntry->set_single_line_mode(false);
}

//	Destructor.
//	Parameters:	none.
CPokeInfoSub::~CPokeInfoSub() {

}

//	getMainBox	--	Returns pointer to main box.
//	Parameters:	none.
//	Returns:	pointer to main box.
Gtk::Box* CPokeInfoSub::getMainBox() {
	return m_pokeMainVBox;
}