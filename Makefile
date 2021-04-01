snazzy_shell: main.o functions.o
	g++ -o snazzy_shell main.o functions.o; rm *.o

functions.o: functions.cpp prototypes.h
	g++ -Wall -c functions.cpp

main.o: main.cpp prototypes.h
	g++ -Wall -c main.cpp

clean_all:
	rm *.o snazzy_shell

pushall:
	git add .
	git commit -m "$(comment)"
	git push -u origin main

pushmain:
	git add main.cpp
	git commit -m "$(comment)"
	git push -u origin main

pushfunc:
	git add functions.cpp
	git commit -m "$(comment)"
	git push -u origin main

pushproto:
	git add prototypes.cpp
	git commit -m "$(comment)"
	git push -u origin main

pushmake:
	git add Makefile
	git commit -m "$(comment)"
	git push -u origin main