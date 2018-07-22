#Variable CC is the compiler to use
CC = g++

#Variable CFLAGS contains the options for the compiler
CFLAGS = -Wall -lmysqlcppconn

#Command contains everything that needs to be done
PokedexC++: PokedexC++.cpp DexConnector.cpp
	$(CC) $(CFLAGS) *.cpp -o PokedexC++