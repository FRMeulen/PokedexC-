//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>

//Class
class PokemonScreen : public Gtk::Box {
public:
	PokemonScreen();
	virtual ~PokemonScreen();
	void setContents(
		std::string _pokeNumber,
		std::string _pokeName,
		std::string _pokePriType,
		std::string _pokeSecType,
		std::string _pokeFirstGen,
		std::string _pokePath);
	void removeContents();

	//Button getters
	Gtk::Button& getReturnButton();

protected:
	//Child widgets
	///Boxes
	Gtk::Box mainHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
	Gtk::Box spriteBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
	Gtk::Box rightVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
	Gtk::Box infoVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);

	///Frames
	Gtk::Frame frame;
	Gtk::Frame spriteFrame = Gtk::Frame("Sprite");
	Gtk::Frame infoFrame = Gtk::Frame("Information");
	Gtk::Frame optionsFrame = Gtk::Frame("Options");

	///Labels
	Gtk::Label pokeNum;
	Gtk::Label pokeName;
	Gtk::Label pokePriType;
	Gtk::Label pokeSecType;
	Gtk::Label pokeGen;

	///Sprite
	Gtk::Image sprite;

	///Buttons
	Gtk::Button returnButton = Gtk::Button("Back to Main Screen");
};