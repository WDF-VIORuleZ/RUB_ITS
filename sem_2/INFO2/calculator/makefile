prog: test.o calculator.o
	g++ test.o calculator.o -o ./out/calc

test.o: test.cpp
	g++ -c test.cpp

calculator.o: calculator.cpp
	g++ -c calculator.cpp

clean:
	@rm -f *.o
