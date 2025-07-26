#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    map<char, vector<char>> adjList;

public:
    void addEdge(char u, char v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    void BFS(char start) {
        map<char, bool> visited;
        queue<char> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from " << start << ": ";

        while (!q.empty()) {
            char current = q.front();
            q.pop();
            cout << current << " ";

            for (char neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void printGraph() {
        cout << "V = { ";
        for (auto& pair : adjList)
            cout << pair.first << " ";
        cout << "}" << endl;

        cout << "E = { ";
        map<string, bool> printed;
        for (auto& pair : adjList) {
            for (char neighbor : pair.second) {
                string edge = string(1, min(pair.first, neighbor)) + string(1, max(pair.first, neighbor));
                if (!printed[edge]) {
                    cout << "(" << pair.first << "," << neighbor << ") ";
                    printed[edge] = true;
                }
            }
        }
        cout << "}" << endl;
    }
};

int main() {
    Graph g;

    // Add edges from the image
    g.addEdge('A', 'B');
    g.addEdge('B', 'E');
    g.addEdge('A', 'D');
    g.addEdge('A', 'C');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');
    g.addEdge('B', 'D');

    // Optional: Print the graph structure
    g.printGraph();

    // BFS traversal
    g.BFS('A');
    g.BFS('B');
    g.BFS('C');
    g.BFS('D');
    g.BFS('E');
    

    return 0;
}
