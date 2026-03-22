template <typename T>
ArrayQueue<T>::ArrayQueue(int size) {
    if (size <= 0) {
        throw string("Queue size must be positive");
    }

    maxSize = size;
    buffer = new T[maxSize];
    this->length = 0;

    frontIndex = 0;
    backIndex = -1; // no elements yet
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (this->isEmpty()) {
        throw string("Queue is empty");
    }

    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    delete[] buffer;

    buffer = nullptr;
    this->length = 0;
    maxSize = 0;
    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;

    buffer = new T[maxSize];

    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[(copyObj.frontIndex + i) % copyObj.maxSize];
    }

    frontIndex = 0;
    backIndex = this->length - 1;
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (this->isEmpty()) {
        throw string("Cannot dequeue from empty queue");
    }

    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        throw string("Queue is full");
    }

    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (this->isEmpty()) {
        throw string("Queue is empty");
    }

    return buffer[frontIndex];
}