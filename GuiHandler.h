//Pragma
#pragma once

//Inclusions
#include "MainScreen.h"
#include "HelpScreen.h"
#include "SearchScreen.h"
#include "PokemonScreen.h"
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

	//Methods
	///Screen transitions
	void toHelp();
	void toMain();
	void toSearch();
	
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

	//Temporary methods
	void showWip();
};