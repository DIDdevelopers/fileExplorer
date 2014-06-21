CC=g++
usage.o:usage.cpp menuWidget.o
	$(CC) -g -o usage.o usage.cpp menuWidget.o -lmenu -lncurses
menu.o:menuWidget.cpp menuWidget.cpp wid.o
	$(CC) -g -c -o menuWidget.o menuWidget.cpp widget.o -lmenu -lncurses
wid.o:wid.cpp -lncurses -lmenu
	$(CC) -g -c wid.cpp
clean:
	rm *.o
