#ifndef PERSON_H
#define PERSON_H


class Person {
    int arrivalTime;
    int processTime;

public:
    Person();
    Person(int, int);
    //Person(Person& copyPerson);
    int getArrivalTime();
    int getProcessTime();

    void setArrivalTime(int newATime);
    void setProcessTime(int newPTime);
};
#endif