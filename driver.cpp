#include <iostream>
#include "ArrayQueue.hpp"
using namespace std;

int main() {
    try {
        cout << "=== Testing Integer Queue ===" << endl;
        ArrayQueue<int> q(5);

        // Enqueue
        for (int i = 1; i <= 5; i++) {
            q.enqueue(i * 10);
            cout << "Enqueued: " << i * 10 << endl;
        }

        // Try overflow
        try {
            q.enqueue(60);
        } catch (string e) {
            cout << "Expected error: " << e << endl;
        }

        // Front & Back
        cout << "Front: " << q.front() << endl;
        cout << "Back: " << q.back() << endl;

        cout << endl;

        // Dequeue
        cout << "Dequeuing..." << endl;
        while (!q.isEmpty()) {
            cout << "Removed: " << q.front() << endl;
            q.dequeue();
        }

        // Try dequeue on empty
        try {
            q.dequeue();
        } catch (string e) {
            cout << "Expected error: " << e << endl;
        }

        cout << endl;

        // Circular behavior test
        cout << "=== Circular Behavior Test ===" << endl;
        for (int i = 1; i <= 3; i++) q.enqueue(i);
        q.dequeue();
        q.dequeue();
        q.enqueue(4);
        q.enqueue(5);
        q.enqueue(6);

        while (!q.isEmpty()) {
            cout << q.front() << " ";
            q.dequeue();
        }
        cout << endl;

        cout << endl;

        // Copy constructor
        cout << "=== Copy Constructor Test ===" << endl;
        ArrayQueue<int> q1(5);
        q1.enqueue(1);
        q1.enqueue(2);
        q1.enqueue(3);

        ArrayQueue<int> q2(q1);

        while (!q2.isEmpty()) {
            cout << q2.front() << " ";
            q2.dequeue();
        }
        cout << endl;

        cout << endl;

        // Assignment operator
        cout << "=== Assignment Operator Test ===" << endl;
        ArrayQueue<int> q3(5);
        q3 = q1;

        while (!q3.isEmpty()) {
            cout << q3.front() << " ";
            q3.dequeue();
        }
        cout << endl;

        cout << endl;

        // String queue test
        cout << "=== String Queue Test ===" << endl;
        ArrayQueue<string> qs(3);
        qs.enqueue("Hello");
        qs.enqueue("World");

        cout << qs.front() << " " << qs.back() << endl;

    } catch (string e) {
        cout << "Error: " << e << endl;
    }

    return 0;
}