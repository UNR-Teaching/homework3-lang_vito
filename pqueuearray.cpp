#include "pqueuearray.h"

PQueueArray<ItemType>::PQueueArray(int newSize) {
    itemCount = frontIndex = backIndex = 0;
    maxSize = newSize;
}

PQueueArray<ItemType>::PQueueArray(const PQueueArray& oldQueue) {
    frontIndex = oldQueue.frontIndex;
    while (!oldQueue.isEmpty()) {
        PQueueArray.enqueue(oldQueue.peekFront());
        oldQueue.dequeue();
    }
}

bool PQueueArray<ItemType>::isEmpty() const {
    if (itemCount == 0)
        return true;
    else
        return false;
}

bool PQueueArray<ItemType>::isFull() const {
    if (itemCount == maxSize)
        return true;
    else
        return false;
}

bool PQueueArray<ItemType>::enqueue(const ItemType& newEntry) {
    if (!isFull()) {
        PQueueArray[++backIndex] = newEntry;
        itemCount++;
        return true;
    }
    else {
        return false;
    }
}
bool PQueueArray<ItemType>::dequeue() {
    if (isEmpty()) {
        return false;
    }
    else {
        // delete person at frontIndex
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
        return PQueueArray[frontIndex];
}