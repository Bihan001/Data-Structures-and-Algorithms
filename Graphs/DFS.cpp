#include <bits/stdc++.h>

using namespace std;

/*
    # Depth First Search Traversal.
    # Requires a stack.
    # The edges of the graph can be unidirectional/bidirectional.
    # Time complexity: O(V + E) | Space complexity: O(V)
*/

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
    void dfsUtil(int start, vector<bool> &visited) {
        visited[start] = true;
        cout << vertexList[start].data << " ";
        for (int x : vertexList[start].neighbours) {
            if (!visited[x]) {
                dfsUtil(x, visited);
            }
        }
    }
    void dfs() {
        vector<bool> visited(vertexList.size(), false);
        for (int i = 0; i < vertexList.size(); i++) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
        visited.clear();
        cout << endl;
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
    g.set_edge(0, 3);
    g.set_edge(0, 4);
    g.set_edge(3, 2);
    g.set_edge(2, 4);
    g.set_edge(4, 1);
    g.set_edge(4, 5);
    g.set_edge(4, 3);
    g.dfs();
    return 0;
}