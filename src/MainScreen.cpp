//	Project:	PokedexC++.
//	MainScreen.cpp	--	Implementation of the CMainScreen class.
//	Revisions:
//	2018-10-25	--	F.R. van der Meulen	--	Created.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Include files.
#include "MainScreen.h"
#include <iostream>

//	Constructor.
//	Parameters:
//		parmGui	--	Gui containing this screen.
CMainScreen::CMainScreen(CDexGui *parmGui) : m_gui(parmGui) {
	//	Tracing.
	std::cout << "MainScreen: constructor called." << std::endl;

	//	Build child widgets.
	m_framesVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		m_resultsFrame = new Gtk::Frame("Results");
			m_scrollWindow = new Gtk::ScrolledWindow();
				m_resultsListVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_resultsEntries = new std::vector<CResultsEntry*>();

		m_specifyFrame = new Gtk::Frame("Specify");
			m_specifyHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
				m_filterOneVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_filterOneLabel = new Gtk::Label("Filter 1: ---");
					m_filterOneButton = new Gtk::Button("SELECT");
				
				m_filterTwoVBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
					m_filterTwoLabel = new Gtk::Label("Filter 2: ---");
					m_filterTwoButton = new Gtk::Button("SELECT");
				
				m_searchButton = new Gtk::Button("Search");

	//	Build screen.
	m_framesVBox->pack_start(*m_resultsFrame, Gtk::PACK_EXPAND_WIDGET, 10);
		m_resultsFrame->add(*m_scrollWindow);
			m_scrollWindow->add(*m_resultsListVBox);
				getQueryResults("SELECT * FROM pokemon;");

	m_framesVBox->pack_start(*m_specifyFrame, Gtk::PACK_SHRINK, 10);
		m_specifyFrame->add(*m_specifyHBox);
			m_specifyHBox->pack_start(*m_filterOneVBox, Gtk::PACK_EXPAND_WIDGET, 10);
				m_filterOneVBox->pack_start(*m_filterOneLabel, Gtk::PACK_SHRINK, 10);
				m_filterOneVBox->pack_start(*m_filterOneButton, Gtk::PACK_SHRINK, 10);

			m_specifyHBox->pack_start(*m_filterTwoVBox, Gtk::PACK_EXPAND_WIDGET, 10);
				m_filterTwoVBox->pack_start(*m_filterTwoLabel, Gtk::PACK_SHRINK, 10);
				m_filterTwoVBox->pack_start(*m_filterTwoButton, Gtk::PACK_SHRINK, 10);
			
			m_specifyHBox->pack_start(*m_searchButton, Gtk::PACK_EXPAND_WIDGET, 10);

	//	Configure widgets.
	m_resultsFrame->set_border_width(10);
	m_specifyFrame->set_border_width(10);

	//	Signal handlers.
	m_filterOneButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CMainScreen::swapScreen), "filterscreen1"));
	m_filterTwoButton->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &CMainScreen::swapScreen), "filterscreen2"));

	//	Make self known to Gui.
	m_gui->setMainScreen(this);
	m_gui->getNotebook()->append_page(*m_framesVBox);
}

//	Copy constructor.
//	Parameters:
//		main	--	MainScreen address.
CMainScreen::CMainScreen(const CMainScreen& other) {
	//	Tracing.
	std::cout << "CMainScreen: copy constructor called." << std::endl;

	//	Copy member pointers.
	m_framesVBox = other.m_framesVBox;
		m_resultsFrame = other.m_resultsFrame;
			m_scrollWindow = other.m_scrollWindow;
				m_resultsListVBox = other.m_resultsListVBox;
					m_resultsEntries = other.m_resultsEntries;

		m_specifyFrame = other.m_specifyFrame;
			m_specifyHBox = other.m_specifyHBox;
				m_filterOneVBox = other.m_filterOneVBox;
					m_filterOneLabel = other.m_filterOneLabel;
					m_filterOneButton = other.m_filterOneButton;

				m_filterTwoVBox = other.m_filterTwoVBox;
					m_filterTwoLabel = other.m_filterTwoLabel;
					m_filterTwoButton = other.m_filterTwoButton;

				m_searchButton = other.m_searchButton;
}

