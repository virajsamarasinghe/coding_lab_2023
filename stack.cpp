#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* data;
    int capacity;

public:
    Stack(int k) {
        capacity = k;
        data = new int[capacity];
        top = 0;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int val) {
        if (top >= capacity) {
            cout << "Stack is full" << endl;
        } else {
            data[top] = val;
            top++;
        }
    }

    int pop() {
        if (top == 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        } else {
            top--;
            return data[top];
        }
    }

    void traverse() {
        if (top > 0) {
            cout << "stack elements are: ";
            for (int i = 0; i < top; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    void display() const {
        if (top == 0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack Elements: ";
            for (int i = 0; i < top; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }

   
};

int main() {
    cout <<"Enter capacity: ";
    int x,y;
    cin>>x;
    // Example usage of the Stack class
    Stack myStack(x); // Create a stack with a capacity of 5

    // Push elements onto the stack
    
    for(int i =0;i<x;i++){
        cout << "Enter the Element: ";
        cin >> y;
        myStack.push(y);
    }
    
    // Display the stack elements
    myStack.display();

    // Pop elements from the stack
    cout << "Popped Element: " << myStack.pop() << endl;

    // Display the modified stack elements
    myStack.display();

    // Traverse the stack
    myStack.traverse();

    return 0;
}
