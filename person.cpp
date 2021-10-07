#ifndef PERSON_CPP
#define PERSON_CPP
#include "person.h"

Person::Person() : waitTime(0), processTime(0), arrivalTime(0) {}

Person::Person(int waitTime, int processTime, int arrivalTime) : waitTime(waitTime), processTime(processTime), arrivalTime(arrivalTime) {}

int Person::getWaitTime() const
{
    return waitTime;
}

int Person::getProcessTime() const
{
    return processTime;
}

int Person::getArrivalTime() const
{
    return arrivalTime;
}

void Person::setWaitTime(int waitTime)
{
    this->waitTime = waitTime;
}

void Person::setProcessTime(int processTime)
{
    this->processTime = processTime;
}

void Person::setArrivalTime(int arrivalTime)
{
    this->arrivalTime = arrivalTime;
}
#endif