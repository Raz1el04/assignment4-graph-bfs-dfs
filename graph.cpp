#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

using namespace std;

// Структура для хранения ребра с весом
struct Edge {
    int to;
    int weight;
};

class Graph {
private:
    int numVertices;
    bool isDirected;
    // Список смежности: вектор списков ребер 
    vector<list<Edge>> adjList;

public:
    // Конструктор: задаем количество вершин и тип графа 
    Graph(int n, bool directed = false) : numVertices(n), isDirected(directed) {
        adjList.resize(n);
    }

    // Добавление ребра 
    void addEdge(int u, int v, int weight = 1) {
        adjList[u].push_back({v, weight});
        if (!isDirected) {
            adjList[v].push_back({u, weight});
        }
    }

    // Удаление ребра 
    void removeEdge(int u, int v) {
        adjList[u].remove_if([v](const Edge& e) { return e.to == v; });
        if (!isDirected) {
            adjList[v].remove_if([u](const Edge& e) { return e.to == u; });
        }
    }

    // Получение соседей вершины 
    list<Edge> getNeighbors(int u) {
        return adjList[u];
    }

    // Основные запросы: количество вершин и ребер [cite: 20]
    int getV() const { return numVertices; }
    int getE() const {
        int count = 0;
        for (int i = 0; i < numVertices; i++) {
            count += adjList[i].size();
        }
        return isDirected ? count : count / 2;
    }

    // Экспорт в Adjacency Matrix 
    vector<vector<int>> getAdjacencyMatrix() {
        vector<vector<int>> matrix(numVertices, vector<int>(numVertices, 0));
        for (int u = 0; u < numVertices; u++) {
            for (const auto& edge : adjList[u]) {
                matrix[u][edge.to] = edge.weight;
            }
        }
        return matrix;
    }

    // Визуализация списка смежности
    void printAdjList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (const auto& edge : adjList[i]) {
                cout << "-> " << edge.to << "(" << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Пример: 5 вершин, неориентированный граф 
    Graph g(5, false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAdjList();

    // Демонстрация матрицы 
    vector<vector<int>> matrix = g.getAdjacencyMatrix();
    cout << "\nAdjacency Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
