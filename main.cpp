#include "Queue.h"

using namespace std;

int main() {
    MyQueue myQueue;

    cout << "Queue size: " << myQueue.size() << endl;

    // Example usage of the queue
    cout << "Enqueuing 5" << endl;
    myQueue.enqueue(5);
    cout << "Enqueuing 10" << endl;
    myQueue.enqueue(10);
    cout << "Enqueuing 15" << endl;
    myQueue.enqueue(15);

    cout << "Front element: " << myQueue.front() << endl;
    cout << "Queue size: " << myQueue.size() << endl;

    while (!myQueue.isEmpty()) {
        cout << "Dequeued: " << myQueue.dequeue() << endl;
        cout << "Queue size: " << myQueue.size() << endl;
    }

    cout << "Front element: " << myQueue.front() << endl;

    return 0;
}
