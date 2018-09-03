//Inclusions
#include "HelpScreen.h"

//Methods
HelpScreen::HelpScreen(){
	//Add main box
	this->pack_start(mainVBox);

	//Pack main box
	mainVBox.pack_start(textFrame);
	mainVBox.pack_start(returnButton);

	//Pack frames
	textFrame.add(helpText);

	//Configure label
	helpText.set_single_line_mode(false);
	helpText.set_markup(
			"<b><big>This Pokedex offers many features:</big></b>\n"
			"	<b><big>2 search options</big></b>\n"
			"	<b><big>6 show options</big></b>\n\n"
			"<big>Search options allow you to search for a specific Pokemon.</big>\n"
			"<big>Show options allow you to show certain sets of Pokemon.</big>"
		);
}

HelpScreen::~HelpScreen(){

}

Gtk::Button& HelpScreen::getReturnButton(){
	return returnButton;
}