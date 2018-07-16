//Inclusions
#include "DexConnector.h"
#include "MainScreen.h"
#include <gtkmm-3.0/gtkmm.h>
#include <iostream>
#include <stdlib.h>
#include <string>

//Fields
bool running = true;
DexConnector dex;

//Method
void askCommand(){
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "\tA) Search by number" << std::endl;
	std::cout << "\tB) Search by name" << std::endl;
	std::cout << "\tC) Search by primary type" << std::endl;
	std::cout << "\tD) Search by secondary type" << std::endl;
	std::cout << "\tE) Search by generation" << std::endl;
	std::cout << "\tF) Show hybrids" << std::endl;
	std::cout << "\tG) Show legendaries" << std::endl;
	std::cout << "\tH) Show all pokemon" << std::endl;
	std::cout << "\tI) Quit" << std::endl;

	std::string input;
	std::cout << "Choose: ";
	std::cin >> input;
	std::cout << std::endl;

	if(input == "A" || input == "a"){
		//Search by number
		std::cout << "Enter number to search: ";
		std::cin >> input;
		dex.searchByNumber(input);
	}
	else if(input == "B" || input == "b"){
		//Search by name
		std::cout << "Enter name to search: ";
		std::cin >> input;
		dex.searchByName(input);
	}
	else if(input == "C" || input == "c"){
		//Search by primary type
		std::cout << "Enter type to search: ";
		std::cin >> input;
		dex.searchByPrimaryType(input);
	}
	else if(input == "D" || input == "d"){
		//Search by secondary type
		std::cout << "Enter type to search: ";
		std::cin >> input;
		dex.searchBySecondaryType(input);
	}
	else if(input == "E" || input == "e"){
		//Search by generation
		std::cout << "Enter generation to search: ";
		std::cin >> input;
		dex.searchByGeneration(input);
	}
	else if(input == "F" || input == "f"){
		//Show hybrids
		dex.showHybrids();
	}
	else if(input == "G" || input == "g"){
		//Show legendaries
		dex.showLegendaries();
	}
	else if(input == "H" || input == "h"){
		//Show all pokemon
		dex.showAll();
	}
	else if(input == "I" || input == "i"){
		//Quit
		std::cout << "Exiting pokebase! Bye!" << std::endl;
		running = false;
	}
	else{
		std::cout << "Unknown command! Exiting!" << std::endl;
		running = false;
	}
}

int main(int argc, char *argv[]){
	std::cout << "--==Welcome to the pokebase!==--" << std::endl;
	
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	MainScreen mainScreen;

	return app->run(mainScreen);

	/*
	while(running){
		askCommand();
	}

	return 0;
	*/
}