#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int num_vertices;
    vector<set<int>> adjacency_list;

public:
    Graph(int n) {
        num_vertices = n;
        adjacency_list.resize(num_vertices);
    }

    void add_edge(int u, int v) {
        adjacency_list[u].insert(v);
        adjacency_list[v].insert(u);
    }

    Graph create_subgraph(set<int> nodes) {
        Graph subgraph(nodes.size());
        for (auto u : nodes) {
            for (auto v : nodes) {
                if (adjacency_list[u].count(v) > 0) {
                    subgraph.add_edge(u - *nodes.begin(), v - *nodes.begin());
                }
            }
        }
        subgraph.display();
        return subgraph;
    }

    Graph graph_union(Graph g2) {
        Graph result(num_vertices + g2.num_vertices);
        for (int u = 0; u < num_vertices; u++) {
            for (auto v : adjacency_list[u]) {
                result.add_edge(u, v);
            }
        }
        for (int u = 0; u < g2.num_vertices; u++) {
            for (auto v : g2.adjacency_list[u]) {
                result.add_edge(u + num_vertices, v + num_vertices);
            }
        }
        return result;
    }

    Graph graph_intersection(Graph g2) {
        set<int> common_nodes;
        for (int u = 0; u < num_vertices; u++) {
            for (auto v : adjacency_list[u]) {
                if (g2.adjacency_list[u].count(v) > 0) {
                    common_nodes.insert(u);
                    common_nodes.insert(v);
                }
            }
        }
        return create_subgraph(common_nodes);
    }

    bool is_disconnected(int u) {
        queue<int> q;
        vector<bool> visited(num_vertices, false);
        q.push(u);
        visited[u] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto w : adjacency_list[v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
        for (int i = 0; i < num_vertices; i++) {
            if (!visited[i]) {
                return true;
            }
        }
        return false;
    }

    int degree(int u) {
        return adjacency_list[u].size();
    }

    bool has_path(int u, int v) {
        vector<bool> visited(num_vertices, false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty()) {
            int w = q.front();
            q.pop();
            for (auto x : adjacency_list[w]) {
                if (x == v) {
                    return true;
                }
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return false;
    }

    void display() {
        for (int u = 0; u < num_vertices; u++) {
            cout << u << " -> ";
            for (auto v : adjacency_list[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(3, 4);
    std::cout << "Graph 1: " << std::endl;
    g.display();

    cout << "Create subgraph: ";
    set<int> nodes = {0, 1, 2};
    std::cout << "Created subgraph: " << std::endl;
    g.create_subgraph(nodes);

    Graph g2(4);
    g2.add_edge(0, 1);
    g2.add_edge(0, 2);
    g2.add_edge(1, 3);
    std::cout << "Graph 2: " << std::endl;
    g2.display();

    cout << "Graph union: " << std::endl;
    Graph union_graph = g.graph_union(g2);
    union_graph.display();

    cout << "Graph intersection: " << std::endl;
    Graph intersection_graph = g.graph_intersection(g2);
    intersection_graph.display();

    cout << "Disconnected vertex: " << g.is_disconnected(3) << endl;
    cout << "Degree of vertex 2: " << g.degree(2) << endl;
    cout << "Has path from 0 to 4: " << g.has_path(0, 4) << endl;

    return 0;
}
