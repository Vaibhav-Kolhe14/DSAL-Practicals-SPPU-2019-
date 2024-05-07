#include <iostream>
#include <stack>
using namespace std;

class Graph
{
    int a[10][10];
    int n, m = 0;
    int l = 0;
    int visited[10], city[10], visit[10];
    int s[10];

public:
    Graph()
    {
        for (int i = 0; i < 10; i++)
        {
            visited[i] = 0;
        }
    }
    void create();
    void display();
    void Display();
    void DFS(int);
    void NDFS(int);
};

void Graph::DFS(int start)
{
    visited[start] = 1;
    s[m] = start;
    m++;
    for (int i = 0; i < n; i++)
    {
        if (a[start][i] == 1 && visited[i] != 1)
        {
            DFS(i);
        }
    }
}

void Graph::NDFS(int start)
{

    stack<int> st;
    st.push(start);
    visit[start] = 1;
    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        s[l] = current;
        l++;
        for (int i = 0; i < n; i++)
        {
            if (a[current][i] == 1 && visited[i] != 1)
            {
                st.push(i);
                visit[i] = 1;
            }
        }
    }
}

void Graph::create()
{
    cout << "Enter No. of node:";
    cin >> n;
    cout << "enter the locations\n";
    for (int i = 0; i < n; i++)
        cin >> city[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter the value " << city[i] << " to " << city[j] << " 1/0: ";
            cin >> a[i][j];
        }
    }
}

void Graph::display()
{
    cout << "Representation of Graph Using Adjacency Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << "]";
        cout << endl;
    }
}

void Graph::Display()
{
    cout << "Display DFS using Recursion" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    cout << "Display DFS using Non-Recursion" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
}

int main()
{
    Graph g;
    g.create();
    g.display();
    g.DFS(0); // Starting Vertex

    g.NDFS(0); // Starting Vertex
    g.Display();

    return 0;
}