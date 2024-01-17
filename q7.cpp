#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int>& out, vector<int>& A1, vector<int>& A2) {
    out.clear();

    out.insert(out.end(), A1.begin(), A1.end());
    out.insert(out.end(), A2.begin(), A2.end());

    sort(out.begin(), out.end());  // Sort the merged vector once
}

int main() {
    vector<int> A1;
    vector<int> A2;
    int size;

    cin >> size;

    int num;

    for (int j = 0; j < size; j++) {
        cin >> num;
        A1.push_back(num);
    }

    cin >> size;

    for (int j = 0; j < size; j++) {
        cin >> num;
        A2.push_back(num);
    }

    vector<int> out;
    merge(out, A1, A2);

    for (int element : out) {
        cout << element << " ";
    }

    return 0;
}
