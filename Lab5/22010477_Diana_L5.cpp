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

// Stack class using singly linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push a node onto the stack
    void push(const string& name) {
        Node* node = new Node(name);
        node->next = top;
        top = node;
    }

    // Pop a node from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->name << endl;
        delete temp;
    }

    // Display all elements in the stack
    void display_stack() {
        if (isEmpty()) {
            cout << "Stack is empty: NULL" << endl;
            return;
        }
        Node* curr = top;
        while (curr != nullptr) {
            cout << curr->name;
            if (curr->next != nullptr) {
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};

// Main program
int main() {
    Stack student_stack;

    student_stack.push("Ali");    // Top = Ali
    student_stack.push("Ahmed");  // Top = Ahmed
    student_stack.push("Alice");  // Top = Alice

    student_stack.display_stack();

    student_stack.pop();  // Removes Alice
    student_stack.display_stack();  // Shows Ahmed -> Ali
    student_stack.pop();  // Removes Ahmed
    student_stack.display_stack();  // Shows Ali
    student_stack.pop();  // Removes Ali
    student_stack.display_stack();  // Shows NULL

    return 0;
}
