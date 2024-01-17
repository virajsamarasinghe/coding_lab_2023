#include<iostream>
#include<list>
#include<cstring>
#include<string>
#include<sstream>

using namespace std;

class Data_Item {
public:
    string key;
    string val;

    Data_Item() {
        key = "";
        val = "";
    }

    Data_Item(string k, string v) {
        key = k;
        val = v;
    }
};

class HashTable {
private:
    static const int size = 10;
    list<Data_Item> table[size];

public:
    int getHash(string key);
    void insert(string key, string val);
    bool isKeyExist(string key);
    void search(string value);
};

int HashTable::getHash(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + key[i];
    }
    return sum % size;
}

void HashTable::insert(string key, string val) {
    int index = getHash(key);
    Data_Item di(key, val);
    if (!isKeyExist(key)) {
        table[index].push_back(di);
        cout << "Key inserted" << endl;
    }
    else {
        cout << "Key exists" << endl;
    }
}

bool HashTable::isKeyExist(string key) {
    int index = getHash(key);
    for (const auto& item : table[index]) {
        if (item.key == key) {
            return true;
        }
    }
    return false;
}

void HashTable::search(string value) {
    for (int i = 0; i < size; i++) {
        for (const auto& item : table[i]) {
            if (item.val == value) {
               cout <<"True\n";
                return;
            }
        }
    }
    cout << "False\n";
}

int main() {
    HashTable ht;
    string n_temp;
    getline(cin, n_temp);
    int lines = stoi(n_temp); // number of insert operations

    for (int i = 0; i < lines; i++) {
        getline(cin, n_temp);
        stringstream ss(n_temp);
        string s;
        int j = 0;
        string k, v;
        while (getline(ss, s, ' ')) {
            if (j == 0) {
                k = s;
            }
            else {
                v = s;
            }
            j++;
        }
        ht.insert(k, v);
    }

    getline(cin, n_temp);
    lines = stoi(n_temp); // number of search operations

    for (int i = 0; i < lines; i++) {
        getline(cin, n_temp);
        ht.search(n_temp);
    }

    return 0;
}
