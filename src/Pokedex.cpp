//	Project:	PokedexC++.
//	Pokedex.cpp	--	Main class of PokedexC++.
//	Revisions:
//	2018-07-09	--	F.R. van der Meulen	--	Created.
//	2018-10-25	--	F.R. van der Meulen	--	Altered to match V2 style.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.

//	Include files.
#include "DexGui.h"
#include "MainScreen.h"
#include "FilterScreen.h"

//	Main method	--	Entry point for PokedexC++ program.
//	Parameters:	none.
//	Returns:	int.
int main() {
	//	Create dex objects.
	CDexGui *m_gui = new CDexGui();

	//	Create screens.
	CMainScreen *m_mainScreen = new CMainScreen(*m_gui);
	CFilterScreen *m_filterScreen = new CFilterScreen(*m_gui);

	//	Familiarize screens.
	m_mainScreen->updatePointers(*m_filterScreen);
	m_filterScreen->updatePointers(*m_mainScreen);

	//	Start gui.
	std::cout << "Pokedex: Starting GUI!" << std::endl;
	m_gui->start();

	//	Delete objects.
	delete m_filterScreen;
	delete m_mainScreen;
	delete m_gui;

	//	Exit program.
	std::cout << "Pokedex: Terminating program!" << std::endl;
	return 0;
}