#ifndef PERSON
#define PERSON


class Person {
    int arrivalTime;
    int processTime;

public:
    Person();
    int getArrivalTime() const;
    int getProcessTime() const;

    void setArrivalTime(int newATime);
    void setProcessTime(int newPTime);
};
#include "person.cpp"
#endif