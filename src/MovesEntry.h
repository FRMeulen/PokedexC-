//	Project:	PokedexC++.
//	MovesEntry.h	--	Interface for the CMovesEntry class.
//	Revisions:
//	2018-12-11	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>

//	Class interface.
class CMovesEntry {
protected:
	//	Data holders.
	std::string m_strMoveLearnCondition;
	std::string m_strMoveName;
	std::string m_strMovePower;
	std::string m_strMoveAccuracy;
	std::string m_strMovePP;
	std::string m_strMoveType;
	std::string m_strMoveCategory;

	//	Child widget pointers.
	Gtk::Frame* m_entryMainFrame;
		Gtk::Box* m_entryMainVBox;
			Gtk::Box* m_entryTopHBox;
				Gtk::Frame* m_moveLearnConditionFrame;
					Gtk::Label* m_moveLearnCondition;

				Gtk::Frame* m_moveNameFrame;
					Gtk::Label* m_moveName;

				Gtk::Frame* m_movePowerFrame;
					Gtk::Label* m_movePower;

				Gtk::Frame* m_moveAccuracyFrame;
					Gtk::Label* m_moveAccuracy;

				Gtk::Frame* m_movePPFrame;
					Gtk::Label* m_movePP;

			Gtk::Box* m_entryBottomHBox;
				Gtk::Frame* m_moveTypeFrame;
					Gtk::Label* m_moveType;

				Gtk::Frame* m_moveCategoryFrame;
					Gtk::Label* m_moveCategory;

public:
	//	Constructors & destructor.
	CMovesEntry(std::string condition, std::string name, std::string power, std::string accuracy, std::string pp, std::string type, std::string category);
	virtual ~CMovesEntry();

	//	Methods.
	Gtk::Frame* getMainFrame();
};