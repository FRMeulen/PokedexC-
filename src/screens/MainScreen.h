#include <gtkmm-3.0/gtkmm.h>

class CMainScreen : public Gtk::Box {
protected:
	Gtk::Box m_framesVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		Gtk::Frame m_resultsFrame = Gtk::Frame("Results");
			Gtk::Label m_placeholder = Gtk::Label("<TREEVIEW WITH QUERY RESULTS>");

		Gtk::Frame m_specifyFrame = Gtk::Frame("Specify");
			Gtk::Box m_specifyHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				Gtk::Button m_filterOneButton	=	Gtk::Button("Filter 1: ---");
				Gtk::Button m_filterTwoButton	=	Gtk::Button("Filter 2: ---");
				Gtk::Button m_searchButton		=	Gtk::Button("Search");
public:
	CMainScreen();
	virtual ~CMainScreen();
};