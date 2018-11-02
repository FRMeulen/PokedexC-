//	Project:	PokedexC++.
//	FilterScreen.h	--	Interface for the CFilterScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Pragma.
#pragma once

//	Include files.
#include "DexGui.h"
#include <gtkmm-3.0/gtkmm.h>
#include "MainScreen.h"

//	Class interface.
class CFilterScreen {
protected:
	//	Gui pointers.
	CDexGui* m_gui;
	CMainScreen* m_mainScreen;

	//	Child widget pointers.
	Gtk::Box* m_framesVBox;
		Gtk::Frame* m_optionsFrame;
			Gtk::Box* m_optionsHBox;
				Gtk::Button* m_backButton;
				Gtk::Button* m_confirmButton;

		Gtk::Frame* m_filtersFrame;
			Gtk::Box* m_filtersVBox;
				Gtk::Frame* m_selectedFilterFrame;
					Gtk::Box* m_selectedFilterHBox;
						Gtk::Label* m_selectedFilterGroupLabel;
						Gtk::Label* m_selectedFilterNameLabel;

				Gtk::Frame* m_typeFiltersFrame;
					Gtk::Box* m_typeFilterRowsVBox;
						Gtk::Box* m_typeFiltersTopHBox;
							Gtk::Button* m_typeFilterNormal;
								Gtk::Image* m_imgTypeNormal;
							Gtk::Button* m_typeFilterFighting;
								Gtk::Image* m_imgTypeFighting;
							Gtk::Button* m_typeFilterFlying;
								Gtk::Image* m_imgTypeFlying;
							Gtk::Button* m_typeFilterPoison;
								Gtk::Image* m_imgTypePoison;
							Gtk::Button* m_typeFilterGround;
								Gtk::Image* m_imgTypeGround;
							Gtk::Button* m_typeFilterRock;
								Gtk::Image* m_imgTypeRock;

						Gtk::Box* m_typeFiltersMiddleHBox;
							Gtk::Button* m_typeFilterBug;
								Gtk::Image* m_imgTypeBug;
							Gtk::Button* m_typeFilterGhost;
								Gtk::Image* m_imgTypeGhost;
							Gtk::Button* m_typeFilterSteel;
								Gtk::Image* m_imgTypeSteel;
							Gtk::Button* m_typeFilterFire;
								Gtk::Image* m_imgTypeFire;
							Gtk::Button* m_typeFilterWater;
								Gtk::Image* m_imgTypeWater;
							Gtk::Button* m_typeFilterGrass;
								Gtk::Image* m_imgTypeGrass;

						Gtk::Box* m_typeFiltersBottomHBox;
							Gtk::Button* m_typeFilterElectric;
								Gtk::Image* m_imgTypeElectric;
							Gtk::Button* m_typeFilterPsychic;
								Gtk::Image* m_imgTypePsychic;
							Gtk::Button* m_typeFilterIce;
								Gtk::Image* m_imgTypeIce;
							Gtk::Button* m_typeFilterDragon;
								Gtk::Image* m_imgTypeDragon;
							Gtk::Button* m_typeFilterDark;
								Gtk::Image* m_imgTypeDark;
							Gtk::Button* m_typeFilterFairy;
								Gtk::Image* m_imgTypeFairy;

				Gtk::Frame* m_genFiltersFrame;
					Gtk::Box* m_genFiltersHBox;
						Gtk::Button* m_genFilterKanto;
						Gtk::Button* m_genFilterJohto;
						Gtk::Button* m_genFilterHoenn;
						Gtk::Button* m_genFilterSinnoh;
						Gtk::Button* m_genFilterUnova;
						Gtk::Button* m_genFilterKalos;
						Gtk::Button* m_genFilterAlola;

				Gtk::Frame* m_miscFiltersFrame;
					Gtk::Box* m_miscFiltersHBox;
						Gtk::Button* m_miscFilterLegendary;
						Gtk::Button* m_miscFilterDualType;
public:
	//	Constructors & desctructor.
	CFilterScreen(CDexGui parmGui);
	virtual ~CFilterScreen();

	//	Methods.
	void swapScreen(std::string newScreen);
	void selectFilter(std::string group, std::string name);
	void updatePointers(CMainScreen newMainScreen);

	//	Setters.
	void setFilterNum(int num);
};