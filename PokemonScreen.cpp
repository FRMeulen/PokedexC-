//Inclusions
#include "PokemonScreen.h"

//Methods
PokemonScreen::PokemonScreen(){
	DexConnector dex;
	pokeDex = &dex;

	//Add frame
	this->pack_start(frame);

	//Pack frame
	frame.add(mainHBox);

	//Pack main box
	mainHBox.pack_start(sprite, Gtk::PACK_EXPAND_WIDGET, 10);
	mainHBox.pack_start(infoVBox, Gtk::PACK_EXPAND_WIDGET, 10);

	//Configure boxes
	infoVBox.set_border_width(10);

	//Pack info box
	infoVBox.pack_start(pokeNum, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokeName, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokePriType, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokeSecType, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(pokeGen, Gtk::PACK_EXPAND_WIDGET, 10);
	infoVBox.pack_start(returnButton, Gtk::PACK_EXPAND_WIDGET, 10);
}

PokemonScreen::~PokemonScreen(){

}

void PokemonScreen::setByNumber(std::string number){
	sql::ResultSet *result = pokeDex->searchByNumber(number);

	//Store information
	std::string dataNumber = result->getString("number");
	std::string dataName = result->getString("name");
	std::string dataPrimaryType = result->getString("primary_type");
	std::string dataSecondaryType = result->getString("secondary_type");
	std::string dataGenIntroduced = result->getString("gen_introduced");
	std::string spritePath = "./sprites/" + result->getString("name");

	pokeNum = Gtk::Label(dataNumber);
	pokeName = Gtk::Label(dataName);
	pokePriType = Gtk::Label(dataPrimaryType);
	pokeSecType = Gtk::Label(dataSecondaryType);
	pokeGen = Gtk::Label(dataGenIntroduced);
	sprite = Gtk::Image(spritePath);
}

void PokemonScreen::setByName(std::string name){

}

void PokemonScreen::setByPriType(std::string priType){

}

void PokemonScreen::setBySecType(std::string secType){

}

void PokemonScreen::setByGeneration(std::string gen){

}

Gtk::Button& PokemonScreen::getReturnButton(){
	return returnButton;
}