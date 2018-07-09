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

void DexConnector::searchByNumber(std::string pokeNum){
	if(pokeNum.length() == 1){
		pokeNum = "00" + pokeNum;
	}
	else if(pokeNum.length() == 2){
		pokeNum = "0" + pokeNum;
	}

	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `number` = '" + pokeNum + "';");

	printOnce();
}

void DexConnector::searchByName(std::string pokeName){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `name` = '" + pokeName + "';");

	printOnce();
}

void DexConnector::searchByPrimaryType(std::string pokeType){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `primary_type` = '" + pokeType + "';");

	printGroup();
}

void DexConnector::searchBySecondaryType(std::string pokeType){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `secondary_type` = '" + pokeType + "';");

	printGroup();
}

void DexConnector::searchByGeneration(std::string pokeGen){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `gen_introduced` = '" + pokeGen + "';");

	printGroup();
}

void DexConnector::showHybrids(){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE NOT `secondary_type` = '-';");

	printGroup();
}

void DexConnector::showLegendaries(){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon WHERE `legendary` = '1';");

	printGroup();
}

void DexConnector::showAll(){
	statement = conn->createStatement();
	res = statement->executeQuery("SELECT * FROM pokemon;");

	printGroup();
}

void DexConnector::printOnce(){
	res->next();

	//Print values
	std::cout << "Number: " << res->getString("number") << "\t\t\t";
	std::cout << "Name: " << res->getString("name") << std::endl;
	std::cout << "Primary type: " << res->getString("primary_type") << "\t\t";
	std::cout << "Secondary type: " << res->getString("secondary_type") << std::endl;
	std::cout << "Generation introduced: " << res->getString("gen_introduced") << "\t";
	std::cout << "Legendary: ";
	if(res->getString("legendary") == "1"){
		std::cout << "YES";
	}
	else{
		std::cout << "NO";
	}
	std::cout << std::endl << std::endl;
}

void DexConnector::printGroup(){
	while(res->next()){
		//Print values
		std::cout << "Number: " << res->getString("number") << "\t\t\t";
		std::cout << "Name: " << res->getString("name") << std::endl;
		std::cout << "Primary type: " <<  res->getString("primary_type") << "\t\t";
		std::cout << "Secondary type: " << res->getString("secondary_type") << std::endl;
		std::cout << "Generation introduced: " << res->getString("gen_introduced") << "\t";
		std::cout << "Legendary: ";
		if(res->getString("legendary") == "1"){
			std::cout << "YES";
		}
		else{
			std::cout << "NO";
		}
		std::cout << std::endl << std::endl;
	}
}