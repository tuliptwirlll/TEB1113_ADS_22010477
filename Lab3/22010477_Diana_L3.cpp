#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }

    void delete_value(const string& name) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value not found: " << name << endl;
            return;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        if (current == tail) {
            tail = previous;
        }

        delete current;
        cout << "Deleted \"" << name << "\" from the list." << endl;
    }
};

int main() {
    LinkedList std_list;

    std_list.add_item(new Node("Ali"));
    std_list.add_item(new Node("Ahmed"));
    std_list.add_item(new Node("Alice"));

    cout << "Initial list:" << endl;
    std_list.display_list();

    string nameToDelete;
    cout << "Enter the name to delete: ";
    getline(cin, nameToDelete);

    std_list.delete_value(nameToDelete);

    cout << "List after deletion:" << endl;
    std_list.display_list();

    return 0;
}

