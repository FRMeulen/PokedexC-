//Pragma
#pragma once

//Inclusions
#include "MainScreen.h"
#include "HelpScreen.h"
#include "NumberSearchScreen.h"
#include "PokemonScreen.h"

//Class
class GuiHandler {
public:
	GuiHandler();
	virtual ~GuiHandler();

protected:
	Gtk::Window *guiWindow;	//Window pointer


	//Screen pointers
	MainScreen *mainScreen;
	HelpScreen *helpScreen;
	NumberSearchScreen *numberSearch;
	PokemonScreen *pokemonScreen;

	//Methods
	void toHelp();
	void toMain();
	void toNumberSearch();
	void toPokemonByNumber();

	//Temporary methods
	void showWip();
};