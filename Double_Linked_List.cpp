#include <iostream>
#include <string> // Corrected capitalization of 'String' to 'string'
using namespace std;

class Node {
public:
    int elem;
    Node* next;
    Node* prev;
    Node(int newElem) : elem(newElem), next(nullptr), prev(nullptr) {} // Added initialization for 'prev'
};

class doubly_Linked_List {
private:
    Node* head;
    Node* tail;
    int size;

public:
    doubly_Linked_List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insertFirst(int elem) {
        Node* temp = new Node(elem);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertLast(int elem) {
        Node* temp = new Node(elem);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAt(int pos, int elem) {
        if (pos < 0 || pos > size) {
            cout << "Invalid Index" << endl;
        } else if (pos == 0) {
            insertFirst(elem);
        } else if (pos == size) {
            insertLast(elem);
        } else {
            Node* temp = new Node(elem);
            Node* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            temp->next = current->next;
            temp->prev = current;
            current->next = temp;
            (temp->next)->prev = temp;
            size++;
        }
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Empty List" << endl;
        } else {
            Node* temp = head;
            if (size == 1) {
                delete temp;
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
            size--;
        }
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "Empty List" << endl;
        } else {
            Node* temp = tail;
            if (size == 1) {
                delete temp;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* current = head;
                for (int i = 0; i < size - 2; i++) {
                    current = current->next;
                }
                tail = current;
                tail->next = nullptr;
                delete temp;
            }
            size--;
        }
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid Position" << endl;
        } else if (pos == 0) {
            deleteFirst();
        } else if (pos == size - 1) {
            deleteLast();
        } else {
            Node* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            Node* temp = current;
            (current->prev)->next = temp->next;
            (current->next)->prev = temp->prev;
            delete temp;
            size--;
        }
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
    doubly_Linked_List myList;

    // Predefined values to insert into the doubly linked list
    int values[] = {1, 2, 3, 4, 5};

    // Insert each element into the doubly linked list
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        myList.insertLast(values[i]);
    }

    // Display the doubly linked list
    cout << "Doubly Linked List: ";
    myList.display();

    // Insert at a specific position
    myList.insertAt(2, 10);

    // Display the modified doubly linked list
    cout << "Doubly Linked List after insertion: ";
    myList.display();

    // Delete at a specific position
    myList.deleteAt(1);

    // Display the modified doubly linked list
    cout << "Doubly Linked List after deletion: ";
    myList.display();

    return 0;
}
