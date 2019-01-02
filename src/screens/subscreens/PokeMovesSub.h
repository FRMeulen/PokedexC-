//	Project:	PokedexC++.
//	PokeMovesSub.h	--	Interface for the CPokeMovesSub class.
//	Revisions:
//	2018-12-11	--	F.R. van der Meulen	--	Created.

//	Pragma
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include <cppconn/resultset.h>
#include "../../DexGui.h"
#include "../../MovesEntry.h"

//	Class interface.
class CPokeMovesSub {
protected:
	//	Gui pointer.
	CDexGui* m_gui;

	//	Resultset pointer.
	sql::ResultSet* m_res;

	//	Data holders.
	std::string m_strPokeNum;
	bool dummy;

	//	Child widget pointers.
	Gtk::Box* m_mainVBox;
		Gtk::Frame* m_moveLearnMethodsFrame;
			Gtk::Box* m_moveLearnMethodsHBox;
				Gtk::Button* m_levelUpMovesButton;
				Gtk::Button* m_tmHmMovesButton;
				Gtk::Button* m_eggMovesButton;
				Gtk::Button* m_tutorMovesButton;
		
		Gtk::Frame* m_movesFrame;
			Gtk::ScrolledWindow* m_scrollWindow;
				Gtk::Box* m_movesListVBox;
					std::vector<CMovesEntry*>* m_movesEntries;
					CMovesEntry* m_moveEntry;

public:
	//	Constructors & destructor.
	CPokeMovesSub();
	CPokeMovesSub(CDexGui* parmGui, std::string num);
	virtual ~CPokeMovesSub();

	//	Methods.
	void appendMove(CMovesEntry* entry);
	void showLevelUpMoves();
	void showTmHmMoves();
	void showEggMoves();
	void showTutorMoves();

	//	Getters.
	Gtk::Box* getMainBox();
	void getQueryResults(std::string newQuery);
};