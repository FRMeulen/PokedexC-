//Inclusions
#include "SearchScreen.h"

//Methods
SearchScreen::SearchScreen(){
	//Add main box
	this->pack_start(frame);

	//Pack main box
	frame.add(mainVBox);

	//Pack frame
	mainVBox.pack_start(entryHBox, Gtk::PACK_EXPAND_WIDGET, 10);
	mainVBox.pack_start(returnButton, Gtk::PACK_EXPAND_WIDGET, 10);

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