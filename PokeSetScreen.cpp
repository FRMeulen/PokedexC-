//Inclusions
#include "PokeSetScreen.h"

//Methods
PokeSetScreen::PokeSetScreen(){
	//Add main box
	this->pack_start(mainVBox, Gtk::PACK_EXPAND_WIDGET, 10);

	//Pack main box
	mainVBox.pack_start(scrollFrame, Gtk::PACK_EXPAND_WIDGET, 10);
	mainVBox.pack_start(optionsFrame, Gtk::PACK_SHRINK, 10);

	//Pack frames
	scrollFrame.add(treeView);
	optionsFrame.add(returnButton);

	//Hide scrollbar when not necessary
	scrollWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
}

PokeSetScreen::~PokeSetScreen(){

}

Gtk::Button& PokeSetScreen::getReturnButton(){
	return returnButton;
}
