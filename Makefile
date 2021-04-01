snazzy_shell: main.o functions.o
	g++ -o snazzy_shell main.o functions.o; rm *.o

functions.o: functions.cpp prototypes.h
	g++ -Wall -c functions.cpp

main.o: main.cpp prototypes.h
	g++ -Wall -c main.cpp

clean_all:
	rm *.o snazzy_shell