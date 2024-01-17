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

    void insertFirst(int elem) {
        Node* temp = new Node(elem);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;

        }
        size++;
    }

    void insertLast(int elem) {
        Node* temp = new Node(elem);
        if (tail == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAt(int pos, int elem) {
        cout << "Enter the position that you want to change: ";
        cin >> pos;
        cout << "Enter the value: ";
        cin >> elem;

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
            current->next = temp;
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
                delete temp;
            }
            size--;
        }
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "Empty List" << endl;
        } else {
            if (size == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
            size--;
        }
    }


    void deleteAt(int pos) {
        cout << "Enter the position to delete: ";
        cin >> pos;

        if (pos < 0 || pos >= size) {
            cout << "Invalid Position" << endl;
        } else if (pos == 0) {
            deleteFirst();
        } else if (pos == size - 1) {
            deleteLast();
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }


    void search(int elem) {
        Node* current = head;
        cout << "Position(s) of the node with element : ";
        cin>> elem;
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (current->elem == elem) {
                cout << i << " ";
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Not found";
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

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }
};

int main() {
    singly_Linked_List myList;

    // Taking input from the user
    int inputValue;
    cout << "Enter values for the linked list (enter -1 to stop):" << endl;
    while (true) {
        cout << "Enter a value: ";
        cin >> inputValue;

        if (inputValue == -1) {
            break;
        }

        // Assuming you want to insert values at the end
        myList.insertLast(inputValue);
    }

    // Inserting at a specific position
    int x, y;
    myList.insertAt(x, y);

    // Display the modified list
    cout << "List: ";
    myList.display();

    // Deleting the given position
    myList.deleteAt(x);
    cout << "List: ";
    myList.display();
    myList.search(x);

    // Deleting the last element
    myList.deleteLast();

    // Display the modified list
    cout << "List after deleting the last element: ";
    myList.display();

    // Clearing the list
    myList.clear();

    // Display the cleared list
    cout << "List after clearing: ";
    myList.display();

    return 0;
}
