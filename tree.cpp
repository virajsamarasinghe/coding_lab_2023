#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node() {
        // default constructor
        key = -1;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    Node(int k) {
        // constructor for initializing a node
        key = k;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class Binary_Tree {
public:
    Node* root;
    int size;

    Binary_Tree() {
        root = NULL;
        size = 0;
    }

    void insert(int key) {
        Node* temp = new Node(key);
        Node* current = root;
        Node* prev = NULL;

        while (current != NULL) {
            prev = current;
            if (key > current->key) {
                current = current->right;
            }
            else if (key < current->key) {
                current = current->left;
            }
            else if (key == current->key) {
                cout << "Duplicate keys are not allowed." << endl;
                return;
            }
        }

        if (prev == NULL) { // if the tree is empty
            root = temp;
        }
        else if (key > prev->key) {
            prev->right = temp;
            temp->parent = prev;
        }
        else if (key < prev->key) {
            prev->left = temp;
            temp->parent = prev;
        }
        size++;
    }

    bool search(int key) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return false;
        }
        else {
            Node* current = root;
            while (current != NULL) {
                if (key == current->key) {
                    cout << "The key exists." << endl;
                    return true;
                }
                else if (key > current->key) {
                    current = current->right;
                }
                else {
                    current = current->left;
                }
            }
            cout << "Searched key does not exist." << endl;
            return false;
        }
    }

    void display(Node* current) {
        if (current != NULL) {
            display(current->left);
            cout << current->key << " ";
            display(current->right);
        }
    }

    void display() {
        display(root);
        cout << endl;
    }

    void Delete(int key) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
        }
        else {
            Node* current = root;
            while ((current != NULL) && (current->key != key)) {
                if (key < current->key) {
                    current = current->left;
                }
                else if (key > current->key) {
                    current = current->right;
                }
            }

            if (current == NULL) {
                cout << "Searched key does not exist." << endl;
            }
            else {
                if ((current->left == NULL) && (current->right == NULL)) {
                    // Case 1: Deleting the leaf node
                    if (current == root) {
                        root = NULL;
                    }
                    else if (current->key < current->parent->key) {
                        current->parent->left = NULL;
                    }
                    else {
                        current->parent->right = NULL;
                    }
                    delete current;
                    size--;
                }
                else if (current->left == NULL) {
                    // Case 2: Node has only a right child
                    if (current == root) {
                        root = current->right;
                        root->parent = NULL;
                    }
                    else if (current->key < current->parent->key) {
                        current->parent->left = current->right;
                        current->right->parent = current->parent;
                    }
                    else {
                        current->parent->right = current->right;
                        current->right->parent = current->parent;
                    }
                    delete current;
                    size--;
                }
                else if (current->right == NULL) {
                    // Case 3: Node has only a left child
                    if (current == root) {
                        root = current->left;
                        root->parent = NULL;
                    }
                    else if (current->key < current->parent->key) {
                        current->parent->left = current->left;
                        current->left->parent = current->parent;
                    }
                    else {
                        current->parent->right = current->left;
                        current->left->parent = current->parent;
                    }
                    delete current;
                    size--;
                }
                else {
                    // Case 4: Deleting a node with 2 children
                    Node* max = current->left;
                    while (max->right != NULL) {
                        max = max->right;
                    }
                    current->key = max->key;
                    if (max == current->left) {
                        current->left = max->left;
                        if (max->left != NULL) {
                            max->left->parent = current;
                        }
                    }
                    else {
                        max->parent->right = max->left;
                        if (max->left != NULL) {
                            max->left->parent = max->parent;
                        }
                    }
                    delete max;
                    size--;
                }
            }
        }
    }
    void pre_order(Node* current){
        if(current != NULL){
            cout << current->key << " ";
            pre_order(current->left);
            pre_order(current->right); 
        }
    }
    void pre_order(){
        pre_order(root);
        cout << endl;
    }
    void in_order(Node* current){
        if(current != NULL){
            in_order(current->left);
            cout << current->key << " ";
            in_order(current->right);
            return;

        }

    }
    void in_order(){
        in_order(root);
        cout << endl;
    }
    void post_order(Node* current){
        if(current != NULL){
            post_order(current->left);
            post_order(current->right);
            cout << current->key << " ";
            return;
        }
    }
    void post_order(){
        post_order(root);
    }
};

int main() {
    Binary_Tree myTree;
    int x,y;
    bool next1 = true;
    while(next1){
        cout << "Enter Value(if you want to stop enter -1): ";
        cin >> x;
        if(x==-1){
            break;
        }
        else{
            myTree.insert(x);
        }
    }

  
    cout << "Original Tree: ";
    myTree.display();

    cout << "Pre_orders: ";

    myTree.pre_order();

    cout << "In_orders: ";
    myTree.in_order();

    cout << "Post_orders: ";
    myTree.post_order();
    

    cout<< "Enter value for deleting: ";
    cin >> y;

    myTree.Delete(y);

    cout << "Tree after deleting : ";
    myTree.display();

    return 0;
}
