//Inclusions
#include "GuiHandler.h"
#include <iostream>
#include <gtkmm-3.0/gtkmm.h>

//Methods
GuiHandler::GuiHandler() {
	auto app = Gtk::Application::create();

	Gtk::Window window;
	MainScreen main;
	HelpScreen help;

	guiWindow = &window;
	mainScreen = &main;
	helpScreen = &help;

	//Set screen button functions
	///Main screen
	main.getNumberButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getNameButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getPrimaryTypeButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getSecondaryTypeButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getGenerationButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getDualtypesButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getLegendariesButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getAllButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::showWip));
	main.getHelpButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toHelp));

	///Help Screen
	help.getReturnButton().signal_clicked().connect(sigc::mem_fun(*this, &GuiHandler::toMain));

	toMain();

	app->run(window);
}

GuiHandler::~GuiHandler() {

}

void GuiHandler::toMain() {
	guiWindow->remove();
	guiWindow->add(*mainScreen);	//Add main screen to window
	guiWindow->show_all_children();	//Show all children
}

void GuiHandler::toHelp() {
	guiWindow->remove();
	guiWindow->add(*helpScreen);
	guiWindow->show_all_children();
}

void GuiHandler::showWip(){
	std::cout << "In progress!" << std::endl;
}