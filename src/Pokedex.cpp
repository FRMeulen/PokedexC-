//	Project:	PokedexC++.
//	Pokedex.cpp	--	Main class of PokedexC++.
//	Revisions:
//	2018-07-09	--	F.R. van der Meulen	--	Created.
//	2018-10-25	--	F.R. van der Meulen	--	Altered to match V2 style.

//	Include files.
#include "DexConnector.h"
#include "DexGui.h"

//	Main method	--	Entry point for PokedexC++ program.
//	Parameters:	none.
//	Returns:	int.
int main() {
	//	Create essential objects.
	CDexGui *m_gui = new CDexGui();
	CDexConnector *m_dex = new CDexConnector();

	//	Exit program.
	return 0;
}