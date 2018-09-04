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

protected:
	//Tree model
	class ModelColumns : public Gtk::TreeModel::ColumnRecord {
	public:
		ModelColumns() {
			add(modelColumnID);
			add(modelColumnName);
			add(modelColumnSprite);
			add(modelColumnButton);
		}

		Gtk::TreeModelColumn<std::string> modelColumnID;
		Gtk::TreeModelColumn<std::string> modelColumnName;
		Gtk::TreeModelColumn<std::string> modelColumnSprite;
		Gtk::TreeModelColumn<std::string> modelColumnButton;
	};

	ModelColumns modelColumns;

	Gtk::Box listVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
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