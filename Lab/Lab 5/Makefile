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
	./T16.out
	./T17.out
	./T18.out
	./T21.out
	./T22.out
	./T23.out

$(PROGRAM): main.cpp stringset.cpp
	g++ $(OPTIONS) main.cpp stringset.cpp -o main.out


test: main.cpp stringset.cpp
	g++ $(OPTIONS) main.cpp stringset.cpp T1.cpp -o T1.out
	g++ $(OPTIONS) main.cpp stringset.cpp T2.cpp -o T2.out
	g++ $(OPTIONS) main.cpp stringset.cpp T3.cpp -o T3.out
	g++ $(OPTIONS) main.cpp stringset.cpp T4.cpp -o T4.out
	g++ $(OPTIONS) main.cpp stringset.cpp T5.cpp -o T5.out
	g++ $(OPTIONS) main.cpp stringset.cpp T6.cpp -o T6.out
	g++ $(OPTIONS) main.cpp stringset.cpp T7.cpp -o T7.out
	g++ $(OPTIONS) main.cpp stringset.cpp T8.cpp -o T8.out
	g++ $(OPTIONS) main.cpp stringset.cpp T9.cpp -o T9.out
	g++ $(OPTIONS) main.cpp stringset.cpp T16.cpp -o T16.out
	g++ $(OPTIONS) main.cpp stringset.cpp T17.cpp -o T17.out
	g++ $(OPTIONS) main.cpp stringset.cpp T18.cpp -o T18.out
	g++ $(OPTIONS) main.cpp stringset.cpp T21.cpp -o T21.out
	g++ $(OPTIONS) main.cpp stringset.cpp T22.cpp -o T22.out
	g++ $(OPTIONS) main.cpp stringset.cpp T23.cpp -o T23.out

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
	@del -f T16.out
	@del -f T17.out
	@del -f T18.out
	@del -f T21.out
	@del -f T22.out
	@del -f T23.out

clean:
	@del -f main.out

