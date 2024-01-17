#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

    string n_temp;
    
    // Read the size of the array
    getline(cin, n_temp);
    int size = stoi(n_temp);
    
    // Create dynamic array
    int* A = new int[size];
    
    // Read the elements of the array
    getline(cin, n_temp);
    stringstream ss(n_temp);
    string s;
    int j = 0;
    while (getline(ss, s, ' ')) {
        if (j < size)
            A[j] = stoi(s);
        j++;
    }

    // Read the position and value to add
    getline(cin, n_temp);
    int pos = stoi(n_temp);

    getline(cin, n_temp);
    int add = stoi(n_temp);
   
    if(pos>=0 && pos<=size-1){
        for(int i= pos;i<size-1;i++){
            A[i]=A[i+1];
        }
        
        A[pos]=add;
    }
    else{
        cout << "Invalid position";
    }


  



    // Print the modified array
    for (int i = 0; i < size ; i++) {
        cout << A[i] << " ";
    }

    cout << endl;

    // Deallocate the dynamic array
    delete[] A;

    return 0;
}
