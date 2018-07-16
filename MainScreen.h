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
	///Box
	Gtk::Box buttonBox;

	///Buttons
	Gtk::Button numberButton = Gtk::Button("Search by Number.");
	Gtk::Button nameButton = Gtk::Button("Search by Name.");
	Gtk::Button primaryTypeButton = Gtk::Button("Search by Primary Type.");
	Gtk::Button secondaryTypeButton = Gtk::Button("Search by Secondary Type.");
	Gtk::Button generationButton = Gtk::Button("Search by Generation.");
	Gtk::Button hybridsButton = Gtk::Button("Show dual-type Pokemon.");
	Gtk::Button legendariesButton = Gtk::Button("Show legendary Pokemon.");
	Gtk::Button showAllButton = Gtk::Button("Show all Pokemon.");
	Gtk::Button quitButton = Gtk::Button("Exit PokedexC++.");
};