#include <gtkmm-3.0/gtkmm.h>

class CFilterScreen : public Gtk::Box {
protected:
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
							Gtk::Button m_typeFilterNormal		= Gtk::Button("Normal");
							Gtk::Button m_typeFilterFighting	= Gtk::Button("Fighting");
							Gtk::Button m_typeFilterFlying		= Gtk::Button("Flying");
							Gtk::Button m_typeFilterPoison		= Gtk::Button("Poison");
							Gtk::Button m_typeFilterGround		= Gtk::Button("Ground");
							Gtk::Button m_typeFilterRock		= Gtk::Button("Rock");

						Gtk::Box m_typeFiltersMiddleHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							Gtk::Button m_typeFilterBug			= Gtk::Button("Bug");
							Gtk::Button m_typeFilterGhost		= Gtk::Button("Ghost");
							Gtk::Button m_typeFilterSteel		= Gtk::Button("Steel");
							Gtk::Button m_typeFilterFire		= Gtk::Button("Fire");
							Gtk::Button m_typeFilterWater		= Gtk::Button("Water");
							Gtk::Button m_typeFilterGrass		= Gtk::Button("Grass");

						Gtk::Box m_typeFiltersBottomHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
							Gtk::Button m_typeFilterElectric	= Gtk::Button("Electric");
							Gtk::Button m_typeFilterPsychic		= Gtk::Button("Psychic");
							Gtk::Button m_typeFilterIce			= Gtk::Button("Ice");
							Gtk::Button m_typeFilterDragon		= Gtk::Button("Dragon");
							Gtk::Button m_typeFilterDark		= Gtk::Button("Dark");
							Gtk::Button m_typeFilterFairy		= Gtk::Button("Fairy");

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
	CFilterScreen();
	virtual ~CFilterScreen();
};