//	Project:	PokedexC++.
//	ResultsEntry.cpp	--	Implementation of the CResultsEntry class.
//	Revisions:
//	2018-10-26	--	F.R. van der Meulen	--	Created.
//	2018-10-29	--	F.R. van der Meulen	--	Renamed, now derived from Gtk::Frame.

//	Include files.
#include "ResultsEntry.h"
#include <iostream>

//	Constructor.
CResultsEntry::CResultsEntry() {
	//	Child widgets.
	this->set_border_width(10);
	this->add(m_entryMainHBox);

	m_entryMainHBox.pack_start(m_entryInfoVBox, Gtk::PACK_EXPAND_WIDGET, 5);
		m_entryInfoVBox.pack_start(m_entryNumNameHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryNumNameHBox.pack_start(m_entryNumFrame, Gtk::PACK_SHRINK, 5);
				m_entryNumFrame.add(m_entryNumLabel);
			m_entryNumNameHBox.pack_start(m_entryNameFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entryNameFrame.add(m_entryNameLabel);

		m_entryInfoVBox.pack_start(m_entryTypesHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryTypesHBox.pack_start(m_entryPriTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entryPriTypeFrame.add(m_entryPriTypeLabel);

			m_entryTypesHBox.pack_start(m_entrySecTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entrySecTypeFrame.add(m_entrySecTypeLabel);

	m_entryMainHBox.pack_start(m_selectEntryButton, Gtk::PACK_SHRINK, 5);

	//	Signal handler.
	//m_selectEntryButton.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &EntryBox::FUNCNAME), m_entryNumLabel.get_text()));
}

//	Destructor.
CResultsEntry::~CResultsEntry() {

}

//	setEntryData	--	Sets data in entry boxes.
//	Parameters:
//		num		--	String of Pokemon number.
//		name	--	String of Pokemon name.
//		pritype	--	String of Pokemon primary type.
//		sectype	--	String of Pokemon secondary type.
//	Returns:	void.
void CResultsEntry::setEntryData(std::string num, std::string name, std::string pritype, std::string sectype) {
	m_entryNumLabel.set_text(num);
	m_entryNameLabel.set_text(name);
	m_entryPriTypeLabel.set_text(pritype);
	m_entrySecTypeLabel.set_text(sectype);
}

//	getNumber	--	Returns Pokemon number.
//	Parameters:	none.
//	Returns:	String of Pokemon number.
std::string CResultsEntry::getNumber() {
	return m_entryNumLabel.get_text();
}