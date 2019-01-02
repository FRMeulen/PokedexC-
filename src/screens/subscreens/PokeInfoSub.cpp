//	Project:	PokedexC++.
//	PokeInfoSub.cpp	--	Implementation of the CPokeInfoSub class.
//	Revisions:
//	2018-12-10	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "PokeInfoSub.h"
#include <iostream>

//	Dummy constructor.
//	Parameters:	none.
CPokeInfoSub::CPokeInfoSub() {
	//	Tracing.
	std::cout << "[POKEINFOSUB]	--	dummy constructor called." << std::endl;

	//	Set dummy bool to true.
	dummy = true;
}

//	Constructor.
//	Parameters:
//		parmGui	--	pointer to GUI.
//		pokeNum		--	string of Pokemon number.
CPokeInfoSub::CPokeInfoSub(CDexGui *parmGui, std::string pokeNum) : m_gui(parmGui), m_strPokeNum(pokeNum) {
	//	Tracing.
	std::cout << "[POKEINFOSUB]	--	constructor called." << std::endl;

	//	Set dummy bool to false.
	dummy = false;

	//	Get data.
	std::string pokeQuery = "SELECT * FROM pokemon WHERE pokemon_number = '" + m_strPokeNum + "';";
	m_res = m_gui->getDex()->retrieveData(pokeQuery);

	//	Get information.
	m_res->next();

	//	Store information.
	std::string strPokeNum = m_strPokeNum;
	std::string strPokeName = m_res->getString("pokemon_name");
	std::string strPokePriType = m_res->getString("pokemon_primary_type");
	std::string strPokeSecType = m_res->getString("pokemon_secondary_type");
	std::string strPokeHeight = m_res->getString("pokemon_height");
	std::string strPokeWeight = m_res->getString("pokemon_weight");
	std::string strPokeSpecies = m_res->getString("pokemon_species");
	std::string strSpritePath = "res/sprites/" + strPokeNum + ".png";
	int pokeAltForms = m_res->getInt("pokemon_forms_count") - 1;

	//	Get pokedex entry.
	std::string entryQuery = "SELECT * FROM pokedex_entries WHERE pokemon_number = '" + m_strPokeNum + "';";
	sql::ResultSet* dexEntry = m_gui->getDex()->retrieveData(entryQuery);
	dexEntry->next();
	std::string strPokeEntry = dexEntry->getString("pokemon_description");

	//	Build child widgets.
	m_pokeMainVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_pokeMainHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			m_pokeSpriteFrame = new Gtk::Frame();
				m_pokeSpriteVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_pokeSpriteList = new std::vector<Gtk::Image*>();
					m_pokeSpritesHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
						m_pokePrevSpriteButtonHolder = new Gtk::Box();	
							//	m_pokePrevSpriteButton made if alt forms exist.
						m_pokeSpriteHolder = new Gtk::Box();
							std::cout << "Sprite from path: " << strSpritePath << std::endl;
							m_pokeSprite = new Gtk::Image(strSpritePath);
							m_pokeSpriteList->push_back(m_pokeSprite);
							
						m_pokeNextSpriteButtonHolder = new Gtk::Box();
							//	m_pokeNextSpriteButton made if alt forms exist.
					
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

		m_pokeEntryFrame = new Gtk::Frame("Pokedex Entry");
			m_pokeEntry = new Gtk::Label(strPokeEntry);

	//	Build screen.
	m_pokeMainVBox->pack_start(*m_pokeMainHBox, Gtk::PACK_EXPAND_WIDGET, 5);
		m_pokeMainHBox->pack_start(*m_pokeSpriteFrame, Gtk::PACK_EXPAND_WIDGET, 5);
			m_pokeSpriteFrame->add(*m_pokeSpriteVBox);
				m_pokeSpriteVBox->pack_start(*m_pokeSpritesHBox, Gtk::PACK_EXPAND_WIDGET, 5);
					m_pokeSpritesHBox->pack_start(*m_pokePrevSpriteButtonHolder, Gtk::PACK_SHRINK, 5);
						//	m_pokePrevSpriteButton added if alt forms exist.

					m_pokeSpritesHBox->pack_start(*m_pokeSpriteHolder, Gtk::PACK_EXPAND_WIDGET, 5);
						m_pokeSpriteHolder->pack_start(*m_pokeSprite, Gtk::PACK_EXPAND_WIDGET, 5);

					m_pokeSpritesHBox->pack_start(*m_pokeNextSpriteButtonHolder, Gtk::PACK_SHRINK, 5);
						//	m_pokeNextSpriteButton added if alt forms exist.

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

	//	Configure frames.
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

	//	Configure boxes.
	m_pokeTypesHBox->set_homogeneous(true);
	m_pokeHeightWeightHBox->set_homogeneous(true);

	//	Configure labels.
	m_pokeEntry->set_single_line_mode(false);

	//	Setup multi-sprite mode if alt-forms exist.
	if (pokeAltForms > 0) {
		//	Tracing.
		std::cout << "[POKEINFOSUB]	--	" << std::to_string(pokeAltForms) << " Alt form(s) detected!" << std::endl;

		//	Add sprite switching buttons.
		m_pokePrevSpriteButton = new Gtk::Button("<");
		m_pokeNextSpriteButton = new Gtk::Button(">");
		m_pokePrevSpriteButtonHolder->pack_start(*m_pokePrevSpriteButton, Gtk::PACK_EXPAND_WIDGET, 5);
		m_pokeNextSpriteButtonHolder->pack_start(*m_pokeNextSpriteButton, Gtk::PACK_EXPAND_WIDGET, 5);

		//	Get alt sprites.
		for (int i = 1; i <= pokeAltForms; i++) {
			std::string strAltSpritePath = "res/sprites/" + strPokeNum + ":" + std::to_string(i) + ".png";
			m_pokeSprite = new Gtk::Image(strAltSpritePath);
			m_pokeSpriteList->push_back(m_pokeSprite);
		}

		//	Signal handlers.
		m_pokePrevSpriteButton->signal_clicked().connect(sigc::mem_fun(*this, &CPokeInfoSub::prevSprite));
		m_pokeNextSpriteButton->signal_clicked().connect(sigc::mem_fun(*this, &CPokeInfoSub::nextSprite));
	}
}

