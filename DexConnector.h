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
	sql::ResultSet* searchByNumber(std::string pokeNum);
	sql::ResultSet* searchByName(std::string pokeName);
	sql::ResultSet* searchByPrimaryType(std::string pokeType);
	sql::ResultSet* searchBySecondaryType(std::string pokeType);
	sql::ResultSet* searchByGeneration(std::string pokeGen);
	sql::ResultSet* searchDualTypes();
	sql::ResultSet* searchLegendaries();
	sql::ResultSet* searchAll();
	DexConnector();
	~DexConnector();
};