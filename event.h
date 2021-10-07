#ifndef EVENT
#define EVENT


class Event {
    int arrivalTime;
    int processTime;
    bool isArrival;

public:
    Event();
    Event(int arrivalTime, int processTime, bool isArrival);
    int getArrivalTime() const;
    int getProcessTime() const;
    bool getEventType() const;

    void setArrivalTime(int newATime);
    void setProcessTime(int newPTime);
    void setEventType(bool event);
};
#include "event.cpp"
#endif