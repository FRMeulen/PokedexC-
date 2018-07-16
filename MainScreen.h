//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>

//Class
class MainScreen : public Gtk::Window {
public:
	MainScreen();
	virtual ~MainScreen();

protected:
	//Signal handlers
	void searchByNumber();
	void searchByName();
	void searchByPrimaryType();
	void searchBySecondaryType();
	void searchByGeneration();
	void showHybrids();
	void showLegendaries();
	void showAll();
	void quitDex();

	void showWip();	//Test function

	//Member widgets
	Gtk::Button numberButton;
	Gtk::Button nameButton;
	Gtk::Button primaryTypeButton;
	Gtk::Button secondaryTypeButton;
	Gtk::Button generationButton;
	Gtk::Button hybridsButton;
	Gtk::Button legendariesButton;
	Gtk::Button showAllButton;
	Gtk::Button quitButton;
};