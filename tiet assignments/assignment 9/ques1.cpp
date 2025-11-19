#include <iostream>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j] = 0;

    for(int i=0;i<e;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cin >> start;

    int visited[20];
    for(int i=0;i<n;i++)
        visited[i] = 0;

    int q[20];
    int front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    cout << "BFS: ";

    while(front != rear)
    {
        int node = q[front++];
        cout << node << " ";

        for(int i=0;i<n;i++)
        {
            if(adj[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }

    return 0;
}
