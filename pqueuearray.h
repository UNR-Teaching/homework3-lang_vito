#ifndef P_QUEUE_ARRAY
#define P_QUEUE_ARRAY
#include "queueinterface.h"

template<class ItemType>
class PQueueArray : public QueueInterface<ItemType> {
private:
    static const int DEFAULT_SIZE = 50;
    int itemCount, maxSize = DEFAULT_SIZE, frontIndex, backIndex;
    ItemType queue[DEFAULT_SIZE];
public:
    PQueueArray();
    PQueueArray(int newSize);
    PQueueArray(const PQueueArray& oldQueue);
    bool isEmpty() const;
    bool isFull() const;
    bool add(const ItemType& newEntry);
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
    ~PQueueArray();
};

#include "pqueuearray.cpp"
#endif