//	Assignment operator.
//	Parameters:
//		main	--	Reference to MainScreen object.
CMainScreen& CMainScreen::operator=(const CMainScreen& other) {
	//	Tracing.
	std::cout << "CMainScreen: assignment operator called." << std::endl;

	//	Swap members.
	std::swap(*m_framesVBox, *other.m_framesVBox);
	std::swap(*m_resultsFrame, *other.m_resultsFrame);
	std::swap(*m_scrollWindow, *other.m_scrollWindow);
	std::swap(*m_resultsListVBox, *other.m_resultsListVBox);
	std::swap(*m_resultsEntries, *other.m_resultsEntries);
	std::swap(*m_specifyFrame, *other.m_specifyFrame);
	std::swap(*m_specifyHBox, *other.m_specifyHBox);
	std::swap(*m_filterOneVBox, *other.m_filterOneVBox);
	std::swap(*m_filterOneLabel, *other.m_filterOneLabel);
	std::swap(*m_filterOneButton, *other.m_filterOneButton);
	std::swap(*m_filterTwoVBox, *other.m_filterTwoVBox);
	std::swap(*m_filterTwoLabel, *other.m_filterTwoLabel);
	std::swap(*m_filterTwoButton, *other.m_filterTwoButton);
	std::swap(*m_searchButton, *other.m_searchButton);

	return *this;
}

//	Destructor.
//	Parameters:	none.
CMainScreen::~CMainScreen() {
	//	Tracing.
	std::cout << "MainScreen: destructor called." << std::endl;

	m_gui->setMainScreen(NULL);

	m_resultsEntries->clear();
}

//	swapScreen	--	Tells the window to switch screens.
//	Parameters:
//		newScreen	--	String of new screen name.
//	Returns:	void.
void CMainScreen::swapScreen(std::string newScreen) {
	//	Tracing.
	std::cout << "MainScreen: swapScreen called -> newScreen=" << newScreen << "." << std::endl;

	if (newScreen == "filterscreen1") {
		m_gui->getFilterScreen()->setFilterNum(1);
		swapScreen("filterscreen");
	} else if (newScreen == "filterscreen2") {
		m_gui->getFilterScreen()->setFilterNum(2);
		swapScreen("filterscreen");
	} else {
		m_gui->swapScreen(newScreen);
	}
}

//	appendResultsEntry	--	Appends results entry to vector.
//	Parameters:
//		--	num		--	String of Pokemon number.
//		--	name	--	String of Pokemon name.
//		--	pritype	--	String of Pokemon primary type.
//		--	sectype	--	String of Pokemon secondary type.
//	Returns:	void.
void CMainScreen::appendResultsEntry(CResultsEntry* entry) {
	//	Append entry frame to vector.
	m_resultsEntries->push_back(entry);
	Gtk::Frame* entryFrame = entry->getMainFrame();
	m_resultsListVBox->pack_start(*entryFrame, Gtk::PACK_SHRINK, 5);
}

//	updateQuery	--	Updates query to include filters
//	Parameters:	none.
//	Returns:	void.
void CMainScreen::updateQuery() {
	std::cout << "MainScreen: updateQuery called." << std::endl;

	int colonPos;
	std::string filterOneGroup, filterOneName, filterTwoGroup, filterTwoName;

	//	Get first filter info.
	if (m_filterOneLabel->get_text() != "Filter 1: ---") {
		//	Retrieve filter string.
		std::string filterOne = m_filterOneLabel->get_text();
		filterOne = filterOne.substr(10);
		
		//	Split filter string.
		colonPos = filterOne.find(":");
		filterOneGroup = filterOne.substr(0, colonPos);
		filterOneName = filterOne.substr(colonPos + 1);
	}

	//	Get second filter info.
	if (m_filterTwoLabel->get_text() != "Filter 2: ---") {
		//	Retrieve filter string.
		std::string filterTwo = m_filterTwoLabel->get_text();
		filterTwo = filterTwo.substr(10);
		
		//	Split filter string.
		colonPos = filterTwo.find(":");
		filterTwoGroup = filterTwo.substr(0, colonPos);
		filterTwoName = filterTwo.substr(colonPos + 1);
	}

	//	Build new query.
	std::string newQuery = "SELECT * FROM pokemon";
	bool doubleFilter = false;

	//	Filter one check.
	if (m_filterOneLabel->get_text() != "Filter 1: ---") {
		if (filterOneGroup == "Type") {
			newQuery += " WHERE (pokemon_primary_type = '" + filterOneName + "' OR pokemon_secondary_type = '" + filterOneName + "')";
		} else if (filterOneGroup == "Generation") {
			newQuery += " WHERE (pokemon_generation = '";
			if (filterOneName == "Kanto") 
				newQuery += "1";
			else if (filterOneName == "Johto")
				newQuery += "2";
			else if (filterOneName == "Hoenn")
				newQuery += "3";
			else if (filterOneName == "Sinnoh")
				newQuery += "4";
			else if (filterOneName == "Unova")
				newQuery += "5";
			else if (filterOneName == "Kalos")
				newQuery += "6";
			else if (filterOneName == "Alola")
				newQuery += "7";
			newQuery += "')";
		} else if (filterOneGroup == "Misc") {
			if 	(filterOneName == "Legendary")
				newQuery += " WHERE (pokemon_is_legendary = true)";
			else if (filterOneName == "Dual-Type")
				newQuery += " WHERE NOT (pokemon_secondary_type = '-')";
		}
	}

	//	Check for combined filter.
	if (m_filterOneLabel->get_text() != "Filter 1: ---") {
		if (m_filterTwoLabel->get_text() != "Filter 2: ---") {
			newQuery += " AND";
			doubleFilter = true;
		}
	}

	//	Filter two check.
	if (m_filterTwoLabel->get_text() != "Filter 2: ---") {
		if (filterTwoGroup == "Type") {
			if (!doubleFilter)
				newQuery += " WHERE";
			newQuery += " (pokemon_primary_type = '" + filterTwoName + "' OR pokemon_secondary_type = '" + filterTwoName + "')";
		} else if (filterTwoGroup == "Generation") {
			if (!doubleFilter)
				newQuery += " WHERE";
			newQuery += " (pokemon_generation = '";
			if (filterTwoName == "Kanto") 
				newQuery += "1";
			else if (filterTwoName == "Johto")
				newQuery += "2";
			else if (filterTwoName == "Hoenn")
				newQuery += "3";
			else if (filterTwoName == "Sinnoh")
				newQuery += "4";
			else if (filterTwoName == "Unova")
				newQuery += "5";
			else if (filterTwoName == "Kalos")
				newQuery += "6";
			else if (filterTwoName == "Alola")
				newQuery += "7";
			newQuery += "')";
		} else if (filterTwoGroup == "Misc") {
			if 	(filterTwoName == "Legendary") {
				if (!doubleFilter)
					newQuery += " WHERE";
				newQuery += " (pokemon_is_legendary = true)";
			}
			else if (filterTwoName == "Dual-Type") {
				if (!doubleFilter)
					newQuery += " WHERE";
				newQuery += " NOT (pokemon_secondary_type = '-')";
			}
		}
	}

	//	End query.
	newQuery += ";";

	getQueryResults(newQuery);
}

