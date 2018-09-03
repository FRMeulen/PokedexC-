//Inclusions
#include "GuiHandler.h"
#include <iostream>
#include <gtkmm-3.0/gtkmm.h>

//Methods
GuiHandler::GuiHandler() {
	auto app = Gtk::Application::create();

	//Setup dex connector
	DexConnector dex;
	
	Gtk::Window window;	//Window object

	//Screen objects
	MainScreen main;
	HelpScreen help;
	SearchScreen search;
	PokemonScreen pokemon;

	//Set pointers
	pokeDex = &dex;

	guiWindow = &window;

	mainScreen = &main;
	helpScreen = &help;
	searchScreen = &search;
	pokemonScreen = &pokemon;

	//Set screen button functions
	///Main screen
	main.getNumberButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toNumberSearch));
	main.getNameButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toNameSearch));
	main.getPrimaryTypeButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toPriTypeSearch));
	main.getSecondaryTypeButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toSecTypeSearch));
	main.getGenerationButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toGenSearch));
	main.getDualtypesButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getLegendariesButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getAllButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getHelpButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toHelp));

	///Help Screen
	help.getReturnButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toMain));

	///Search Screen
	search.getSearchButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::searchPokemon));
	search.getReturnButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toMain)); 

	//Pokemon screen
	pokemon.getReturnButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toMain));

	toMain();

	app->run(window);
}

GuiHandler::~GuiHandler() {

}

void GuiHandler::toMain() {
	pokemonScreen->removeContents();

	guiWindow->remove();
	guiWindow->add(*mainScreen);	//Add main screen to window
	guiWindow->show_all_children();	//Show all children
}

void GuiHandler::toNumberSearch(){
	searchMode = 1;
	toSearch();
}

void GuiHandler::toNameSearch(){
	searchMode = 2;
	toSearch();
}

void GuiHandler::toPriTypeSearch(){
	searchMode = 3;
	toSearch();
}

void GuiHandler::toSecTypeSearch(){
	searchMode = 4;
	toSearch();
}

void GuiHandler::toGenSearch(){
	searchMode = 5;
	toSearch();
}

void GuiHandler::toSearch(){
	guiWindow->remove();
	guiWindow->add(*searchScreen);
	guiWindow->show_all_children();
}

void GuiHandler::toHelp() {
	guiWindow->remove();
	guiWindow->add(*helpScreen);
	guiWindow->show_all_children();
}

void GuiHandler::searchPokemon(){
	//Search pokemon
	std::string searchTerm = searchScreen->getInputEntry().get_text();	//Set search term
	sql::ResultSet *result;

	if(searchMode == 1){	//If searching by number
		result = pokeDex->searchByNumber(searchTerm);
		searchOne(result);
	}
	else if(searchMode == 2){	//... by name
		result = pokeDex->searchByName(searchTerm);
		searchOne(result);
	}
	else if(searchMode == 3){	//... by primary type
		result = pokeDex->searchByPrimaryType(searchTerm);
	}
	else if(searchMode == 4){	//... by secondary type
		result = pokeDex->searchBySecondaryType(searchTerm);
	}
	else if(searchMode == 5){	//... by generation
		result = pokeDex->searchByGeneration(searchTerm);
	}
}

void GuiHandler::searchOne(sql::ResultSet *result){
	result->next();

	//Fill data strings
	std::string dataNumber = "Number: " + result->getString("number");
	std::string dataName = "Name: " + result->getString("name");
	std::string dataPrimaryType = "Primary Type: " + result->getString("primary_type");
	std::string dataSecondaryType = "Secondary Type: " + result->getString("secondary_type");
	std::string dataGenIntroduced = "Generation Introduced: " + result->getString("gen_introduced");
	std::string spritePath = "./sprites/" + result->getString("name") + ".png";

	//Set window
	guiWindow->remove();
	guiWindow->add(*pokemonScreen);
	pokemonScreen->setContents(
		dataNumber,
		dataName,
		dataPrimaryType,
		dataSecondaryType,
		dataGenIntroduced,
		spritePath);
	guiWindow->show_all_children();

	//Reset input entry
	searchScreen->getInputEntry().set_text("");
}

void GuiHandler::searchSet(sql::ResultSet *result){

}

void GuiHandler::showWip(){
	std::cout << "In progress!" << std::endl;
}