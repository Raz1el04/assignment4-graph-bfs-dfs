#include <iostream>
#include <vector>

using namespace std;

bool hasCycleDFS(int u, int parent,
                 const vector<vector<int>>& adj,
                 vector<bool>& visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycleDFS(v, u, adj, visited)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    const int N = 4;
    vector<vector<int>> adj(N);

    // Undirected graph with a cycle
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {2, 0};

    vector<bool> visited(N, false);

    if (hasCycleDFS(0, -1, adj, visited)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}