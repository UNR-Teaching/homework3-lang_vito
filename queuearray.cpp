#ifndef QUEUE_ARRAY_CPP
#define QUEUE_ARRAY_CPP
#include "queuearray.h"

template<class ItemType>
QueueArray<ItemType>::QueueArray() {
    itemCount = frontIndex = backIndex = 0;
}

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
        ~queue[frontIndex];
        frontIndex++;
        itemCount--;
        return true;
    }
}

template<class ItemType>
ItemType QueueArray<ItemType>::peekFront() const {
    if (isEmpty()) {
        // return null or error
        return NULL;
    }
    else
        return queue[frontIndex];
}
#endif