#include<iostream>
#include<vector>

using namespace std;


void countTriangles(vector<vector<bool>>& adj, int nV) {
    int triangleCount = 0;


    for (int i = 0; i < nV; ++i) {
        for (int j = i + 1; j < nV; ++j) {
            for (int k = j + 1; k < nV; ++k) {
                
                
                if (adj[i][j] && adj[j][k] && adj[k][i]) {
                   
                    triangleCount++;
                    
                }
            }
        }
    }

    cout << "Number of triangles: " << triangleCount << endl;
}

int main() {
    int nV, nE;
    cin >> nV >> nE;

    vector<bool> row(nV, false);
    vector<vector<bool>> adj(nV, row);

    for (int i = 0; i < nE; ++i) {
        int u, v;
        cin >> u >> v;

        // Create the adjacency matrix
        // Array index starts with 0 and Graph node index starts from 1
        u -= 1;
        v -= 1;

        adj[u][v] = true;
        adj[v][u] = true; // Assuming an undirected graph
    }

    countTriangles(adj, nV);

    return 0;
}
