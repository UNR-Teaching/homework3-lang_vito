#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY
#include "queueinterface.h"

template <class ItemType>
class QueueArray : public QueueInterface<ItemType> {
    static const int DEFAULT_SIZE = 50;
    int frontIndex, backIndex, itemCount;
    ItemType queue[DEFAULT_SIZE];
public:
    QueueArray();
    QueueArray(int newSize);
    QueueArray(const QueueArray& oldQueue);
    bool isEmpty() const;
    bool isFull() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
    ~QueueArray() { }

};

#endif