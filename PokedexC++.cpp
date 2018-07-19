//Inclusions
#include "DexConnector.h"
#include "MainScreen.h"
#include "HelpScreen.h"
#include <gtkmm-3.0/gtkmm.h>
#include <iostream>
#include <stdlib.h>
#include <string>

//Fields
DexConnector dex;
std::string currentScreen = "main";

int main(int argc, char *argv[]){
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	Gtk::Window window;

	//Screen objects
	MainScreen mainScreen;
	HelpScreen helpScreen;

	//Add to window before running
	window.add(helpScreen);

	//Show all window children
	window.show_all_children();

	app->run(window);

	return 0;
}