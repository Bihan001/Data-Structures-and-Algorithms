#include <bits/stdc++.h>

using namespace std;

// In the graph, we have an array of vertices. When we set edges of the vertices, we consider the vertex's index in the array instead of the vertex itself.
// Every vertex object holds a data variable and the list of indexes of its neighbours.

class Vertex {
   public:
    string data;
    vector<int> neighbours;
    Vertex(string val) {
        data = val;
    }
};

class Graph {
   private:
    vector<Vertex> vertexList;

   public:
    void addVertex(string data) {
        vertexList.push_back(Vertex(data));
    }
    void set_edge(int u, int v) {
        vertexList[u].neighbours.push_back(v);
    }
    void dfs(int start, vector<bool> &visiting, vector<bool> &visited) {
        visiting[start] = true;
        visited[start] = true;
        for (int x : vertexList[start].neighbours) {
            if (visiting[x] == true) {
                cout << "Cycle found between " << vertexList[start].data << " and " << vertexList[x].data << endl;
                return;
            }
            if (!visited[x]) {
                dfs(x, visiting, visited);
            }
        }
        visiting[start] = false;
    }
    void find_cycles() {
        vector<bool> visiting(vertexList.size(), false);
        vector<bool> visited(vertexList.size(), false);
        for (int i = 0; i < vertexList.size(); i++) {
            if (!visited[i]) {
                dfs(i, visiting, visited);
            }
        }
        visiting.clear();
        visited.clear();
    }
};

int main() {
    Graph g;
    g.addVertex("A");  // 0
    g.addVertex("B");  // 1
    g.addVertex("C");  // 2
    g.addVertex("D");  // 3
    g.addVertex("E");  // 4
    g.addVertex("F");  // 5
    g.set_edge(0, 1);
    g.set_edge(0, 2);
    g.set_edge(1, 2);
    g.set_edge(3, 0);
    g.set_edge(3, 4);
    g.set_edge(4, 5);
    g.set_edge(5, 3);  // Makes the cycle
    g.find_cycles();
    return 0;
}