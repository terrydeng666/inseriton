insert: clock.o insertionsort.o
	g++ -o insert clock.o insertionsort.o

clock.o:clock.cpp clock.h
	g++ -c clock.cpp

insertionsort.o: insertionsort.cpp clock.h
	g++ -c insertionsort.cpp

clean:
	rm insert *.o 