#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
vector<int> g[N];
int visited[N];
int level[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);

    visited[source] = 1;
    while (!q.empty())
    {
        int current_vertex = q.front();
        cout << current_vertex << endl;
        q.pop();
        for (auto child : g[current_vertex])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                level[child] = level[current_vertex] + 1;
            }
        }
    }
}

int main()
{
    // BFS -> level order traversal, help in shortest path (level give the shortest path)
    // v- nodes, E-edges so while loop run v time and for loop run connected edges(e) time
    // O(V+E)
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);

    for (int i = 1; i < n; i++)
    {
        cout << i << ":" << level[i] << endl;
    }

    return 0;
}