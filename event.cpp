#ifndef EVENT_CPP
#define EVENT_CPP

Event::Event() : arrivalTime(0), processTime(0), isArrival(true){}

Event::Event(int arrivalTime, int processTime, bool isArrival) : arrivalTime(arrivalTime), processTime(processTime), isArrival(isArrival){}

int Event::getArrivalTime() const{
    return arrivalTime;
}

int Event::getProcessTime() const{
    return processTime;
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

void Event::setEventType(bool event){
    isArrival = event;
}

bool Event::operator<=(const Event& compareEvent) {
    if (arrivalTime =< compareEvent.arrivalTime)
        return true;
    else
        return false;
}

bool Event::operator>(const Event& compareEvent) {
    if (arrivalTime > compareEvent.arrivalTime)
        return true;
    else
        return false;
}
#endif