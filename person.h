#ifndef PERSON_H
#define PERSON_H

class Person
{
    int waitTime;
    int processTime;
    int arrivalTime;

public:
    Person();
    Person(int waitTime, int processTime, int arrivalTime);

    int getWaitTime() const;
    int getProcessTime() const;
    int getArrivalTime() const;

    void setProcessTime(int processTime);
    void setWaitTime(int waitTime);
    void setArrivalTime(int arrivalTime);

    ~Person() { }
};

#endif