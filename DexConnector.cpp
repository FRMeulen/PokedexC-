//Inclusions
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>

#include <string>
#include "DexConnector.h"

//Methods
DexConnector::DexConnector(){
	driver = sql::mysql::get_mysql_driver_instance();
	conn = driver->connect("tcp://127.0.0.1:3306", "pokedex", "CppDex");

	conn->setSchema("pokebase");
}

DexConnector::~DexConnector(){
	
}

sql::ResultSet* DexConnector::searchByNumber(std::string pokeNum){
	if(pokeNum.length() == 1){
		pokeNum = "00" + pokeNum;
	}
	else if(pokeNum.length() == 2){
		pokeNum = "0" + pokeNum;
	}

	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `number` = '" + pokeNum + "';");

	return res;
}

sql::ResultSet* DexConnector::searchByName(std::string pokeName){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `name` = '" + pokeName + "';");

	return res;
}

sql::ResultSet* DexConnector::searchByPrimaryType(std::string pokeType){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `primary_type` = '" + pokeType + "';");

	return res;
}

sql::ResultSet* DexConnector::searchBySecondaryType(std::string pokeType){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `secondary_type` = '" + pokeType + "';");

	return res;
}

sql::ResultSet* DexConnector::searchByGeneration(std::string pokeGen){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `gen_introduced` = '" + pokeGen + "';");

	return res;
}

sql::ResultSet* DexConnector::searchDualTypes(){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE NOT `secondary_type` = '-';");

	return res;
}

sql::ResultSet* DexConnector::searchLegendaries(){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `legendary` = '1';");

	return res;
}

sql::ResultSet* DexConnector::searchAll(){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon;");

	return res;
}