//	displayResultsEntries	--	Displays vector contents on screen.
//	Parameters:	none.
//	Returns:	void.
void CMainScreen::getQueryResults(std::string newQuery) {
	//	Tracing.
	std::cout << "MainScreen: getQueryResults called -> newQuery='" << newQuery << "'." << std::endl;
	std::cout << "Current entry count: " << m_resultsEntries->size() << std::endl;

	//	Clear entries from vector and box.
	for (int i = m_resultsEntries->size()-1; i > -1; i--) {
		CResultsEntry* temp = m_resultsEntries->at(i);
		Gtk::Frame* tempFrame = temp->getMainFrame();
		m_resultsListVBox->remove(*tempFrame);
	}
	m_resultsEntries->clear();

	//	Tracing.
	std::cout << "Cleared entry vector!" << std::endl;
	std::cout << "Current entry count: " << m_resultsEntries->size() << std::endl;

	//	Update resultset
	m_queryRes = m_gui->getDex()->retrieveData(newQuery);

	while (m_queryRes->next()) {
		m_resEntry = new CResultsEntry();

		std::string _num = m_queryRes->getString("pokemon_number");
		std::string _name = m_queryRes->getString("pokemon_name");
		std::string _pritype = m_queryRes->getString("pokemon_primary_type");
		std::string _sectype = m_queryRes->getString("pokemon_secondary_type");

		m_resEntry->setEntryData(_num, _name, _pritype, _sectype);
		appendResultsEntry(m_resEntry);
	}


	std::cout << "MainScreen: getQueryResults finished with " << m_resultsEntries->size() << " entries." << std::endl;
}

//	setQuery	--	Sets query string.
//	Parameters:
//		newQuery	--	String of new query.
//	Returns:	void.
void CMainScreen::setQuery(std::string newQuery) {
	//	Tracing.
	std::cout << "MainScreen: setQuery called -> newQuery=" << newQuery << "." << std::endl;

	m_query = newQuery;
}

//	setFilter	--	Sets filter string.
//	Parameters:
//		filterNum	--	Int deciding which filter is filled.
//		filter	--	String containing filter.
//	Returns:	void.
void CMainScreen::setFilter(int filterNum, std::string filter) {
	//	Tracing.
	std::cout << "MainScreen: setFilter called -> filterNum=" << filterNum << ", filter=" << filter << "." << std::endl;

	if (filterNum == 1) {
		m_filterOneLabel->set_text("Filter 1: " + filter);
	} else if (filterNum == 2) {
		m_filterTwoLabel->set_text("Filter 2: " + filter);
	}

	updateQuery();
}