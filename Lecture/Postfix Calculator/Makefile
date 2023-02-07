OPTIONS = -Wall
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
	./T12.out
	./T13.out
	./T14.out
	./T15.out

$(PROGRAM): calculatePostfixExpression.cpp
	g++ $(OPTIONS) calculatePostfixExpression.cpp -o main.out


test: calculatePostfixExpression.cpp
	g++ $(OPTIONS) calculatePostfixExpression.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T3.cpp -o T3.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T4.cpp -o T4.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T5.cpp -o T5.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T6.cpp -o T6.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T9.cpp -o T9.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T12.cpp -o T12.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T13.cpp -o T13.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T14.cpp -o T14.out
	g++ $(OPTIONS) calculatePostfixExpression.cpp T15.cpp -o T15.out


testclean:
	del -f T1.out
	del -f T2.out
	del -f T3.out
	del -f T4.out
	del -f T5.out
	del -f T6.out
	del -f T9.out
	del -f T12.out
	del -f T13.out
	del -f T14.out
	del -f T15.out


clean:
	del -f main.out

