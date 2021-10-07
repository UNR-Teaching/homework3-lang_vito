bankline: bankline.o person.o
	g++ bankline.o person.o -o bankline

bankline.o: main.cpp pqueuearray.h
	g++ -c -std=c++11 main.cpp -o bankline.o

person.o: person.cpp person.h
	g++ -c -std=c++11 person.cpp

clean:
	rm *.o bankline