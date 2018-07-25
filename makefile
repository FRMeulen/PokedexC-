#Variable CC is the compiler to use
CC = g++

#Variable CFLAGS contains the options for the compiler
CFLAGS = -Wall -lmysqlcppconn

#Variable PKGCONFIG contains pkg-config info
PKGCONFIG = `pkg-config gtkmm-3.0 --cflags --libs`

#Command contains everything that needs to be done
PokedexC++: PokedexC++.cpp DexConnector.cpp MainScreen.cpp HelpScreen.cpp
	$(CC) $(CFLAGS) *.cpp -o PokedexC++ $(PKGCONFIG)