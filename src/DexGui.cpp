//	Project:	PokedexC++
//	DexGui.cpp	--	Implementation of the CDexGui class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "DexGui.h"

//	Constructor.
CDexGui::CDexGui() {
	//	Create application.
	auto app = Gtk::Application::create();
	
	//	Dex connector
	m_dex = new CDexConnector();

	//	Create & configure window.
	Gtk::Window m_window;
	m_window.set_title("PokedexC++");
	m_window.set_default_size(800, 600);
	m_window.set_resizable(false);

	//	Create notebook & screen objects.
	m_screens = new Gtk::Notebook();
	m_screens->set_show_tabs(false);
	m_mainScreen = new CMainScreen(*m_screens, m_dex, "SELECT * FROM pokemon;");
	m_filterScreen = new CFilterScreen(*m_screens);

	//	Add notebook to window.
	m_window.add(*m_screens);

	//Insert pages.
	m_screens->append_page(*m_mainScreen);
	m_screens->append_page(*m_filterScreen);

	//	Show all children & run app.
	m_window.show_all_children();
	app->run(m_window);
}

//	Destructor.
CDexGui::~CDexGui() {

}

//	getScreens	--	Returns the notebook.
//	Parameters:	none.
//	Returns:	reference to notebook containing screens.
Gtk::Notebook& CDexGui::getScreens() {
	return *m_screens;
}

//	getMainScreen	--	Returns main screen.
//	Parameters:	none.
//	Returns:	Pointer to main screen.
CMainScreen* CDexGui::getMainScreen() {
	return m_mainScreen;
}

//	getFilterScreen	--	Returns filter screen.
//	Parameters:	none.
//	Returns:	Pointer to filter screen.
CFilterScreen* CDexGui::getFilterScreen() {
	return m_filterScreen;
}