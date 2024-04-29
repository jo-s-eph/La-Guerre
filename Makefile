CC=g++
CPPFLAGS=-Wall -Wextra -std=c++20
CPPFILES= main
FILENAME= Projet
BIN=$(shell find . -maxdepth 1 -type f ! -name "*.*" ! -name "Makefile")

all: $(CPPFILES)

main: main.cpp pion.cpp jeu.cpp
	$(CC) -o jeu.exe $^ $(CPPFLAGS)

zip:
	mkdir $(FILENAME)
	cp *.cpp Makefile $(FILENAME)
	tar -zcvf $(FILENAME).tar.gz $(FILENAME)
	rm -rf $(FILENAME)

clean:
	rm -f $(BIN) $(FILENAME).tar.gz