#include <iostream>
#include <list>
#include <stack>

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

    // Function to perform DFS traversal from a given source vertex
    void DFS(int s) {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;

        // Create a stack for DFS
        stack<int> stack;

        // Mark the current node as visited and push it onto the stack
        visited[s] = true;
        stack.push(s);

        // 'i' will be used to get all adjacent vertices of a vertex
        list<int>::iterator i;

        while(!stack.empty()) {
            // Pop a vertex from stack and print it
            s = stack.top();
            cout << s << " ";
            stack.pop();

            // Get all adjacent vertices of the popped vertex s. If an adjacent vertex has not been visited, then mark it visited and push it onto the stack
            for(i = adj[s].begin(); i != adj[s].end(); ++i) {
                if(!visited[*i]) {
                    visited[*i] = true;
                    stack.push(*i);
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

    cout << "DFS traversal starting from vertex 2: ";
    g.DFS(2);

    return 0;
}
