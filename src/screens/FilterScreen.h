//	Project:	PokedexC++.
//	FilterScreen.h	--	Interface for the CFilterScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>

//Class interface.
class CFilterScreen : public Gtk::Box {
protected:
	//	Parent notebook pointer.
	Gtk::Notebook* parent;

	//	Child widgets.
	Gtk::Box m_framesVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		Gtk::Frame m_optionsFrame = Gtk::Frame("Options");
			Gtk::Box m_optionsHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				Gtk::Button m_backButton = Gtk::Button("Back");
				Gtk::Button m_confirmButton = Gtk::Button("Confirm");

		Gtk::Frame m_filtersFrame = Gtk::Frame("Filters");
			Gtk::Box m_filtersVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
				Gtk::Label m_selectedFilter = Gtk::Label("Selected: ---");
				Gtk::Frame m_typeFiltersFrame = Gtk::Frame("Type Filters");
					Gtk::Box m_typeFilterRowsVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
						Gtk::Box m_typeFiltersTopHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							Gtk::Button m_typeFilterNormal;
								Gtk::Image m_imgTypeNormal		=	Gtk::Image("./res/types/type_normal.png");
							Gtk::Button m_typeFilterFighting;
								Gtk::Image m_imgTypeFighting	=	Gtk::Image("./res/types/type_fighting.png");
							Gtk::Button m_typeFilterFlying;
								Gtk::Image m_imgTypeFlying		=	Gtk::Image("./res/types/type_flying.png");
							Gtk::Button m_typeFilterPoison;
								Gtk::Image m_imgTypePoison		=	Gtk::Image("./res/types/type_poison.png");
							Gtk::Button m_typeFilterGround;
								Gtk::Image m_imgTypeGround		=	Gtk::Image("./res/types/type_ground.png");
							Gtk::Button m_typeFilterRock;
								Gtk::Image m_imgTypeRock		=	Gtk::Image("./res/types/type_rock.png");

						Gtk::Box m_typeFiltersMiddleHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							Gtk::Button m_typeFilterBug;
								Gtk::Image m_imgTypeBug			=	Gtk::Image("./res/types/type_bug.png");
							Gtk::Button m_typeFilterGhost;
								Gtk::Image m_imgTypeGhost		=	Gtk::Image("./res/types/type_ghost.png");
							Gtk::Button m_typeFilterSteel;
								Gtk::Image m_imgTypeSteel		=	Gtk::Image("./res/types/type_steel.png");
							Gtk::Button m_typeFilterFire;
								Gtk::Image m_imgTypeFire		=	Gtk::Image("./res/types/type_fire.png");
							Gtk::Button m_typeFilterWater;
								Gtk::Image m_imgTypeWater		=	Gtk::Image("./res/types/type_water.png");
							Gtk::Button m_typeFilterGrass;
								Gtk::Image m_imgTypeGrass		=	Gtk::Image("./res/types/type_grass.png");

						Gtk::Box m_typeFiltersBottomHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							Gtk::Button m_typeFilterElectric;
								Gtk::Image m_imgTypeElectric	=	Gtk::Image("./res/types/type_electric.png");
							Gtk::Button m_typeFilterPsychic;
								Gtk::Image m_imgTypePsychic		=	Gtk::Image("./res/types/type_psychic.png");
							Gtk::Button m_typeFilterIce;
								Gtk::Image m_imgTypeIce			=	Gtk::Image("./res/types/type_ice.png");
							Gtk::Button m_typeFilterDragon;
								Gtk::Image m_imgTypeDragon		=	Gtk::Image("./res/types/type_dragon.png");
							Gtk::Button m_typeFilterDark;
								Gtk::Image m_imgTypeDark		=	Gtk::Image("./res/types/type_dark.png");
							Gtk::Button m_typeFilterFairy;
								Gtk::Image m_imgTypeFairy		=	Gtk::Image("./res/types/type_fairy.png");

				Gtk::Frame m_genFiltersFrame = Gtk::Frame("Generation Filters");
					Gtk::Box m_genFiltersHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
						Gtk::Button m_genFilterKanto	= Gtk::Button("Kanto");
						Gtk::Button m_genFilterJohto	= Gtk::Button("Johto");
						Gtk::Button m_genFilterHoenn	= Gtk::Button("Hoenn");
						Gtk::Button m_genFilterSinnoh	= Gtk::Button("Sinnoh");
						Gtk::Button m_genFilterUnova	= Gtk::Button("Unova");
						Gtk::Button m_genFilterKalos	= Gtk::Button("Kalos");
						Gtk::Button m_genFilterAlola	= Gtk::Button("Alola");

				Gtk::Frame m_miscFiltersFrame = Gtk::Frame("Miscellaneous Filters");
					Gtk::Box m_miscFiltersHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
						Gtk::Button m_miscFilterLegendary	= Gtk::Button("Legendary");
						Gtk::Button m_miscFilterDualType	= Gtk::Button("Dual-Type");
public:
	//	Constructors & desctructor.
	CFilterScreen(Gtk::Notebook& par);
	virtual ~CFilterScreen();

	//	Methods.
	void toMainScreen();
};