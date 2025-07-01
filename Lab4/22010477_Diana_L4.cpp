#include <iostream>
#include <string>
#include <vector> 

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

public:
    LinkedList() {
        head = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = node;
            head->next = head; 
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = node;
            node->next = head;
        }
    }

    // Forward traversal (Ali -> Ahmed -> Alice -> Ali)
    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head); 
        cout << head->name << endl; 
    }

    // Reverse traversal simulation (Alice -> Ahmed -> Ali -> Alice)
    void display_list_reverse() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        vector<string> names;

        // Store names in reverse order
        Node* temp = head;

        // First, find the tail (Alice) to start collecting in reverse
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        // Collect in reverse
        temp = tail;
        do {
            names.push_back(temp->name);
            Node* prev = head;
            while (prev->next != temp) {
                prev = prev->next;
            }
            temp = prev;
        } while (temp != tail); // End when we circle back

        // Print in reverse + make it circular
        for (size_t i = 0; i < names.size(); ++i) {
            cout << names[i];
            if (i < names.size() - 1) {
                cout << " -> ";
            } else {
                cout << " -> " << names[0] << endl; // Complete circularity
            }
        }
    }
};

int main() {
    LinkedList std_list;

    std_list.add_item(new Node("Ali"));    
    std_list.add_item(new Node("Ahmed"));  
    std_list.add_item(new Node("Alice"));
    std_list.add_item(new Node("Ana"));    
    std_list.add_item(new Node("Abu"));  
    std_list.add_item(new Node("Amar"));  

    //cout << "Original List: ";
    std_list.display_list(); // Ali -> Ahmed -> Alice -> Ana -> Abu -> Amar-> Ali

    //cout << "Reversed List: ";
    std_list.display_list_reverse(); // Amar -> Abu -> Ana -> Alice -> Ahmed -> Amar

    return 0;
}
