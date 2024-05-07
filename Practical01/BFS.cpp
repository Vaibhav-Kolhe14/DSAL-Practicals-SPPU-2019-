#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int n;
    list<int>*adj;
    public:
    Graph(int vertices)
    {
        n = vertices;
        adj = new list<int>[n];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void BFS(int start)
    {
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++){
            visited[i] = false;
        }
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        delete[] visited;
    }
};

int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    Graph g(n);
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (from -> to):" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter starting vertex for BFS: ";
    cin >> startVertex;
    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    g.BFS(startVertex);

    return 0;
}
