#include <iostream>
#include <limits.h>
#include <list>
#include <stack>

using namespace std;

class nodoTopologico {
    int v;
    int weight;

public:
    nodoTopologico(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};


class Graph {
    int V;

    list<nodoTopologico>* adj;

    // helping function
    void activityOrder(int v, bool visited[],stack<int>& Stack)
{
    visited[v] = true;

    list<nodoTopologico>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        nodoTopologico node = *i;
        if (!visited[node.getV()])
            activityOrder(node.getV(), visited, Stack);
    }

    Stack.push(v);
}

public:
    Graph(int V) // Constructor
    {
        this->V = V;
        adj = new list<nodoTopologico>[V];
    }
    ~Graph()
    {
        delete [] adj;
    }

    void addEdge(int u, int v, int weight)
    {
        nodoTopologico node(v, weight);
        adj[u].push_back(node); // Add v to u's list
    }

    void longestPath(int s=0)
    {
        stack<int> Stack;
        int dist[V];
        bool* visited = new bool[V];
        //sets all to unvisited
        for (int i = 0; i < V; i++)visited[i] = false;

        //orden topologico al stack
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                activityOrder(i, visited, Stack);
        //sets distances to minimum value
        for (int i = 0; i < V; i++)dist[i] = INT_MIN;
        dist[s] = 0;

        while (Stack.empty() == false)
        {
            int u = Stack.top();
            Stack.pop();
            list<nodoTopologico>::iterator i;
            if (dist[u] != INT_MIN) {
                for (i = adj[u].begin(); i != adj[u].end(); ++i)
                {
                    if (dist[i->getV()] < dist[u] + i->getWeight())dist[i->getV()] = dist[u] + i->getWeight();
                }
            }
        }

    for (int i = 0; i < V; i++)
        (dist[i] == INT_MIN) ? cout << "Infinite " : cout << dist[i] << " ";
        delete [] visited;
    }
};


int main()
{
    Graph g(9);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 2);
    g.addEdge(5, 7, 4);
    g.addEdge(4, 7, 7);
    g.addEdge(4, 6, 9);
    g.addEdge(6, 8, 2);
    g.addEdge(7, 8, 4);

    int s = 0;
    cout << "Critical Path from source "<< s << " \n";
    g.longestPath();

    return 0;
}
