//	Project:	PokedexC++
//	DexConnector.cpp	--	Implementation of the CDexConnector class.
//	Revisions:
//	2018-07-09	--	F.R. van der Meulen	--	Created.
//	2018-10-25	--	F.R. van der Meulen	--	Altered to match V2 style.

//	Include files.
#include "DexConnector.h"
#include <iostream>

//	Constructor.
CDexConnector::CDexConnector(){
	//	Tracing.
	std::cout << "[DEXCONNECTOR]	--	constructor called." << std::endl;

	//	Set up driver & connection.
	m_pdriver = sql::mysql::get_mysql_driver_instance();
	m_pconn = m_pdriver->connect("tcp://127.0.0.1:3306", "pokedex", "CppDex");

	//	Select database.
	m_pconn->setSchema("pokebase");
}

//	Destructor.
CDexConnector::~CDexConnector(){
	//	Tracing.
	std::cout << "[DEXCONNECTOR]	--	destructor called." << std::endl;
}

//	searchByNumber	--	returns record with matching number.
//	Parameters:
//		pokeNum	--	string of number.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::retrieveData(std::string query){
	//	Tracing.
	std::cout << "[DEXCONNECTOR]	--	retrieveData called -> query=" << query << "." << std::endl;

	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery(query);

	//	Return resultset.
	return m_pres;
}