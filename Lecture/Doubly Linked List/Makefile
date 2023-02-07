OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./main.out

testrun: test
	./T1.out
	./T2.out
	./T4.out
	./T6.out

$(PROGRAM): doublyLinkedSwap.cpp
	g++ $(OPTIONS) doublyLinkedSwap.cpp -o main.out


test: doublyLinkedSwap.cpp
	g++ $(OPTIONS) doublyLinkedSwap.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) doublyLinkedSwap.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) doublyLinkedSwap.cpp T4.cpp -o T4.out
	g++ $(OPTIONS) doublyLinkedSwap.cpp T6.cpp -o T6.out

testclean:
	del -f T1.out
	del -f T2.out
	del -f T4.out
	del -f T6.out

clean:
	del -f main.out

