#include<iostream>
#include<string>
using namespace std;

class Queue_Array {
public:
    int size;
    int capacity;
    int front; // position of the beginning of the queue
    int rear;  // position of the ending of the queue
    int* data;

    Queue_Array(int cap) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
        front = 0;
        rear = 0;
    }

    void enQueue(int val) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
        }
        else {
            data[rear] = val; // insert value at the rear
            rear = (rear + 1) % capacity; // increment rear and start from 0 if it reaches cap
            size++;
        }
    }

    int Dequeue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return INT_MIN; // return lowest integer to indicate invalid operation
        }
        else {
            int temp = data[front]; // take the value front of the queue
            front = (front + 1) % capacity; // increment front and reset to 0 if it reaches cap
            size--;
            return temp;
        }
    }

    void display() {
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << data[index] << endl;
            index = (index + 1) % capacity;
        }
        cout << endl;
    }

    int search(int i) {
        if ((i < front) || (i >= rear) || (size == 0)) {
            cout << "Index out of range or Queue is empty" << endl;
            return -1; // Return a special value to indicate an error
        }
        else {
            cout << data[i] << endl;
            return data[i];
        }
    }
};

int main() {
    cout << "Enter capacity: ";
    int x, y, z;
    cin >> x;
    Queue_Array myQueue_Array(x);
    for (int i = 0; i < x; i++) {
        cout << "Enter the values: ";
        cin >> y;
        myQueue_Array.enQueue(y);
    }
    myQueue_Array.display();
    myQueue_Array.Dequeue();
    myQueue_Array.display();
    cout << "Enter the position: ";
    cin >> z;
    myQueue_Array.search(z);
    myQueue_Array.display();

    return 0;
}
