//Inclusions
#include "PokemonScreen.h"

//Methods
PokemonScreen::PokemonScreen(){
	//Add frame
	this->pack_start(frame);

	//Pack frame
	frame.add(mainHBox);

	//Pack main box
	mainHBox.pack_start(spriteFrame, Gtk::PACK_EXPAND_WIDGET, 10);
	mainHBox.pack_start(rightVBox, Gtk::PACK_EXPAND_WIDGET, 10);

	//Pack right box
	rightVBox.pack_start(infoFrame);
	rightVBox.pack_start(optionsFrame);

	//Configure boxes
	rightVBox.set_border_width(10);
	infoVBox.set_border_width(10);

	//Pack frames
	///Sprite frame
	spriteFrame.add(spriteBox);

	///Info frame
	infoFrame.add(infoVBox);

	///Options frame
	optionsFrame.add(returnButton);
}

PokemonScreen::~PokemonScreen(){

}

void PokemonScreen::setContents(
	std::string _pokeNumber,
	std::string _pokeName,
	std::string _pokePriType,
	std::string _pokeSecType,
	std::string _pokeFirstGen,
	std::string _pokePath
	){

	//Set contents
	pokeNum = Gtk::Label(_pokeNumber);
	pokeName = Gtk::Label(_pokeName);
	pokePriType = Gtk::Label(_pokePriType);
	pokeSecType = Gtk::Label(_pokeSecType);
	pokeGen = Gtk::Label(_pokeFirstGen);
	sprite = Gtk::Image(_pokePath);

	//Pack sprite
	spriteBox.pack_start(sprite, Gtk::PACK_EXPAND_WIDGET, 10);
	sprite.set_pixel_size(4);

	//Pack info
	infoVBox.pack_start(pokeNum, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokeName, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokePriType, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokeSecType, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokeGen, Gtk::PACK_EXPAND_WIDGET, 10);
}

void PokemonScreen::removeContents(){
	infoVBox.remove(pokeNum);
	infoVBox.remove(pokeName);
	infoVBox.remove(pokePriType);
	infoVBox.remove(pokeSecType);
	infoVBox.remove(pokeGen);
	spriteBox.remove(sprite);
}


Gtk::Button& PokemonScreen::getReturnButton(){
	return returnButton;
}