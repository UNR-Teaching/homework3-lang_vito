#include <iostream>
#include <fstream>

#include "event.h"
#include "person.h"
#include "pqueuearray.h"
#include "queuearray.h"

bool tellerAvailable = true;
int currTime = 0;
int totalWaitTime = 0, numCustomers = 0;
double avgWait = 0;

void processArrival(Event &arrivalEvent, PQueueArray<Event> &eventList, QueueArray<Person> &bankLine)
{
    Person customer(0, eventList.peekFront().getProcessTime(), eventList.peekFront().getArrivalTime());
    int departureTime;

    std::cout << "Processing an arrival event at time: " << eventList.peekFront().getArrivalTime() << std::endl;
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

void processDeparture(Event &departureEvent, PQueueArray<Event> &eventList, QueueArray<Person> &bankLine)
{
    int departureTime;
    Person customer;

    std::cout << "Processing a departure event at time: " << eventList.peekFront().getDepartureTime() << std::endl;
    eventList.dequeue();

    if (!bankLine.isEmpty())
    {
        customer = bankLine.peekFront();

        totalWaitTime += currTime - customer.getArrivalTime();

        bankLine.dequeue(); //dequeue this customer since they are now being served
        departureTime = currTime + customer.getProcessTime();
        Event newDepartureEvent(0, 0, departureTime, false);
        eventList.enqueue(newDepartureEvent);
    }
    else
    {
        tellerAvailable = true;
    }
}

int main()
{
    std::ifstream inputFile;
    int arrivalTime = 0, processTime = 0, nextAvailableTime = 0;
    QueueArray<Person> bankLine;
    PQueueArray<Event> eventList;

    inputFile.open("inputfile.txt");

    while (inputFile >> arrivalTime >> processTime)
    {
        Event arrivalEvent(arrivalTime, processTime, 0, true);
        eventList.enqueue(arrivalEvent);
        numCustomers++;
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

    avgWait = totalWaitTime / numCustomers;

    std::cout << "Average wait time: " << avgWait << std::endl;
    std::cout << "Number of customers processed: " << numCustomers << std::endl;

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