//Inclusions
#include <iostream>
#include "HelpScreen.h"

//Methods
HelpScreen::HelpScreen(){
	//Set parent
	parent = dex;

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
			"    <b><big>5 search options</big></b>\n"
			"    <b><big>3 show options</big></b>\n\n"
			"<big>Search options allow you to search for a specific Pokemon.</big>\n"
			"<big>Show options allow you to show certain sets op Pokemon.</big>"
		);

	//Signal handlers
	returnButton.signal_clicked().connect(sigc::mem_fun(*this, &HelpScreen::toMainScreen));

	//Display widgets
	show_all_children();
}

HelpScreen::~HelpScreen(){

}

void HelpScreen::toMainScreen(){

}