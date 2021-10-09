#ifndef EVENT
#define EVENT


class Event {
    int arrivalTime;
    int processTime;
    int departureTime;
    bool isArrival;

public:
    Event();
    Event(int arrivalTime, int processTime, int departureTime, bool isArrival);
    int getArrivalTime() const;
    int getProcessTime() const;
    int getDepartureTime() const;
    bool getEventType() const;

    void setArrivalTime(int newATime);
    void setProcessTime(int newPTime);
    void setDepartureTime(int newDTime);
    void setEventType(bool event);

    bool operator<=(const Event& compareEvent) const;
    bool operator>(const Event& compareEvent) const;
    bool operator<(const Event& compareEvent) const;
    bool operator==(const Event& compareEvent) const;
};

#endif