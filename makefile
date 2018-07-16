#Variable CC is the compiler to use
CC = g++

#Variable CFLAGS contains the options for the compiler
CFLAGS = -Wall -lmysqlcppconn

#Variable PKGCONF configures gtkmm
PKGCONF = `pkg-config gtkmm-3.0 --cflags --libs`

#Command contains everything that needs to be done
PokedexC++: PokedexC++.cpp DexConnector.cpp
	$(CC) $(CFLAGS) *.cpp -o PokedexC++ $(PKGCONF)