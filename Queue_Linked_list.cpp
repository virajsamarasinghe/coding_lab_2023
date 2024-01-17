#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue_LinkedList {
public:
    Node* front;
    Node* rear;

    Queue_LinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    void enQueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int Dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        else {
            int temp = front->data;
            Node* tempNode = front;
            front = front->next;
            delete tempNode;
            if (front == nullptr) {
                rear = nullptr;
            }
            return temp;
        }
    }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int search(int i) {
        Node* current = front;
        int index = 0;
        while (current != nullptr) {
            if (index == i) {
                cout << current->data << endl;
                return current->data;
            }
            current = current->next;
            index++;
        }

        cout << "Index out of range or Queue is empty" << endl;
        return -1;
    }
};

int main() {
    cout << "Enter capacity: ";
    int x, y, z;
    cin >> x;
    Queue_LinkedList myQueue_LinkedList;
    for (int i = 0; i < x; i++) {
        cout << "Enter the values: ";
        cin >> y;
        myQueue_LinkedList.enQueue(y);
    }
    myQueue_LinkedList.display();
    myQueue_LinkedList.Dequeue();
    myQueue_LinkedList.display();
    cout << "Enter the position: ";
    cin >> z;
    myQueue_LinkedList.search(z);
    myQueue_LinkedList.display();

    return 0;
}
