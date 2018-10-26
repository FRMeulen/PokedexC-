//	Project:	PokedexC++.
//	FilterScreen.cpp	--	Implementation of the CFilterScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "FilterScreen.h"

//	Definitions.
#define	posMainScreen	0
#define	posFilterScreen	1

//	Constructor.
CFilterScreen::CFilterScreen(Gtk::Notebook& par) : parent(&par) {
	//	Build screen.
	this->pack_start(m_framesVBox, Gtk::PACK_EXPAND_WIDGET, 5);

	m_framesVBox.pack_start(m_optionsFrame, Gtk::PACK_SHRINK, 10);
		m_optionsFrame.add(m_optionsHBox);
			m_optionsHBox.pack_start(m_backButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_optionsHBox.pack_start(m_confirmButton, Gtk::PACK_EXPAND_WIDGET, 10);

	m_framesVBox.pack_start(m_filtersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_filtersFrame.add(m_filtersVBox);
			m_filtersVBox.pack_start(m_selectedFilterFrame, Gtk::PACK_SHRINK, 10);
				m_selectedFilterFrame.add(m_selectedFilterHBox);
					m_selectedFilterHBox.pack_start(m_selectedFilterGroupLabel, Gtk::PACK_EXPAND_WIDGET, 10);
					m_selectedFilterHBox.pack_start(m_selectedFilterNameLabel, Gtk::PACK_EXPAND_WIDGET, 10);

			m_filtersVBox.pack_start(m_typeFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_typeFiltersFrame.add(m_typeFilterRowsVBox);
					
					m_typeFilterRowsVBox.pack_start(m_typeFiltersTopHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersTopHBox.pack_start(m_typeFilterNormal, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterNormal.set_image(m_imgTypeNormal);
						m_typeFiltersTopHBox.pack_start(m_typeFilterFighting, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFighting.set_image(m_imgTypeFighting);
						m_typeFiltersTopHBox.pack_start(m_typeFilterFlying, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFlying.set_image(m_imgTypeFlying);
						m_typeFiltersTopHBox.pack_start(m_typeFilterPoison, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterPoison.set_image(m_imgTypePoison);
						m_typeFiltersTopHBox.pack_start(m_typeFilterGround, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterGround.set_image(m_imgTypeGround);
						m_typeFiltersTopHBox.pack_start(m_typeFilterRock, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterRock.set_image(m_imgTypeRock);

					m_typeFilterRowsVBox.pack_start(m_typeFiltersMiddleHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterBug, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterBug.set_image(m_imgTypeBug);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterGhost, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterGhost.set_image(m_imgTypeGhost);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterSteel, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterSteel.set_image(m_imgTypeSteel);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterFire, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFire.set_image(m_imgTypeFire);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterWater, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterWater.set_image(m_imgTypeWater);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterGrass, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterGrass.set_image(m_imgTypeGrass);

					m_typeFilterRowsVBox.pack_start(m_typeFiltersBottomHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterElectric, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterElectric.set_image(m_imgTypeElectric);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterPsychic, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterPsychic.set_image(m_imgTypePsychic);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterIce, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterIce.set_image(m_imgTypeIce);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterDragon, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterDragon.set_image(m_imgTypeDragon);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterDark, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterDark.set_image(m_imgTypeDark);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterFairy, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFairy.set_image(m_imgTypeFairy);


			m_filtersVBox.pack_start(m_genFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_genFiltersFrame.add(m_genFiltersHBox);
					m_genFiltersHBox.pack_start(m_genFilterKanto, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox.pack_start(m_genFilterJohto, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox.pack_start(m_genFilterHoenn, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox.pack_start(m_genFilterSinnoh, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox.pack_start(m_genFilterUnova, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox.pack_start(m_genFilterKalos, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox.pack_start(m_genFilterAlola, Gtk::PACK_EXPAND_WIDGET, 5);

			m_filtersVBox.pack_start(m_miscFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_miscFiltersFrame.add(m_miscFiltersHBox);
					m_miscFiltersHBox.pack_start(m_miscFilterLegendary, Gtk::PACK_EXPAND_WIDGET, 10);
					m_miscFiltersHBox.pack_start(m_miscFilterDualType, Gtk::PACK_EXPAND_WIDGET, 10);

	//	Configure widgets.
	m_optionsFrame.set_border_width(10);
	m_filtersFrame.set_border_width(10);
	m_selectedFilterFrame.set_border_width(10);
	m_typeFiltersFrame.set_border_width(10);
	m_genFiltersFrame.set_border_width(10);
	m_miscFiltersFrame.set_border_width(10);

	//	Signal handlers	-	Options frame.
	m_backButton.signal_clicked().connect(sigc::mem_fun(*this, &CFilterScreen::toMainScreen));

	//	Signal handlers	-	Type filters.
	m_typeFilterNormal.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Normal"));
	m_typeFilterFighting.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Fighting"));
	m_typeFilterFlying.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Flying"));
	m_typeFilterPoison.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Poison"));
	m_typeFilterGround.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Ground"));
	m_typeFilterRock.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Rock"));
	m_typeFilterBug.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Bug"));
	m_typeFilterGhost.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Ghost"));
	m_typeFilterSteel.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Steel"));
	m_typeFilterFire.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Fire"));
	m_typeFilterWater.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Water"));
	m_typeFilterGrass.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Grass"));
	m_typeFilterElectric.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Electric"));
	m_typeFilterPsychic.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Psychic"));
	m_typeFilterIce.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Ice"));
	m_typeFilterDragon.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Dragon"));
	m_typeFilterDark.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Dark"));
	m_typeFilterFairy.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Fairy"));

	//	Signal handlers	-	Generation filters.
	m_genFilterKanto.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Kanto"));
	m_genFilterJohto.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Johto"));
	m_genFilterHoenn.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Hoenn"));
	m_genFilterSinnoh.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Sinnoh"));
	m_genFilterUnova.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Unova"));
	m_genFilterKalos.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Kalos"));
	m_genFilterAlola.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Alola"));

	//	Signal handlers	-	Miscellaneous filters.
	m_miscFilterLegendary.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Misc", "Legendary"));
	m_miscFilterDualType.signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Misc", "Dual-Type"));
}

//	Destructor.
CFilterScreen::~CFilterScreen() {

}


//	toMainScreen	--	Sets notebook page to main screen.
//	Parameters:	none.
//	Returns:	void.
void CFilterScreen::toMainScreen() {
	parent->set_current_page(0);
}

//	selectFilter	--	Selects a filter
//	Parameters:
//		group	--	string of filter group
//		name	--	string of filter name
//	Returns:	void.
void CFilterScreen::selectFilter(std::string group, std::string name) {
	m_selectedFilterGroupLabel.set_text("Group: " + group);
	m_selectedFilterNameLabel.set_text("Name: " + name);
}