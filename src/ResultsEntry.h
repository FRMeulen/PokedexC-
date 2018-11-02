//	Project:	PokedexC++.
//	ResultsEntry.h	--	Interface for the CResultsEntry class.
//	Revisions:
//	2018-10-26	--	F.R. van der Meulen	--	Created.
//	2018-10-29	--	F.R. van der Meulen	--	Renamed, now derived from Gtk::Frame.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>
#include "MainScreen.h"

//	Class interface.
class CResultsEntry {
protected:
	//	Main screen pointer.
	CMainScreen* m_mainScreen;

	//	Child widget pointers.
	Gtk::Frame* m_entryMainFrame;
		Gtk::Box* m_entryMainHBox;
			Gtk::Box* m_entryInfoVBox;
				Gtk::Box* m_entryNumNameHBox;
					Gtk::Frame* m_entryNumFrame;
						Gtk::Label* m_entryNumLabel;
				
					Gtk::Frame* m_entryNameFrame;
						Gtk::Label* m_entryNameLabel;

				Gtk::Box* m_entryTypesHBox;
					Gtk::Frame* m_entryPriTypeFrame;
						Gtk::Label* m_entryPriTypeLabel;

					Gtk::Frame* m_entrySecTypeFrame;
						Gtk::Label* m_entrySecTypeLabel;

		Gtk::Button* m_selectEntryButton;
public:
	//	Constructors & destructor.
	CResultsEntry(CMainScreen parmScreen);
	virtual ~CResultsEntry();

	//	Methods.
	void appendToScreen();

	//	Getters.
	std::string getNumber();

	//	Setters.
	void setEntryData(std::string num, std::string name, std::string pritype, std::string(sectype));
};