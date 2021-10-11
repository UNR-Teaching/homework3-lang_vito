#ifndef QUEUE_ARRAY_CPP
#define QUEUE_ARRAY_CPP
#include "queuearray.h"

template<class ItemType>
QueueArray<ItemType>::QueueArray() : itemCount(0), frontIndex(0), backIndex(0), maxSize(DEFAULT_SIZE) { }

template<class ItemType>
QueueArray<ItemType>::QueueArray(int newSize) : maxSize(newSize), itemCount(0), frontIndex(0), backIndex(0) {}

template<class ItemType>
QueueArray<ItemType>::QueueArray(const QueueArray& oldQueue) {
    frontIndex = oldQueue.frontIndex;
    while(!oldQueue.isEmpty()) {
        enqueue(oldQueue.peekFront());
        oldQueue.dequeue();
    }
} // ends copy constructor

template<class ItemType>
bool QueueArray<ItemType>::isEmpty() const {
    return itemCount == 0;
} // ends isEmpty

template<class ItemType>
bool QueueArray<ItemType>::isFull() const {
    return itemCount == maxSize;
} // ends isFull

template<class ItemType>
bool QueueArray<ItemType>::enqueue(const ItemType& newEntry) {
    if (!isFull()) {
        queue[toCircIndex(backIndex)] = newEntry;
        backIndex++;
        itemCount++;
        return true;
    }
    else {
        return false;
    }
} // ends enqueue

template<class ItemType>
bool QueueArray<ItemType>::dequeue() {
    if (isEmpty()) {
        return false;
    }
    else {
        frontIndex++;
        itemCount--;
        return true;
    }
} // ends dequeue

template<class ItemType>
int QueueArray<ItemType>::toCircIndex(int index) const {
    return index % maxSize;
}

template<class ItemType>
ItemType QueueArray<ItemType>::peekFront() const {
    try
    {
        if(isEmpty())
        {
            throw std::string("Invalid");
        }

        return queue[toCircIndex(frontIndex)];
    }
    catch(std::string &e)
    {
        std::cout << e << std::endl;
    }
} // ends peekFront

template<class ItemType>
QueueArray<ItemType>::~QueueArray() {
    while(!isEmpty()) {
        dequeue();
    }
} // ends destructor

#endif