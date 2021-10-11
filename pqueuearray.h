#ifndef P_QUEUE_ARRAY
#define P_QUEUE_ARRAY
#include "queueinterface.h"
#include "queuearray.h"

template<class ItemType>
class PQueueArray : public QueueArray<ItemType> {
private:

public:
    PQueueArray();
    PQueueArray(int newSize);
    PQueueArray(const PQueueArray& oldQueue);
    bool enqueue(const ItemType& newEntry);
    ~PQueueArray();
};

#include "pqueuearray.cpp"
#endif