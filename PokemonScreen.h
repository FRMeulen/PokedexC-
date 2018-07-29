//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include "DexConnector.h"

//Class
class PokemonScreen : public Gtk::Box {
public:
	PokemonScreen();
	virtual ~PokemonScreen();
	void setByNumber(std::string number);
	void setByName(std::string name);
	void setByPriType(std::string priType);
	void setBySecType(std::string secType);
	void setByGeneration(std::string gen);

	//Button getters
	Gtk::Button& getReturnButton();

protected:
	//Dex pointer
	DexConnector *pokeDex;

	//Child widgets
	///Boxes
	Gtk::Box mainHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
	Gtk::Box infoVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);

	///Frames
	Gtk::Frame frame;

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