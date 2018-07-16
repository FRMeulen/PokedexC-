//Inclusions
#include "MainScreen.h"
#include <iostream>

//Constructor
MainScreen::MainScreen() {
	//Window properties
	set_border_width(10);

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

	//Pack into box
	buttonBox.pack_start(numberButton);
	buttonBox.pack_start(nameButton);
	buttonBox.pack_start(primaryTypeButton);
	buttonBox.pack_start(secondaryTypeButton);
	buttonBox.pack_start(generationButton);
	buttonBox.pack_start(hybridsButton);
	buttonBox.pack_start(legendariesButton);
	buttonBox.pack_start(showAllButton);
	buttonBox.pack_start(quitButton);

	//Pack into window
	add(boxBox);

	//Display widgets
	numberButton.show();
	nameButton.show();
	primaryTypeButton.show();
	secondaryTypeButton.show();
	generationButton.show();
	hybridsButton.show();
	legendariesButton.show();
	showAllButton.show();
	quitButton.show();
	buttonBox.show();
	buttonBox.show();
	boxBox.show();
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