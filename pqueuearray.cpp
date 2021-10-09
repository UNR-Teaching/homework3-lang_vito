#ifndef P_QUEUE_ARRAY_CPP
#define P_QUEUE_ARRAY_CPP

#include <iostream>
#include "pqueuearray.h"

template <class ItemType>
PQueueArray<ItemType>::PQueueArray() : itemCount(0), maxSize(DEFAULT_SIZE), frontIndex(0), backIndex(0) { }

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
    if (isEmpty()) {
        queue[frontIndex] = newEntry;
        backIndex++;
        itemCount++;
        return true;
    }
    else if (!isFull()) {
        for (int i = frontIndex; i <= backIndex; i++) {
            if (newEntry <= queue[i]) {
                for (int j = backIndex+1; j > i; j--) {
                    queue[j] = queue[j-1];
                }
                queue[i] = newEntry;
                i = backIndex + 1;
            }
            else if (newEntry > queue[i] && i == backIndex) {
                queue[i] = newEntry;
            }
        }
        backIndex++;
        itemCount++;
        return true;
    }


    else
        return false;
}

template<class ItemType>
bool PQueueArray<ItemType>::dequeue() {
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
ItemType PQueueArray<ItemType>::peekFront() const {
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
    /*
    if (isEmpty()) {
        return '\0';
    }
    else
        return queue[frontIndex]; */
}

template<class ItemType>
PQueueArray<ItemType>::~PQueueArray() {
    while(!isEmpty()) {
        dequeue();
    }
}
#endif