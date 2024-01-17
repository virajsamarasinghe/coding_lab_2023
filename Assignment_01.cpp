#include <iostream>
using namespace std;

class Node {
public:
    int elem;
    Node* next;

    Node(int newElem) : elem(newElem), next(nullptr) {}
};

class singly_Linked_List {
private:
    Node* head;
    Node* tail;
    int size;

public:
    singly_Linked_List() : head(nullptr), tail(nullptr), size(0) {}

    void insertLast(int elem) {
        Node* temp = new Node(elem);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void deleteWith(int elem) {
    Node* current = head;
    Node* prev = nullptr;
    cout << "Position(s) of the node with element: ";
    cin>> elem;

    while (current != nullptr) {
        if (current->elem == elem) {
            
            if (prev == nullptr) {
                // If the element to delete is in the head
                head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
            size--;
        } else {
            prev = current;
            current = current->next;
        }
    }

    cout << endl;
}


    void display() {
        Node* current = head;
        while (current) {
            cout << current->elem << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    singly_Linked_List myList;

    // Predefined values to insert into the linked list
    int values[] = {5, 4, 5, 5, 8,2,5};

    // Insert each element into the linked list
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        myList.insertLast(values[i]);
    }

    // Display the linked list
    cout << "Linked List: ";
    myList.display();

    // Delete nodes with a specific element
    int x;
    myList.deleteWith(x);

    // Display the modified linked list
    cout << "Linked List after deletion: ";
    myList.display();

    return 0;
}
