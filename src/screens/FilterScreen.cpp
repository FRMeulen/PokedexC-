//	Project:	PokedexC++.
//	FilterScreen.cpp	--	Implementation of the CFilterScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.
//	2018-12-04	--	F.R. van der Meulen --	Fixed copying DexGui instead of referencing it.
//	2018-12-04	--	F.R. van der Meulen	--	Added option to remove a filter.

//	Include files.
#include "FilterScreen.h"
#include <iostream>

//	Constructor.
//	Parameters:
//		parmGui	--	Gui containing this screen.
CFilterScreen::CFilterScreen(CDexGui *parmGui) : m_gui(parmGui) {
	//	Tracing.
	std::cout << "[FILTERSCREEN]	--	constructor called." << std::endl;

	//	Build child widgets.
	m_framesVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_optionsFrame = new Gtk::Frame("Options");
			m_optionsHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_backButton = new Gtk::Button("Back");
				m_removeButton = new Gtk::Button("Remove Filter");
				m_confirmButton = new Gtk::Button("Done");

		m_filtersFrame = new Gtk::Frame("Filters");
			m_filtersVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
				m_selectedFilterFrame = new Gtk::Frame("Selected");
					m_selectedFilterHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
						m_selectedFilterGroupLabel = new Gtk::Label("Group: ---");
						m_selectedFilterNameLabel = new Gtk::Label("Name: ---");

				m_typeFiltersFrame = new Gtk::Frame("Type Filters");
					m_typeFilterRowsVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
						m_typeFiltersTopHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_typeFilterNormal = new Gtk::Button();
								m_imgTypeNormal		=	new Gtk::Image("./res/types/type_normal.png");
							m_typeFilterFighting = new Gtk::Button();
								m_imgTypeFighting	=	new Gtk::Image("./res/types/type_fighting.png");
							m_typeFilterFlying = new Gtk::Button();
								m_imgTypeFlying		=	new Gtk::Image("./res/types/type_flying.png");
							m_typeFilterPoison = new Gtk::Button();
								m_imgTypePoison		=	new Gtk::Image("./res/types/type_poison.png");
							m_typeFilterGround = new Gtk::Button();
								m_imgTypeGround		=	new Gtk::Image("./res/types/type_ground.png");
							m_typeFilterRock = new Gtk::Button();
								m_imgTypeRock		=	new Gtk::Image("./res/types/type_rock.png");

						m_typeFiltersMiddleHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_typeFilterBug = new Gtk::Button();
								m_imgTypeBug		=	new Gtk::Image("./res/types/type_bug.png");
							m_typeFilterGhost = new Gtk::Button();
								m_imgTypeGhost		=	new Gtk::Image("./res/types/type_ghost.png");
							m_typeFilterSteel = new Gtk::Button();
								m_imgTypeSteel		=	new Gtk::Image("./res/types/type_steel.png");
							m_typeFilterFire = new Gtk::Button();
								m_imgTypeFire		=	new Gtk::Image("./res/types/type_fire.png");
							m_typeFilterWater = new Gtk::Button();
								m_imgTypeWater		=	new Gtk::Image("./res/types/type_water.png");
							m_typeFilterGrass = new Gtk::Button();
								m_imgTypeGrass		=	new Gtk::Image("./res/types/type_grass.png");

						m_typeFiltersBottomHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							m_typeFilterElectric = new Gtk::Button();
								m_imgTypeElectric	=	new Gtk::Image("./res/types/type_electric.png");
							m_typeFilterPsychic = new Gtk::Button();
								m_imgTypePsychic	=	new Gtk::Image("./res/types/type_psychic.png");
							m_typeFilterIce = new Gtk::Button();
								m_imgTypeIce		=	new Gtk::Image("./res/types/type_ice.png");
							m_typeFilterDragon = new Gtk::Button();
								m_imgTypeDragon		=	new Gtk::Image("./res/types/type_dragon.png");
							m_typeFilterDark = new Gtk::Button();
								m_imgTypeDark		=	new Gtk::Image("./res/types/type_dark.png");
							m_typeFilterFairy = new Gtk::Button();
								m_imgTypeFairy		=	new Gtk::Image("./res/types/type_fairy.png");

				m_genFiltersFrame = new Gtk::Frame("Generation Filters");
					m_genFiltersHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
						m_genFilterKanto	= new Gtk::Button("Kanto");
						m_genFilterJohto	= new Gtk::Button("Johto");
						m_genFilterHoenn	= new Gtk::Button("Hoenn");
						m_genFilterSinnoh	= new Gtk::Button("Sinnoh");
						m_genFilterUnova	= new Gtk::Button("Unova");
						m_genFilterKalos	= new Gtk::Button("Kalos");
						m_genFilterAlola	= new Gtk::Button("Alola");

				m_miscFiltersFrame = new Gtk::Frame("Misc Filters");
					m_miscFiltersHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
						m_miscFilterLegendary	= new Gtk::Button("Legendary");
						m_miscFilterDualType	= new Gtk::Button("Dual-Type");

	//	Build screen.
	m_framesVBox->pack_start(*m_optionsFrame, Gtk::PACK_SHRINK, 10);
		m_optionsFrame->add(*m_optionsHBox);
			m_optionsHBox->pack_start(*m_backButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_optionsHBox->pack_start(*m_removeButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_optionsHBox->pack_start(*m_confirmButton, Gtk::PACK_EXPAND_WIDGET, 10);

	m_framesVBox->pack_start(*m_filtersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_filtersFrame->add(*m_filtersVBox);
			m_filtersVBox->pack_start(*m_selectedFilterFrame, Gtk::PACK_SHRINK, 10);
				m_selectedFilterFrame->add(*m_selectedFilterHBox);
					m_selectedFilterHBox->pack_start(*m_selectedFilterGroupLabel, Gtk::PACK_EXPAND_WIDGET, 10);
					m_selectedFilterHBox->pack_start(*m_selectedFilterNameLabel, Gtk::PACK_EXPAND_WIDGET, 10);

			m_filtersVBox->pack_start(*m_typeFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_typeFiltersFrame->add(*m_typeFilterRowsVBox);
					
					m_typeFilterRowsVBox->pack_start(*m_typeFiltersTopHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersTopHBox->pack_start(*m_typeFilterNormal, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterNormal->set_image(*m_imgTypeNormal);
						m_typeFiltersTopHBox->pack_start(*m_typeFilterFighting, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFighting->set_image(*m_imgTypeFighting);
						m_typeFiltersTopHBox->pack_start(*m_typeFilterFlying, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFlying->set_image(*m_imgTypeFlying);
						m_typeFiltersTopHBox->pack_start(*m_typeFilterPoison, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterPoison->set_image(*m_imgTypePoison);
						m_typeFiltersTopHBox->pack_start(*m_typeFilterGround, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterGround->set_image(*m_imgTypeGround);
						m_typeFiltersTopHBox->pack_start(*m_typeFilterRock, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterRock->set_image(*m_imgTypeRock);

					m_typeFilterRowsVBox->pack_start(*m_typeFiltersMiddleHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersMiddleHBox->pack_start(*m_typeFilterBug, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterBug->set_image(*m_imgTypeBug);
						m_typeFiltersMiddleHBox->pack_start(*m_typeFilterGhost, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterGhost->set_image(*m_imgTypeGhost);
						m_typeFiltersMiddleHBox->pack_start(*m_typeFilterSteel, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterSteel->set_image(*m_imgTypeSteel);
						m_typeFiltersMiddleHBox->pack_start(*m_typeFilterFire, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFire->set_image(*m_imgTypeFire);
						m_typeFiltersMiddleHBox->pack_start(*m_typeFilterWater, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterWater->set_image(*m_imgTypeWater);
						m_typeFiltersMiddleHBox->pack_start(*m_typeFilterGrass, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterGrass->set_image(*m_imgTypeGrass);

					m_typeFilterRowsVBox->pack_start(*m_typeFiltersBottomHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersBottomHBox->pack_start(*m_typeFilterElectric, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterElectric->set_image(*m_imgTypeElectric);
						m_typeFiltersBottomHBox->pack_start(*m_typeFilterPsychic, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterPsychic->set_image(*m_imgTypePsychic);
						m_typeFiltersBottomHBox->pack_start(*m_typeFilterIce, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterIce->set_image(*m_imgTypeIce);
						m_typeFiltersBottomHBox->pack_start(*m_typeFilterDragon, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterDragon->set_image(*m_imgTypeDragon);
						m_typeFiltersBottomHBox->pack_start(*m_typeFilterDark, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterDark->set_image(*m_imgTypeDark);
						m_typeFiltersBottomHBox->pack_start(*m_typeFilterFairy, Gtk::PACK_EXPAND_WIDGET, 5);
							m_typeFilterFairy->set_image(*m_imgTypeFairy);


			m_filtersVBox->pack_start(*m_genFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_genFiltersFrame->add(*m_genFiltersHBox);
					m_genFiltersHBox->pack_start(*m_genFilterKanto, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox->pack_start(*m_genFilterJohto, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox->pack_start(*m_genFilterHoenn, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox->pack_start(*m_genFilterSinnoh, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox->pack_start(*m_genFilterUnova, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox->pack_start(*m_genFilterKalos, Gtk::PACK_EXPAND_WIDGET, 5);
					m_genFiltersHBox->pack_start(*m_genFilterAlola, Gtk::PACK_EXPAND_WIDGET, 5);

			m_filtersVBox->pack_start(*m_miscFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_miscFiltersFrame->add(*m_miscFiltersHBox);
					m_miscFiltersHBox->pack_start(*m_miscFilterLegendary, Gtk::PACK_EXPAND_WIDGET, 10);
					m_miscFiltersHBox->pack_start(*m_miscFilterDualType, Gtk::PACK_EXPAND_WIDGET, 10);

	//	Configure frames.
	m_optionsFrame->set_border_width(10);
	m_filtersFrame->set_border_width(10);
	m_selectedFilterFrame->set_border_width(10);
	m_typeFiltersFrame->set_border_width(10);
	m_genFiltersFrame->set_border_width(10);
	m_miscFiltersFrame->set_border_width(10);

	//	Configure boxes.
	m_optionsHBox->set_homogeneous(true);
	m_selectedFilterHBox->set_homogeneous(true);
	m_typeFiltersTopHBox->set_homogeneous(true);
	m_typeFiltersMiddleHBox->set_homogeneous(true);
	m_typeFiltersBottomHBox->set_homogeneous(true);
	m_genFiltersHBox->set_homogeneous(true);
	m_miscFiltersHBox->set_homogeneous(true);

	//	Signal handlers	-	Options frame.
	m_backButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CFilterScreen::swapScreen), "mainscreenreturn"));
	m_removeButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CFilterScreen::swapScreen), "mainscreenremove"));
	m_confirmButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CFilterScreen::swapScreen), "mainscreenadd"));
	
	//	Signal handlers	-	Type filters.
	m_typeFilterNormal->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Normal"));
	m_typeFilterFighting->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Fighting"));
	m_typeFilterFlying->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Flying"));
	m_typeFilterPoison->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Poison"));
	m_typeFilterGround->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Ground"));
	m_typeFilterRock->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Rock"));
	m_typeFilterBug->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Bug"));
	m_typeFilterGhost->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Ghost"));
	m_typeFilterSteel->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Steel"));
	m_typeFilterFire->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Fire"));
	m_typeFilterWater->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Water"));
	m_typeFilterGrass->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Grass"));
	m_typeFilterElectric->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Electric"));
	m_typeFilterPsychic->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Psychic"));
	m_typeFilterIce->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Ice"));
	m_typeFilterDragon->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Dragon"));
	m_typeFilterDark->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Dark"));
	m_typeFilterFairy->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Type", "Fairy"));

	//	Signal handlers	-	Generation filters.
	m_genFilterKanto->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Kanto"));
	m_genFilterJohto->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Johto"));
	m_genFilterHoenn->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Hoenn"));
	m_genFilterSinnoh->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Sinnoh"));
	m_genFilterUnova->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Unova"));
	m_genFilterKalos->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Kalos"));
	m_genFilterAlola->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Generation", "Alola"));

	//	Signal handlers	-	Miscellaneous filters.
	m_miscFilterLegendary->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Misc", "Legendary"));
	m_miscFilterDualType->signal_clicked().connect(sigc::bind<std::string, std::string>(sigc::mem_fun(*this, &CFilterScreen::selectFilter), "Misc", "Dual-Type"));

	//	Make self known to Gui.
	m_gui->setFilterScreen(this);
	m_gui->getNotebook()->append_page(*m_framesVBox);
}

//	Destructor.
CFilterScreen::~CFilterScreen() {
	//	Tracing.
	std::cout << "[FILTERSCREEN]	--	destructor called." << std::endl;
}

//	swapScreen	--	Tells the window to switch screens.
//	Parameters:
//		newScreen	--	String of new screen name.
//	Returns:	void.
void CFilterScreen::swapScreen(std::string newScreen) {
	//	Tracing.
	std::cout << "[FILTERSCREEN]	--	swapScreen called -> newScreen=" << newScreen << "." << std::endl;

	//	If back button is pressed.
	if (newScreen == "mainscreenreturn") {
		//	Return to main screen.
		swapScreen("mainscreen");
	}

	//	If filter is removed.
	else if (newScreen== "mainscreenremove") {
		//	Reset labels.
		m_selectedFilterGroupLabel->set_text("Group: ---");
		m_selectedFilterNameLabel->set_text("Name: ---");
		
		//	If filter one is reset.
		if (m_filtersFrame->get_label() == "Filter 1") {
			//	Reset filter.
			m_gui->getMainScreen()->setFilter(1, "---");
			
			//	Return to main screen.
			swapScreen("mainscreen");
		}

		//	If filter two is reset.
		else if (m_filtersFrame->get_label() == "Filter 2") {
			//	Reset filter.
			m_gui->getMainScreen()->setFilter(2, "---");
			
			//	Return to main screen.
			swapScreen("mainscreen");
		}
	} 

	//	If new filter is set.
	else if (newScreen == "mainscreenadd") {
		//	Set filter string.
		std::string filterGroup = m_selectedFilterGroupLabel->get_text();
		filterGroup = filterGroup.substr(7);
		std::string filterName = m_selectedFilterNameLabel->get_text();
		filterName = filterName.substr(6);
		std::string filterString = filterGroup + ":" + filterName;

		//	If filter one is set.
		if (m_filtersFrame->get_label() == "Filter 1") {
			//	Set filter.
			m_gui->getMainScreen()->setFilter(1, filterString);
			
			//	Return to main screen.
			swapScreen("mainscreen");
		}

		//	If filter two is set.
		else if (m_filtersFrame->get_label() == "Filter 2") {
			//	Set filter.
			m_gui->getMainScreen()->setFilter(2, filterString);
			
			//	Return to main screen.
			swapScreen("mainscreen");
		}
	}

	//	If screen has no special actions.
	else {
		//	Tell gui to swap screens.
		m_gui->swapScreen(newScreen);
	}
}

//	selectFilter	--	Selects a filter
//	Parameters:
//		group	--	string of filter group
//		name	--	string of filter name
//	Returns:	void.
void CFilterScreen::selectFilter(std::string group, std::string name) {
	//	Tracing.
	std::cout << "[FILTERSCREEN]	--	selectFilter called -> group=" << group << ", name=" << name << "." << std::endl;

	m_selectedFilterGroupLabel->set_text("Group: " + group);
	//m_filterGroup = group;
	m_selectedFilterNameLabel->set_text("Name: " + name);
	//m_filterName = name;
}

//	getFilterNum	--	Returns filter number.
//	Parameters:	none.
//	Returns:	string of filter number.
std::string CFilterScreen::getFilterNum() {
	//	Tracing.
	std::cout << "[FILTERSCREEN]	--	getFilterNum called -> num='" << m_filtersFrame->get_label() << "'." << std::endl;

	//	Return string
	return m_filtersFrame->get_label();
}

//	setFilterNum	--	Sets filter number.
//	Parameters:
//		--	num	--	Filter number.
//	Returns:	void.
void CFilterScreen::setFilterNum(int num) {
	//	Tracing.
	std::cout << "[FILTERSCREEN]	--	setFilterNum called -> num='" << num << "'." << std::endl;

	m_filtersFrame->set_label("Filter " + std::to_string(num));
}