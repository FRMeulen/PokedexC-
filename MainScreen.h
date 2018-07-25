//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>

//Class
class MainScreen : public Gtk::Box {
public:
	MainScreen();
	virtual ~MainScreen();

	//Button getters
	Gtk::Button& getNumberButton();
	Gtk::Button& getNameButton();
	Gtk::Button& getPrimaryTypeButton();
	Gtk::Button& getSecondaryTypeButton();
	Gtk::Button& getGenerationButton();
	Gtk::Button& getDualtypesButton();
	Gtk::Button& getLegendariesButton();
	Gtk::Button& getAllButton();
	Gtk::Button& getHelpButton();

protected:
	void quitDex();

	//Child widgets
	///Boxes
	Gtk::Box mainVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
	Gtk::Box buttonsHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
	Gtk::Box searchVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
	Gtk::Box showVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
	Gtk::Box optionsVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);

	///Frames
	Gtk::Frame searchFrame = Gtk::Frame("Search pokemon");
	Gtk::Frame showFrame = Gtk::Frame("Show pokemon sets");
	Gtk::Frame optionsFrame = Gtk::Frame("Options");

	///Labels
	Gtk::Label welcome;

	///Buttons
	Gtk::Button numberButton = Gtk::Button("Search by Number");
	Gtk::Button nameButton = Gtk::Button("Search by Name");
	Gtk::Button primaryTypeButton = Gtk::Button("Search by Primary Type");
	Gtk::Button secondaryTypeButton = Gtk::Button("Search by Secondary Type");
	Gtk::Button generationButton = Gtk::Button("Search by Generation");
	Gtk::Button dualtypesButton = Gtk::Button("Show Dual-Type Pokemon");
	Gtk::Button legendariesButton = Gtk::Button("Show Legendary Pokemon");
	Gtk::Button allButton = Gtk::Button("Show all Pokemon");
	Gtk::Button helpButton = Gtk::Button("Help");
	Gtk::Button quitButton = Gtk::Button("Exit PokedexC++");
};