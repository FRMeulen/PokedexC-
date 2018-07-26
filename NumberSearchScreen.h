//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>

//Class
class NumberSearchScreen : public Gtk::Box {
public:
	NumberSearchScreen();
	virtual ~NumberSearchScreen();

	//Button getters
	Gtk::Button& getSearchButton();
	Gtk::Button& getReturnButton();

	//Entry getter
	Gtk::Entry& getInputEntry();

protected:
	//Child widgeets
	///Boxes
	Gtk::Box mainVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
	Gtk::Box entryHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

	///Frames
	Gtk::Frame frame = Gtk::Frame("Search by Number");

	///Entries
	Gtk::Entry numberEntry = Gtk::Entry();

	///Buttons
	Gtk::Button searchButton = Gtk::Button("Find Pokemon!");
	Gtk::Button returnButton = Gtk::Button("Back to Main Screen");
};