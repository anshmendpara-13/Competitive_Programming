#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;

vector<int> g[N];
int dist[N][N]; // global are initialize with zero

int main()
{
    /*
    Shorted path find algorithm
    All pair shortest path algorithm
    In dijkstra algorithm work only one node at a time
    This algorithm not handle negative weight -> we handle this using if statement
    */

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }

            dist[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }

    for (int k = 1; k <= n; k++) // level; O(N^3)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "I"
                     << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}