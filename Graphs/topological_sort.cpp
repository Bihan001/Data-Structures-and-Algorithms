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
    void dfs(int start, vector<bool> &visited, stack<int> &s) {
        visited[start] = true;
        for (int x : vertexList[start].neighbours) {
            if (!visited[x]) {
                dfs(x, visited, s);
            }
        }
        s.push(start);
    }
    void topological_sort() {
        vector<bool> visited(vertexList.size(), false);
        stack<int> s;
        for (int i = 0; i < vertexList.size(); i++) {
            if (!visited[i]) {
                dfs(i, visited, s);
            }
        }
        while (!s.empty()) {
            cout << vertexList[s.top()].data << " ";
            s.pop();
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
    g.set_edge(2, 3);
    g.set_edge(3, 1);
    g.set_edge(4, 0);
    g.set_edge(4, 1);
    g.set_edge(5, 0);
    g.set_edge(5, 2);
    g.topological_sort();
    return 0;
}