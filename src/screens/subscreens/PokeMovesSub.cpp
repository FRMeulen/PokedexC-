//	Project:	PokedexC++.
//	PokeMovesSub.cpp	--	Implementation of the CPokeMovesSub class.
//	Revisions:
//	2018-12-11	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "PokeMovesSub.h"
#include <iostream>

//	Constructor.
//	Parameters:
//		parmGui	--	pointer to GUI.
//		res		--	pointer to ResultSet containing Pokemon info.
CPokeMovesSub::CPokeMovesSub(CDexGui *parmGui, std::string num) : m_gui(parmGui), m_strPokeNum(num) {
	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	constructor called." << std::endl;

	//	Build child widgets.
	m_mainVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_moveLearnMethodsFrame = new Gtk::Frame("Learn Methods");
			m_moveLearnMethodsHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_levelUpMovesButton 	= new Gtk::Button("Level-Up");
				m_tmHmMovesButton		= new Gtk::Button("TMs");
				m_eggMovesButton		= new Gtk::Button("Egg");
				m_tutorMovesButton		= new Gtk::Button("Tutor");

		m_movesFrame = new Gtk::Frame("Moves");
			m_scrollWindow = new Gtk::ScrolledWindow();
				m_movesListVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_movesEntries = new std::vector<CMovesEntry*>();
					//	m_moveEntry is made when appending moves.

	//	Build subscreen.
	m_mainVBox->pack_start(*m_moveLearnMethodsFrame, Gtk::PACK_SHRINK, 5);
		m_moveLearnMethodsFrame->add(*m_moveLearnMethodsHBox);
			m_moveLearnMethodsHBox->pack_start(*m_levelUpMovesButton, Gtk::PACK_EXPAND_WIDGET, 0);
			m_moveLearnMethodsHBox->pack_start(*m_tmHmMovesButton, Gtk::PACK_EXPAND_WIDGET, 0);
			m_moveLearnMethodsHBox->pack_start(*m_eggMovesButton, Gtk::PACK_EXPAND_WIDGET, 0);
			m_moveLearnMethodsHBox->pack_start(*m_tutorMovesButton, Gtk::PACK_EXPAND_WIDGET, 0);

	m_mainVBox->pack_start(*m_movesFrame, Gtk::PACK_EXPAND_WIDGET, 5);
		m_movesFrame->add(*m_scrollWindow);
			m_scrollWindow->add(*m_movesListVBox);
				m_movesEntries  = new std::vector<CMovesEntry*>();
				//	Move entries are added when appending moves.

	//	Signal handlers.
	m_levelUpMovesButton->signal_clicked().connect(sigc::mem_fun(*this, &CPokeMovesSub::showLevelUpMoves));
	m_tmHmMovesButton->signal_clicked().connect(sigc::mem_fun(*this, &CPokeMovesSub::showTmHmMoves));
	m_eggMovesButton->signal_clicked().connect(sigc::mem_fun(*this, &CPokeMovesSub::showEggMoves));
	m_tutorMovesButton->signal_clicked().connect(sigc::mem_fun(*this, &CPokeMovesSub::showTutorMoves));

	//	Configure frames.
	m_moveLearnMethodsFrame->set_border_width(10);
	m_movesFrame->set_border_width(10);

	//	Configure boxes.
	m_moveLearnMethodsHBox->set_homogeneous(true);

	//	Show level-up moves by default.
	showLevelUpMoves();
}

//	Destructor.
CPokeMovesSub::~CPokeMovesSub() {
	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	destructor called." << std::endl;
}

//	appendMove	--	Appends move to list & screen.
//	Parameters:
//		entry	--	pointer to CMovesEntry.
//	Returns:	void.
void CPokeMovesSub::appendMove(CMovesEntry* entry) {
	//	Append entry to vector.
	m_movesEntries->push_back(entry);

	//	Pack entry frame in box.
	Gtk::Frame* tempFrame = entry->getMainFrame();
	m_movesListVBox->pack_start(*tempFrame, Gtk::PACK_SHRINK, 0);
}

//	showLevelUpMoves	--	Shows all moves learned by leveling up.
//	Parameters:	none.
//	Returns:	void.
void CPokeMovesSub::showLevelUpMoves() {
	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	showLevelUpMoves called." << std::endl;

	//	Formulate query.
	std::string moveQuery = "";
	moveQuery += "SELECT m.*, pm.learn_method, pm.method_extra_data ";
	moveQuery += "FROM moves AS m ";
	moveQuery += "INNER JOIN pokemon_moves AS pm ";
	moveQuery += "ON m.move_name = pm.move_name ";
	moveQuery += "WHERE pm.pokemon_number = '" + m_strPokeNum + "' ";
	moveQuery += "AND pm.learn_method = 'Level' ";
	moveQuery += "ORDER BY pm.method_extra_data;";

	//	Retrieve data with query.
	getQueryResults(moveQuery);
}

