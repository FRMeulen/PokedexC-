#include "FilterScreen.h"

CFilterScreen::CFilterScreen() {
	//Build screen
	this->pack_start(m_framesVBox, Gtk::PACK_EXPAND_WIDGET, 5);

	m_framesVBox.pack_start(m_optionsFrame, Gtk::PACK_SHRINK, 10);
		m_optionsFrame.add(m_optionsHBox);
			m_optionsHBox.pack_start(m_backButton, Gtk::PACK_EXPAND_WIDGET, 10);
			m_optionsHBox.pack_start(m_confirmButton, Gtk::PACK_EXPAND_WIDGET, 10);

	m_framesVBox.pack_start(m_filtersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_filtersFrame.add(m_filtersVBox);
			m_filtersVBox.pack_start(m_selectedFilter, Gtk::PACK_SHRINK, 10);
			m_filtersVBox.pack_start(m_typeFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_typeFiltersFrame.add(m_typeFilterRowsVBox);
					m_typeFilterRowsVBox.pack_start(m_typeFiltersTopHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersTopHBox.pack_start(m_typeFilterNormal, Gtk::PACK_SHRINK, 5);
						m_typeFiltersTopHBox.pack_start(m_typeFilterFighting, Gtk::PACK_SHRINK, 5);
						m_typeFiltersTopHBox.pack_start(m_typeFilterFlying, Gtk::PACK_SHRINK, 5);
						m_typeFiltersTopHBox.pack_start(m_typeFilterPoison, Gtk::PACK_SHRINK, 5);
						m_typeFiltersTopHBox.pack_start(m_typeFilterGround, Gtk::PACK_SHRINK, 5);
						m_typeFiltersTopHBox.pack_start(m_typeFilterRock, Gtk::PACK_SHRINK, 5);

					m_typeFilterRowsVBox.pack_start(m_typeFiltersMiddleHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterBug, Gtk::PACK_SHRINK, 5);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterGhost, Gtk::PACK_SHRINK, 5);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterSteel, Gtk::PACK_SHRINK, 5);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterFire, Gtk::PACK_SHRINK, 5);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterWater, Gtk::PACK_SHRINK, 5);
						m_typeFiltersMiddleHBox.pack_start(m_typeFilterGrass, Gtk::PACK_SHRINK, 5);

					m_typeFilterRowsVBox.pack_start(m_typeFiltersBottomHBox, Gtk::PACK_EXPAND_WIDGET, 5);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterElectric, Gtk::PACK_SHRINK, 5);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterPsychic, Gtk::PACK_SHRINK, 5);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterIce, Gtk::PACK_SHRINK, 5);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterDragon, Gtk::PACK_SHRINK, 5);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterDark, Gtk::PACK_SHRINK, 5);
						m_typeFiltersBottomHBox.pack_start(m_typeFilterFairy, Gtk::PACK_SHRINK, 5);


			m_filtersVBox.pack_start(m_genFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_genFiltersFrame.add(m_genFiltersHBox);
					m_genFiltersHBox.pack_start(m_genFilterKanto, Gtk::PACK_SHRINK, 5);
					m_genFiltersHBox.pack_start(m_genFilterJohto, Gtk::PACK_SHRINK, 5);
					m_genFiltersHBox.pack_start(m_genFilterHoenn, Gtk::PACK_SHRINK, 5);
					m_genFiltersHBox.pack_start(m_genFilterSinnoh, Gtk::PACK_SHRINK, 5);
					m_genFiltersHBox.pack_start(m_genFilterUnova, Gtk::PACK_SHRINK, 5);
					m_genFiltersHBox.pack_start(m_genFilterKalos, Gtk::PACK_SHRINK, 5);
					m_genFiltersHBox.pack_start(m_genFilterAlola, Gtk::PACK_SHRINK, 5);

			m_filtersVBox.pack_start(m_miscFiltersFrame, Gtk::PACK_EXPAND_WIDGET, 10);
				m_miscFiltersFrame.add(m_miscFiltersHBox);
					m_miscFiltersHBox.pack_start(m_miscFilterLegendary, Gtk::PACK_EXPAND_WIDGET, 10);
					m_miscFiltersHBox.pack_start(m_miscFilterDualType, Gtk::PACK_EXPAND_WIDGET, 10);

	//Configure widgets
	m_optionsFrame.set_border_width(10);
	m_filtersFrame.set_border_width(10);
	m_typeFiltersFrame.set_border_width(10);
	m_genFiltersFrame.set_border_width(10);
	m_miscFiltersFrame.set_border_width(10);

	m_typeFilterNormal.set_size_request(115, 30);
	m_typeFilterFighting.set_size_request(115, 30);
	m_typeFilterFlying.set_size_request(115, 30);
	m_typeFilterPoison.set_size_request(115, 30);
	m_typeFilterGround.set_size_request(115, 30);
	m_typeFilterRock.set_size_request(115, 30);
	m_typeFilterBug.set_size_request(115, 30);
	m_typeFilterGhost.set_size_request(115, 30);
	m_typeFilterSteel.set_size_request(115, 30);
	m_typeFilterFire.set_size_request(115, 30);
	m_typeFilterWater.set_size_request(115, 30);
	m_typeFilterGrass.set_size_request(115, 30);
	m_typeFilterElectric.set_size_request(115, 30);
	m_typeFilterPsychic.set_size_request(115, 30);
	m_typeFilterIce.set_size_request(115, 30);
	m_typeFilterDragon.set_size_request(115, 30);
	m_typeFilterDark.set_size_request(115, 30);
	m_typeFilterFairy.set_size_request(115, 30);
}

CFilterScreen::~CFilterScreen() {

}