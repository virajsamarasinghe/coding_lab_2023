#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>  // Added for the max function
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

    Node(int val) {
        // constructor for initializing a node
        key = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class BST {
public:
    Node* root;
    int size;

    BST() {
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

   void getLeftHeight(Node* node, int& h) {
    if (node == NULL) {
        h = 0; // Base case: height of an empty subtree is 0
    } else {
        int leftSubtreeHeight = 0;
        int rightSubtreeHeight = 0;

        getLeftHeight(node->left, leftSubtreeHeight);
        getLeftHeight(node->right, rightSubtreeHeight);

        h = max(leftSubtreeHeight, rightSubtreeHeight)+1 ;
    }
}

void getRightHeight(Node* node, int& h) {
    if (node == NULL) {
        h = 0; // Base case: height of an empty subtree is 0
    } else {
        int leftSubtreeHeight = 0;
        int rightSubtreeHeight = 0;

        getRightHeight(node->left, leftSubtreeHeight);
        getRightHeight(node->right, rightSubtreeHeight);

        h = max(leftSubtreeHeight, rightSubtreeHeight)+1 ;
    }
}

void traverse(int method) {
    int h = 0;
    if (method == 0) {
        getLeftHeight(root, h);
        cout << h << endl;
    } else {
        getRightHeight(root, h);
        cout << h << endl;
    }
}

};
int main() {
    BST tree;
    string n_temp;
    getline(cin, n_temp);
    stringstream ss(n_temp);
    string s;
    while (getline(ss, s, ' ')) {
        tree.insert(stoi(s));
    }
    getline(cin, n_temp);
    int method = stoi(n_temp);
    tree.traverse(method);

    return 0;
}
