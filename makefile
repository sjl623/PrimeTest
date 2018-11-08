build:main.o MRPrime.o
	g++ -o main MRPrime.o main.o -lgmp -lgmpxx -g -Wall

main.o:main.cpp MRPrime.h
	g++ main.cpp -c -g -Wall

MRPrime.o:MRPrime.cpp MRPrime.h
	g++ MRPrime.cpp -c -lgmp -lgmpxx -g -Wall

run:main
	./main

clean:
	rm *.o

