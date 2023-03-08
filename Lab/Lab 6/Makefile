OPTIONS = -g
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./main.out

testrun: test
	./T1.out
	./T2.out
	./T6.out

$(PROGRAM): closestPair.cpp
	g++ $(OPTIONS) closestPair.cpp -o main.out


test: closestPair.cpp
	g++ $(OPTIONS) closestPair.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) closestPair.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) closestPair.cpp T6.cpp -o T6.out

testclean:
	@del -f T1.out
	@del -f T2.out
	@del -f T6.out

clean:
	@del -f main.out

oogly boogly