#ifndef P_QUEUE_ARRAY
#define P_QUEUE_ARRAY

template<class ItemType>
class PQueueArray : public QueueInterface<ItemType> {
private:
    int itemCount, frontIndex, backIndex;
public:
    PQueueArray();
    PQueueArray(const PQueueArray& oldQueue);
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
    ~PQueueArray() { }
};
#include "pqueuearray.cpp"
#endif