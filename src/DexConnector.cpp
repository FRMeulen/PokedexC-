//	Project:	PokedexC++
//	DexConnector.cpp	--	Implementation of the CDexConnector class.
//	Revisions:
//	2018-07-09	--	F.R. van der Meulen	--	Created.
//	2018-10-25	--	F.R. van der Meulen	--	Altered to match V2 style.

//	Include files.
#include "DexConnector.h"

//	Constructor.
CDexConnector::CDexConnector(){
	//	Set up driver & connection.
	m_pdriver = sql::mysql::get_mysql_driver_instance();
	m_pconn = m_pdriver->connect("tcp://127.0.0.1:3306", "pokedex", "CppDex");

	//	Select database.
	m_pconn->setSchema("pokebase");
}

//	Destructor.
CDexConnector::~CDexConnector(){
	
}

//	searchByNumber	--	returns record with matching number.
//	Parameters:
//		pokeNum	--	string of number.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchByNumber(std::string pokeNum){
	//	Insert 0's to match record length.
	if(pokeNum.length() == 1){
		pokeNum = "00" + pokeNum;
	}
	else if(pokeNum.length() == 2){
		pokeNum = "0" + pokeNum;
	}

	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon WHERE `number` = '" + pokeNum + "';");

	//	Return resultset.
	return m_pres;
}

//	searchByName	--	returns record with matching name.
//	Parameters:
//		pokeName	--	string of name.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchByName(std::string pokeName){
	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon WHERE `name` = '" + pokeName + "';");

	//	Return resultset.
	return m_pres;
}

//	searchByPrimaryType	--	returns record with matching primary type.
//	Parameters:
//		pokeType	--	string of primary type.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchByPrimaryType(std::string pokeType){
	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon WHERE `primary_type` = '" + pokeType + "';");

	//	Return resultset.
	return m_pres;
}

//	searchBySecondaryTYpe	--	returns record with matching secondary type.
//	Parameters:
//		pokeType	--	string of secondary type.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchBySecondaryType(std::string pokeType){
	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon WHERE `secondary_type` = '" + pokeType + "';");

	//	Return resultset.
	return m_pres;
}

//	searchByGeneration	--	returns record with matching generation.
//	Parameters:
//		pokeGen	--	string of generation.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchByGeneration(std::string pokeGen){
	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon WHERE `gen_introduced` = '" + pokeGen + "';");

	//	Return resultset.
	return m_pres;
}

//	searchDualTypes	--	returns records of dual-types.
//	Parameters:	none.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchDualTypes(){
	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon WHERE NOT `secondary_type` = '-';");

	//	Return resultset.
	return m_pres;
}

//	searchLegendaries	--	returns records of legendaries.
//	Parameters:	none.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchLegendaries(){
	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon WHERE `legendary` = '1';");

	//	Return resultset.
	return m_pres;
}

//	searchAll	--	returns all records..
//	Parameters:	none.
//	Returns:	pointer to SQL ResultSet of executed query.
sql::ResultSet* CDexConnector::searchAll(){
	//	Execute query.
	m_pstatement = m_pconn->createStatement();
	m_pres = m_pstatement->executeQuery("SELECT * FROM pokemon;");

	//	Return resultset.
	return m_pres;
}