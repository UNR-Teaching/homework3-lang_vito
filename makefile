bankline: bankline.o person.o
	g++ bankline.o person.o -o bankline

bankline.o: bankline.cpp pqueuearray.h
	g++ -c -std=c++11 bankline.cpp

person.o: person.cpp person.h
	g++ -c -std=c++11 person.cpp

clean:
	rm *.o bankline