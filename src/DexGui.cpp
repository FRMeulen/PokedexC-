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
	
	//	Create & configure window.
	Gtk::Window m_window;
	m_window.set_title("PokedexC++");
	m_window.set_default_size(800, 600);
	m_window.set_resizable(false);

	//	Create notebook & screen objects.
	m_screens = new Gtk::Notebook();
	m_screens->set_show_tabs(false);
	m_mainScreen = new CMainScreen(*m_screens);
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