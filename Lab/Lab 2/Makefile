OPTIONS = -g -Wall
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
	./T9.out
	./T16.out
	./T17.out
	./T18.out
	./T19.out

$(PROGRAM): infixToPostfix.cpp
	g++ $(OPTIONS) infixToPostfix.cpp -o main.out


test: infixToPostfix.cpp
	g++ $(OPTIONS) infixToPostfix.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) infixToPostfix.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) infixToPostfix.cpp T3.cpp -o T3.out
	g++ $(OPTIONS) infixToPostfix.cpp T4.cpp -o T4.out
	g++ $(OPTIONS) infixToPostfix.cpp T5.cpp -o T5.out
	g++ $(OPTIONS) infixToPostfix.cpp T6.cpp -o T6.out
	g++ $(OPTIONS) infixToPostfix.cpp T9.cpp -o T9.out
	g++ $(OPTIONS) infixToPostfix.cpp T16.cpp -o T16.out
	g++ $(OPTIONS) infixToPostfix.cpp T17.cpp -o T17.out
	g++ $(OPTIONS) infixToPostfix.cpp T18.cpp -o T18.out
	g++ $(OPTIONS) infixToPostfix.cpp T19.cpp -o T19.out

testclean:
	@del -f T1.out
	@del -f T2.out
	@del -f T3.out
	@del -f T4.out
	@del -f T5.out
	@del -f T6.out
	@del -f T9.out
	@del -f T16.out
	@del -f T17.out
	@del -f T18.out
	@del -f T19.out

clean:
	@del -f main.out

