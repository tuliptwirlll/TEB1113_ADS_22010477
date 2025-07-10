#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 100; // Set maximum size
    string arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue (Insert at rear)
    void enqueue(const string& name) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is full." << endl;
            return;
        }

        if (front == -1) { // Queue is empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = name;
        cout << "Enqueued: " << name << endl;
    }

    // Dequeue (Remove from front)
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display queue contents
    void display_queue() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents: ";
        int i = front;
        while (true) {
            cout << arr[i] << " -> ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Ali");    // Front = Ali
    q.enqueue("Ahmed");  // Rear = Ahmed
    q.enqueue("Alice");  // Rear = Alice

    q.display_queue();   // Ali -> Ahmed -> Alice -> NULL

    q.dequeue();         // Removes Ali
    q.display_queue();   // Ahmed -> Alice -> NULL

    q.dequeue();         // Removes Ahmed
    q.display_queue();   // Alice -> NULL

    q.dequeue();         // Removes Alice
    q.display_queue();   // Queue is empty.

    return 0;
}
