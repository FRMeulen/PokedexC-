//Pragma
#pragma once

//Inclusions
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <string>

//Class
class DexConnector{
private:
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *conn;
	sql::Statement *statement;
	sql::ResultSet *res;
public:
	void searchByNumber(std::string pokeNum);
	void searchByName(std::string pokeName);
	void searchByPrimaryType(std::string pokeType);
	void searchBySecondaryType(std::string pokeType);
	void searchByGeneration(std::string pokeGen);
	void showHybrids();
	void showLegendaries();
	void showAll();
	void printOnce();
	void printGroup();
	DexConnector();
	~DexConnector();
};