//	Project:	PokedexC++.
//	ResultsEntry.cpp	--	Implementation of the CResultsEntry class.
//	Revisions:
//	2018-10-26	--	F.R. van der Meulen	--	Created.
//	2018-10-29	--	F.R. van der Meulen	--	Renamed, now derived from Gtk::Frame.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.
//	2018-12-04	--	F.R. van der Meulen	--	Added getName method.

//	Include files.
#include "ResultsEntry.h"
#include <iostream>

//	Constructor.
CResultsEntry::CResultsEntry() {
	//	Build child widgets.
	m_entryMainFrame = new Gtk::Frame();
		m_entryMainHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			m_entryInfoVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
				m_entryNumNameHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
					m_entryNumFrame = new Gtk::Frame();
						m_entryNumLabel = new Gtk::Label();

					m_entryNameFrame = new Gtk::Frame();
						m_entryNameLabel = new Gtk::Label();

				m_entryTypesHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
					m_entryPriTypeFrame = new Gtk::Frame();
						m_entryPriTypeLabel = new Gtk::Label();

					m_entrySecTypeFrame = new Gtk::Frame();
						m_entrySecTypeLabel = new Gtk::Label();

		m_selectEntryButton = new Gtk::Button("GO");

	//	Build entry.
	m_entryMainFrame->set_border_width(10);
	m_entryMainFrame->add(*m_entryMainHBox);

	m_entryMainHBox->pack_start(*m_entryInfoVBox, Gtk::PACK_EXPAND_WIDGET, 5);
		m_entryInfoVBox->pack_start(*m_entryNumNameHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryNumNameHBox->pack_start(*m_entryNumFrame, Gtk::PACK_SHRINK, 5);
				m_entryNumFrame->add(*m_entryNumLabel);
			m_entryNumNameHBox->pack_start(*m_entryNameFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entryNameFrame->add(*m_entryNameLabel);

		m_entryInfoVBox->pack_start(*m_entryTypesHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryTypesHBox->pack_start(*m_entryPriTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entryPriTypeFrame->add(*m_entryPriTypeLabel);

			m_entryTypesHBox->pack_start(*m_entrySecTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entrySecTypeFrame->add(*m_entrySecTypeLabel);

	m_entryMainHBox->pack_start(*m_selectEntryButton, Gtk::PACK_SHRINK, 5);

	//	Signal handler.
	//m_selectEntryButton.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &EntryBox::FUNCNAME), m_entryNumLabel.get_text()));
}

//	Destructor.
CResultsEntry::~CResultsEntry() {
	delete m_selectEntryButton;
	delete m_entrySecTypeLabel;
	delete m_entrySecTypeFrame;
	delete m_entryPriTypeLabel;
	delete m_entryPriTypeFrame;
	delete m_entryTypesHBox;
	delete m_entryNameLabel;
	delete m_entryNameFrame;
	delete m_entryNumLabel;
	delete m_entryNumFrame;
	delete m_entryNumNameHBox;
	delete m_entryInfoVBox;
	delete m_entryMainHBox;
	delete m_entryMainFrame;
}

//	getNumber	--	Returns Pokemon number.
//	Parameters:	none.
//	Returns:	String of Pokemon number.
std::string CResultsEntry::getNumber() {
	return m_entryNumLabel->get_text();
}

//	getMainFrame	--	Returns Pokemon name.
//	Parameters:	none.
//	Returns:	String of Pokemon name.
std::string CResultsEntry::getName() {
	return m_entryNameLabel->get_text();
}

//	getMainFrame	--	Returns main frame of entry.
//	Parameters:	none.
//	Returns:	pointer to main frame.
Gtk::Frame* CResultsEntry::getMainFrame() {
	return m_entryMainFrame;
}

//	setEntryData	--	Sets data in entry boxes.
//	Parameters:
//		num		--	String of Pokemon number.
//		name	--	String of Pokemon name.
//		pritype	--	String of Pokemon primary type.
//		sectype	--	String of Pokemon secondary type.
//	Returns:	void.
void CResultsEntry::setEntryData(std::string num, std::string name, std::string pritype, std::string sectype) {
	m_entryNumLabel->set_text(num);
	m_entryNameLabel->set_text(name);
	m_entryPriTypeLabel->set_text(pritype);
	m_entrySecTypeLabel->set_text(sectype);
}