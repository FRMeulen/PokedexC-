//Inclusions
#include "MainScreen.h"

//Methods
MainScreen::MainScreen(){
	//Add main box
	this->pack_start(mainVBox);

	//Pack main box
	mainVBox.pack_start(welcome, Gtk::PACK_EXPAND_WIDGET, 10);
	mainVBox.pack_start(buttonsHBox, Gtk::PACK_EXPAND_WIDGET, 10);

	//Configure welcome label
	welcome.set_markup("<b><big>-= Welcome to PokedexC++ =-</big></b>");

	//Pack buttons box
	buttonsHBox.pack_start(searchFrame, Gtk::PACK_EXPAND_WIDGET, 10);
	buttonsHBox.pack_start(showFrame, Gtk::PACK_EXPAND_WIDGET, 10);
	buttonsHBox.pack_start(optionsFrame, Gtk::PACK_EXPAND_WIDGET, 10);

	//Pack frames
	searchFrame.add(searchVBox);
	showFrame.add(showVBox);
	optionsFrame.add(optionsVBox);

	//Configure boxes
	searchVBox.set_border_width(10);
	showVBox.set_border_width(10);
	optionsVBox.set_border_width(10);

	//Pack boxes
	///Search box
	searchVBox.pack_start(numberButton);
	searchVBox.pack_start(nameButton);

	///Show box
	showVBox.pack_start(primaryTypeButton);
	showVBox.pack_start(secondaryTypeButton);
	showVBox.pack_start(generationButton);
	showVBox.pack_start(dualtypesButton);
	showVBox.pack_start(legendariesButton);
	showVBox.pack_start(allButton);

	///Options box
	optionsVBox.pack_start(helpButton);
	optionsVBox.pack_start(quitButton);
}

MainScreen::~MainScreen(){

}

Gtk::Button& MainScreen::getNumberButton(){
	return numberButton;
}

Gtk::Button& MainScreen::getNameButton(){
	return nameButton;
}

Gtk::Button& MainScreen::getPrimaryTypeButton(){
	return primaryTypeButton;
}

Gtk::Button& MainScreen::getSecondaryTypeButton(){
	return secondaryTypeButton;
}

Gtk::Button& MainScreen::getGenerationButton(){
	return generationButton;
}

Gtk::Button& MainScreen::getDualtypesButton(){
	return dualtypesButton;
}

Gtk::Button& MainScreen::getLegendariesButton(){
	return legendariesButton;
}

Gtk::Button& MainScreen::getAllButton(){
	return allButton;
}

Gtk::Button& MainScreen::getHelpButton(){
	return helpButton;
}

Gtk::Button& MainScreen::getQuitButton(){
	return quitButton;
}