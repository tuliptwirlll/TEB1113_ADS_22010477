#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    map<char, vector<char>> adjList;

public:
    void addEdge(char u, char v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    void DFSUtil(char current, map<char, bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        // Sort neighbors to get consistent output order
        sort(adjList[current].begin(), adjList[current].end());

        for (char neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(char start) {
        map<char, bool> visited;
        cout << "DFS traversal starting from " << start << ": ";
        DFSUtil(start, visited);
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

    // Add edges based on your image
    g.addEdge('A', 'B');
    g.addEdge('B', 'E');
    g.addEdge('A', 'D');
    g.addEdge('A', 'C');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');
    g.addEdge('B', 'D');

    // Optional: print graph structure
    g.printGraph();

    // DFS traversal
    g.DFS('A');
    g.DFS('B');
    g.DFS('C');
    g.DFS('D');
    g.DFS('E');

    return 0;
}
