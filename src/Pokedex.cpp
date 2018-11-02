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

	//	Start gui.
	m_gui->start();

	//	Exit program.
	return 0;
}