#include <gtkmm-3.0/gtkmm.h>
#include "screens/MainScreen.h"
#include "screens/FilterScreen.h"

class CDexGui {
protected:
	Gtk::Notebook *m_screens;
	CMainScreen *m_mainScreen;
	CFilterScreen *m_filterScreen;
public:
	CDexGui();
	virtual ~CDexGui();
	void setScreen(int screenPos);
	Gtk::Notebook& getScreens();
};