#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Graph class
class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's adjacency list
    }

    // Function to perform BFS traversal from a given source vertex
    void BFS(int s) {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        // 'i' will be used to get all adjacent vertices of a vertex
        list<int>::iterator i;

        while(!queue.empty()) {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex s. If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for(i = adj[s].begin(); i != adj[s].end(); ++i) {
                if(!visited[*i]) {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }
        }
    }
};

int main() {
    // Create a graph given in the example
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS traversal starting from vertex 2: ";
    g.BFS(2);

    return 0;
}