//	Destructor.
//	Parameters:	none.
CPokeInfoSub::~CPokeInfoSub() {
	//	Tracing.
	std::cout << "[POKEINFOSUB]	--	destructor called." << std::endl;

	//	Stop if dummy.
	if (dummy)
		return;

	//	Delete sprites.
	m_pokeSpriteList->clear();

	//	Delete children in reverse order.
	delete m_pokeEntry;
	delete m_pokeEntryFrame;
	delete m_pokeWeight;
	delete m_pokeWeightText;
	delete m_pokeWeightVBox;
	delete m_pokeWeightFrame;
	delete m_pokeHeight;
	delete m_pokeHeightText;
	delete m_pokeHeightVBox;
	delete m_pokeHeightFrame;
	delete m_pokeHeightWeightHBox;
	delete m_pokeSecType;
	delete m_pokeSecTypeFrame;
	delete m_pokePriType;
	delete m_pokePriTypeFrame;
	delete m_pokeTypesHBox;
	delete m_pokeTypesText;
	delete m_pokeTypesVBox;
	delete m_pokeName;
	delete m_pokeNameText;
	delete m_pokeNameHBox;
	delete m_pokeNameFrame;
	delete m_pokeNum;
	delete m_pokeNumText;
	delete m_pokeNumHBox;
	delete m_pokeNumFrame;
	delete m_pokeInfoVBox;
	delete m_pokeInfoFrame;
	delete m_pokeSpecies;
	delete m_pokeSpeciesFrame;
	if (m_pokeNextSpriteButton != NULL)
		delete m_pokeNextSpriteButton;
	delete m_pokeNextSpriteButtonHolder;
	delete m_pokeSpriteHolder;
	if (m_pokePrevSpriteButton != NULL)
		delete m_pokePrevSpriteButton;
	delete m_pokePrevSpriteButtonHolder;
	delete m_pokeSpritesHBox;
	delete m_pokeSpriteList;
	delete m_pokeSpriteVBox;
	delete m_pokeSpriteFrame;
	delete m_pokeMainHBox;
	delete m_pokeMainVBox;
}

//	prevSprite	--	Shows the previous sprite.
//	Parameters:	none.
//	Returns:	void.
void CPokeInfoSub::prevSprite() {
	//	Tracing.
	std::cout << "[POKEINFOSUB]	--	prevSprite called." << std::endl;

	//	Check sprites count.
	int totalSpritesCount = m_pokeSpriteList->size();
	
	//	Remove current sprite.
	Gtk::Image* tmp = m_pokeSpriteList->at(currentSprite);
	m_pokeSpriteHolder->remove(*tmp);

	//	Set current sprite number.
	if (currentSprite == 0) {
		currentSprite = totalSpritesCount - 1;
	} else {
		currentSprite--;
	}

	//	Set current sprite.
	tmp = m_pokeSpriteList->at(currentSprite);
	m_pokeSpriteHolder->pack_start(*tmp);

	//	Update window.
	m_gui->getWindow()->show_all_children();
}

//	nextSprite	--	Shows the next sprite.
//	Parameters:	none.
//	Returns:	void.
void CPokeInfoSub::nextSprite() {
	//	Tracing.
	std::cout << "[POKEINFOSUB]	--	nextSprite called." << std::endl;

	//	Check sprites count.
	int totalSpritesCount = m_pokeSpriteList->size();
	
	//	Remove current sprite.
	Gtk::Image* tmp = m_pokeSpriteList->at(currentSprite);
	m_pokeSpriteHolder->remove(*tmp);

	//	Set current sprite number.
	if (currentSprite == totalSpritesCount - 1) {
		currentSprite = 0;
	} else {
		currentSprite++;
	}

	//	Set current sprite.
	tmp = m_pokeSpriteList->at(currentSprite);
	m_pokeSpriteHolder->pack_start(*tmp);

	//	Update window.
	m_gui->getWindow()->show_all_children();
}

//	getMainBox	--	Returns pointer to main box.
//	Parameters:	none.
//	Returns:	pointer to main box.
Gtk::Box* CPokeInfoSub::getMainBox() {
	return m_pokeMainVBox;
}