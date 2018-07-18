//Inclusions
#include "MainScreen.h"
#include <iostream>

//Constructor
MainScreen::MainScreen() {
	//Window properties
	set_border_width(10);
	set_title("PokedexC++");

	//Add main box
	add(mainVBox);

	//Pack main box
	mainVBox.pack_start(welcome, Gtk::PACK_EXPAND_WIDGET, 10);
	mainVBox.pack_start(buttonsHBox, Gtk::PACK_EXPAND_WIDGET, 10);

	//Configure label
	welcome.set_markup("<b>-= Welcome to PokedexC++ =-</b>");

	//Pack buttons box
	buttonsHBox.pack_start(searchFrame, Gtk::PACK_EXPAND_WIDGET, 10);
	buttonsHBox.pack_start(showFrame, Gtk::PACK_EXPAND_WIDGET, 10);
	buttonsHBox.pack_start(quitButton, Gtk::PACK_EXPAND_WIDGET, 10);

	//Pack frames
	searchFrame.add(searchVBox);
	showFrame.add(showVBox);

	//Configure boxes
	searchVBox.set_border_width(10);
	showVBox.set_border_width(10);

	//Pack boxes
	///Searchbox
	searchVBox.pack_start(numberButton);
	searchVBox.pack_start(nameButton);
	searchVBox.pack_start(primaryTypeButton);
	searchVBox.pack_start(secondaryTypeButton);
	searchVBox.pack_start(generationButton);

	///Showbox
	showVBox.pack_start(hybridsButton);
	showVBox.pack_start(legendariesButton);
	showVBox.pack_start(showAllButton);


	//Signal handlers
	numberButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::searchByNumber));
	nameButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::searchByName));
	primaryTypeButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::searchByPrimaryType));
	secondaryTypeButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::searchBySecondaryType));
	generationButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::searchByGeneration));
	hybridsButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::showHybrids));
	legendariesButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::showLegendaries));
	showAllButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::showAll));
	quitButton.signal_clicked().connect(sigc::mem_fun(*this, &MainScreen::quitDex));

	//Display widgets
	show_all_children();
}

MainScreen::~MainScreen(){

}

void MainScreen::searchByNumber(){
	showWip();
}

void MainScreen::searchByName(){
	showWip();
}

void MainScreen::searchByPrimaryType(){
	showWip();
}

void MainScreen::searchBySecondaryType(){
	showWip();
}

void MainScreen::searchByGeneration(){
	showWip();
}

void MainScreen::showHybrids(){
	showWip();
}

void MainScreen::showLegendaries(){
	showWip();
}

void MainScreen::showAll(){
	showWip();
}

void MainScreen::quitDex(){
	
}

void MainScreen::showWip(){
	std::cout << "Sorry! Not implemented yet!" << std::endl;
}