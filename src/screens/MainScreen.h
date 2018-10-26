//	Project:	PokedexC++.
//	MainScreen.h	--	Interface for the CMainScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>

//	Class interface.
class CMainScreen : public Gtk::Box {
protected:
	//	Parent notebook pointer.
	Gtk::Notebook* parent;

	//	Child widgets.
	Gtk::Box m_framesVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		Gtk::Frame m_resultsFrame = Gtk::Frame("Results");
			Gtk::Label m_placeholder = Gtk::Label("<TREEVIEW WITH QUERY RESULTS>");

		Gtk::Frame m_specifyFrame = Gtk::Frame("Specify");
			Gtk::Box m_specifyHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				Gtk::Button m_filterOneButton	=	Gtk::Button("Filter 1: ---");
				Gtk::Button m_filterTwoButton	=	Gtk::Button("Filter 2: ---");
				Gtk::Button m_searchButton		=	Gtk::Button("Search");
public:
	//	Constructors & desctructor.
	CMainScreen(Gtk::Notebook& par);
	virtual ~CMainScreen();

	//	Methods.
	void toFilterScreen();
};