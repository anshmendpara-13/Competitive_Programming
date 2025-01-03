#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
int graph1[N][N];
// O(N^2) - space complexity
// N = 10^5 -> this we can not store, max store is upto N < 1e3+7

vector<pair<int, int>> graph2[N];
// O(V+E)  - time and space complexity maximum - O(V^2)

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        // cin >> v1 >> v2;
        // graph1[v1][v2] = 1;
        // graph1[v2][v1] = 1;

        // if weighted graph
        cin >> v1 >> v2 >> w;
        graph1[v1][v2] = w;
        graph1[v2][v1] = w;

        graph2[v1].push_back({v2, w});
        graph2[v2].push_back({v1, w});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (auto val : graph2[i])
        {
            cout << i << " " << val.first << " " << val.second;
            cout << endl;
        }
    }

    // i,j connected ?
    // if (graph1[i][j] == 1) // O(n^2)
    // {
    //     // connected
    // }

    // for (auto child : graph2[i])  // O(n)
    // {
    //     if (child == j)
    //     {
    //         // connected
    //     }
    // }

    // for weighted graph
    // for (auto val : graph2[i])
    // {
    //     if(child.first == j)
    //         // connected
    //         child.second
    // }

    return 0;
}