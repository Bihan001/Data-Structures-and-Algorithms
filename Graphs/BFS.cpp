#include <bits/stdc++.h>

using namespace std;

// In the graph, we have an array of vertexes. When we set edges of the vertexes, we consider the vertex's index in the array instead of the vertex itself.
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
    void bfs() {
        queue<int> q;
        vector<bool> visited(vertexList.size(), false);
        for (int i = 0; i < vertexList.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int p = q.front();
                    q.pop();
                    cout << vertexList[p].data << " ";
                    for (int x : vertexList[p].neighbours) {
                        if (!visited[x]) {
                            visited[x] = true;
                            q.push(x);
                        }
                    }
                }
            }
        }
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
    g.addVertex("G");  // 6
    g.addVertex("H");  // 7
    g.set_edge(0, 1);
    g.set_edge(0, 5);
    g.set_edge(0, 6);
    g.set_edge(1, 2);
    g.set_edge(1, 3);
    g.set_edge(3, 4);
    g.set_edge(6, 7);
    g.bfs();
    return 0;
}