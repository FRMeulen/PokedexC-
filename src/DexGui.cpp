#include "DexGui.h"

#define posMain 1
#define posFilter 2

CDexGui::CDexGui() {
	auto app = Gtk::Application::create();
	Gtk::Window m_window;
	m_window.set_title("PokedexC++");
	m_window.set_default_size(800, 600);
	m_window.set_resizable(false);

	m_screens = new Gtk::Notebook();
	m_mainScreen = new CMainScreen();
	m_filterScreen = new CFilterScreen();

	m_window.add(*m_screens);

	//m_screens->set_show_tabs(false);
	m_screens->insert_page(*m_mainScreen, posMain);
	m_screens->insert_page(*m_filterScreen, posFilter);

	m_window.show_all_children();
	app->run(m_window);
}

CDexGui::~CDexGui() {

}

void CDexGui::setScreen(int screenPos) {
	m_screens->set_current_page(screenPos);
}

Gtk::Notebook& CDexGui::getScreens() {
	return *m_screens;
}