//	showTmHmMoves	--	Shows all moves learned by TMs or HMs.
//	Parameters:	none.
//	Returns:	void.
void CPokeMovesSub::showTmHmMoves() {
	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	showTmHmMoves called." << std::endl;

	//	Formulate query.
	std::string moveQuery = "";
	moveQuery += "SELECT m.*, pm.learn_method, pm.method_extra_data ";
	moveQuery += "FROM moves AS m ";
	moveQuery += "INNER JOIN pokemon_moves AS pm ";
	moveQuery += "ON m.move_name = pm.move_name ";
	moveQuery += "WHERE pm.pokemon_number = '" + m_strPokeNum + "' ";
	moveQuery += "AND pm.learn_method = 'TM' ";
	moveQuery += "ORDER BY pm.method_extra_data;";

	//	Retrieve data with query.
	getQueryResults(moveQuery);
}

//	showEggMoves	--	Shows all moves learned by egg breeding.
//	Parameters:	none.
//	Returns;	void.
void CPokeMovesSub::showEggMoves() {
	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	showEggMoves called." << std::endl;

	//	Formulate query.
	std::string moveQuery = "";
	moveQuery += "SELECT m.*, pm.learn_method, pm.method_extra_data ";
	moveQuery += "FROM moves AS m ";
	moveQuery += "INNER JOIN pokemon_moves AS pm ";
	moveQuery += "ON m.move_name = pm.move_name ";
	moveQuery += "WHERE pm.pokemon_number = '" + m_strPokeNum + "' ";
	moveQuery += "AND pm.learn_method = 'Egg' ";
	moveQuery += "ORDER BY pm.method_extra_data;";

	//	Retrieve data with query.
	getQueryResults(moveQuery);
}

//	showTutorMoves	--	Shows all moves learned from the tutor.
//	Parameters:	none.
//	Returns:	void.
void CPokeMovesSub::showTutorMoves() {
	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	showTutorMoves called." << std::endl;

	//	Formulate query.
	std::string moveQuery = "";
	moveQuery += "SELECT m.*, pm.learn_method, pm.method_extra_data ";
	moveQuery += "FROM moves AS m ";
	moveQuery += "INNER JOIN pokemon_moves AS pm ";
	moveQuery += "ON m.move_name = pm.move_name ";
	moveQuery += "WHERE pm.pokemon_number = '" + m_strPokeNum + "' ";
	moveQuery += "AND pm.learn_method = 'Tutor' ";
	moveQuery += "ORDER BY pm.method_extra_data;";

	//	Retrieve data with query.
	getQueryResults(moveQuery);
}

//	getMainBox	--	Returns pointer to main box.
//	Parameters:	none.
//	Returns:	pointer to main box.
Gtk::Box* CPokeMovesSub::getMainBox() {
	return m_mainVBox;
}

//	getQueryResults	--	Executes new query on database.
//	Parameters:
//		newQuery	--	String of new query.
//	Returns:	void.
void CPokeMovesSub::getQueryResults(std::string newQuery) {
	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	getQueryResults called -> " << newQuery << "." << std::endl;

	//	Clear entries from vector and box.
	for (int i = m_movesEntries->size()-1; i > -1; i--) {
		CMovesEntry* temp = m_movesEntries->at(i);
		Gtk::Frame* tempFrame = temp->getMainFrame();
		m_movesListVBox->remove(*tempFrame);
	}
	m_movesEntries->clear();

	//	Retrieve data.
	sql::ResultSet* pokeMoves = m_gui->getDex()->retrieveData(newQuery);

	//	Process entries.
	while (pokeMoves->next()) {
		//	Get move data.
		std::string strMoveName			= pokeMoves->getString("move_name");
		std::string strMovePower		= pokeMoves->getString("move_power");
		std::string strMoveAccuracy		= pokeMoves->getString("move_accuracy");
		std::string strMovePP			= pokeMoves->getString("move_pp");
		std::string strMoveType			= pokeMoves->getString("move_type");
		std::string strMoveCategory		= pokeMoves->getString("move_category");
		std::string strMoveLearnMethod	= pokeMoves->getString("learn_method");
		
		if ((strMoveLearnMethod == "Level") | (strMoveLearnMethod == "TM")) {
			//	Concatenate move learn condition.
			std::string strMoveLearnData = pokeMoves->getString("method_extra_data");
			strMoveLearnMethod = strMoveLearnMethod + " " + strMoveLearnData;
		}

		//	Append move entry.
		m_moveEntry = new CMovesEntry(strMoveLearnMethod, strMoveName, strMovePower, strMoveAccuracy, strMovePP, strMoveType, strMoveCategory);
		appendMove(m_moveEntry);

		//	Update GUI.
		m_gui->getWindow()->show_all_children();
	}

	//	Tracing.
	std::cout << "[POKEMOVESSUB]	--	getQueryResults finished with " << m_movesEntries->size() << " entries." << std::endl;
}