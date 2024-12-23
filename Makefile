all: testa_velha

testa_velha: testa_velha.cpp velha.o
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs velha.o testa_velha.cpp -o testa_velha
	./testa_velha

velha.o: velha.cpp velha.hpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c velha.cpp -o velha.o

compile: testa_velha.cpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha

test: testa_velha
	./testa_velha

cpplint: testa_velha.cpp velha.cpp velha.hpp
	python3 cpplint.py --exclude=catch.hpp *.*

gcov: testa_velha.cpp velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c velha.cpp -o velha.o
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs velha.o testa_velha.cpp -o testa_velha
	./testa_velha || true
	gcov *.cpp

debug: testa_velha.cpp velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp -o velha.o
	g++ -std=c++11 -Wall -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha

cppcheck: testa_velha.cpp velha.cpp velha.hpp
	cppcheck --enable=warning .

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_velha

clean:
	rm -rf *.o *.exe *.gc* testa_velha
