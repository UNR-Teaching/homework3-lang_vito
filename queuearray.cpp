#ifndef QUEUE_ARRAY_CPP
#define QUEUE_ARRAY_CPP
#include "queuearray.h"

template<class ItemType>
QueueArray<ItemType>::QueueArray() : itemCount(0), frontIndex(0), backIndex(0), maxSize(DEFAULT_SIZE) { }

template<class ItemType>
QueueArray<ItemType>::QueueArray(int newSize) {
    itemCount = frontIndex = backIndex = 0;
    maxSize = newSize;
}

template<class ItemType>
QueueArray<ItemType>::QueueArray(const QueueArray& oldQueue) {
    frontIndex = oldQueue.frontIndex;
    while(!oldQueue.isEmpty()) {
        enqueue(oldQueue.peekFront());
        oldQueue.dequeue();
    }
}

template<class ItemType>
bool QueueArray<ItemType>::isEmpty() const {
    if (itemCount == 0)
        return true;
    else
        return false;
}

template<class ItemType>
bool QueueArray<ItemType>::isFull() const {
    if (itemCount == maxSize)
        return true;
    else
        return false;
}

template<class ItemType>
bool QueueArray<ItemType>::enqueue(const ItemType& newEntry) {
    if (!isFull()) {
        queue[backIndex] = newEntry;
        backIndex++;
        itemCount++;
        return true;
    }
    else {
        return false;
    }
}

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
}

template<class ItemType>
ItemType QueueArray<ItemType>::peekFront() const {
    try
    {
        if(isEmpty())
        {
            throw std::string("Invalid");
        }

        return queue[frontIndex];
    }
    catch(std::string &e)
    {
        std::cout << e << std::endl;
    }
}

template<class ItemType>
QueueArray<ItemType>::~QueueArray() {
    while(!isEmpty()) {
        dequeue();
    }
}
#endif