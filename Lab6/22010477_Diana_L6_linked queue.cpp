#include <iostream>
#include <string>
using namespace std;

// Node structure
class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: insert at rear
    void enqueue(const string& name) {
        Node* newNode = new Node(name);

        if (rear == nullptr) {
            // Queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Enqueued: " << name << endl;
    }

    // Dequeue: remove from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->name << endl;

        front = front->next;

        // If queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Display queue contents
    void display_queue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "list: ";
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Ahmed");
    q.enqueue("Alice");

    q.display_queue();   // Ali -> Ahmed -> Alice -> NULL

    q.dequeue();         // Removes Ali
    q.display_queue();   // Ahmed -> Alice -> NULL

    q.dequeue();         // Removes Ahmed
    q.display_queue();   // Alice -> NULL

    q.dequeue();         // Removes Alice
    q.display_queue();   // Queue is empty.

    return 0;
}
