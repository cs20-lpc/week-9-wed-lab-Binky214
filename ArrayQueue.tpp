// Constructor
template <typename T>
ArrayQueue<T>::ArrayQueue(int size) {
    if (size <= 0) { // check for invalid size
        throw string("Queue size must be positive"); // throw error if invalid
    }

    maxSize = size;              // set maximum capacity
    buffer = new T[maxSize];     // allocate array for queue elements
    this->length = 0;            // initialize current number of elements

    frontIndex = 0;              // front starts at index 0
    backIndex = -1;              // back is -1 because queue is empty
}

// Returns the element at the back of the queue
template <typename T>
T ArrayQueue<T>::back() const {
    if (this->isEmpty()) { // check if queue is empty
        throw string("Queue is empty"); // error if empty
    }

    return buffer[backIndex]; // return last element
}

// Clears the queue and frees memory
template <typename T>
void ArrayQueue<T>::clear() {
    delete[] buffer;   // delete dynamically allocated array

    buffer = nullptr;  // avoid dangling pointer
    this->length = 0;  // reset number of elements
    maxSize = 0;       // reset capacity
    frontIndex = 0;    // reset front index
    backIndex = -1;    // reset back index
}

// Copies another queue into this one (deep copy)
template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;       // copy capacity
    this->length = copyObj.length;   // copy current size

    buffer = new T[maxSize];         // allocate new array

    // copy elements in correct order (handles circular indexing)
    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[(copyObj.frontIndex + i) % copyObj.maxSize];
    }

    frontIndex = 0;                  // reset front to 0 in new array
    backIndex = this->length - 1;    // set back to last valid element
}

// Removes the front element from the queue
template <typename T>
void ArrayQueue<T>::dequeue() {
    if (this->isEmpty()) { // check if queue is empty
        throw string("Cannot dequeue from empty queue"); // error if empty
    }

    // move front forward (circularly)
    frontIndex = (frontIndex + 1) % maxSize;
    this->length--; // decrease number of elements
}

// Adds an element to the back of the queue
template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) { // check if queue is full
        throw string("Queue is full"); // error if full
    }

    // move back forward (circularly)
    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem; // insert new element
    this->length++;           // increase number of elements
}

// Returns the front element without removing it
template <typename T>
T ArrayQueue<T>::front() const {
    if (this->isEmpty()) { // check if empty
        throw string("Queue is empty"); // error if empty
    }

    return buffer[frontIndex]; // return front element
}
