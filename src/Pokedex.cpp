//	Project:	PokedexC++.
//	Pokedex.cpp	--	Main class of PokedexC++.
//	Revisions:
//	2018-07-09	--	F.R. van der Meulen	--	Created.
//	2018-10-25	--	F.R. van der Meulen	--	Altered to match V2 style.
//	2018-11-02	--	F.R. van der Meulen	--	Program architecture overhaul.
//	2018-12-04	--	F.R. van der Meulen --	Fixed copying DexGui instead of referencing it.

//	Include files.
#include "DexGui.h"
#include "screens/MainScreen.h"
#include "screens/FilterScreen.h"

//	Main method	--	Entry point for PokedexC++ program.
//	Parameters:	none.
//	Returns:	int.
int main() {
	//	Create dex objects.
	CDexGui *m_gui = new CDexGui();

	//	Create screens.
	CMainScreen *m_mainScreen = new CMainScreen(m_gui);
	CFilterScreen *m_filterScreen = new CFilterScreen(m_gui);

	//	Start gui.
	std::cout << "[POKEDEX]	--	Starting GUI!" << std::endl;
	m_gui->start();

	//	Delete objects.
	delete m_filterScreen;
	delete m_mainScreen;
	delete m_gui;

	//	Exit program.
	std::cout << "[POKEDEX]	--	Terminating program!" << std::endl;
	return 0;
}