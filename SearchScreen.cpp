//Inclusions
#include "SearchScreen.h"

//Methods
SearchScreen::SearchScreen(){
	//Add main box
	this->pack_start(mainVBox, Gtk::PACK_EXPAND_WIDGET, 10);

	//Pack main box
	mainVBox.pack_start(searchFrame, Gtk::PACK_EXPAND_WIDGET, 10);
	mainVBox.pack_start(optionsFrame, Gtk::PACK_SHRINK, 10);

	//Pack frames
	searchFrame.add(entryHBox);
	optionsFrame.add(returnButton);

	//Configure boxes
	entryHBox.set_border_width(10);

	//Pack boxes
	///Entry box
	entryHBox.pack_start(numberEntry, Gtk::PACK_EXPAND_WIDGET, 10);
	entryHBox.pack_start(searchButton, Gtk::PACK_EXPAND_WIDGET, 10);
}

SearchScreen::~SearchScreen(){

}

Gtk::Button& SearchScreen::getSearchButton(){
	return searchButton;
}

Gtk::Button& SearchScreen::getReturnButton(){
	return returnButton;
}

Gtk::Entry& SearchScreen::getInputEntry(){
	return numberEntry;
}