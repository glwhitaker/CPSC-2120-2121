OPTIONS = -g
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./main.out

testrun: test
	./T1.out
	./T2.out
	./T3.out
	./T4.out
	./T5.out
	./T6.out

$(PROGRAM): anagram.cpp
	g++ $(OPTIONS) anagram.cpp -o main.out


test: anagram.cpp
	g++ $(OPTIONS) anagram.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) anagram.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) anagram.cpp T3.cpp -o T3.out
	g++ $(OPTIONS) anagram.cpp T4.cpp -o T4.out
	g++ $(OPTIONS) anagram.cpp T5.cpp -o T5.out
	g++ $(OPTIONS) anagram.cpp T6.cpp -o T6.out

testclean:
	@del -f T1.out
	@del -f T2.out
	@del -f T3.out
	@del -f T4.out
	@del -f T5.out
	@del -f T6.out

clean:
	@del -f main.out

