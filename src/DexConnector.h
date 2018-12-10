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
	sql::mysql::MySQL_Driver *m_driver;
	
	//	MySQL object pointers.
	sql::Connection *m_conn;
	sql::Statement *m_statement;
	sql::ResultSet *m_res;
public:
	//	Constructors & destructor.
	CDexConnector();
	~CDexConnector();
	
	//	Methods.
	sql::ResultSet* retrieveData(std::string query);
};