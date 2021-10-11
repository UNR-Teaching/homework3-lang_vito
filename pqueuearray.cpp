#ifndef P_QUEUE_ARRAY_CPP
#define P_QUEUE_ARRAY_CPP

#include <iostream>
#include "pqueuearray.h"

template <class ItemType>
PQueueArray<ItemType>::PQueueArray() : QueueArray<ItemType>() {}

template<class ItemType>
PQueueArray<ItemType>::PQueueArray(int newSize) : QueueArray<ItemType>(newSize) {}

template<class ItemType>
PQueueArray<ItemType>::PQueueArray(const PQueueArray& oldQueue) : QueueArray<ItemType>(oldQueue) {}

// template<class ItemType>
// bool PQueueArray<ItemType>::enqueue(const ItemType& newEntry) {
//     if (this->isEmpty()) {
//         this->queue[this->frontIndex] = newEntry;
//         this->backIndex++;
//         this->itemCount++;
//         return true;
//     }
//     else if (!this->isFull()) {
//         for (int i = this->frontIndex; i <= this->backIndex; i++) {
//             if (newEntry <= this->queue[i]) {
//                 for (int j = this->backIndex+1; j > i; j--) {
//                     this->queue[j] = this->queue[j-1];
//                 }
//                 this->queue[i] = newEntry;
//                 i = this->backIndex + 1;
//             }
//             else if (newEntry > this->queue[i] && i == this->backIndex) {
//                 this->queue[i] = newEntry;
//             }
//         }
//         this->backIndex++;
//         this->itemCount++;
//         return true;
//     }


//     else
//         return false;
// }

template<class ItemType>
bool PQueueArray<ItemType>::enqueue(const ItemType& newEntry) {
    using QueueArray<ItemType>::frontIndex, QueueArray<ItemType>::backIndex, 
    QueueArray<ItemType>::itemCount, QueueArray<ItemType>::maxSize;
    if (isEmpty()) {
        queue[this->frontIndex] = newEntry;
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
PQueueArray<ItemType>::~PQueueArray() {
    using QueueArray<ItemType>::isEmpty, QueueArray<ItemType>::dequeue;
    while(!isEmpty()) {
        dequeue();
    }
}
#endif