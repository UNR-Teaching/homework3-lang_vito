#include "pqueuearray.h"

template <class ItemType>
PQueueArray<ItemType>::PQueueArray() : itemCount(0), maxSize(DEFAULT_SIZE), frontIndex(0), backIndex(0) {}

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

template <class ItemType>
bool PQueueArray<ItemType>::add(const ItemType& newEntry) {
    return enqueue(newEntry);
}

template<class ItemType>
bool PQueueArray<ItemType>::enqueue(const ItemType& newEntry) {
    if (!isFull()) {
        for (int i = 0, i < itemCount; i++) {
            if (newEntry <= queue[i]) {
                ItemType tempEntry = queue[i];
                queue[i] = newEntry;

                for (int j = i+1; j < itemCount+1; j++) {
                    queue[j] = tempEntry;
                    tempEntry = j+1;
                }

                i = itemCount;
            }
        }
        itemCount++;
    }
    else
        return false;
    
    /*
    if (!isFull()) {
        queue[++backIndex] = newEntry;
        itemCount++;
        return true;
    }
    else {
        return false;
    }
    */
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