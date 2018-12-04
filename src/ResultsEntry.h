//	Project:	PokedexC++.
//	ResultsEntry.h	--	Interface for the CResultsEntry class.
//	Revisions:
//	2018-10-26	--	F.R. van der Meulen	--	Created.
//	2018-10-29	--	F.R. van der Meulen	--	Renamed, now derived from Gtk::Frame.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.
//	2018-12-04	--	F.R. van der Meulen	--	Added getName method.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>

//	Class interface.
class CResultsEntry {
protected:
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
	CResultsEntry();
	virtual ~CResultsEntry();

	//	Getters.
	std::string getNumber();
	std::string getName();
	Gtk::Frame* getMainFrame();

	//	Setters.
	void setEntryData(std::string num, std::string name, std::string pritype, std::string(sectype));
};