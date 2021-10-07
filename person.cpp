#ifndef PERSON
#define PERSON
#include "person.h"

Person::Person() {
    arrivalTime = 0;
    processTime = 0;
}

Person::Person(int newArrival, int newProcess) {
    arrivalTime = newArrival;
    processTime = newProcess;
}

int Person::getArrivalTime() const {
    return arrivalTime;
}

int Person::getProcessTime() const {
    return processTime;
}

void Person::setArrivalTime(int newATime) {
    arrivalTime = newATime;
}

void Person::setProcessTime(int newPTime) {
    processTime = newPTime;
}

#endif