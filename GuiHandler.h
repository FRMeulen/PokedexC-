//Pragma
#pragma once

//Inclusions
#include "MainScreen.h"
#include "HelpScreen.h"
#include "SearchScreen.h"
#include "PokemonScreen.h"
#include "PokeSetScreen.h"
#include "DexConnector.h"

//Class
class GuiHandler {
public:
	GuiHandler();
	virtual ~GuiHandler();
	DexConnector *pokeDex;

protected:
	int searchMode = 0;	//Tracks search mode

	Gtk::Window *guiWindow;	//Window pointer

	//Screen pointers
	MainScreen *mainScreen;
	HelpScreen *helpScreen;
	SearchScreen *searchScreen;
	PokemonScreen *pokemonScreen;
	PokeSetScreen *pokeSetScreen;

	//Methods
	///Screen transitions
	void toHelp();
	void toMain();
	void toSearch();
	void toPokeSetScreen();
	
	//Search options
	void toNumberSearch();
	void toNameSearch();
	void toPriTypeSearch();
	void toSecTypeSearch();
	void toGenSearch();

	//Functional methods
	void searchPokemon();
	void searchOne(sql::ResultSet *result);
	void searchSet(sql::ResultSet *result);
	void quitDex();

	//Temporary methods
	void showWip();
};