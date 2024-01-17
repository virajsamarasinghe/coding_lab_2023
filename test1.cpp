#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//---------- write your code in this function--------------//
void Sum(vector<int> &arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    // Print the sum
    cout << sum << endl;
}

int main() {

    int nTestCases;
    int size;
    int val;

    cin >> nTestCases;
    for (int i = 0; i < nTestCases; i++) {
        cin >> size;
        vector<int> A;
        for (int j = 0; j < size; j++) {
            cin >> val;
            A.push_back(val);
        }

        Sum(A);
    }

    return 0;
}
