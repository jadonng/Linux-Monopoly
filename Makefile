FLAGS = -pedantic-errors -std=c++11

structures.o: structures.cpp structures.h
	g++ $(FLAGS) -c $<

board.o: board.cpp board.h structures.h
	g++ $(FLAGS) -c $<

action.o: action.cpp action.h structures.h
	g++ $(FLAGS) -c $<

checkstatus.o: checkstatus.cpp checkstatus.h structures.h
	g++ $(FLAGS) -c $<

wincheck.o: wincheck.cpp wincheck.h structures.h
	g++ $(FLAGS) -c $<

printBoard.o: printBoard.cpp printBoard.h
	g++ $(FLAGS) -c $<

main.o: main.cpp printBoard.h checkstatus.h wincheck.h structures.h action.h
	g++ $(FLAGS) -c $<

main: structures.o board.o action.o checkstatus.o wincheck.o printBoard.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main main.o printBoard.o wincheck.o checkstatus.o action.o structures.o

.PHONY: clean
