//Pragma
#pragma once

//Inclusions
#include <gtkmm-3.0/gtkmm.h>

//Class
class PokeSetScreen : public Gtk::Box {
public:
	PokeSetScreen();
	virtual ~PokeSetScreen();
	Gtk::Button& getReturnButton();
	void clearPokemon();
	void appendPokemon(
		std::string _pokeNum,
		std::string _pokeName,
		std::string _pokePriType,
		std::string _pokeSecType,
		std::string _pokeGen
	);

protected:
	//Tree model
	class ModelColumns : public Gtk::TreeModel::ColumnRecord {
	public:
		ModelColumns() {
			add(modelColumnID);
			add(modelColumnName);
			add(modelColumnPriType);
			add(modelColumnSecType);
			add(modelColumnGen);
		}

		Gtk::TreeModelColumn<std::string> modelColumnID;
		Gtk::TreeModelColumn<std::string> modelColumnName;
		Gtk::TreeModelColumn<std::string> modelColumnPriType;
		Gtk::TreeModelColumn<std::string> modelColumnSecType;
		Gtk::TreeModelColumn<std::string> modelColumnGen;
	};

	ModelColumns modelColumns;

	Gtk::ScrolledWindow scrollWindow;
	Gtk::TreeView treeView;
	Glib::RefPtr<Gtk::ListStore> refTreeModel;

	//Child widgets
	///Boxes
	Gtk::Box mainVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);

	///Frames
	Gtk::Frame scrollFrame = Gtk::Frame("Matching Pokemon");
	Gtk::Frame optionsFrame = Gtk::Frame("Options");

	///Buttons
	Gtk::Button returnButton = Gtk::Button("Return to main screen");
};