//	Project:	PokedexC++.
//	ResultsEntry.h	--	Interface for the CResultsEntry class.
//	Revisions:
//	2018-10-26	--	F.R. van der Meulen	--	Created.
//	2018-10-29	--	F.R. van der Meulen	--	Renamed, now derived from Gtk::Frame.

//	Pragma.
#pragma once

//	Include files.
#include <gtkmm-3.0/gtkmm.h>

//	Class interface.
class CResultsEntry : public Gtk::Frame {
protected:
	//	Child widgets
	Gtk::Box m_entryMainHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
		Gtk::Box m_entryInfoVBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
			Gtk::Box m_entryNumNameHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				Gtk::Frame m_entryNumFrame;
					Gtk::Label m_entryNumLabel;
				
				Gtk::Frame m_entryNameFrame;
					Gtk::Label m_entryNameLabel;

			Gtk::Box m_entryTypesHBox = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				Gtk::Frame m_entryPriTypeFrame;
					Gtk::Label m_entryPriTypeLabel;

				Gtk::Frame m_entrySecTypeFrame;
					Gtk::Label m_entrySecTypeLabel;

		Gtk::Button m_selectEntryButton = Gtk::Button("More...");
public:
	//	Constructors & destructor.
	CResultsEntry();
	virtual ~CResultsEntry();

	//	Methods
	void setEntryData(std::string num, std::string name, std::string pritype, std::string(sectype));
	std::string getNumber();
};