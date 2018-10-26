//	Project:	PokedexC++.
//	DexConnector.h	--	Interface for the CDexConnector class.
//	Revisions:
//	2018-07-09	--	F.R. van der Meulen	--	Created.
//	2018-10-25	--	F.R. van der Meulen	--	Altered to match V2 style.

//	Pragma.
#pragma once

//	Include files.
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <string>

//	Class interface.
class CDexConnector{
private:
	//	MySQL driver.
	sql::mysql::MySQL_Driver *m_pdriver;
	
	//	MySQL object pointers.
	sql::Connection *m_pconn;
	sql::Statement *m_pstatement;
	sql::ResultSet *m_pres;
public:
	//	Constructors & destructor.
	CDexConnector();
	~CDexConnector();
	
	//	Methods.
	sql::ResultSet* searchByNumber(std::string pokeNum);
	sql::ResultSet* searchByName(std::string pokeName);
	sql::ResultSet* searchByPrimaryType(std::string pokeType);
	sql::ResultSet* searchBySecondaryType(std::string pokeType);
	sql::ResultSet* searchByGeneration(std::string pokeGen);
	sql::ResultSet* searchDualTypes();
	sql::ResultSet* searchLegendaries();
	sql::ResultSet* searchAll();
};