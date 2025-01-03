#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;

vector<pair<int, int>> g[N];
vector<int> level(N, INF);
int n, m;

int bfs()
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop_front();

        for (auto child : g[current_vertex])
        {
            int child_vertex = child.first;
            int wt = child.second;

            if (level[current_vertex] + wt < level[child_vertex])
            {
                level[child_vertex] = level[current_vertex] + wt;
                if (wt == 1)
                {
                    q.push_back(child_vertex);
                }
                else
                {
                    q.push_front(child_vertex);
                }
            }
        }
    }
    return level[n] == INF ? -1 : level[n];
}

int main()
{
    // at a time queue have only two levels of nodes
    // chef and reversing
    // in zero-one bfs no need to visited array and use dequeue

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }

    cout << bfs() << endl;

    return 0;
}