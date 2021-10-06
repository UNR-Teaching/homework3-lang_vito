#ifndef PERSON_H
#define PERSON_H


class Person {
    int arrivalTime;
    int processTime;

public:
    Person();
    Person(int arrival, int process);
    int getArrivalTime() const;
    int getProcessTime() const;

    void setArrivalTime(int newATime);
    void setProcessTime(int newPTime);
};
#endif