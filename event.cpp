#ifndef EVENT_CPP
#define EVENT_CPP

#include <iostream>
#include "event.h"

Event::Event() : arrivalTime(0), processTime(0), departureTime(0), isArrival(true){}

Event::Event(int arrivalTime, int processTime, int departureTime, bool isArrival) : arrivalTime(arrivalTime), processTime(processTime), departureTime(departureTime), isArrival(isArrival){}

int Event::getArrivalTime() const{
    return arrivalTime;
}

int Event::getProcessTime() const{
    return processTime;
}

int Event::getDepartureTime() const{
    return departureTime;
}

bool Event::getEventType() const{
    return isArrival; //isArrival = 0 means its a departure
}

void Event::setArrivalTime(int newATime) {
    arrivalTime = newATime;
}

void Event::setProcessTime(int newPTime) {
    processTime = newPTime;
}

void Event::setDepartureTime(int newDTime){
    departureTime = newDTime;
}

void Event::setEventType(bool event){
    isArrival = event;
}

bool Event::operator==(const Event& compareEvent) const {
    return arrivalTime == compareEvent.arrivalTime;
}

bool Event::operator<(const Event& compareEvent) const {
    return arrivalTime < compareEvent.arrivalTime;
}

bool Event::operator<=(const Event& compareEvent) const {
    if (isArrival == 0)
        return departureTime <= compareEvent.arrivalTime;
    else
        return arrivalTime <= compareEvent.arrivalTime;
}

bool Event::operator>(const Event& compareEvent) const {
    return arrivalTime > compareEvent.arrivalTime;
}
#endif