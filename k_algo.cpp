#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

vector<vector<pii>> adjList;
vector<int> dist;
vector<int> pred;

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    dist[source] = 0;
    pred[source] = -1;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto edge : adjList[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                pred[v] = u;
            }
        }
    }
}

void printShortestPaths(int source)
{
    cout << "For node " << source << " : ";
    for (int i = 0; i < adjList.size(); ++i)
    {
        stack<int> path;
        for (int j = i; j != -1; j = pred[j])
        {
            path.push(j);
        }

        cout << dist[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    adjList.resize(n);
    dist.assign(n, INF);
    pred.assign(n, -1);

    for (int u = 0; u < n; ++u)
    {
        int m;
        cout << "Enter the number of adjacent nodes to node " << u << ": ";
        cin >> m;

        cout << "Enter the adjacent nodes and their weights for node " << u << ": ";
        for (int j = 0; j < m; ++j)
        {
            int v, w;
            cin >> v >> w;
            adjList[u].push_back({v, w});
        }
    }
    cout << endl;
    cout << "The minimum distances as per Dijkshtra's algoritm are :" << endl;
    for (int i = 0; i < n; i++)
    {
        dijkstra(i);
        printShortestPaths(i);
        cout << endl;
        adjList.resize(n);
        dist.assign(n, INF);
        pred.assign(n, -1);
    }

    return 0;
}
