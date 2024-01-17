#include<cstddef>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Node {
    public:
    int elem;
    Node* next;
    Node(int newElem) : elem(newElem), next(nullptr) {}

    Node(){
        elem = -1;
        next = NULL;

    }
};
class Singly_Linked_List{
    private:
    Node* head;
    Node* tail;
    int size;

    public:
    Singly_Linked_List(){
        head = NULL;
        tail = NULL;
        size = 0;

    }
    Node* getHead(){
        return head;
    }

    Node* hettail(){
        return tail;
    }

    void insertLast(int elem){
        Node* temp = new Node(elem);
        if(head == NULL){
            head =  temp;
            tail = temp;
            size++;

        }
        else{
            tail->next = temp;
            tail = temp;
            size++;

        }
    }
    void deleteWith(int elem){
        Node* current = head;
        Node* p = nullptr;

        while(current != nullptr){
            if(current->elem== elem){
                if(p == nullptr){
                    head = current->next;
                }
                else{
                    p->next = current->next;
                }
                Node* temp= current;
                current = current->next;
                delete temp;
                size--;

            }else{
                p=current;
                current = current->next;


            }
        }
    }
    void print(){
        Node* current = head;
        while (current != NULL){
            cout << current->elem << " ";
            current = current->next;
        }
        cout << endl;
    }


};
int main(){
    Singly_Linked_List sll;
    string n_temp;
    getline(cin, n_temp);
    stringstream ss(n_temp);
    string s;

    while (getline(ss, s,' ')){
        sll.insertLast(stoi(s));

    }
    getline(cin, n_temp);
    int del_val = stoi(n_temp);

    sll.deleteWith(del_val);
    sll.print();

}