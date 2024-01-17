#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> multiply(vector<vector<bool>> mtr1, vector<vector<bool>> mtr2, int vertices);
int getTrace(vector<vector<bool>> mtr1, int vertices);
void countTriangles(vector<vector<bool>>& adj, int nV);


// Complete the following function to calculate Triangles
// adj is a 2D vector
void countTriangles(vector<vector<bool>>& adj, int nV) {
    if(nV<=2)
    {
        cout<< 0;
        return;
    }
    vector<vector<bool>> matrix1 = multiply(adj, adj, nV);
    vector<vector<bool>> matrix2 = multiply(adj, matrix1, nV);

    cout <<  getTrace(matrix2, nV)/6;

}

int getTrace(vector<vector<bool>> mtr1, int vertices)
{
    int count = 0;
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            if(i == j & mtr1[i][j] == true)
            {
                count++;
            }
        }
    }
    return count;
}

vector<vector<bool>> multiply(vector<vector<bool>> mtr1, vector<vector<bool>> mtr2, int vertices)
{
    vector<vector<bool>> mtr3;
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            for(int k = 0; k < vertices; k++)
            {
                mtr3[i][j] = mtr3[i][j] || mtr1[i][k] && mtr2[k][j];
            }
        }
    }
    return mtr3;
}


int main() {
    int nV, nE;
    cin >> nV >> nE;
    vector<bool> row(nV, 0);
    vector<vector<bool>> adj(nV, row);

    for (int i = 0; i < nE; ++i) {
        int u, v;
        cin >> u >> v;
        // Create the adjacency matrix
        // Array index starts with 0 and Graph node index starts from 1
        u -= 1;
        v -= 1;
        adj[u][v] = true;
        adj[v][u] = true;
    }

    countTriangles(adj, nV);

    return 0;
}
