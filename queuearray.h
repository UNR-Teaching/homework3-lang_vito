#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY
#include "queueinterface.h"

template <class ItemType>
class QueueArray<ItemType> : public QueueInterface {
    int frontIndex, backIndex, itemCount;
    const int DEFAULT_SIZE = 50;
    ItemType queue[DEFAULT_SIZE];
public:
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
    ~QueueArray() { }

};

#endif