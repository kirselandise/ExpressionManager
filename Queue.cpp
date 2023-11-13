#include "Queue.h"

// Inserts a new element at the rear of the queue.
void MyQueue::enqueue(int element) {
    q.push(element);
}

// Removes the front element of the queue and returns it.
int MyQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return -1; // Assuming -1 as an indicator of an empty queue
    }
    int frontElement = q.front();
    q.pop();
    return frontElement;
}

// Returns the front element present in the queue without removing it.
int MyQueue::front() {
    if (isEmpty()) {
        std::cout << "Queue is empty. No front element." << std::endl;
        return -1; // Assuming -1 as an indicator of an empty queue
    }
    return q.front();
}

// Checks if the queue is empty.
bool MyQueue::isEmpty() {
    return q.empty();
}

// Returns the total number of elements present in the queue.
int MyQueue::size() {
    return q.size();
}
