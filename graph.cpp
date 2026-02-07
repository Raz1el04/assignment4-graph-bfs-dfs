#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int N = 5;   // number of vertices
    vector<vector<int>> adj(N);

    // Add edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);

    cout << "Adjacency List:\n";
    for (int u = 0; u < N; u++) {
        cout << u << ": ";
        for (int v : adj[u]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}