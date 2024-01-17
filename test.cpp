#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_neighbors(vector<vector<bool>> &adj, int nV) {
    for (int i = 0; i < nV; ++i) {
        int neighborCount = count(adj[i].begin(), adj[i].end(), true);
        cout << neighborCount<< " ";
        for (int j = 0; j < nV; ++j) {
            if (adj[i][j]) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int nV, nE;
    cin >> nV >> nE;

    vector<bool> row(nV, false);
    vector<vector<bool>> adj(nV, row);

    for (int i = 0; i < nE; ++i) {
        int u, v;
        cin >> u >> v;
        u-=1;
        v-=1;
        
        // Assuming 1-based indexing, update the adjacency matrix
        adj[u][v] = true;
        adj[v][u] = true; // Assuming an undirected graph
    }

    print_neighbors(adj, nV);

    return 0;
}
