OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./main.out

testrun: test
	./T1.out
	./T2.out
	./T3.out
	./T6.out
	./T7.out

$(PROGRAM): IntegerArrayQueue.cpp
	g++ $(OPTIONS) IntegerArrayQueue.cpp -o main.out


test: IntegerArrayQueue.cpp
	g++ $(OPTIONS) IntegerArrayQueue.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) IntegerArrayQueue.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) IntegerArrayQueue.cpp T3.cpp -o T3.out
	g++ $(OPTIONS) IntegerArrayQueue.cpp T6.cpp -o T6.out
	g++ $(OPTIONS) IntegerArrayQueue.cpp T6.cpp -o T7.out

testclean:
	del -f T1.out
	del -f T2.out
	del -f T3.out
	del -f T6.out
	del -f T7.out

clean:
	del -f main.out

