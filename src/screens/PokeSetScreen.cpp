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
	optionsFrame.add(returnButton);

	//Setup scroll window
	scrollWindow.add(treeView);
	scrollWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);	//Hide scrollbar when not necessary
	
	//Create tree model
	refTreeModel = Gtk::ListStore::create(modelColumns);
	treeView.set_model(refTreeModel);

	//Add TreeView view columns
	treeView.append_column("Number", modelColumns.modelColumnID);
	treeView.append_column("Name", modelColumns.modelColumnName);
	treeView.append_column("Primary Type", modelColumns.modelColumnPriType);
	treeView.append_column("Secondary Type", modelColumns.modelColumnSecType);
	treeView.append_column("Gen Introduced", modelColumns.modelColumnGen);
	//Pack scroll frame
	scrollFrame.add(scrollWindow);

	//Show all children
	show_all_children();
}

PokeSetScreen::~PokeSetScreen(){

}

void PokeSetScreen::clearPokemon(){
	refTreeModel->clear();
}

void PokeSetScreen::appendPokemon(
	std::string _pokeNum,
	std::string _pokeName,
	std::string _pokePriType,
	std::string _pokeSecType,
	std::string _pokeGen
){
	Gtk::TreeModel::Row row = *(refTreeModel->append());
	row[modelColumns.modelColumnID] = _pokeNum;
	row[modelColumns.modelColumnName] = _pokeName;
	row[modelColumns.modelColumnPriType] = _pokePriType;
	row[modelColumns.modelColumnSecType] = _pokeSecType;
	row[modelColumns.modelColumnGen] = _pokeGen;
}

Gtk::Button& PokeSetScreen::getReturnButton(){
	return returnButton;
}