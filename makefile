CC=g++
usage:usage.cpp menu.o widget.o
	$(CC) -o usage usage.cpp menu.o widget.o -lmenu -lncurses
menu.o:menu.cpp widget.o
	$(CC) -c -o menu.o menu.cpp widget.o -lmenu -lncurses
widget.o:widget.cpp
	$(CC) -c -o widget.o widget.cpp -lncurses
