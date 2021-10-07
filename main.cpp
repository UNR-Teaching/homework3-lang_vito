#include <iostream>
#include <fstream>

#include "event.h"
#include "person.h"
#include "pqueuearray.h"
#include "pqueuearray.cpp"
#include "queuearray.h"
#include "queuearray.cpp"

bool tellerAvailable = true;
int currTime = 0;

void processArrival(Event &arrivalEvent, PQueueArray<Event> &eventList, PQueueArray<Person> &bankLine)
{
    Person customer(0, eventList.peekFront().getProcessTime(), eventList.peekFront().getArrivalTime());
    int departureTime;
    eventList.dequeue();

    if (bankLine.isEmpty() && tellerAvailable)
    {
        departureTime = currTime + arrivalEvent.getProcessTime();
        Event departureEvent(0, 0, departureTime, false);
        eventList.enqueue(departureEvent);
        tellerAvailable = false;
    }
    else
    {
        bankLine.enqueue(customer);
    }
}

void processDeparture(Event &departureEvent, PQueueArray<Event> &eventList, PQueueArray<Person> &bankLine)
{
    int departureTime;
    Person customer;
    eventList.dequeue();

    if (!bankLine.isEmpty())
    {
        customer = bankLine.peekFront();

        bankLine.dequeue();
        departureTime = currTime + customer.getProcessTime();
        Event newDepartureEvent(0, 0, departureTime, false);
        eventList.enqueue(newDepartureEvent);
    }
    else
    {
        tellerAvailable = true;
    }
}

/*
int main() {
    PQueueArray<char> testQueue;
    //QueueArray<char> testQueue;
    testQueue.enqueue('q');
    std::cout << "front of testQueue: " << testQueue.peekFront() << std::endl;
}
*/

int main()
{
    std::ifstream inputFile;
    int arrivalTime = 0, processTime = 0, nextAvailableTime = 0;
    PQueueArray<Person> bankLine;
    PQueueArray<Event> eventList;

    inputFile.open("inputfile.txt");

    while (inputFile >> arrivalTime >> processTime)
    {
        Event arrivalEvent(arrivalTime, processTime, 0, true);
        eventList.enqueue(arrivalEvent);
    }

    while (!eventList.isEmpty())
    {
        Event event = eventList.peekFront();
        currTime = event.getArrivalTime() + event.getDepartureTime();

        if (event.getEventType() == true) //if event is an arrival
        {
            processArrival(event, eventList, bankLine);
        }
        else
        {
            processDeparture(event, eventList, bankLine);
        }
    }

    return 0;
}

// if (!line.isFull() && currTime == 0) //First time the loop happens
// {
//     customer.setArrivalTime(arrivalTime);
//     customer.setProcessTime(processTime);
//     line.enqueue(customer);
//     nextAvailableTime = line.peekFront().getArrivalTime() + line.peekFront().getProcessTime();
//     std::cout << "Simulation Begins Processing an arrival event at time: " << line.peekFront().getArrivalTime() << std::endl;
// }
// if (!line.isFull() && arrivalTime < nextAvailableTime)
// {
//     customer.setArrivalTime(arrivalTime);
//     customer.setProcessTime(processTime);
//     line.enqueue(customer);
//     std::cout << "Processing an arrival event at time: " << line.peekFront().getArrivalTime();
// }
// else if (!line.isFull() && arrivalTime >= nextAvailableTime)
// {
//     while (arrivalTime >= nextAvailableTime && line.isEmpty() == false)
//     {
//         std::cout << "Processing a departure event at time: " << nextAvailableTime << std::endl;
//         line.dequeue();
//         if (line.isEmpty())
//         {
//             break;
//         }
//         else
//         {
//             nextAvailableTime += line.peekFront().getProcessTime();
//         }
//     }
//     customer.setArrivalTime(arrivalTime);
//     customer.setProcessTime(processTime);
//     line.enqueue(customer);
//     std::cout << "Processing an arrival event at time: " << line.peekFront().getArrivalTime();
// }