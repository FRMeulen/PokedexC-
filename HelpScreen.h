//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>

//Class
class HelpScreen : public Gtk::Box {
public:
	HelpScreen();
	virtual ~HelpScreen();

protected:
	//Signal handlers
	void toMainScreen();

	//Child widgets
	///Boxes
	Gtk::Box mainVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);

	///Frames
	Gtk::Frame textFrame = Gtk::Frame("Explanation");

	///Labels
	Gtk::Label helpText;

	///Buttons
	Gtk::Button returnButton = Gtk::Button("Return to Main Screen");
};