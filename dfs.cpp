#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsRecursive(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsRecursive(v, adj, visited);
        }
    }
}

int main() {
    const int N = 5;
    vector<vector<int>> adj(N);

    // Graph definition
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {};
    adj[3] = {4};

    // Recursive DFS
    vector<bool> visited(N, false);
    cout << "DFS recursive: ";
    dfsRecursive(0, adj, visited);

    // Iterative DFS
    cout << "\nDFS iterative: ";
    vector<bool> visitedIter(N, false);
    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (visitedIter[current]) continue;

        visitedIter[current] = true;
        cout << current << " ";

        for (int v : adj[current]) {
            st.push(v);
        }
    }

    return 0;
}