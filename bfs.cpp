#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    const int N = 6;
    vector<vector<int>> adj(N);

    // Graph definition
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3, 5};
    adj[3] = {4};
    adj[4] = {5};

    vector<bool> visited(N, false);
    vector<int> distance(N, -1);
    vector<int> parent(N, -1);

    queue<int> q;
    int start = 0;

    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    cout << "BFS order: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int next : adj[current]) {
            if (!visited[next]) {
                visited[next] = true;
                distance[next] = distance[current] + 1;
                parent[next] = current;
                q.push(next);
            }
        }
    }

    int target = 5;
    cout << "\nShortest path 0 -> 5: ";

    if (!visited[target]) {
        cout << "No path";
    } else {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }

    return 0;
}