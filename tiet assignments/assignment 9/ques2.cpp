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

    int st[20];
    int top = -1;

    st[++top] = start;

    cout << "DFS: ";

    while(top != -1)
    {
        int node = st[top--];

        if(visited[node] == 0)
        {
            cout << node << " ";
            visited[node] = 1;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(adj[node][i] == 1 && visited[i] == 0)
            {
                st[++top] = i;
            }
        }
    }

    return 0;
}
