Person::Person() {
    arrivalTime = 0;
    processTime = 0;
}

int Person::getArrivalTime() {
    return arrivalTime;
}

int Person::getProcessTime() {
    return processTime;
}

void Person::setArrivalTime(int newATime) {
    arrivalTime = newATime;
}

void Person::setProcessTime(int newPTime) {
    processTime = newPTime;
}