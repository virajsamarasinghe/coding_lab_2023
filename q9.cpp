#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_neighbors(vector<vector<bool>> & adj,int nV){

}
int main(){
    int nV ,nE;
    cin>> nV >> nE;
    vector <bool> row(nV,0);
    vector<vector<bool>> adj(nV,row);
    for(int i = 0;i<nE;i++){
        int u,v;
        cin >> u >> v;
        //create the adjaceny matrix
        //Array index strat with 0 nd Graph node index start from 1


    }
    print_neighbors(adj,nV);
    return 0;
}