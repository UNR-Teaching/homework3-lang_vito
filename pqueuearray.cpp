#include "pqueuearray.h"

template<class ItemType>
PQueueArray<ItemType>::PQueueArray() {
    itemCount = frontIndex = backIndex = 0;
}

template<class ItemType>
PQueueArray<ItemType>::PQueueArray(int newSize) {
    itemCount = frontIndex = backIndex = 0;
    maxSize = newSize;
}

template<class ItemType>
PQueueArray<ItemType>::PQueueArray(const PQueueArray& oldQueue) {
    frontIndex = oldQueue.frontIndex;
    while (!oldQueue.isEmpty()) {
        enqueue(oldQueue.peekFront());
        oldQueue.dequeue();
    }
}

template<class ItemType>
bool PQueueArray<ItemType>::isEmpty() const {
    if (itemCount == 0)
        return true;
    else
        return false;
}

template<class ItemType>
bool PQueueArray<ItemType>::isFull() const {
    if (itemCount == maxSize)
        return true;
    else
        return false;
}

template<class ItemType>
bool PQueueArray<ItemType>::enqueue(const ItemType& newEntry) {
    if (!isFull()) {
        queue[++backIndex] = newEntry;
        itemCount++;
        return true;
    }
    else {
        return false;
    }
}

template<class ItemType>
bool PQueueArray<ItemType>::dequeue() {
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
ItemType PQueueArray<ItemType>::peekFront() const {
    if (isEmpty()) {
        // return null or error
    }
    else
        return queue[frontIndex];
}