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
	./T7.out
	./T8.out
	./T9.out

$(PROGRAM): Grouping.cpp
	g++ $(OPTIONS) Grouping.cpp -o main.out


test: Grouping.cpp
	g++ $(OPTIONS) Grouping.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) Grouping.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) Grouping.cpp T3.cpp -o T3.out
	g++ $(OPTIONS) Grouping.cpp T4.cpp -o T4.out
	g++ $(OPTIONS) Grouping.cpp T5.cpp -o T5.out
	g++ $(OPTIONS) Grouping.cpp T6.cpp -o T6.out
	g++ $(OPTIONS) Grouping.cpp T7.cpp -o T7.out
	g++ $(OPTIONS) Grouping.cpp T8.cpp -o T8.out
	g++ $(OPTIONS) Grouping.cpp T9.cpp -o T9.out

testclean:
	@del -f T1.out
	@del -f T2.out
	@del -f T3.out
	@del -f T4.out
	@del -f T5.out
	@del -f T6.out
	@del -f T7.out
	@del -f T8.out
	@del -f T9.out

clean:
	@del -f main.out

