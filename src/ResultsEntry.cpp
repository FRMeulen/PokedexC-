//	Project:	PokedexC++.
//	ResultsEntry.cpp	--	Implementation of the CResultsEntry class.
//	Revisions:
//	2018-10-26	--	F.R. van der Meulen	--	Created.
//	2018-10-29	--	F.R. van der Meulen	--	Renamed, now derived from Gtk::Frame.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.
//	2018-12-05	--	F.R. van der Meulen	--	Added getter methods.

//	Include files.
#include "ResultsEntry.h"
#include <iostream>

//	Constructor.
CResultsEntry::CResultsEntry(std::string num, std::string name, std::string pritype, std::string sectype, std::string gen)
: pokeNum(num), pokeName(name), pokePriType(pritype), pokeSecType(sectype), pokeGen(gen) {
	//	Determine icon path.
	std::string pokeIconPath = "res/icons/" + pokeNum + ".png";

	//	Build child widgets.
	m_entryMainFrame = new Gtk::Frame();
		m_entryMainHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			m_entryImageFrame = new Gtk::Frame();
				m_entryImage = new Gtk::Image(pokeIconPath);

			m_entryInfoVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
				m_entryNumNameGenHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
					m_entryNumFrame = new Gtk::Frame();
						m_entryNumLabel = new Gtk::Label(pokeNum);

					m_entryNameFrame = new Gtk::Frame();
						m_entryNameLabel = new Gtk::Label(pokeName);

					m_entryGenFrame = new Gtk::Frame();
						m_entryGenLabel = new Gtk::Label(pokeGen);

				m_entryTypesHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
					m_entryPriTypeFrame = new Gtk::Frame();
						m_entryPriTypeLabel = new Gtk::Label(pokePriType);

					m_entrySecTypeFrame = new Gtk::Frame();
						m_entrySecTypeLabel = new Gtk::Label(pokeSecType);

			m_selectEntryButton = new Gtk::Button("GO");

	//	Build entry.
	m_entryMainFrame->add(*m_entryMainHBox);


	m_entryMainHBox->pack_start(*m_entryImageFrame, Gtk::PACK_SHRINK, 5);
		m_entryImageFrame->add(*m_entryImage);

	m_entryMainHBox->pack_start(*m_entryInfoVBox, Gtk::PACK_EXPAND_WIDGET, 5);
		m_entryInfoVBox->pack_start(*m_entryNumNameGenHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryNumNameGenHBox->pack_start(*m_entryNumFrame, Gtk::PACK_SHRINK, 5);
				m_entryNumFrame->add(*m_entryNumLabel);
			m_entryNumNameGenHBox->pack_start(*m_entryNameFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entryNameFrame->add(*m_entryNameLabel);
			m_entryNumNameGenHBox->pack_start(*m_entryGenFrame, Gtk::PACK_SHRINK, 5);
				m_entryGenFrame->add(*m_entryGenLabel);

		m_entryInfoVBox->pack_start(*m_entryTypesHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryTypesHBox->pack_start(*m_entryPriTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entryPriTypeFrame->add(*m_entryPriTypeLabel);

			m_entryTypesHBox->pack_start(*m_entrySecTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_entrySecTypeFrame->add(*m_entrySecTypeLabel);

	m_entryMainHBox->pack_start(*m_selectEntryButton, Gtk::PACK_SHRINK, 5);

	//	Configure frames.
	m_entryMainFrame->set_border_width(10);
	m_entryImageFrame->set_border_width(5);
}

//	Destructor.
CResultsEntry::~CResultsEntry() {
	delete m_selectEntryButton;
	delete m_entrySecTypeLabel;
	delete m_entrySecTypeFrame;
	delete m_entryPriTypeLabel;
	delete m_entryPriTypeFrame;
	delete m_entryTypesHBox;
	delete m_entryGenLabel;
	delete m_entryGenFrame;
	delete m_entryNameLabel;
	delete m_entryNameFrame;
	delete m_entryNumLabel;
	delete m_entryNumFrame;
	delete m_entryNumNameGenHBox;
	delete m_entryInfoVBox;
	delete m_entryMainHBox;
	delete m_entryImage;
	delete m_entryImageFrame;
	delete m_entryMainFrame;
}

//	getNumber	--	Returns Pokemon number.
//	Parameters:	none.
//	Returns:	String of Pokemon number.
std::string CResultsEntry::getNumber() {
	return m_entryNumLabel->get_text();
}

//	getName	--	Returns Pokemon name.
//	Parameters:	none.
//	Returns:	String of Pokemon name.
std::string CResultsEntry::getName() {
	return m_entryNameLabel->get_text();
}

//	getPriType	--	Returns Pokemon primary type.
//	Parameters:	none.
//	Returns:	String of Pokemon primary type.
std::string CResultsEntry::getPriType() {
	return m_entryPriTypeLabel->get_text();
}

//	getSecType	--	Returns Pokemon secondary type.
//	Parameters:	none.
//	Returns:	String of Pokemon secondary type.
std::string CResultsEntry::getSecType() {
	return m_entrySecTypeLabel->get_text();
}

//	getGen	--	Returns Pokemon generation.
//	Parameters:	none.
//	Returns:	String of Pokemon generation.
std::string CResultsEntry::getGen() {
	return m_entryGenLabel->get_text();
}


//	getMainFrame	--	Returns main frame of entry.
//	Parameters:	none.
//	Returns:	pointer to main frame.
Gtk::Frame* CResultsEntry::getMainFrame() {
	return m_entryMainFrame;
}

//	getButton	--	Returns button in entry.
//	Parameters:	none.
//	Returns:	pointer to button.
Gtk::Button* CResultsEntry::getButton() {
	return m_selectEntryButton;
}