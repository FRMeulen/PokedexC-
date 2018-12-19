//	Project:	PokedexC++.
//	MovesEntry.cpp	--	Implementation of the CMovesEntry class.
//	Revisions:
//	2018-12-11	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "MovesEntry.h"
#include <iostream>

//	Constructor.
CMovesEntry::CMovesEntry(std::string condition, std::string name, std::string power, std::string accuracy, std::string pp, std::string type, std::string category)
: m_strMoveLearnCondition(condition), m_strMoveName(name), m_strMovePower(power), m_strMoveAccuracy(accuracy), m_strMovePP(pp), m_strMoveType(type), m_strMoveCategory(category) {

	//	Build child widgets.
	m_entryMainFrame = new Gtk::Frame();
		m_entryMainVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
			m_entryTopHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_moveLearnConditionFrame = new Gtk::Frame();
					m_moveLearnCondition = new Gtk::Label(m_strMoveLearnCondition);

				m_moveNameFrame = new Gtk::Frame();
					m_moveName = new Gtk::Label(m_strMoveName);

				m_movePowerFrame = new Gtk::Frame();
					m_movePower = new Gtk::Label("Power: " + m_strMovePower);

				m_moveAccuracyFrame = new Gtk::Frame();
					m_moveAccuracy = new Gtk::Label("Accuracy: " + m_strMoveAccuracy);

				m_movePPFrame = new Gtk::Frame();
					m_movePP = new Gtk::Label("PP: " + m_strMovePP);

			m_entryBottomHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_moveTypeFrame = new Gtk::Frame();
					m_moveType = new Gtk::Label("Type: " + m_strMoveType);

				m_moveCategoryFrame = new Gtk::Frame();
					m_moveCategory = new Gtk::Label("Category: " + m_strMoveCategory);

	//	Build entry.
	m_entryMainFrame->add(*m_entryMainVBox);
		m_entryMainVBox->pack_start(*m_entryTopHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryTopHBox->pack_start(*m_moveLearnConditionFrame, Gtk::PACK_SHRINK, 5);
				m_moveLearnConditionFrame->add(*m_moveLearnCondition);

			m_entryTopHBox->pack_start(*m_moveNameFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_moveNameFrame->add(*m_moveName);

			m_entryTopHBox->pack_start(*m_movePowerFrame, Gtk::PACK_SHRINK, 5);
				m_movePowerFrame->add(*m_movePower);

			m_entryTopHBox->pack_start(*m_moveAccuracyFrame, Gtk::PACK_SHRINK, 5);
				m_moveAccuracyFrame->add(*m_moveAccuracy);

			m_entryTopHBox->pack_start(*m_movePPFrame, Gtk::PACK_SHRINK, 5);
				m_movePPFrame->add(*m_movePP);

		m_entryMainVBox->pack_start(*m_entryBottomHBox, Gtk::PACK_EXPAND_WIDGET, 5);
			m_entryBottomHBox->pack_start(*m_moveTypeFrame, Gtk::PACK_EXPAND_WIDGET, 5);
				m_moveTypeFrame->add(*m_moveType);

			m_entryBottomHBox->pack_start(*m_moveCategoryFrame, Gtk::PACK_SHRINK, 5);
				m_moveCategoryFrame->add(*m_moveCategory);

	//	Configure frames.
	m_entryMainFrame->set_border_width(10);
}

//	Destructor.
CMovesEntry::~CMovesEntry() {

}

//	getMainFrame	--	Returns pointer to main Entry frame.
//	Parameters:	none.
//	Returns:	pointer to main frame.
Gtk::Frame* CMovesEntry::getMainFrame() {
	return m_entryMainFrame;
}