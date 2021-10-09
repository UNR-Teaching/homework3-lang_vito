bankline: bankline.o person.o event.o
	g++ bankline.o person.o event.o -o bankline

bankline.o: main.cpp pqueuearray.h queuearray.h
	g++ -c -std=c++11 main.cpp -o bankline.o

person.o: person.cpp person.h
	g++ -c -std=c++11 person.cpp

event.o: event.cpp event.h
	g++ -c -std=c++11 event.cpp

clean:
	rm *.o bankline