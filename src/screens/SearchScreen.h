//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>

//Class
class SearchScreen : public Gtk::Box {
public:
	SearchScreen();
	virtual ~SearchScreen();

	//Button getters
	Gtk::Button& getSearchButton();
	Gtk::Button& getReturnButton();

	//Entry getter
	Gtk::Entry& getInputEntry();

protected:
	//Child widgets
	///Boxes
	Gtk::Box mainVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
	Gtk::Box entryHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

	///Frames
	Gtk::Frame searchFrame = Gtk::Frame("Search");
	Gtk::Frame optionsFrame = Gtk::Frame("Options");

	///Entries
	Gtk::Entry numberEntry = Gtk::Entry();

	///Buttons
	Gtk::Button searchButton = Gtk::Button("Find Pokemon!");
	Gtk::Button returnButton = Gtk::Button("Back to Main Screen");
};