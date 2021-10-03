PQueueArray::PQueueArray() {
    itemCount = frontIndex = backIndex = 0;
}

PQueueArray::PQueueArray(const PQueueArray& oldQueue) {
    frontIndex = oldQueue.frontIndex;
    while (!oldQueue.isEmpty()) {
        PQueueArray.enqueue(oldQueue.peekFront());
        oldQueue.dequeue();
    }
}

bool PQueueArray::isEmpty() const {
    if (itemCount == 0)
        return true;
    else
        return false;
}
bool PQueueArray::enqueue(const ItemType& newEntry) {
    // add conditional for space
    PQueueArray[backIndex] = newEntry;
    backIndex++;
    return true;
}
bool PQueueArray::dequeue() {
    // add error for M_T
    // delete person at frontIndex
    frontIndex++;
    return true;
}
ItemType PQueueArray::peekFront() const {
    if (isEmpty()) {
        // return null or error
    }
    else
        return PQueueArray[frontIndex];
}