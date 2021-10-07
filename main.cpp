#include <iostream>
#include <fstream>

#include "event.h"
#include "person.h"
#include "pqueuearray.h"

void processArrival(Event &arrivalEvent, PQueueArray<Event> &eventList, PQueueArray<Person> &bankLine)
{
    eventList.dequeue();

    

}

void processDeparture()
{

}


int main()
{

    std::ifstream inputFile;
    int arrivalTime = 0, processTime = 0, currTime = 0, nextAvailableTime = 0;
    //Person customer;
    PQueueArray<Event> eventList;
    PQueueArray<Person> bankLine;

    inputFile.open("inputfile.txt");

    while(inputFile >> arrivalTime >> processTime)
    {
        Event arrivalEvent(arrivalTime, processTime, true);
        eventList.enqueue(arrivalEvent);
    }

    while(!eventList.isEmpty())
    {
        Event event = eventList.peekFront();
        currTime = event.getArrivalTime();

        if(event.getEventType() == true) //if event is an arrival
        {
            processArrival(event, eventList, bankLine);
        }
        else
        {
            //processDeparture();
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