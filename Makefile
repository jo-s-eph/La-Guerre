CC=g++
CPPFLAGS=-Wall -Wextra -std=c++20
CPPFILES= main
FILENAME= Projet
BIN= jeu.exe

all: $(CPPFILES)

main: main.cpp pion.cpp jeu.cpp joueur.cpp utils.cpp
	$(CC) -o jeu.exe $^ $(CPPFLAGS)

zip:
	mkdir $(FILENAME)
	cp *.cpp Makefile $(FILENAME)
	tar -zcvf $(FILENAME).tar.gz $(FILENAME)
	rm -rf $(FILENAME)

clean:
	rm -f $(BIN) $(FILENAME).tar.gz