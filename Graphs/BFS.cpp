#include <bits/stdc++.h>

using namespace std;

/*
    # Breadth First Search Traversal.
    # Requires a queue.
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
    int getVertexListSize() {
        return vertexList.size();
    }
    void addVertex(string data) {
        vertexList.push_back(Vertex(data));
    }
    // Directed
    void set_edge(int u, int v) {
        vertexList[u].neighbours.push_back(v);
    }

    // Normal BFS
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
    // Calculates distance from root node...assuming its undirected and tree like
    vector<int> bfs_calc_distance() {
        queue<int> q;
        vector<bool> visited(vertexList.size(), false);
        vector<int> distance(vertexList.size(), -1);
        for (int i = 0; i < vertexList.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                distance[i] = 0;
                while (!q.empty()) {
                    int p = q.front();
                    q.pop();
                    for (int x : vertexList[p].neighbours) {
                        if (!visited[x]) {
                            visited[x] = true;
                            q.push(x);
                            distance[x] = distance[p] + 1;
                        }
                    }
                }
            }
        }
        return distance;
    }

    // Calculates parent of each ndoe...assuming its undirected
    vector<int> bfs_calc_parent() {
        queue<int> q;
        vector<bool> visited(vertexList.size(), false);
        vector<int> parent(vertexList.size(), -1);
        for (int i = 0; i < vertexList.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int p = q.front();
                    q.pop();
                    for (int x : vertexList[p].neighbours) {
                        if (!visited[x]) {
                            visited[x] = true;
                            q.push(x);
                            parent[x] = p;
                        }
                    }
                }
            }
        }
        return parent;
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
    cout << endl;
    vector<int> dist = g.bfs_calc_distance();
    for (auto it : dist) cout << it << " ";
    cout << endl;
    vector<int> par = g.bfs_calc_parent();
    for (auto it : par) cout << it << " ";
    cout << endl;
    for (int i = 0; i < g.getVertexListSize(); i++) {
        cout << i << "\t";
        int cur = par[i];
        deque<int> path;
        path.push_front(i);
        while (cur != -1) {
            path.push_front(cur);
            cur = par[cur];
        }
        for (auto it : path) cout << it << " ";
        path.clear();
        cout << endl;
    }
    return 0;
}